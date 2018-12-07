#include <stdio.h>
#include "libBMP.h"
#include <complex.h>
#define TT 1000
#define COLOR_YELLOW 0x00FFFF00

void toMath(double *x, double *y, double width, double hight){
    *x =  (double)*((-2)+ (((*x)*(1 - (-2))/(width))));
    *y =  (double)*((1) + (((*y)*((-1) - (1))/(hight))));
}
//void toBmp2(){
  //  *x = (double)*((((*x) - (-2))/((1) - (-2)))*width);
    //*y = (double)*((((*y) - (1))/((-1) - (1)))*height);
//}
int Tiefe(int n, double cx, double cy){
    cx = (cx*cx)+cy;

    if (((cx*cx)+(cy*cy))>=2){
       return n;}
    if(n==TT){
        return (TT);}
            else{n++;
              return (Tiefe(n, cx, cy));}

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

double width  = 500;
double hight = 800;
int n_max  = 100;
int n = 0;
double cx;
double cy;
double x,y;
int rn;

uint32_t* pMandel = (uint32_t*) malloc(width*hight*sizeof(uint32_t)); //Weißer Hintergrund warscheinlich unnötig
for(int j= 0;j<hight;j++){
        for(int k= 0;k<width;k++){
    pMandel[j*width+k]=COLOR_WHITE;
        }
}

for(int l=0;l<hight;l++){
        for(int k=0;k<width;k++){
          n=0;
          cx=k;
          cy=l;
          toMath(&cx, &cy, width, hight);
 rn = Tiefe(n, cx, cy);
 pMandel [l*hight+k]=Farben(rn);
        }
}
//to math();
bmp_create("pic.bmp", pMandel, width, hight);
free(pMandel);
return 0;
}
