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

void toBMP2(double*x, double*y, int minX, int minY, int maxX, int maxY, int width, int height){
  *x = (double)(1)*((((*x) - minX)/(maxX - minX))*width);
  *y = (double)(1)*((((*y) - minY)/(maxY - minY))*height);
}

int main() {
   printf("Start\n");
   int maxX = 1;
   int minX = -1;
   int maxY = 1;
   int minY = -1;
   int size = 100; // größe des speicherplatzbedarfs.
   uint32_t*data;     // var definieren als pointer
   data = (uint32_t*) calloc(size * size, sizeof(uint32_t));
   for (int y = 0; y < size; y++) {
      for (int x = 0; x < size; x++) {
         data[y*size + x] = COLOR_WHITE;
      }
   }
   int t = maxY; // Umdrehen der Y Achse
   maxY = minY;
   minY = t;
   maxY *= (-1);
   minY *= (-1);

   double spalten = 0, zeilen = 0; // Koordinatenachsen
   toBMP2(&spalten, &zeilen, minX, minY, maxX, maxY, size, size);
   int spalten1 = spalten, zeilen1 = zeilen;
   for (int spalte = 0; spalte < size; spalte++) {
      data[zeilen1*size + spalte] = COLOR_RED;
   }
   for (int zeile = 0; zeile < size; zeile++) {
      data[zeile*size + spalten1] = COLOR_RED;
   }

   double x = 0, y = 0;
   for (int xn = 0; xn < size; xn++) { // Schleife mit der Funktion
      x = xn;
      toMath(&x,&y,minX, maxX, minY, maxY, size, size);

      /*
       *  Funktion eingeben
       */
      y = x*x;
      /*
       *  Funktion eingabe ende
       */

      y *= (-1);
      printf("Rechnung %f - %f\n", x, y);
      // toBMP(&x,&y, minX, minY, size, size, distX, distY);
      toBMP2(&x,&y, minX, minY, maxX, maxY, size, size);
      if(y >= 0 && y < size) {
         int xa = x, ya = y;
         data[ya*size + xa] = COLOR_BLACK;
      }
   }

   bmp_create("pic.bmp",data, size, size);
   free(data); // Speicherplatz wiederfreigeben.
   return 0;
}
