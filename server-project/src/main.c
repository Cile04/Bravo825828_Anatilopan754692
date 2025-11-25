/*
 * main.c
 *
 * TCP Server - Template for Computer Networks assignment
 *
 * This file contains the boilerplate code for a TCP server
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
#include <ctype.h>
#include <netdb.h>
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

float get_temperature(void) { // Range: -10.0 to 40.0 gradi C
    return (-10.0) + ((float) rand() / (float) RAND_MAX * (50.0));
}

float get_humidity(void) { // Range: 20.0 to 100.0 %
    return (20.0) + ((float) rand() / (float) RAND_MAX * (80.0));
}

float get_wind(void) { // Range: 0.0 to 100.0 km/h
    return (float) rand() / (float) RAND_MAX * (100.0);
}

float get_pressure(void) { // Range: 950.0 to 1050.0 hPa
    return (950.0) + ((float) rand() / RAND_MAX * (100.0));
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


    //Creazione Socket
    int my_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (my_socket < 0) {
        perror("Socket creation failed.\n");
        return -1;
    }

    // Connessione SERVER
    struct sockaddr_in sad;
    
    memset(&sad, 0, sizeof(sad)); 
    
    sad.sin_family = AF_INET;
    sad.sin_addr.s_addr = inet_addr(DEFAULT_IP_SV); 
    sad.sin_port = htons(SERVER_PORT); 

    // binding al socket
    if (bind(my_socket, (struct sockaddr*) &sad, sizeof(sad)) < 0) {
        perror("Bind failed.\n");
        return -1;
    }

    // Metto in ascolto il server
    if (listen(my_socket, QUEUE_SIZE) < 0) {
        perror("Listen failed.\n");
        return -1;
    }

    printf("Server listening on 127.0.0.1:%d\n", SERVER_PORT);

    //accetto connessione
    struct sockaddr_in cad; // Client Address
    int client_socket;
    int client_len;

    while (1) {
        printf("Waiting for a client to connect...\n");
        client_len = sizeof(cad);

        client_socket = accept(my_socket, (struct sockaddr *)&cad, &client_len);

        if (client_socket < 0) {
            perror("Accept failed.\n");
            continue; 
        }

        printf("Handling client: %s\n", inet_ntoa(cad.sin_addr));

        
        closesocket(client_socket);
        printf("Client disconnected.\n");
    }

    closesocket(my_socket);
    return 0;
}

// TODO: Create socket
	// my_socket = socket(...);

	// TODO: Configure server address
	// struct sockaddr_in server_addr;
	// server_addr.sin_family = AF_INET;
	// server_addr.sin_port = htons(SERVER_PORT);
	// server_addr.sin_addr.s_addr = INADDR_ANY;

	// TODO: Bind socket
	// bind(...);

	// TODO: Set socket to listen
	// listen(...);

	// TODO: Implement connection acceptance loop
	// while (1) {
	//     int client_socket = accept(...);
	//     // Handle client communication
	//     closesocket(client_socket);
	// }
