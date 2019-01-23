#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>
#include "main.h"

char server_message[256] = "Schiffeversenken";
pthread_t connection;
bool is_client;
int server_socket;
int client_socket;
void*verbindungAufbauen(void*);
void senden(const char *);
void findConnection() {
  strcpy(zuSenden, "Hallo\0");
  char ipAddressenTest[100];
  getIP(ipAddressenTest);
  strcpy(aktuellerStatus.ip, ipAddressenTest);

  printf("thread gestartet\n");
}


void delay(unsigned int mseconds)
{
  clock_t goal = mseconds + clock();
  while (goal > clock());
}

static void *connected(void *val){//Abfagen für Spilactionen
  while(is_Running && aktuellerStatus.verbunden) {

    if(is_Running && aktuellerStatus.verbunden) {
      recv(client_socket, &server_response, 200, 0);

      switch (server_response[0]) {
      case 's':   //shoot

        Schuss_gegner(server_response[1] - 2, server_response[2] - 2);
        break;
      case 'r':   //ready
        //get the array of opponent
        setGegnerSchiffe();
        break;
      case 'w':
        if(server_response[1] == 'w' && server_response[2] == 'w') {
          aktuelleSpielphase.phase = 3;
        }
        break;
      case 'l':
        if(server_response[1] == 'l' && server_response[2] == 'l') {
          aktuelleSpielphase.gewonnen = 1;
          aktuelleSpielphase.phase = 3;
        }
        break;
      case 'e':   //end flag
        aktuellerStatus.verbunden = false;
        break;
      }

      send(client_socket, &zuSenden, 200, 0);   //zuSenden, sizeof(zuSenden), 0);
      ist_gesendet = 0;


    }
  }
}

void host(){
  if (serving_host == false && aktuellerStatus.frame > 0) {//Serverhost
    is_client = false;
    // serversocket
    rgba(76, 150, 181, 95);
    rect(0,0,1200,700);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // serveraddress
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(6789);
    server_address.sin_addr.s_addr = INADDR_ANY;

    printf("warten auf connection\n");
    // bind
    bind(server_socket, (struct sockaddr * ) &server_address, sizeof(server_address));

    listen(server_socket, 1);
    client_socket = accept(server_socket, NULL, NULL);

    // Send welcome Message
    send(client_socket, &zuSenden, sizeof(zuSenden), 0);
    bool connection_established = true;
    aktuellerStatus.verbunden = true;
    pthread_create(&connection, NULL, &connected, NULL);
  }
}

void client() {
  // new Socket
  is_client = true;
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  //specify the adresse
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(6789);
  server_address.sin_addr.s_addr = inet_addr(aktuellerStatus.connectTO);

  int status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  if(status == -1) {
    printf("Fehler mit der Verbindung\n");
  }
  aktuellerStatus.verbunden = true;
  server_socket = client_socket;
  pthread_create(&connection, NULL, &connected, NULL);
}

void beenden(){
  // geschlossen
  aktuellerStatus.verbunden = false;
  close(server_socket);
}

int ping() {
  return 0;
}

void getIP(char *ptr) {//Ip um zu spieler zu verbinden
  const char* google_dns_server = "8.8.8.8";
  int dns_port = 53;

  struct sockaddr_in serv;

  int sock = socket ( AF_INET, SOCK_DGRAM, 0);

  //Socket could not be created
  if(sock < 0)
  {
    perror("Socket error");
  }

  memset( &serv, 0, sizeof(serv) );
  serv.sin_family = AF_INET;
  serv.sin_addr.s_addr = inet_addr( google_dns_server );
  serv.sin_port = htons( dns_port );

  int err = connect( sock, (const struct sockaddr*) &serv, sizeof(serv) );

  struct sockaddr_in name;
  socklen_t namelen = sizeof(name);
  err = getsockname(sock, (struct sockaddr*) &name, &namelen);

  char buffer[100];
  const char* p = inet_ntop(AF_INET, &name.sin_addr, buffer, 100);

  if(p != NULL)
  {
    printf("Local ip is : %s \n", buffer);
  }
  else
  {
    //Some error
    printf ("Error number : %d . Error message : %s \n", errno, strerror(errno));
  }

  close(sock);
  // return buffer;
  strcpy(ptr, buffer);
}
