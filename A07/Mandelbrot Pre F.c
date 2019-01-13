#include <stdio.h>
#include "libBMP.h"
#include <complex.h>
#define TT 1000
#define COLOR_YELLOW 0x00FFFF00

void toMath(double *x, double *y, int minX,int minY, int maxX, int maxY,double width, double height){
  *x =  (double)((-2) + (((*x)*(1 - (-2))/(width))));
  *y =  (double)((1) + (((*y)*((-1) - (1))/(height))));
}

int Tiefe(int n, double *cx, double *cy,double zn){

    zn = (zn*zn)+(cy+cx); 
    if ((((*cx)*(*cx)+(cy*cy))>=2)){
       return n;}
    if(n==TT){
        return (TT);}
            else{n++;
              return (Tiefe(n, cx, cy, zn));}

}

int Farben (int zahl){  //rn in main
if (zahl < 4) {
     return COLOR_WHITE;
   } else if (zahl < 10) {          //Farben anhand von Tiefe mit Hexcode
     return COLOR_GREEN;
   } else if (zahl < 15) {            //if else Schleife
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


int main (){  //main

int width  = 500;  //initialisierung
int  height = 800;
int n_max  = 100;
int n = 0;
double cx ;
double cy ;
double x,y;
int rn;
int minX = -2, maxX = 1, minY = -1, maxY = 1; //min und max were für das Koordinaten feld
double cx2;
double  zn;

uint32_t* pMandel = (uint32_t*) malloc(width*height*sizeof(uint32_t));
for(int j= 0;j<height;j++){  //array für weißen hintergrung
        for(int k= 0;k<width;k++){
    pMandel[j*width+k]=COLOR_WHITE;
        }
}

for(int l=0;l<height;l++){  //Hauptschleife für Programm  l = y
        for(int k=0;k<width;k++){ //k = c Koordianten
          n=0;
          zn=0;       //Tiefen ähler auf 0 setzen
          cx=k;     //Pixel werden nacheinander durchgegangen und mit dem WErten wird gerechnet
          cy=l;

          toMath(&cx, &cy, minX , minY, maxX, maxY,width, height);  // Zahlen in Koordinaten umgerechnet Funktion
 rn = Tiefe(n, &cx, &cy, zn);         //Die Rekursion wird durchgefühlt und ausgegebne
 pMandel [l*height+k]=Farben(rn); //Feld wird entsprechned der Tiefe Farbe zugewiesen
        }
}

bmp_create("pic.bmp", pMandel, width, height);  //Wenn Schleife fertig Bild wird erstellt
free(pMandel);    //Array wird freigegenben
return 0;       //Programm fertig
}
