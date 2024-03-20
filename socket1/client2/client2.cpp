#include"../tcpsocket/tcpsocket.h"

int main() {
	init_socket();
	SOCKET client_fd = create_client_socket();
	char sendbuffer[BUFSIZ] = "\0";
	char buffer[BUFSIZ] = "\0";
	std::thread thread1(send_thread, sendbuffer, client_fd);
	std::thread thread2(recv_thread, buffer, client_fd);
	thread1.join();
	thread2.join();
	std::cout << "closing..." << std::endl;
	closesocket(client_fd);
	close_socket();
	std::cout << "closed" << std::endl;
	getchar(); getchar();
	return 0;
}