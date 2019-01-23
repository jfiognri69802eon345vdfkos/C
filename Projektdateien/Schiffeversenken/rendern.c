#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "main.h"

SDL_Color render_color = {255, 255, 255, 255};

int Sprites_buchstaben[67][5] = {{'A',44,27,38,82}, //Sprite Datei für Buchstaben (Koordinaten und Größe)
                                 {'B',44,65,59,82},
                                 {'C',44,124,59,82},
                                 {'D',44,183,59,82},
                                 {'E',44,242,59,82},
                                 {'F',44,302,59,82},
                                 {'G',44,362,59,82},
                                 {'H',44,424,59,82},
                                 {'I',44,483,59,82},
                                 {'J',44,525,59,82},
                                 {'K',44,584,59,82},
                                 {'L',44,643,59,82},
                                 {'M',44,702,59,82},
                                 {'N',44,761,59,82},
                                 {'O',44,820,59,82},
                                 {'P',44,879,59,82},
                                 {'Q',44,939,59,82},
                                 {'R',44,1001,59,82},
                                 {'S',44,1060,59,82},
                                 {'T',44,1119,59,82},
                                 {'U',44,1178,59,82},
                                 {'V',44,1237,59,82},
                                 {'W',44,1296,59,82},
                                 {'X',44,1357,59,82},
                                 {'Y',44,1416,59,82},
                                 {'Z',44,1475,59,82},

                                 {'a',183,27,38,82},
                                 {'b',183,86,59,82},
                                 {'c',183,145,59,82},
                                 {'d',183,204,59,82},
                                 {'e',183,263,59,82},
                                 {'f',183,320,59,82},
                                 {'g',204,373,59,82},
                                 {'h',183,432,59,82},
                                 {'i',183,491,12,82},
                                 {'j',183,529,33,96},
                                 {'k',183,588,33,82},
                                 {'l',183,647,29,82},
                                 {'m',183,702,33,82},
                                 {'n',183,761,33,82},
                                 {'o',183,820,33,82},
                                 {'p',183,879,33,82},
                                 {'q',183,938,33,82},
                                 {'r',183,997,33,82},
                                 {'s',183,1056,33,82},
                                 {'t',183,1113,36,82},
                                 {'u',183,1175,33,82},
                                 {'v',183,1234,33,82},
                                 {'w',183,1293,33,82},
                                 {'x',183,1352,33,82},
                                 {'y',183,1411,33,82},
                                 {'z',183,1470,33,82},

                                 {'1',371,24,28,82},
                                 {'2',371,69,39,82},
                                 {'3',371,124,59,82},
                                 {'4',371,190,36,82},
                                 {'5',371,252,33,82},
                                 {'6',371,311,33,82},
                                 {'7',371,370,33,82},
                                 {'8',371,429,33,82},
                                 {'9',371,488,33,82},
                                 {'0',371,547,33,82},
                                 {'.',371,616,33,82},
                                 {',',371,677,33,82},
                                 {'-',371,734,33,82},
                                 {'?',371,797,33,82},
                                 {'!',371,854,33,82}};

void display() {
  felder();
}

void felder() {
  int startfeldx = 66;
  int startfeldy = 50;
  int kastensize = 50;
  int felder = 10;
  grey(255);
  for (int x = 0; x < felder  + 1; x++) {
    for (int y = 0; y < felder + 1; y++) {
      line(startfeldx + kastensize * x, startfeldy + kastensize * y, startfeldx + kastensize * x, startfeldy + kastensize * felder);
      line(startfeldx + kastensize * x, startfeldy + kastensize * y, startfeldx + kastensize * felder, startfeldy + kastensize * y);
    }
  }
  startfeldx = 2*startfeldx + kastensize * felder;
  for (int x = 0; x < felder  + 1; x++) {
    for (int y = 0; y < felder + 1; y++) {
      line(startfeldx + kastensize * x, startfeldy + kastensize * y, startfeldx + kastensize * x, startfeldy + kastensize * felder);
      line(startfeldx + kastensize * x, startfeldy + kastensize * y, startfeldx + kastensize * felder, startfeldy + kastensize * y);
    }
  }
}

void text(const char *texten, int x, int y, double size, int farbe){//Ausgabe von Text(render)
  int i = 0;
  int j = 0;
  int aktuelle_positon = x;
  for (i = 0; i < (int) strlen(texten); i++) {
    for (j = 0; j < 67; j++) {
      if(Sprites_buchstaben[j][0] == texten[i]) {
        break;
      }
    }

    // Hier sind die x und y koordinaten vertauscht
    switch (farbe) {
    case 0:
      sprite_size_diff(buchstaben_weiss, aktuelle_positon, y, Sprites_buchstaben[j][3] * size, Sprites_buchstaben[j][4] * size,
                       Sprites_buchstaben[j][2], Sprites_buchstaben[j][1], Sprites_buchstaben[j][3], Sprites_buchstaben[j][4]);
      aktuelle_positon += Sprites_buchstaben[j][3] * size  + 5;
      break;
    }
  }
}

SDL_Texture * loadpic(const char *text){//rendern der Texte
  SDL_Surface *imageLoader = IMG_Load(text);
  SDL_Texture *a = SDL_CreateTextureFromSurface(renderer, imageLoader);
  SDL_FreeSurface(imageLoader);
  return a;
}

void bild(SDL_Texture *texture, int x, int y, int w, int h){
  SDL_Rect helperRect;
  helperRect.x = x;
  helperRect.y = y;
  helperRect.w = w;
  helperRect.h = h;
  SDL_RenderCopy(renderer, texture, NULL, &helperRect);
}

void animation(struct AnimationSprite *bild, int x, int y, int w, int h) {//Animationen Schiffe
  if(bild->frame < bild->animationsTeile && bild->Animationsdetail > 0) {
    sprite(bild->textur,x,y,w,h,bild->reihnfolge[2*(bild->frame)],bild->reihnfolge[2*(bild->frame)+1],bild->sizex,bild->sizey);
    if(bild->Animationsdetail > 0) {
      if((bild->Animationsdetail == 1 && bild->frame < (bild->animationsTeile) -1)||bild->Animationsdetail==2) {
        bild->frame++;
      }
    }
  }else{
    if(bild->Animationsdetail == 2) {
      bild->frame = 0;
    }
    animation(bild, x, y, w, h);
  }
}

void sprite_size_diff(SDL_Texture *texture, int x, int y, int w, int h, int posx, int posy, int sizex, int sizey) {//anpassung Text größe von Sprites
  SDL_Rect helperRect;
  helperRect.x = x;
  helperRect.y = y;
  helperRect.w = w;
  helperRect.h = h;
  SDL_Rect animationFrame;
  animationFrame.x = posx;
  animationFrame.y = posy;
  animationFrame.w = sizex;
  animationFrame.h = sizey;
  SDL_RenderCopy(renderer, texture, &animationFrame, &helperRect);
}

void sprite(SDL_Texture *texture, int x, int y, int w, int h, int posx, int posy, int sizex, int sizey) {//zugriff auf Sprites
  SDL_Rect helperRect;
  helperRect.x = x;
  helperRect.y = y;
  helperRect.w = w;
  helperRect.h = h;
  SDL_Rect animationFrame;
  animationFrame.x = sizex*posx;
  animationFrame.y = sizey*posy;
  animationFrame.w = sizex;
  animationFrame.h = sizey;
  SDL_RenderCopy(renderer, texture, &animationFrame, &helperRect);
}

void background_clear(){
  // Set render color to red ( background will be rendered in this color )
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
  // Clear winow
  SDL_RenderClear( renderer );
}

void rect(int x, int y, int w, int h) {//Render zerstörte Schiffe
  SDL_Rect r;
  r.x = x;
  r.y = y;
  r.w = w;
  r.h = h;

  // Render rect
  SDL_RenderFillRect( renderer, &r );
}

void rgba(int r,int g,int b,int alpha){//Render für Farben
  SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
  render_color.r = r;
  render_color.g = g;
  render_color.b = b;
  render_color.a = alpha;
}
void rgb(int r,int g,int b){
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  render_color.r = r;
  render_color.g = g;
  render_color.b = b;
  render_color.a = 255;
}
void greya(int grey, int alpha){
  SDL_SetRenderDrawColor(renderer, grey, grey, grey, alpha);
  render_color.r = grey;
  render_color.g = grey;
  render_color.b = grey;
  render_color.a = alpha;
}
void grey(int grey){
  SDL_SetRenderDrawColor(renderer, grey, grey, grey, 255);
  render_color.r = grey;
  render_color.g = grey;
  render_color.b = grey;
  render_color.a = 255;
}

void line(int x1, int y1, int x2, int y2){
  SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}
