.PHONY:all
all:tcp_client tcp_server

tcp_client:tcp_client.cpp
	g++ -o $@ $^ -std=c++11

tcp_server:tcp_server.cpp
	g++ -o $@ $^ -std=c++11
	
.PHONY:clean
clean:
	rm -f tcp_client tcp_server