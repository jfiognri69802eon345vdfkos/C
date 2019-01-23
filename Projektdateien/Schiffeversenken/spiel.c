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
#include "spiel.h"


bool setztenMoeglich[18] = {false,false,false,false,false,false,false,false,false,
                            false,false,false,false,false,false,false,false,false};

int schiffe[10][3] = {//Die versichdenen Schiffe
  {224, 49, 230},
  {11, 224, 102},
  {242, 232, 99},
  {213, 4, 164},
  {241, 170, 95},
  {120, 38, 212},
  {62, 163, 48},
  {131, 203, 245},
  {161, 125, 41},
  {187, 235, 194}
};

int letzterspielzug_x = 0;
int letzterspielzug_y = 0;
int letzterspielzug_feld = 0;
int letzterspielzug_was = 0; // 1 explo 2 wasser

int schiffe_noch_nicht_gesetzt[4] = {4,3,2,1};
int schiffe_noch_ueber[4] = {4,3,2,1};
int schiffe_noch_ueber_gegner[4] = {4,3,2,1};
bool ist_dran = true;
bool SchiffegegnerNochNichtGesetzt = true;//Abr´frage obnoch Schiffe gesetzt werden können

int spielfeld[10][10] = {{0,0,0,0,0,0,0,0,0,0}, //SpielfeldArrays 0 = frei
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0}};

int spielfeld_gegner[10][10] = {{1,0,0,0,0,3,0,4,0,5}, // gleiche werte für die Schiffe
                                {1,0,2,2,0,3,0,4,0,5},
                                {0,0,0,0,0,0,8,0,0,5},
                                {6,6,6,0,0,0,8,0,0,0},
                                {0,0,0,0,0,0,8,0,0,0},
                                {7,7,7,0,0,0,8,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {0,0,10,10,10,10,10,0,0,0},
                                {0,0,0,0,0,0,0,0,0,0},
                                {9,9,9,9,0,0,0,0,0,0}};

void spiel_draw() {//Spelfeld annimieren
  spielfeldKoordinaten();
  display();
  int feld_x = 0;
  int feld_y = 0;

  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      if(spielfeld[x][y] > 0) {
        umrechnen(2, x, y, &feld_x, &feld_y);
        rgb(schiffe[spielfeld[x][y]-1][0],schiffe[spielfeld[x][y]-1][1],schiffe[spielfeld[x][y]-1][2]);
        rect(feld_x, feld_y, 50,50);
      }
    }
  }
  Schiffeinzeichnen();//Schiffe erstellenn
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      if(spielfeld_gegner[x][y] > 0) {
        umrechnen(1, x, y, &feld_x, &feld_y);
        if(spielfeld_gegner[x][y] < 111 && spielfeld_gegner[x][y] > 99) {

          if(spielfeld_gegner[x][y] == 100) {
            rgb(37, 194, 169);
            rect(feld_x + 8, feld_y + 8, 34, 34);
            if(letzterspielzug_x == x && letzterspielzug_y == y && letzterspielzug_feld == 1){
              animation(&water, feld_x, feld_y, 50, 50);//Falls Wasser getroffen
            }
          }else{
            rgb(209, 183, 6);
            rect(feld_x + 8, feld_y + 8, 34, 34);
            if(letzterspielzug_x == x && letzterspielzug_y == y && letzterspielzug_feld == 1){
              animation(&fire, feld_x, feld_y, 50, 50);//Falls Schiff getroffen
            }
          }
        }else{
          if(spielfeld_gegner[x][y] > 199) {

            rgb(209, 19, 19);
            rect(feld_x + 8, feld_y + 8, 34, 34);
          }
        }
      }
      if(spielfeld[x][y] > 0) {
        umrechnen(2, x, y, &feld_x, &feld_y);
        if(spielfeld[x][y] < 11) {
          rgb(schiffe[spielfeld[x][y]-1][0],schiffe[spielfeld[x][y]-1][1],schiffe[spielfeld[x][y]-1][2]);
          rect(feld_x, feld_y, 50,50);
        }else{
          if(spielfeld[x][y] < 111) {
            rgb(schiffe[spielfeld[x][y]-101][0],schiffe[spielfeld[x][y]-101][1],schiffe[spielfeld[x][y]-101][2]);
            rect(feld_x + 1, feld_y + 1, 49,49);
            rgb(209, 183, 6);
            rect(feld_x + 8, feld_y + 8, 34, 34);
            if(spielfeld[x][y] == 100){
              if(letzterspielzug_x == x && letzterspielzug_y == y && letzterspielzug_feld == 2){
                animation(&water, feld_x, feld_y, 50, 50);
              }
            }else{
              if(letzterspielzug_x == x && letzterspielzug_y == y && letzterspielzug_feld == 2){
                animation(&fire, feld_x, feld_y, 50, 50);
              }
            }
          }else{
            rgb(schiffe[spielfeld[x][y]-201][0],schiffe[spielfeld[x][y]-201][1],schiffe[spielfeld[x][y]-201][2]);
            rect(feld_x + 1, feld_y + 1, 49,49);
            rgb(209, 19, 19);
            rect(feld_x + 8, feld_y + 8, 34, 34);
          }
        }
      }
    }
  }
  if(aktuelleSpielphase.phase == 1) {//Speilphase 1 Schiffe setzen
    //Clear button
    rgb(63, 171, 158);
    rect(1000,600,150,50);
    text("neu", 1010, 605, 0.5, 0);
    if(aktuelleSpielphase.schiffsetzen == 1) {
      umrechnen(2, aktuelleSpielphase.schiffsetzen_x, aktuelleSpielphase.schiffsetzen_y, &feld_x, &feld_y);
      rgb(255, 255, 255);
      rect(feld_x, feld_y, 50,50);
      for (int x = 0; x < 9; x++) {
        if(setztenMoeglich[x]) {
          umrechnen(2, aktuelleSpielphase.schiffsetzen_x - 4 + x, aktuelleSpielphase.schiffsetzen_y, &feld_x, &feld_y);
          rgba(95, 230, 40, 150);
          rect(feld_x, feld_y, 50,50);
        }
      }
      for(int y = 0; y < 9; y++) {
        if(setztenMoeglich[9+y]) {
          umrechnen(2, aktuelleSpielphase.schiffsetzen_x, aktuelleSpielphase.schiffsetzen_y - 4 + y, &feld_x, &feld_y);
          rgba(95, 230, 40, 150);
          rect(feld_x, feld_y, 50,50);
        }
      }
    }
  }
  if(aktuelleSpielphase.phase == 2) {//Speilfase 2 Schießen
    char uebrigeSchiffe[51];
    sprintf(uebrigeSchiffe, "NOCHDA.%d.%d.%d.%d ", schiffe_noch_ueber_gegner[0], schiffe_noch_ueber_gegner[1],
            schiffe_noch_ueber_gegner[2], schiffe_noch_ueber_gegner[3]);
    text(uebrigeSchiffe, 5,2,0.4,0);
  }
  if(aktuelleSpielphase.phase == 3) {//Spielfase 3 Gewonnwn/Verloren
    rgba(121, 121, 121, 200);
    rect(0,0,1200,700);
    if(aktuelleSpielphase.gewonnen == 1) {
      text("GEWONNEN\0", 350, 350, 1, 0);
    }else{
      text("VERLOREN\0", 350, 350, 1, 0);
    }
  }
  spiel_event();
}

void spiel_event(){//Schuss handeling (Events)
  if(ist_dran) {
    if(MausSpieler.gedrueckt == 1) {
      if(MausSpieler.feld == 1) {
        printf("geklickt auf feld 1: %3d:%3d\n", MausSpieler.feldx, MausSpieler.feldy);
        if(aktuelleSpielphase.phase == 2) {
          printf("Abschiessen\n");
          Schuss(MausSpieler.feldx, MausSpieler.feldy);
        }
      }
      if(MausSpieler.feld == 2) {
        if(aktuelleSpielphase.phase == 1) {
          SchiffSetzen(MausSpieler.feldx, MausSpieler.feldy);
          if(MausSpieler.x > 1000 && MausSpieler.x < 1150 &&
             MausSpieler.y > 600 && MausSpieler.y < 650) {
            clearSets();
          }
        }
      }
      MausSpieler.feld = 0;
      MausSpieler.gedrueckt = 0;
    }
  }
}

void gewonnene(){//Abfrage ob gewonnen
  if(aktuelleSpielphase.phase == 2) {
    bool spielende = false;
    int schiffeversenkt = 0;
    int schiffegegnerversenkt = 0;
    for (int i = 0; i < 4; i++) {
      if(schiffe_noch_ueber_gegner[i] == 0) {
        schiffeversenkt++;
      }
      if(schiffe_noch_ueber[i] == 0) {
        schiffegegnerversenkt++;
      }
    }
    if(schiffeversenkt == 4) {
      zuSenden[0] = 'w';
      zuSenden[1] = 'w';
      zuSenden[2] = 'w';
      zuSenden[3] = '\0';
      aktuelleSpielphase.gewonnen = 1;
      aktuelleSpielphase.phase = 3;
      aktuelleSpielphase.punkte++;
    }
    if(schiffegegnerversenkt == 4) {
      zuSenden[0] = 'l';
      zuSenden[1] = 'l';
      zuSenden[2] = 'l';
      zuSenden[3] = '\0';
      aktuelleSpielphase.phase = 3;
      aktuelleSpielphase.punkte--;
    }
  }
}

void clearSets(){
  schiffe_noch_nicht_gesetzt[0] = 4;//Schiffe zu setzen
  schiffe_noch_nicht_gesetzt[1] = 3;
  schiffe_noch_nicht_gesetzt[2] = 2;
  schiffe_noch_nicht_gesetzt[3] = 1;
  aktuelleSpielphase.schiffsetzen = 0; //Spilphasen counter
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      spielfeld[x][y] = 0;
      spielfeld_gegner[x][y] = 0;
    }
  }
}

void fertigSchiffeGesetzt(){//Falls alle Schiffe gesetzt
  ist_gesendet = 1;
  zuSenden[0] = 'r';
  for (size_t y = 0; y < 10; y++) {
    for (size_t x = 0; x < 10; x++) {
      zuSenden[y*10 + x + 1] = spielfeld[x][y]+2;
    }
  }
  zuSenden[101] = '\0';
  ist_gesendet = 1;
  if(SchiffegegnerNochNichtGesetzt) {
    ist_dran = true;
  }else{
    ist_dran = false;
  }
}

void setGegnerSchiffe(){//Gegner setzt Schiffe
  if(SchiffegegnerNochNichtGesetzt) {//Abfage
    SchiffegegnerNochNichtGesetzt = false;
    for (int y = 0; y < 10; y++) {
      for (int x = 0; x < 10; x++) {
        spielfeld_gegner[x][y] = server_response[y*10 + x + 1]-2;//ERstellen Spielfeld
      }
    }
  }
}

void Schuss(int x, int y){//SChuss auf Feld x,y
  if(x >= 0 && x < 10 && y >= 0 && y < 10) {
    if(spielfeld_gegner[x][y] < 100) {
      spielfeld_gegner[x][y] += 100;
      zuSenden[0] = 's';
      zuSenden[1] = x + 2;//Verarbeitung Koordinaten
      zuSenden[2] = y + 2;
      zuSenden[3] = '\0';
      ist_gesendet = 0;
      ist_dran = false;
      letzterspielzug_x = x;
      letzterspielzug_y = y;
      letzterspielzug_feld = 1;
      water.frame = 0;
      fire.frame = 0;
      pruefenVersenkt();//Überprüfen ob Schiff versnekt
      gewonnene();//Abfage ob gewonnen
    }
  }
}

void pruefenVersenkt(){//Abfrage ob Schiff versenkt
  int soll[] = {2,2,2,2,3,3,3,4,4,5};
  for (int i = 101; i < 111; i++) {
    int zahler = 0;
    for (int x = 0; x < 10; x++) {
      for (int y = 0; y < 10; y++) {
        if(i == spielfeld_gegner[x][y]) {
          zahler++;
        }
      }
    }
    if(zahler >= soll[i - 101]) {
      schiffe_noch_ueber_gegner[soll[i-101]-2]--;
      for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
          if(i == spielfeld_gegner[x][y]) {
            spielfeld_gegner[x][y] += 100;
          }
        }
      }
    }
  }
}

void Schuss_gegner(int x, int y){//Abfage von Schuss des Gegners
  if(x >= 0 && x < 10 && y >= 0 && y < 10) {
    if(spielfeld[x][y] < 100) {
      spielfeld[x][y] += 100;
      ist_dran = true;
      letzterspielzug_x = x;
      letzterspielzug_y = y;
      letzterspielzug_feld = 2;
      water.frame = 0;
      fire.frame = 0;
      pruefenVersenkt_gegner();
      gewonnene();
    }
  }
}

void pruefenVersenkt_gegner(){//Abfrage ob Schiff von Gegner zerstört wurde
  int soll[] = {2,2,2,2,3,3,3,4,4,5};
  for (int i = 101; i < 111; i++) {
    int zahler = 0;
    for (int x = 0; x < 10; x++) {
      for (int y = 0; y < 10; y++) {
        if(i == spielfeld[x][y]) {
          zahler++;
        }
      }
    }
    if(zahler >= soll[i - 101]) {
      schiffe_noch_ueber[soll[i-101]-2]--;
      for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
          if(i == spielfeld[x][y]) {
            spielfeld[x][y] += 100;
          }
        }
      }
    }
  }
}

void Schiffeinzeichnen(){//Rendern der Schiffe auf Hintergrund
  bool schoneingezeichnet[] = {false, false, false, false, false, false, false, false, false, false};
  int feld_x = 0;
  int feld_y = 0;
  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      if(spielfeld[x][y] > 0 && schoneingezeichnet[spielfeld[x][y] - 1] == false) {
        int richtung = 0;
        bool Ngefunden = true;
        if (x + 1 < 10 && Ngefunden) {
          if (spielfeld[x+1][y] > 0) {
            richtung = 4;
            Ngefunden = false;
            schoneingezeichnet[spielfeld[x][y] - 1] = true;
            switch (spielfeld[x][y]) {
            case 10:
              umrechnen(2, x, y, &feld_x, &feld_y);
              sprite(Schiff5erHor.textur,feld_x,feld_y,250,50,0,0,Schiff5erHor.sizex,Schiff5erHor.sizey);
              break;
            case 9:
            case 8:
              umrechnen(2, x, y, &feld_x, &feld_y);
              sprite(Schiff4erHor.textur,feld_x,feld_y,200,50,0,0,Schiff4erHor.sizex,Schiff4erHor.sizey);
              break;
            case 7:
            case 6:
            case 5:
              umrechnen(2, x, y, &feld_x, &feld_y);
              sprite(Schiff3erHor.textur,feld_x,feld_y,150,50,0,0,Schiff3erHor.sizex,Schiff3erHor.sizey);


              break;
            case 4:
            case 3:
            case 2:
            case 1:
              umrechnen(2, x, y, &feld_x, &feld_y);
              sprite(Schiff2erHor.textur,feld_x,feld_y,100,50,0,0,Schiff2erHor.sizex,Schiff2erHor.sizey);

              break;
            }
          }
        }
        if (y + 1 < 10 && Ngefunden) {

          if (spielfeld[x][y+1] > 0) {
            richtung = 3;
            Ngefunden = false;
            schoneingezeichnet[spielfeld[x][y] - 1] = true;
            switch (spielfeld[x][y]) {
            case 10:
              umrechnen(2, x, y, &feld_x, &feld_y);
              sprite(Schiff5er.textur,feld_x,feld_y,50,250,0,0,Schiff5er.sizex,Schiff5er.sizey);
              break;
            case 9:
            case 8:
              umrechnen(2, x, y, &feld_x, &feld_y);
              sprite(Schiff4er.textur,feld_x,feld_y,50,200,0,0,Schiff4er.sizex,Schiff4er.sizey);
              break;
            case 7:
            case 6:
            case 5:
              umrechnen(2, x, y, &feld_x, &feld_y);
              sprite(Schiff3er.textur,feld_x,feld_y,50,150,0,0,Schiff3er.sizex,Schiff3er.sizey);

              break;
            case 4:
            case 3:
            case 2:
            case 1:
              umrechnen(2, x, y, &feld_x, &feld_y);
              sprite(Schiff2er.textur,feld_x,feld_y,50,100,0,0,Schiff2er.sizex,Schiff2er.sizey);
              break;
            }
          }
        }
      }
    }
  }
}

void spielfeldKoordinaten(){//Koordinaten handeling für Spielfeld
  int startfeldx = 66;
  int startfeldy = 50;
  int kastensize = 50;
  int felder = 10;
  if(MausSpieler.x < kastensize*felder + startfeldx && MausSpieler.x > startfeldx &&
     MausSpieler.y < kastensize*felder + startfeldy && MausSpieler.y > startfeldy) {       // feld1
    int x = 0, y = 0;
    x = (((double)(MausSpieler.x - startfeldx)) / ((double)kastensize));
    y = (((double)(MausSpieler.y - startfeldy)) / ((double)kastensize));
    MausSpieler.feld = 1;
    MausSpieler.feldx = x;
    MausSpieler.feldy = y;

  }
  if(MausSpieler.x < 2*kastensize*felder + 2*startfeldx && MausSpieler.x > kastensize*felder + 2*startfeldx &&
     MausSpieler.y < kastensize*felder + startfeldy && MausSpieler.y > startfeldy) {       // feld1
    int x = 0, y = 0;
    x = (((double)(MausSpieler.x - startfeldx*2 - felder*kastensize)) / ((double)kastensize));
    y = (((double)(MausSpieler.y - startfeldy)) / ((double)kastensize));
    MausSpieler.feld = 2;
    MausSpieler.feldx = x;
    MausSpieler.feldy = y;

  }
}

void SchiffSetzen(int x, int y) {//Funktion für setzen der Schiffe
  if(aktuelleSpielphase.schiffsetzen == 0) {
    aktuelleSpielphase.schiffsetzen = 1;
    aktuelleSpielphase.schiffsetzen_x = x;
    aktuelleSpielphase.schiffsetzen_y = y;
    for (int x = 0; x < 9; x++) {
      if(SchiffSetzenVonBis(aktuelleSpielphase.schiffsetzen_x, aktuelleSpielphase.schiffsetzen_y,
                            aktuelleSpielphase.schiffsetzen_x - 4 + x, aktuelleSpielphase.schiffsetzen_y)) {
        setztenMoeglich[x] = true;
      }else{
        setztenMoeglich[x] = false;
      }
    }
    for(int y = 0; y < 9; y++) {
      if(SchiffSetzenVonBis(aktuelleSpielphase.schiffsetzen_x, aktuelleSpielphase.schiffsetzen_y,
                            aktuelleSpielphase.schiffsetzen_x, aktuelleSpielphase.schiffsetzen_y - 4 + y)) {
        setztenMoeglich[9+y] = true;
      }else{
        setztenMoeglich[9+y] = false;
      }
    }
  }else{ // beim zweiten
    if(aktuelleSpielphase.schiffsetzen == 1) {
      int position = -1;
      if(x == aktuelleSpielphase.schiffsetzen_x) {
        position = y - aktuelleSpielphase.schiffsetzen_y + 13;
      }else{
        if(y == aktuelleSpielphase.schiffsetzen_y) {
          position = x - aktuelleSpielphase.schiffsetzen_x + 4;
        }
      }
      if(position != -1) {
        if(setztenMoeglich[position] == true) {
          int dist = 0;
          int richtung = 0;
          if(aktuelleSpielphase.schiffsetzen_x == x) {
            if(aktuelleSpielphase.schiffsetzen_y < y) {
              richtung = 1;
            }else{
              richtung = 3;
            }
            dist = abs(aktuelleSpielphase.schiffsetzen_y - y);
          }else{
            if(aktuelleSpielphase.schiffsetzen_y == y) {
              if(aktuelleSpielphase.schiffsetzen_x < x) {
                richtung = 2;
              }else{
                richtung = 4;
              }
              dist = abs(aktuelleSpielphase.schiffsetzen_x - x);
            }
          }
          // Schiffsauswahl(dist); // neue Funiton
          if(dist-1 >= 0 && dist-1 < 4 && richtung != 0) {
            if(schiffe_noch_nicht_gesetzt[dist - 1]> 0) {
              int schiffnr = 0;
              switch (dist + 1) {
              case 5:
                schiffe_noch_nicht_gesetzt[dist - 1]--;
                schiffnr = 10;
                break;
              case 4:
                schiffnr = 7 + schiffe_noch_nicht_gesetzt[dist - 1];
                schiffe_noch_nicht_gesetzt[dist - 1]--;
                break;
              case 3:
                schiffnr = 4 + schiffe_noch_nicht_gesetzt[dist - 1];
                schiffe_noch_nicht_gesetzt[dist - 1]--;
                break;
              case 2:
                schiffnr = schiffe_noch_nicht_gesetzt[dist - 1];
                schiffe_noch_nicht_gesetzt[dist - 1]--;
                break;
              }
              for (int i = 0; i < dist + 1; i++) {
                switch (richtung) {
                case 1:
                  spielfeld[x][aktuelleSpielphase.schiffsetzen_y + i] = schiffnr;
                  break;
                case 2:
                  spielfeld[aktuelleSpielphase.schiffsetzen_x + i][y] = schiffnr;
                  break;
                case 3:
                  spielfeld[x][aktuelleSpielphase.schiffsetzen_y - i] = schiffnr;
                  break;
                case 4:
                  spielfeld[aktuelleSpielphase.schiffsetzen_x - i][y] = schiffnr;
                  break;
                }
              }
            }
          }

          aktuelleSpielphase.schiffsetzen = 0; //
          for (int i = 0; i < 4; i++) {
            if(schiffe_noch_nicht_gesetzt[i] > 0) {
              return;
            }
          }
          // Hier wurden alle Schiffe gesetzt
          aktuelleSpielphase.phase = 2;
          printf("Alle gesetzt\n");
          fertigSchiffeGesetzt();
        }else{
          aktuelleSpielphase.schiffsetzen = 0;
          SchiffSetzen(x,y);
        }
      }else{
        aktuelleSpielphase.schiffsetzen = 0;
        SchiffSetzen(x,y);
      }
    }else{
      aktuelleSpielphase.schiffsetzen = 0;
    }
  }
}

bool istLeer(int x,int y){//Abfrage ob sich Maus in Spielfeld befindet
  if(x>=0 && x<10 && y>=0 && y < 10) { // innerhalb der spielflaeche
    if(x>0&&x<9&&y>0&&y<9) { // mittlerer teil
      if(spielfeld[x-1][y-1]==0 && spielfeld[x][y-1]==0 && spielfeld[x+1][y-1]==0 &&
         spielfeld[x-1][y]==0 && spielfeld[x][y]==0 && spielfeld[x+1][y]==0 &&
         spielfeld[x-1][y+1]==0 && spielfeld[x][y+1]==0 && spielfeld[x+1][y+1]==0) {
        return true;
      }
    }else{
      if(x==0 && y==0) { // ecke 1
        if( spielfeld[x][y]==0 && spielfeld[x+1][y]==0 &&
            spielfeld[x][y+1]==0 && spielfeld[x+1][y+1]==0) {
          return true;
        }
      }
      if(x==9 && y==0) { // ecke 2
        // printf(" - ecke               ||\n");
        if(spielfeld[x-1][y]==0 && spielfeld[x][y]==0 &&
           spielfeld[x-1][y+1]==0 && spielfeld[x][y+1]==0 ) {
          return true;
        }
      }
      if(x==9 && y==9) { // ecke 3

        if(spielfeld[x-1][y-1]==0 && spielfeld[x][y-1]==0 &&
           spielfeld[x-1][y]==0 && spielfeld[x][y]==0) {
          return true;
        }
      }
      if(x==0 && y==9) { // ecke 4
        if(spielfeld[x][y-1]==0 && spielfeld[x+1][y-1]==0 &&
           spielfeld[x][y]==0 && spielfeld[x+1][y]==0) {
          return true;
        }
      }
      if(y==0) { // kante oben
        if(spielfeld[x-1][y]==0 && spielfeld[x][y]==0 && spielfeld[x+1][y]==0 &&
           spielfeld[x-1][y+1]==0 && spielfeld[x][y+1]==0 && spielfeld[x+1][y+1]==0) {
          return true;
        }
      }
      if(y==9) { // kante unten
        if(spielfeld[x-1][y-1]==0 && spielfeld[x][y-1]==0 && spielfeld[x+1][y-1]==0 &&
           spielfeld[x-1][y]==0 && spielfeld[x][y]==0 && spielfeld[x+1][y]==0) {
          return true;
        }
      }
      if(x==0) { // kante links
        if(spielfeld[x][y-1]==0 && spielfeld[x+1][y-1]==0 &&
           spielfeld[x][y]==0 && spielfeld[x+1][y]==0 &&
           spielfeld[x][y+1]==0 && spielfeld[x+1][y+1]==0) {
          return true;
        }
      }
      if(x==9) { // kante rechts
        if(spielfeld[x-1][y-1]==0 && spielfeld[x][y-1]==0 &&
           spielfeld[x-1][y]==0 && spielfeld[x][y]==0 &&
           spielfeld[x-1][y+1]==0 && spielfeld[x][y+1]==0) {
          return true;
        }
      }
    }
  }
  return false;
}

bool SchiffSetzenVonBis(int x1, int y1, int x2, int y2){ //Abfagen an Spiel
  if(x2<0||x2>9||y2<0||y2>9||(x1==x2&&y1==y2)) {
    return false;
  }
  int dist = 0;
  int richtung = 0;
  if(x1 == x2) {
    if(y1 < y2) {
      richtung = 1;
    }else{
      richtung = 3;
    }
    dist = abs(y1 - y2);
  }else{
    if(y1 == y2) {
      if(x1 < x2) {
        richtung = 2;
      }else{
        richtung = 4;
      }
      dist = abs(x1 - x2);
    }
  }
  if(schiffe_noch_nicht_gesetzt[dist - 1] <= 0) {//Abfrage ob schiffe noch gesetz wurden bool
    return false;
  }
  for (int i = 0; i < 5; i++) {
    if(y1 == y2) {
      if(x1 < x2) {
        if(!istLeer(x1+i, y1)) {
          return false;
        }
        if(x1+i == x2) {
          return true;
        }
      }else{
        if(!istLeer(x1-i, y1)) {
          return false;
        }
        if(x1-i == x2) {
          return true;
        }
      }
    }else{
      if(y1 < y2) {
        if(!istLeer(x1,y1+i)) {
          return false;
        }
        if(y1+i == y2) {
          return true;
        }
      }else{
        if(!istLeer(x1,y1-i)) {
          return false;
        }
        if(y1-i == y2) {
          return true;
        }
      }
    }
  }
  return false;
}

void umrechnen(int feld, int x, int y, int * koordinate_x, int * koordinate_y) {//Umrechnen der Koordinaten
  int startfeldx = 66;
  int startfeldy = 50;
  int kastensize = 50;
  int felder = 10;
  if(feld == 2) {
    startfeldx = startfeldx*2 + felder * kastensize;
  }
  *koordinate_x = startfeldx + kastensize * x;
  *koordinate_y = startfeldy + kastensize * y;
}
