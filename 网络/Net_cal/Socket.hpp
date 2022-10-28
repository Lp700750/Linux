#include<iostream>
#include<string>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
class Socket
{
public:
    //1.创建套接字
    static int socket()
    {
        int sock_fd=socket(AF_INET,SOCK_STREAM,0);
        if(sock_fd<0)
        {
            std::cout<<"socket error: "<<errno<<std::endl;
            exit(1);
        }
        return sock_fd;
    }
    //2.绑定端口号
    static void bind(uint16_t server_port)
    {
        struct sockaddr_in server;
        server.sin_family=AF_INET;
        server.sin_port=htons(server_port);
        server.sin_addr.s_addr=INADDR_ANY;
        int bind_num=bind(sock_fd,(struct sockaddr*)&server,sizeof(server));
        if(bind_fd<0)
        {
            std::cout<<"bind error: "<<errno<<std::endl;
            exit(2);            
        }
    }
    //3.监听客户端IP
    static void listen()
    {
        int listen_num=listen(sock_fd,5);
        if(listen_num<0)
        {
            std::cout<<"listen error: "<<errno<<std::endl;
            exit(3); 
        }
    }
    //4.接受客户端的消息
    static int recept()
    {
        //定义一个临时的变量来接收客户端的ip
        struct sockaddr_in tmp;
        int recept_fd=recept(sock_fd,(struct sockaddr*)&tmp,sizeof(tmp));
        if(recept_fd<0)
        {
            continue;
        }
        //接受客户端的ip成功
        std::string client_ip=inet_ntoa(tem.sin_addr);
        uint16_t client_port=ntohs(tem.sin_port);
    }      
   
};
