#include<iostream>
#include<string>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
void usage(std::string proc)
{
    std::cout<<"usage"<<proc<<"server_ip server_port"<<std::endl;
}
std::string server_ip=argv[1];
uint16_t server_port=(uint16_t)atoi(argv[2]);
int main(int argc ,char* argv[])
{
    if(argc !=3)
    {
        usage(argv[0]);
        return 1;
    }
    //1.创建套接字
    int socket_fd=socket(AT_INET,SOCK_STREAM,0);
    if(socket_fd<0)
    {
        std::cout<<"socket error: "<<errno<<std::endl;
        exit(1);
    }

    //2.隐式绑定端口号
    struct sockaddr_in server;
    memset(&server,0,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr(server_ip.c_str());
    server.sin_port=htons(server_port);
    
    //3.连接服务器
    int connect_num=connect(socket_fd,(struct sockaddr*)&server,sizeof(server));
    if(connect_num<0)
    {
        std::cout<<"connect error: "<<errno<<std::endl;
        exit(2);
    }
    
    //4.对信息进行读取或者发送
    while(true)
    {
        std::cout<<"请输入：";
        char pipe[100];
        fget(pipe,sizeof(pipe),stdin);
        
    }

    return 0;
}