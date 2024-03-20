#include"../tcpsocket/tcpsocket.h"


int main() {
	init_socket();
	SOCKET server_fd = create_server_socket();
	std::cout << "waiting...." << std::endl;
	SOCKET client_fd = accept(server_fd, NULL, NULL);
	if (INVALID_SOCKET == client_fd) {
		std::cerr << "line:" << __LINE__ << " accept ½ÓÊÕ´íÎó";
	}
	char buffer[BUFSIZ] = { 0 };
	char buffer_send[BUFSIZ] = { 0 };

	std::thread thread1(send_thread, buffer_send, client_fd);
	std::thread thread2(recv_thread, buffer, client_fd);
	thread1.join();
	thread2.join();
	closesocket(client_fd);
	closesocket(server_fd);
	close_socket();

	getchar();
	return 0;
}