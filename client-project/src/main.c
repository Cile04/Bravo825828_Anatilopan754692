/*
 * main.c
 *
 * TCP Client - Template for Computer Networks assignment
 *
 * This file contains the boilerplate code for a TCP client
 * portable across Windows, Linux and macOS.
 */

#if defined WIN32
#include <winsock.h>
#else
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctype.h>
#define closesocket close
#endif

#include <stdio.h>
#include <stdlib.h>
#include "protocol.h"

#define NO_ERROR 0
#define DEFAULT_IP_SV "127.0.0.1"

void clearwinsock() {
#if defined WIN32
	WSACleanup();
#endif
}

void errorhandler(char *error_message) {
	printf("%s",error_message);
}

int main(int argc, char *argv[]) {

#if defined WIN32
	// Initialize Winsock
	WSADATA wsa_data;
	int result = WSAStartup(MAKEWORD(2,2), &wsa_data);
	if (result != NO_ERROR) {
		printf("Error at WSAStartup()\n");
		return 0;
	}
#endif


    // Creazione socket
    int c_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (c_socket < 0) {
        perror("Socket creation failed.\n");
        return -1;
    }

    // Dico l'indirizzo a cui connettersi 
    struct sockaddr_in sad;
    memset(&sad, 0, sizeof(sad));
    
    sad.sin_family = AF_INET;
    sad.sin_addr.s_addr = inet_addr(DEFAULT_IP_SV); // IP del server (localhost)
    sad.sin_port = htons(SERVER_PORT);            // Porta del server (27015)

    // Connessione al server
    if (connect(c_socket, (struct sockaddr *)&sad, sizeof(sad)) < 0) {
        perror("Failed to connect.\n");
        closesocket(c_socket);
        return -1;
    }

    printf("Connected to server 127.0.0.1:%d\n", SERVER_PORT);

    // TODO: Qui invieresti la weather_request_t con send()
    // e riceveresti la weather_response_t con recv()

    closesocket(c_socket);;
    printf("Client terminated.\n");

	clearwinsock();
    return 0;
	

	// TODO: Create socket
	// my_socket = socket(...);

	// TODO: Configure server address
	// struct sockaddr_in server_addr;
	// ...

	// TODO: Connect to server
	// connect(...);

	// TODO: Implement communication logic
	// send(...);
	// recv(...);

	// TODO: Close socket
	// closesocket(my_socket);

} // main end
