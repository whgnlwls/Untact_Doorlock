#ifndef SERVER_H
#define SERVER_H

#include "DoorLockHead.h"
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUFSIZE 512

//thread
void* clientThread(void* clientSock);

//class
class Server extends SensorControl {
private:
	int serverSocket;
	int clientSocket;
	
	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;
	
	char msgbuf[BUFSIZE + 1];

protected:
	//initialize
	Server() {};
	Server(int PORT);
	
	~Server();
	
	//bind
	void bindSocket();
	
	//listen
	void listenSocket();
	
	//accept
	void acceptSocket();
	
public:
	//print error
	void showError(const char* msg);
	
	//create server
	void createServer(int PORT);
};

#endif
