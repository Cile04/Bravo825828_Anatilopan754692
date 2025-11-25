/*
 * protocol.h
 *
 * Client header file
 * Definitions, constants and function prototypes for the client
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

// Shared application parameters
#define SERVER_PORT 27015  // Server port 
#define BUFFER_SIZE 512    // Buffer size for messages

// Function prototypes
// Add here the signatures of the functions implemented by students

// Strutture dati applicative (Meteo)
typedef struct {
    char type;        // 't', 'h', 'w', 'p'
    char city[64];    // Nome città
} weather_request_t;

typedef struct {
    unsigned int status;  // Codice stato
    char type;            // Echo del tipo richiesta
    float value;          // Valore meteo
} weather_response_t;

/*
 * Example function to implement:
 * int connect_to_server(const char* server_address);
 */

#endif /* PROTOCOL_H_ */
