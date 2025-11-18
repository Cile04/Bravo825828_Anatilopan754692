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
#include <netdb.h>
#define closesocket close
#endif

#include <stdio.h>
#include <stdlib.h>
#include "protocol.h"

#define NO_ERROR 0


int main(int argc, char *argv[]) {


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
    sad.sin_addr.s_addr = inet_addr("127.0.0.1"); 
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
