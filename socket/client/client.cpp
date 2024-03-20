#include"../tcpsocket/tcpsocket.h"

int main() {
	init_socket();
	SOCKET client_fd = create_client_socket();
	while (true) {
		char buffer[BUFSIZ] = "\0";
		std::cout << "send<";
		std::cin >> buffer;
		if (SOCKET_ERROR == send(client_fd, buffer, strlen(buffer), 0)) {
			std::cerr << "line:" << __LINE__ << " send ·¢ËÍ´íÎó";
		}
		if (strcmp(buffer, "quit") == 0) break;
		memset(buffer, 0, sizeof(buffer));
	}
	std::cout << "closing..."<<std::endl;
	closesocket(client_fd);
	close_socket();
	std::cout << "closed" << std::endl;
	getchar(); getchar();
	return 0;
}