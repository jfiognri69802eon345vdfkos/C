#ifndef SPIEL_H
#define SPIEL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <math.h>
#include "rendern.h"
#include "connection.h"



void spiel_draw();
void spiel_event();
void gewonnene();
void clearSets();
void fertigSchiffeGesetzt();
void setGegnerSchiffe();
void Schuss(int, int);
void pruefenVersenkt();
void Schuss_gegner(int, int);
void pruefenVersenkt_gegner();
void spielfeldKoordinaten();
void Schiffeinzeichnen();
void SchiffSetzen(int, int);
bool istLeer(int, int);
bool SchiffSetzenVonBis(int, int, int, int);
void umrechnen(int, int, int, int *, int *);

#endif
