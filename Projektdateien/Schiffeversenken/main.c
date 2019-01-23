#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <math.h>
#include "rendern.h"
#include "connection.h"
#include "menu.h"
#include "spiel.h"
#include "main.h"

SDL_Texture *bild_abc;

int events() {
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT) {//Abfrage ob Event stattfindet
      is_Running = false;//falls nicht runnign zu false
    }else{
      if(event.type == SDL_KEYUP) {//wenn ja

        switch (event.key.keysym.sym)//Events
        {
        case (SDLK_UP)://Alle Cases
          printf("up\n");
        case (SDLK_DOWN):
          printf("down\n");
        case (SDLK_LEFT):
          printf("left\n");
        case (SDLK_RIGHT):
          printf("right\n");
          break;
        case (SDLK_1):
          printf("1\n");
          strcat(aktuellerStatus.connectTO, "1");
          break;
        case (SDLK_2):
          printf("2\n");
          strcat(aktuellerStatus.connectTO, "2");
          break;
        case (SDLK_3):
          printf("3\n");
          strcat(aktuellerStatus.connectTO, "3");
          break;
        case (SDLK_4):
          printf("4\n");
          strcat(aktuellerStatus.connectTO, "4");
          break;
        case (SDLK_5):
          printf("5\n");
          strcat(aktuellerStatus.connectTO, "5");
          break;
        case (SDLK_6):
          printf("6\n");
          strcat(aktuellerStatus.connectTO, "6");
          break;
        case (SDLK_7):
          printf("7\n");
          strcat(aktuellerStatus.connectTO, "7");
          break;
        case (SDLK_8):
          printf("8\n");
          strcat(aktuellerStatus.connectTO, "8");
          break;
        case (SDLK_9):
          printf("9\n");
          strcat(aktuellerStatus.connectTO, "9");
          break;
        case (SDLK_0):
          printf("0\n");
          strcat(aktuellerStatus.connectTO, "0");
          break;
        case (SDLK_PERIOD):
          printf(".\n");
          strcat(aktuellerStatus.connectTO, ".");
          break;
        }
      }else{
        if(event.type == SDL_MOUSEBUTTONUP) { //Abfragen für Mauseingaben und Bewegung

          switch(event.button.button) {
          case SDL_BUTTON_LEFT:
            MausSpieler.gedrueckt = 1;
            MausSpieler.x = event.button.x;
            MausSpieler.y = event.button.y;
            printf("Klick at %4d:%d\n", event.button.x,event.button.y);
            break;
          case SDL_BUTTON_RIGHT:
            MausSpieler.gedrueckt = 2;
            MausSpieler.x = event.button.x;
            MausSpieler.y = event.button.y;
            printf("Klick_rechts at %4d:%d\n", event.button.x,event.button.y);
            break;
          }
        }else{
          if(event.type == SDL_MOUSEMOTION) {
            MausSpieler.x = event.button.x;
            MausSpieler.y = event.button.y;
          }
        }
      }
    }
  }
  return 0;
}


SDL_Rect r;




void start() {
  findConnection();

  // start variabel setzen
  aktuellerStatus.menu = 0;
  aktuellerStatus.is_running = true;
  aktuellerStatus.wechsel = 0;
  aktuellerStatus.frame = 0;
  strcpy(aktuellerStatus.connectTO, "");

  // Spielvar
  // aktuelleSpielphase.phase = 2;
  aktuelleSpielphase.punkte = 0;
  ist_gesendet = 0;
  serving_host = false;

  //Bilder laden

  bild_abc = loadpic("bilder/bild.png");


  load.textur = loadpic("bilder/load.png");
  load.frame = 0;
  load.animationsTeile = 34;
  load.Animationsdetail = 1;

  int arr4[] = {0,0,0,0,1,0,1,0,2,0,2,0,3,0,
                3,0,4,0,4,0,5,0,5,0,6,0,6,0,7,0,7,0,
                8,0,8,0,9,0,9,0,10,0,10,0,
                11,0,11,0,12,0,12,0,13,0,13,0,
                14,0,14,0,15,0,15,0,16,0,16,0};

  for (int i = 0; i < 68; i++) {
    load.reihnfolge[i] = arr4[i];
  }

  load.sizex = 200;
  load.sizey = 200;


  water.textur = loadpic("bilder/wasser.png");//Hintergrund Laden
  water.frame = 0;
  water.animationsTeile = 20;
  water.Animationsdetail = 1;

  int arr2[] = {0,0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,
                8,0,9,0,10,0,11,0,12,0,13,0,14,0,
                15,0,16,0,17,0,18,19,0};

  for (int i = 0; i < 40; i++) {
    water.reihnfolge[i] = arr2[i];
  }

  water.sizex = 50;
  water.sizey = 50;

  //feuer
  fire.textur = loadpic("bilder/Explo.png");//Feuer für zerstötzte Schiffe
  fire.frame = 0;
  fire.animationsTeile = 20;
  fire.Animationsdetail = 1;
  int arr3[] = {0,0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,
                8,0,9,0,10,0,11,0,12,0,13,0,14,0,
                15,0,16,0,17,0,18,19,0};

  for (int i = 0; i < 40; i++) {
    fire.reihnfolge[i] = arr3[i];
  }
  fire.sizex = 50;
  fire.sizey = 50;

  //Laden der Schiffsbilder
  Schiff2er.textur = loadpic("bilder/2erSchiff.png");
  Schiff2er.frame = 0;
  Schiff2er.animationsTeile = 5;
  Schiff2er.Animationsdetail = 2;

  int arr5[] = {0,0,1,0,2,0,3,0,4,0};

  for (int i = 0; i < 10; i++) {
    Schiff2er.reihnfolge[i] = arr5[i];
  }
  Schiff2er.sizex = 50;
  Schiff2er.sizey = 100;
  /*
  * 2er Schiff Horizontal
  */
  Schiff2erHor.textur = loadpic("bilder/2erHorSchiff.png");//Die verschiedenen Schiffe, Größe und Texturen Laden
  Schiff2erHor.frame = 0;
  Schiff2erHor.animationsTeile = 5;
  Schiff2erHor.Animationsdetail = 0;
  for (int i = 0; i < 10; i++) {
    Schiff2erHor.reihnfolge[i] = arr5[i];
  }
  Schiff2erHor.sizex = 150;
  Schiff2erHor.sizey = 100;
  /*
  * 3er Schiff
  */
  Schiff3er.textur = loadpic("bilder/3erSchiff.png");
  Schiff3er.frame = 0;
  Schiff3er.animationsTeile = 5;
  Schiff3er.Animationsdetail = 0;
  for (int i = 0; i < 10; i++) {
    Schiff3er.reihnfolge[i] = arr5[i];
  }
  Schiff3er.sizex = 100;
  Schiff3er.sizey = 150;
  /*
  * 3er Schiff Horizontal
  */
  Schiff3erHor.textur = loadpic("bilder/3erHorSchiff.png");
  Schiff3erHor.frame = 0;
  Schiff3erHor.animationsTeile = 5;
  Schiff3erHor.Animationsdetail = 0;
  for (int i = 0; i < 10; i++) {
    Schiff3erHor.reihnfolge[i] = arr5[i];
  }
  Schiff3erHor.sizex = 150;
  Schiff3erHor.sizey = 100;
  /*
  * 4er Schiff
  */
  Schiff4er.textur = loadpic("bilder/4erSchiff.png");
  Schiff4er.frame = 0;
  Schiff4er.animationsTeile = 5;
  Schiff4er.Animationsdetail = 0;
  for (int i = 0; i < 10; i++) {
    Schiff4er.reihnfolge[i] = arr5[i];
  }
  Schiff4er.sizex = 100;
  Schiff4er.sizey = 200;
  /*
  * 4er Schiff Horizontal
  */
  Schiff4erHor.textur = loadpic("bilder/4erHorSchiff.png");
  Schiff4erHor.frame = 0;
  Schiff4erHor.animationsTeile = 5;
  Schiff4erHor.Animationsdetail = 0;
  for (int i = 0; i < 10; i++) {
    Schiff4erHor.reihnfolge[i] = arr5[i];
  }
  Schiff4erHor.sizex = 100;
  Schiff4erHor.sizey = 200;
  /*
  * 5er Schiff
  */
  Schiff5er.textur = loadpic("bilder/5erSchiff.png");
  Schiff5er.frame = 0;
  Schiff5er.animationsTeile = 5;
  Schiff5er.Animationsdetail = 0;
  for (int i = 0; i < 10; i++) {
    Schiff5er.reihnfolge[i] = arr5[i];
  }
  Schiff5er.sizex = 100;
  Schiff5er.sizey = 250;
  /*
  * 5er Schiff Horizontal
  */
  Schiff5erHor.textur = loadpic("bilder/5erHorSchiff.png");
  Schiff5erHor.frame = 0;
  Schiff5erHor.animationsTeile = 5;
  Schiff5erHor.Animationsdetail = 0;
  for (int i = 0; i < 10; i++) {
    Schiff5erHor.reihnfolge[i] = arr5[i];
  }
  Schiff5erHor.sizex = 250;
  Schiff5erHor.sizey = 100;
  printf("problem bild\n");

  // Laden der schrift
  buchstaben_weiss = loadpic("bilder/Sprite_Buchstaben_Zahlen2.png");//Zugriff auf Sprite
  printf("geht ende des aufrufen\n");
}

void loop() {//Loop zum Frame weiter schalten und Backround seten
  background_clear();
  aktuellerStatus.frame++;
  switch (aktuellerStatus.menu) {
  case 0:
    menu_draw();
    break;
  case 1:
    spiel_draw();
    break;
  }


  rgba(99, 154, 222, 164);
  rect(MausSpieler.x - 25, MausSpieler.y - 25, 50, 50);//Button

}

//Main

int main(int argc, char const *argv[]) {
  is_Running = true;
  SDL_Init(SDL_INIT_VIDEO);

  TTF_Init();
  IMG_Init(IMG_INIT_PNG);
  SDL_Window *window = SDL_CreateWindow("Schiffeversenken", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,//Fenster wird erstellt
                                        1200, 700, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);//Render erstellt
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

  unsigned long lastTime = 0, currentTime;// Time
  int timer = 0;
  start();
  while (is_Running) {
    events();
    currentTime = SDL_GetTicks();
    if(currentTime > lastTime + 25) {//Timer abffrage
      timer++;
      lastTime = currentTime;
      loop();//SChleife
      SDL_RenderPresent(renderer);
      printf("loop: %d - %lu\n", timer, currentTime);
    }
  }
  TTF_Quit();
  IMG_Quit();
  SDL_DestroyWindow(window);//Fenstr wird wieder geschlossen
  SDL_DestroyRenderer(renderer);//Render werden wieder gefreed
  SDL_Quit();//Schließen vom Fenster/Spiel
  return 0;
}
