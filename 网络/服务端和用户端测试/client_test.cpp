#include<iostream>
#include<cerrno>
#include<string>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
int main(int argc,char* argv[])
{
    //创建套接字socket
    int socket_num=socket(AF_INET,SOCK_DGRAM,0);
    if(socket_num<0)
    {
        std::cout<<"socket error"<<errno<<std::endl;
        exit(1);
    }

    //2.绑定端口号，客户端不用显示的进行绑定端口
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(atoi(argv[2]));
    server.sin_addr.s_addr=inet_addr(argv[1]);
    socklen_t len=sizeof(server);
    
    //3.使用来自服务器的服务
    while(1)
    {
        std::string information;
        std::cout<<"请输入->";
        std::cin>>information;

        //1.发送数据
        sendto(socket_num,information.c_str(),information.size(),0,(struct sockaddr*)&server,len);

        //2.接收数据
        char pipe[100];
        struct sockaddr_in ret;
        socklen_t _len=sizeof(ret);
        recvfrom(socket_num,pipe,sizeof(pipe),0,(struct sockaddr*)&ret,&_len);
        std::cout<<"from server:"<<pipe<<std::endl;
    }


    return 0;
}