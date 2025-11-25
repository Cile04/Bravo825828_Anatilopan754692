/*
 * protocol.h
 *
 * Server header file
 * Definitions, constants and function prototypes for the server
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

<<<<<<< Updated upstream
<<<<<<< Updated upstream
// Shared application parameters
#define SERVER_PORT 27015  // Server port (change if needed)
#define BUFFER_SIZE 512    // Buffer size for messages
#define QUEUE_SIZE 5       // Size of pending connections queue

// Function prototypes
// Add here the signatures of the functions implemented by students

// Strutture dati applicative (Meteo)
=======
// Parametri condivisi
#define SERVER_PORT 56700  // REQUISITO: Porta 56700
#define BUFFER_SIZE 512    // Dimensione Buffer
#define QUEUE_SIZE 5       // Coda connessioni

=======
// Parametri condivisi
#define SERVER_PORT 56700  // REQUISITO: Porta 56700
#define BUFFER_SIZE 512    // Dimensione Buffer
#define QUEUE_SIZE 5       // Coda connessioni

>>>>>>> Stashed changes
// Codici di stato (Status Codes)
#define VALID_REQ 0     // Successo
#define INVALID_CITY 1  // Città non disponibile
#define INVALID_REQ 2   // Richiesta non valida

// Struttura Messaggio di Richiesta (Client -> Server)
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
typedef struct {
    char type;        // 't', 'h', 'w', 'p'
    char city[64];    // Nome città (es. "Bari")
} weather_request_t;

// Struttura Messaggio di Risposta (Server -> Client)
typedef struct {
    unsigned int status;  // 0, 1, 2
    char type;            // Echo del tipo
    float value;          // Valore numerico
} weather_response_t;

// Prototipi funzioni meteo (utili per il server)
float get_temperature(void);
float get_humidity(void);
float get_wind(void);
float get_pressure(void);

#endif /* PROTOCOL_H_ */
