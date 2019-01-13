/*
* Das Apfelmännchen oder die Mandelbrotmenge
*/
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

int iteration(double x, double y, double xadd, double yadd, int maxBetrag, int maxIter){
   int fehlendeIter = maxIter;
   double xx = x*x;
   double yy = y*y;
   double xy = x*y;
   double betrag = xx + yy;

   while (betrag <= maxBetrag && fehlendeIter > 0) {
      fehlendeIter--;
      x = xx - yy + xadd;
      y = xy + xy + yadd;
      xx = x*x;
      yy = y*y;
      xy = x*y;
      betrag = xx + yy;
   }
   return maxIter - fehlendeIter;
}

uint32_t farben(int zahl){
   if (zahl < 4) {
     return COLOR_WHITE;
   } else if (zahl < 10) {
     return COLOR_GREEN;
   } else if (zahl < 15) {
      return COLOR_BLUE;
   } else if (zahl < 20) {
     return COLOR_YELLOW;
   } else if (zahl < 500) {
     return COLOR_RED;
   } else {
      return COLOR_BLACK;
   }
   return COLOR_WHITE;
}

int main(void) {
   int size = 500;
   int minX = -2, maxX = 1, minY = -1, maxY = 1;
   int iter = 0;
   double cy = 0;
   double cx = 0;

   int*zahlen;
   zahlen = (int*) calloc(1000, sizeof(int));
   for (int i = 0; i < 1000; i++) {
      zahlen[i] = 0;
   }

   uint32_t*data;    // var definieren als pointer
   data = (uint32_t*) calloc(size * size, sizeof(uint32_t));
   for (int y = 0; y < size; y++) {
      for (int x = 0; x < size; x++) {
         data[y*size + x] = COLOR_WHITE;
      }
   }

   for (int y = 0; y < size; y++) {
      for (int x = 0; x < size; x++) {
         cx = x;
         cy = y;
         toMath(&cx,&cy,minX, maxX, minY, maxY, size, size);

         iter = iteration(cx, cy, cx, cy, 4, 1000);

         if (iter > 999 || iter < 0) {
            zahlen[999]++;
         }else{
            zahlen[iter]++;
         }
         // printf("iter %d\n", iter);
         data[y*size + x] = farben(iter);
      }
   }

   printf("die Zahl kommt x mal vor\n");
   for (int i = 0; i < 1000; i++) {
      printf("%5d -> %10d\n", i, zahlen[i]);
   }

   bmp_create("pic.bmp",data, size, size);
   free(data); // Speicherplatz wiederfreigeben.
   free(zahlen);
   return 0;
}
