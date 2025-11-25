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
#define closesocket close
#endif

#include <stdio.h>
#include <stdlib.h>
#include "protocol.h"

#define NO_ERROR 0
<<<<<<< Updated upstream
=======
#define DEFAULT_IP_SV "127.0.0.1"

void clearwinsock()
{
#if defined WIN32
    WSACleanup();
#endif
}

void errorhandler(char *error_message)
{
    printf("%s", error_message);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
}
>>>>>>> Stashed changes

char *risposta_meteo(char tipo, float value)
{
    static char temp[40];
    switch (tipo)
    {
    case 't':
        snprintf(temp, sizeof(temp), "Temperatura = %.1f \u00B0C", value);
        break;
    case 'p':
        snprintf(temp, sizeof(temp), "Pressione = %.1f hPA", value);
        break;
    case 'h':
        snprintf(temp, sizeof(temp), "Umidità = %.1f %%", value);
        break;
    case 'w':
        snprintf(temp, sizeof(temp), "Vento: %.1f KM/H", value);
        break;
    }
    return temp;
}

int main(int argc, char *argv[])
{
=======
}
=======
}

char *risposta_meteo(char *citta, char tipo, float value)
{
switch (tipo) {
        case 't':
            printf("%s: Temperatura = %.1f°C\n", citta, valore);
            break;
        case 'h':
            printf("%s: Umidità = %.1f%%\n", citta, valore);
            break;
        case 'w':
            printf("%s: Vento = %.1f km/h\n", citta, valore);
            break;
        case 'p':
            printf("%s: Pressione = %.1f hPa\n", citta, valore);
            break;
    }
}

int main(int argc, char *argv[])
{

    char *IP_SV[64] = DEFAULT_IP_SV;
    int port = SERVER_PORT;
    weather_request_t wrichiesta;

    // PER CONTROLLARE CHE I PARAMETRI SIANO ESATTAMENTE 3, ALTRIMENTI, ERRORE //
    if (argc < 3)
    {
        fprintf(stderr, "Il formato per l'utilizzo è: %s [-s server] [-p port] -r \"tipo città\"\n", argv[0]);
        return -1;
    }

    int i = 1;
    int r_trovato = 0;

    // CONTROLLO SU OGNI POSSIBILE PARAMETRO MANCANTE//

    while (i < argc)
    {
        if (strcmp(argv[i], "-s") == 0)
        {
            if (i + 1 >= argc)
            {
                fprintf(stderr, "ERRORE: NON hai inserito il valore dopo -s\n");
                return -1;
            }
            snprintf(IP_SV, sizeof(IP_SV), "%s", argv[i + 1]);
            i += 2;
            continue;
        }

        if (strcmp(argv[i], "-p") == 0)
        {
            if (i + 1 >= argc)
            {
                fprintf(stderr, "ERRORE: NON hai inserito la porta dopo -p\n");
                return -1;
            }
            port = atoi(argv[i + 1]);
            i += 2;
            continue;
        }

        if (strcmp(argv[i], "-r") == 0)
        {
            if (i + 1 >= argc)
            {
                fprintf(stderr, "ERRORE: NON hai inserito il parametro dopo -r \n");
                return -1;
            }
            if (sscanf(argv[i + 1], "%c %39[^\n]", &wrichiesta.type, wrichiesta.city) != 2)
            {
                fprintf(stderr, "ERRORE: Il formato è sbagliato, ricorda che il formato è: \"type\"\n");
                return -1;
            }
            r_trovato = 1;
            i += 2;
            continue;
        }
        fprintf(stderr, "Il parametro che hai inserito è sconosciuto: %s\n", argv[i]);
        return -1;
    }
    if (!r_trovato)
    {
        fprintf(stderr, "ERRORE: Il parametro -r è OBBLIGATORIO!\n");
        return -1;
    }
>>>>>>> Stashed changes

char *risposta_meteo(char tipo, float value)
{
    static char temp[40];
    switch (tipo)
    {
    case 't':
        snprintf(temp, sizeof(temp), "Temperatura = %.1f \u00B0C", value);
        break;
    case 'p':
        snprintf(temp, sizeof(temp), "Pressione = %.1f hPA", value);
        break;
    case 'h':
        snprintf(temp, sizeof(temp), "Umidità = %.1f %%", value);
        break;
    case 'w':
        snprintf(temp, sizeof(temp), "Vento: %.1f KM/H", value);
        break;
    }
    return temp;
}

int main(int argc, char *argv[])
{

    char IP_SV[64] = DEFAULT_IP_SV;
    int port = SERVER_PORT;
    weather_request_t wrichiesta;

    // PER CONTROLLARE CHE I PARAMETRI SIANO ESATTAMENTE 3, ALTRIMENTI, ERRORE //
    if (argc < 3)
    {
        fprintf(stderr, "Il formato per l'utilizzo è: %s [-s server] [-p port] -r \"tipo città\"\n", argv[0]);
        return -1;
    }

    int i = 1;
    int r_trovato = 0;

    // CONTROLLO SU OGNI POSSIBILE PARAMETRO MANCANTE//

    while (i < argc)
    {
        if (strcmp(argv[i], "-s") == 0)
        {
            if (i + 1 >= argc)
            {
                fprintf(stderr, "ERRORE: NON hai inserito il valore dopo -s\n");
                return -1;
            }
            snprintf(IP_SV, sizeof(IP_SV), "%s", argv[i + 1]);
            i += 2;
            continue;
        }

        if (strcmp(argv[i], "-p") == 0)
        {
            if (i + 1 >= argc)
            {
                fprintf(stderr, "ERRORE: NON hai inserito la porta dopo -p\n");
                return -1;
            }
            port = atoi(argv[i + 1]);
            i += 2;
            continue;
        }

        if (strcmp(argv[i], "-r") == 0)
        {
            if (i + 1 >= argc)
            {
                fprintf(stderr, "ERRORE: NON hai inserito il parametro dopo -r \n");
                return -1;
            }
            if (sscanf(argv[i + 1], "%c %39[^\n]", &wrichiesta.type, wrichiesta.city) != 2)
            {
                fprintf(stderr, "ERRORE: Il formato è sbagliato, ricorda che il formato è: \"type\"\n");
                return -1;
            }
            r_trovato = 1;
            i += 2;
            continue;
        }
        fprintf(stderr, "Il parametro che hai inserito è sconosciuto: %s\n", argv[i]);
        return -1;
    }
    if (!r_trovato)
    {
        fprintf(stderr, "ERRORE: Il parametro -r è OBBLIGATORIO!\n");
        return -1;
    }
>>>>>>> Stashed changes

    char IP_SV[64] = DEFAULT_IP_SV;
    int port = SERVER_PORT;
    weather_request_t wrichiesta;

    // PER CONTROLLARE CHE I PARAMETRI SIANO ESATTAMENTE 3, ALTRIMENTI, ERRORE //
    if (argc < 3)
    {
        fprintf(stderr, "Il formato per l'utilizzo è: %s [-s server] [-p port] -r \"tipo città\"\n", argv[0]);
        return -1;
    }

    int i = 1;
    int r_trovato = 0;

    // CONTROLLO SU OGNI POSSIBILE PARAMETRO MANCANTE//

    while (i < argc)
    {
        if (strcmp(argv[i], "-s") == 0)
        {
            if (i + 1 >= argc)
            {
                fprintf(stderr, "ERRORE: NON hai inserito il valore dopo -s\n");
                return -1;
            }
            snprintf(IP_SV, sizeof(IP_SV), "%s", argv[i + 1]);
            i += 2;
            continue;
        }

        if (strcmp(argv[i], "-p") == 0)
        {
            if (i + 1 >= argc)
            {
                fprintf(stderr, "ERRORE: NON hai inserito la porta dopo -p\n");
                return -1;
            }
            port = atoi(argv[i + 1]);
            i += 2;
            continue;
        }

        if (strcmp(argv[i], "-r") == 0)
        {
            if (i + 1 >= argc)
            {
                fprintf(stderr, "ERRORE: NON hai inserito il parametro dopo -r \n");
                return -1;
            }
            if (sscanf(argv[i + 1], "%c %39[^\n]", &wrichiesta.type, wrichiesta.city) != 2)
            {
                fprintf(stderr, "ERRORE: Il formato è sbagliato, ricorda che il formato è: \"type\"\n");
                return -1;
            }
            r_trovato = 1;
            i += 2;
            continue;
        }
        fprintf(stderr, "Il parametro che hai inserito è sconosciuto: %s\n", argv[i]);
        return -1;
    }
    if (!r_trovato)
    {
        fprintf(stderr, "ERRORE: Il parametro -r è OBBLIGATORIO!\n");
        return -1;
    }

<<<<<<< Updated upstream
=======
#if defined WIN32
    SetConsoleOutputCP(CP_UTF8); // PER GRADI IN TEMPERATURA //
    WSADATA wsa_data;
    int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (result != NO_ERROR)
    {
        printf("Error at WSAStartup()\n");
        return -1;
    }
#endif
<<<<<<< Updated upstream
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes

    // Creazione socket
    int my_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (my_socket < 0)
    {
        errorhandler("Creazione socket fallita\n");
        return -1;
    }

    // Dico l'indirizzo a cui connettersi
    struct sockaddr_in sad;
    memset(&sad, 0, sizeof(sad));

    sad.sin_family = AF_INET;
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    sad.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP del server (localhost)
    sad.sin_port = htons(SERVER_PORT);            // Porta del server (27015)
=======
    sad.sin_addr.s_addr = inet_addr(IP_SV); // IP del server (localhost)
    sad.sin_port = htons(port);             // Porta del server (27015)
>>>>>>> Stashed changes
=======
    sad.sin_addr.s_addr = inet_addr(IP_SV); // IP del server (localhost)
    sad.sin_port = htons(port);             // Porta del server (27015)
>>>>>>> Stashed changes
=======
    sad.sin_addr.s_addr = inet_addr(IP_SV); // IP del server (localhost)
    sad.sin_port = htons(port);             // Porta del server (27015)
>>>>>>> Stashed changes

    // Connessione al server
    if (connect(my_socket, (struct sockaddr *)&sad, sizeof(sad)) < 0)
    {
        errorhandler("Errore durante la connessione al server.\n");
        closesocket(my_socket);
        clearwinsock();
        return -1;
    }

    // INVIO PARAMETRI AL SV//
    if (send(my_socket, (char *)&wrichiesta, sizeof(wrichiesta), 0) != sizeof(wrichiesta))
    {
        errorhandler("Send ha inviato un numero differente di bytes di quelli attesi");
        closesocket(my_socket);
        clearwinsock();
        return -1;
    }

    // PER RICEVERE I BYTES E VERIFICHE NEL RICEVERE //

    int bytes_ricevuti;
    unsigned long int tot_bytes_ricevuti = 0;
    char buffer[BUFFER_SIZE];
    weather_response_t risposta;

    while (tot_bytes_ricevuti < sizeof(risposta))
    {
        bytes_ricevuti = recv(
            my_socket, ((char *)&risposta) + tot_bytes_ricevuti, sizeof(risposta) - tot_bytes_ricevuti, 0);

        if (bytes_ricevuti <= 0)
        {
            errorhandler("ERRORE: recv è fallita o la conessione si è persa");
            closesocket(my_socket);
            clearwinsock();
            return -1;
        }
        tot_bytes_ricevuti += bytes_ricevuti;
    }

    // SWITCH PER DARE I RISULTATI IN OUTPUT //
    switch (risposta.status)
    {
    case 1:
        printf("Ricevuto risulatato dal server con IP %s Città NON DISPONIBILE", IP_SV);
        break;
    case 2:
        printf("Ricevuto risultato dal server con IP %s la richiesta NON è VALIDA", IP_SV);
        break;
    case 3:
<<<<<<< Updated upstream
        printf("Ricevuto risultato dal server con IP %s per %s: %s \n", IP_SV, wrichiesta.city, risposta_meteo(risposta.type, risposta.value));
=======
        printf("Ricevuto risultato dal server con IP %s per %s: %s", IP_SV, wrichiesta.city, risposta_meteo(risposta.type, risposta.value));
>>>>>>> Stashed changes
        break;
    defalut:
        printf("Risposta del server non comprensibile (STATUS: %d)\n", risposta.status);
    }

    closesocket(my_socket);
    clearwinsock();
    printf("Client terminato");

    return 0;
} // finisce main