/*
 * protocol.h
 *
 * Server header file
 * Definitions, constants and function prototypes for the server
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

// Shared application parameters
#define SERVER_PORT 27015  // Server port (change if needed)
#define BUFFER_SIZE 512    // Buffer size for messages
#define QUEUE_SIZE 5       // Size of pending connections queue

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

// Prototipi funzioni meteo (se servono al server)
float get_temperature(void);    // Range: -10.0 to 40.0 °C
float get_humidity(void);       // Range: 20.0 to 100.0 %
float get_wind(void);           // Range: 0.0 to 100.0 km/h
float get_pressure(void);       // Range: 950.0 to 1050.0 hPa

/*
 * Example function to implement:
 * int handle_client(int client_socket);
 */

#endif /* PROTOCOL_H_ */
