#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "libBMP.h"

void toMath(double*x, double*y, int minX, int maxX, int minY, int maxY, int width, int height){
   *x = (double)(1)*(minX + (((*x)*(maxX - minX))/width));
   *y = (double)(1)*(minY + (((*y)*(maxY - minY))/height));
}

void toBMP(double*x, double*y, int minX, int minY, int sizeX, int sizeY, int distX, int distY){
   if (minX < 0) {
      *x = (double)(1)*((((*x) + fabs(minX))*(sizeX))/distX);
   }else{
      *x = (double)(1)*((((*x) - minX)*(sizeX))/distX);
   }
   if (minY < 0) {
      *y = (double)(1)*((((*y) + fabs(minY))*(sizeY))/distY);
   }else{
      *y = (double)(1)*((((*y) - minY)*(sizeY))/distY);
   }
}

int main() {
   printf("Start\n");
   int maxX = 10;
   int minX = -10;
   int maxY = 10;
   int minY = -10;
   int distX = 0;
   int distY = 0;
   int size = 500; // größe des speicherplatzbedarfs.
   uint32_t*data;     // var definieren als pointer
   distX = fabs(minX) + fabs(maxX);
   distY = fabs(minY) + fabs(maxY);
   data = (uint32_t*) calloc(size * size, sizeof(uint32_t));
   for (int y = 0; y < size; y++) {
      for (int x = 0; x < size; x++) {
         data[y*size + x] = COLOR_WHITE;
      }
   }

   double spalten = 0, zeilen = 0; // Koordinatenachsen
   toBMP(&spalten, &zeilen, minX, minY, size, size, distX, distY);
   int spalten1 = spalten, zeilen1 = zeilen;
   for (int spalte = 0; spalte < size; spalte++) {
      data[zeilen1*size + spalte] = COLOR_RED;
   }
   for (int zeile = 0; zeile < size; zeile++) {
      data[zeile*size + spalten1] = COLOR_RED;
   }

   double x = 0, y = 0;
   for (int xn = 0; xn < size; xn++) {
      x = xn;
      toMath(&x,&y,minX, maxX, minY, maxY, size, size);

      /*
       *  Funktion eingeben
       */
      // y = sin(x);
      y = x*x;
      /*
       *  Funktion eingabe ende
       */

      y *= (-1);
      printf("Rechnung %f - %f\n", x, y);
      toBMP(&x,&y, minX, minY, size, size, distX, distY);
      if(y >= 0 && y < size) {
         int xa = x, ya = y;
         data[ya*size + xa] = COLOR_BLACK;
      }
   }

   bmp_create("pic.bmp",data, size, size);
   free(data); // Speicherplatz wiederfreigeben.
   return 0;
}
