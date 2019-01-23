#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <math.h>
#include "rendern.h"
#include "connection.h"
#include "main.h"
#include "menu.h"

void menu_draw() {
  // start knopf
  rgb(127, 230, 73);
  rect(800, 500, 300, 150);
  text("Host\0", 920, 550, 0.5, 0);
  rgb(207, 191, 84);
  rect(1000, 300, 170, 60);
  text("Client\0", 1010, 310, 0.5, 0);
  rgb(175, 64, 27);
  rect(600, 200, 100, 60);
  text("neu\0", 610, 210, 0.5, 0);
  rgb(27, 99, 175);
  rect(750, 200, 190, 60);
  text("local\0", 760, 210, 0.5, 0);

  text("IP-Eingeben\0", 200, 300, 0.5, 0);//Fenster zum eingeben erstellen 
  animation(&load, 825, 525, 100, 100);
  text("Schiffeversenken\0", 30, 30, 1,0);//Schriftzu erstelen

  char ipAdressen[100];//Ip adresse abfrage
  strcpy(ipAdressen, aktuellerStatus.connectTO);
  text(ipAdressen, 600, 300, 0.5, 0);
  strcpy(ipAdressen, aktuellerStatus.ip);
  text(ipAdressen, 30, 600, 0.5, 0);
  menu_event();
}

void menu_event(){ //Abfagen für Events
  if(MausSpieler.gedrueckt == 1) {
    if(MausSpieler.x > 800 && MausSpieler.y > 500 &&
       MausSpieler.x < 1100 && MausSpieler.y < 650) {
      host();
      load.Animationsdetail = 2;
      aktuellerStatus.menu = 1;
      aktuelleSpielphase.phase = 1;
      aktuelleSpielphase.gewonnen = 0;
      aktuelleSpielphase.schiffsetzen = 0;
    }
    if(MausSpieler.x > 600 && MausSpieler.y > 200 &&
       MausSpieler.x < 700 && MausSpieler.y < 260) {
      strcpy(aktuellerStatus.connectTO, "");
    }
    if(MausSpieler.x > 750 && MausSpieler.y > 200 &&
       MausSpieler.x < 930 && MausSpieler.y < 260) {
      strcpy(aktuellerStatus.connectTO, "127.0.0.1");
      client();
      load.Animationsdetail = 2;
      aktuellerStatus.menu = 1;
      aktuelleSpielphase.phase = 1;
      aktuelleSpielphase.gewonnen = 0;
      aktuelleSpielphase.schiffsetzen = 0;
    }
    if(MausSpieler.x > 1000 && MausSpieler.y > 300 &&
       MausSpieler.x < 1170 && MausSpieler.y < 360) {
      client();
      load.Animationsdetail = 2;
      aktuellerStatus.menu = 1;
      aktuelleSpielphase.phase = 1;
      aktuelleSpielphase.gewonnen = 0;
      aktuelleSpielphase.schiffsetzen = 0;
    }
    MausSpieler.gedrueckt = 0;
  }
}
