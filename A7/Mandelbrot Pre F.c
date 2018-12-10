#include <stdio.h>
#include "libBMP.h"
#include <complex.h>
#define TT 1000

void toMath(double*x, double*y, double width, double height){
   *x =  (double)((-2) + (((*x)*(1 - (-2))/(width))));
   *y =  (double)((1) + (((*y)*((-1) - (1))/(height))));
}

int Tiefe(int n, double cx, double cy){
   cx = (cx*cx) + cy;

   if (((cx*cx) + (cy*cy)) >= 2) {
      return n;
   }
   if(n == TT) {
      return (TT);
   }else{
      n++;
      return (Tiefe(n, cx, cy));
   }
}

int Farben (int zahl){
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

int main (){

   int width  = 500;
   int height = 800;
   // int n_max  = 100;
   int n = 0;
   double cx = 0.0;
   double cy = 0.0;
   // double x,y;
   int rn = 0;

   uint32_t*pMandel = (uint32_t*) malloc(width*height*sizeof(uint32_t));  //Weißer Hintergrund warscheinlich unnötig
   for(int j = 0; j < height; j++) {
      for(int k = 0; k < width; k++) {
         pMandel[j*width + k] = COLOR_WHITE;
      }
   }

   for(int l = 0; l < height; l++) {
      for(int k = 0; k < width; k++) {
         n = 0;
         cx = k;
         cy = l;
         toMath(&cx, &cy, width, height);
         rn = Tiefe(n, cx, cy);
         pMandel[l*height + k] = Farben(rn);
      }
   }
   //to math()
   bmp_create("pic.bmp", pMandel, width, height);
   free(pMandel);
   return 0;
}
