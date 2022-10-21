#include<iostream>
#include<cerrno>
#include<string>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

const uint16_t port=1020;
int main()
{
    //1.创建socket文件描述符
    int sock_fd=socket(AF_INET,SOCK_DGRAM,0);
    if(sock_fd<0)
    {
        std::cerr<<"socket error"<<errno<<std::endl;
        exit(1);
    }
    //std::cout<<"sock_fd="<<sock_fd<<std::endl;

    //2.绑定端口号
    struct sockaddr_in local;
    local.sin_family=AF_INET;
    local.sin_port= htons(port);
    //local.sin_addr.s_addr=inet_addr("124.223.105.251");
    local.sin_addr.s_addr=INADDR_ANY;
    int bind_num=bind(sock_fd,(struct sockaddr*)&local,sizeof(local));
    if(bind_num<0)
    {
        std::cerr<<"bind error"<<errno<<std::endl;
        exit(1);
    }

    //3.给用户提供服务
    char pipe[100];
    while(1)
    {
        struct sockaddr_in client;
        socklen_t len=sizeof(client);
        
        //1.接收数据
        recvfrom(sock_fd,pipe,sizeof(client)-1,0,(struct sockaddr*)&client,&len);
        std::cout<<"from client:"<<pipe<<std::endl;

        //2.发送数据
        std::string say="hello";
        sendto(sock_fd,say.c_str(),say.size(),0,(struct sockaddr*)&client,len);
    }

    return 0;
}