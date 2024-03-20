#include"tcpsocket.h"


bool init_socket()
{
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) {
		std::cerr << "line:" << __LINE__ << " WSAStartup Ì×½Ó×ÖÆô¶¯´íÎó";
		return false;
	};
	return true;
}

bool close_socket()
{
	if (0 != WSACleanup()) {
		std::cerr << "line:"<< __LINE__ << " WSACleanup Ì×½Ó×Ö¹Ø±Õ´íÎó";
		return false;
	};
	return true;

}

SOCKET create_server_socket()
{
	SOCKET fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (fd == INVALID_SOCKET) {
	std::cerr<< "line:" << __LINE__ << " socket ´´½¨´íÎó";
	return INVALID_SOCKET;
	}

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.S_un.S_addr = ADDR_ANY;
	if (SOCKET_ERROR == bind(fd, (struct sockaddr*)&address, sizeof(address))) {
		std::cerr<< "line:" << __LINE__ << " bind Á´½Ó´íÎó";
		return false;
	};
	listen(fd, 10);
	return fd;
}

SOCKET create_client_socket()
{
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET) {
		std::cerr << "line:" << __LINE__ << " socket ´´½¨´íÎó";
		return INVALID_SOCKET;
	}

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.S_un.S_addr = inet_addr(dir);

	if (INVALID_SOCKET == connect(fd, (struct sockaddr*)&address, sizeof(address))) {
		std::cerr<< "line:" << __LINE__ << " connect Á´½Ó´íÎó";
		return false;
	};

	return fd;
}

void send_thread(char buffer_send[BUFSIZ],SOCKET client_fd) {
	while (true) {
		std::cout << "send<"<<std::endl;
		std::cin >> buffer_send;
		if (SOCKET_ERROR == send(client_fd, buffer_send, strlen(buffer_send), 0)) {
			std::cerr << "line:" << __LINE__ << " send ·þÎñÆ÷·¢ËÍ´íÎó";
		};
	}
}

void recv_thread(char buffer[BUFSIZ], SOCKET client_fd) {
	while (true) {
		time_t curtime = time(NULL);
		char timebuf[26];
		ctime_s(timebuf, sizeof(timebuf), &curtime);

		if (0 < recv(client_fd, buffer, BUFSIZ, 0)) {
			std::cout << "time : " << timebuf << "getmsg: " << buffer << std::endl;
			memset(buffer, 0, sizeof(buffer));
		};
	}
}