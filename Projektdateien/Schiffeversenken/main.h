#ifndef MAIN_H
#define MAIN_H

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
#include "spiel.h"
#include "menu.h"
// #include "main.h"

struct mouseSpieler {
  int x;
  int y;
  int feld;
  int feldx;
  int feldy;
  int gedrueckt;
  int scroll;
};

struct statusInfo {
  bool is_running;
  int menu;
  int wechsel;
  int verbunden;
  int frame;
  char connectTO[20];
  char ip[100];
  struct schusse *start;
};

struct spielphasen{
  int phase; // 1 schiffe setzen 2 versenken
  int punkte;
  int gewonnen; // 0 noch nicht entschieden oder verloren 1 gewonnen
  int schiffsetzen; // 0 kein schiff 1 anfangspunk gesetzt
  int schiffsetzen_x;// position des schiff beginns
  int schiffsetzen_y;
};

struct schusse {
  int feldx;
  int feldy;
  struct schusse *next;
};
// struct mouseSpieler MausSpieler;
SDL_Renderer *renderer;
bool is_Running;


struct mouseSpieler MausSpieler;
struct statusInfo aktuellerStatus;
struct spielphasen aktuelleSpielphase;

struct AnimationSprite load;

struct AnimationSprite water;
struct AnimationSprite fire;

struct AnimationSprite Schiff2erHor;
struct AnimationSprite Schiff2er;
struct AnimationSprite Schiff3erHor;
struct AnimationSprite Schiff3er;
struct AnimationSprite Schiff4erHor;
struct AnimationSprite Schiff4er;
struct AnimationSprite Schiff5erHor;
struct AnimationSprite Schiff5er;

#endif
