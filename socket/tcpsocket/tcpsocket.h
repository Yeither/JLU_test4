#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#include <WinSock2.h>
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#pragma comment (lib,"ws2_32.lib")
#define PORT 8088
bool init_socket();
bool close_socket();
SOCKET create_server_socket();
SOCKET create_client_socket();
const char dir[] = "255.255.255.255";
#endif // !_TCPSOCKET_H_
