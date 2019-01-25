#ifndef CONNECTION_H
#define CONNECTION_H

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

int ist_gesendet;
bool serving_host;
char zuSenden[501];
char server_response[501];
int client_socket;
int server_socket;

void host();
void client();
void findConnection();
void delay(unsigned int);
static void *connected(void *);
void beenden();
void getIP(char *);

#endif
