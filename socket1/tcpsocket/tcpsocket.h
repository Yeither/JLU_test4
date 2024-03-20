#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#include <WinSock2.h>
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include<thread>
#pragma comment (lib,"ws2_32.lib")
#define PORT 8888
bool init_socket();
bool close_socket();
SOCKET create_server_socket();
SOCKET create_client_socket();
void send_thread(char buffer_send[BUFSIZ], SOCKET client_fd);
void recv_thread(char buffer[BUFSIZ], SOCKET client_fd);
const char dir[] = "255.255.255.255";
#endif // !_TCPSOCKET_H_
