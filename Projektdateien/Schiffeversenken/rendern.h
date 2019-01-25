#ifndef RENDERN_H
#define RENDERN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

struct AnimationSprite{
  SDL_Texture *textur;
  int frame; // angezeigtes bild
  int Animationsdetail; // 0 keine Animation 1 einmal durchlaufen 2 dauerschleife
  int sizex;
  int sizey;
  int animationsTeile; // anzahl einzel bilder
  int reihnfolge[500];
};
// SDL_Color render_color = {255, 255, 255, 255};
SDL_Texture * buchstaben_weiss;

void display();
void felder();
// void renderText(const char*, int, int, SDL_Color, int, int);
void text(const char *, int, int, double, int);
SDL_Texture * loadpic(const char *);
void bild(SDL_Texture *, int, int, int, int);
void animation(struct AnimationSprite *, int, int, int, int);
void sprite_size_diff(SDL_Texture *, int, int, int, int, int, int, int, int);
void sprite(SDL_Texture *, int, int, int, int, int, int, int, int);
void background_clear();
void grey(int);
void greya(int, int);
void rgb(int, int, int);
void rgba(int, int, int, int);
void rect(int, int , int, int);
void line(int, int , int, int);


#endif
