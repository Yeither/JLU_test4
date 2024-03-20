#include"../tcpsocket/tcpsocket.h"


int main() {
	init_socket();
	SOCKET server_fd = create_server_socket();
	std::cout << "waiting...."<<std::endl;
	SOCKET client_fd = accept(server_fd, NULL, NULL);
		if (INVALID_SOCKET == client_fd) {
			std::cerr << "line:" << __LINE__ << " accept ½ÓÊÕ´íÎó";
		}
		char buffer[BUFSIZ] = { 0 };
while (true) {
		time_t curtime = time(NULL);
		char buf[26];
		ctime_s(buf, sizeof(buf), &curtime);
		if (0 < recv(client_fd, buffer, BUFSIZ, 0)) {
			std::cout <<"time : " << buf << "getmsg: " << buffer << std::endl;
			memset(buffer, 0, sizeof(buffer));
		};
	}
	
	closesocket(client_fd);
	closesocket(server_fd);
	close_socket();
	
	getchar();
	return 0;
}