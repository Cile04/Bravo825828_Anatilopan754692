/*
 * protocol.h
 *
 * Client header file
 * Definitions, constants and function prototypes for the client
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

<<<<<<< Updated upstream
<<<<<<< Updated upstream
// Shared application parameters
#define SERVER_PORT 27015  // Server port (change if needed)
#define BUFFER_SIZE 512    // Buffer size for messages
=======
=======
>>>>>>> Stashed changes
// Parametri condivisi
#define SERVER_PORT 56700  // REQUISITO: Porta 56700
#define BUFFER_SIZE 512    // Dimensione Buffer
#define QUEUE_SIZE 5       // Coda connessioni
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

// Codici di stato (Status Codes)
#define VALID_REQ 0     // Successo
#define INVALID_CITY 1  // Città non disponibile
#define INVALID_REQ 2   // Richiesta non valida

// Struttura Messaggio di Richiesta (Client -> Server)
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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
// Prototipi funzioni meteo (se servono al server)
float get_temperature(void);    // Range: -10.0 to 40.0 °C
float get_humidity(void);       // Range: 20.0 to 100.0 %
float get_wind(void);           // Range: 0.0 to 100.0 km/h
float get_pressure(void);       // Range: 950.0 to 1050.0 hPa

/*
 * Example function to implement:
 * int connect_to_server(const char* server_address);
 */
=======
=======
>>>>>>> Stashed changes
// Prototipi funzioni meteo (utili per il server)
float get_temperature(void);
float get_humidity(void);
float get_wind(void);
float get_pressure(void);
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

#endif /* PROTOCOL_H_ */