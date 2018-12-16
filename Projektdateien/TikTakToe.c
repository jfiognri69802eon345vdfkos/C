//Projekt


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


static int spielspeicher[3][3] = {{0,0,0},
                                  {0,0,0},
                                  {0,0,0}};



static int zug[9] = {1,2,1,2,1,2,1,2,1};

void Feld() {
   printf("\n");
   printf("      1   2   3  \n");
   printf("     +---+---+---+\n");

   for(int i = 0; i < 3; i++) {
      printf("   %d |",i + 1);

      for(int j = 0; j < 3; j++) {
         if((spielspeicher[i][j]) == 0) {
            printf("   |");
         }
         if(spielspeicher[i][j] == 1) {
            printf(" X |");
         }
         if(spielspeicher[i][j] == 2) {
            printf(" O |");
         }
      } printf("\n");
      printf("     +---+---+---+\n");
   }

}




void Spielzug(int z){

   int zeile;
   int spalte;
   int g = 1;
   while(g != 0) {
      printf("   Zeile eingeben\n");
      scanf("%d", &zeile );
      if( zeile <= 0 || zeile >= 3) {
         printf("Eingabe ist ungultig\n");
      }else{

         printf("   Spalte  eingeben\n");
         scanf("%d", &spalte );
         if(spalte <= 0  || spalte >= 3 ) {
            printf("Eingabe ist ungueltig\n");


         }else{

            if (spielspeicher[zeile - 1][spalte - 1] != 0) {
               printf("Feld ist nicht frei\n");
            }
            else {spielspeicher[zeile - 1][spalte - 1] = z;
                  g = 0;
                  printf("Spielzug ist erlaubt\n");}
         }
      }
   }
}
int Gewonnen(){

   int h;

   if(((spielspeicher[0][0] == 1) && (spielspeicher[0][1] == 1) && (spielspeicher[0][2] == 1)) ||
      ((spielspeicher[1][0] == 1) && (spielspeicher[1][1] == 1) && (spielspeicher[1][2] == 1)) ||
      ((spielspeicher[2][0] == 1) && (spielspeicher[2][1] == 1) && (spielspeicher[2][2] == 1)) ||

      ((spielspeicher[0][0] == 1) && (spielspeicher[1][0] == 1) && (spielspeicher[2][0] == 1)) ||
      ((spielspeicher[0][1] == 1) && (spielspeicher[1][1] == 1) && (spielspeicher[2][1] == 1)) ||
      ((spielspeicher[0][2] == 1) && (spielspeicher[1][2] == 1) && (spielspeicher[2][2] == 1)) ||

      ((spielspeicher[0][0] == 1) && (spielspeicher[1][1] == 1) && (spielspeicher[2][2] == 1)) ||
      ((spielspeicher[0][2] == 1) && (spielspeicher[1][1] == 1) && (spielspeicher[2][0] == 1))) {
      printf("Spieler 1 hat gewonnen");
      h = 0;
   }

   if(((spielspeicher[0][0] == 2) && (spielspeicher[0][1] == 2) && (spielspeicher[0][2] == 2)) ||
      ((spielspeicher[1][0] == 2) && (spielspeicher[1][1] == 2) && (spielspeicher[1][2] == 2)) ||
      ((spielspeicher[2][0] == 2) && (spielspeicher[2][1] == 2) && (spielspeicher[2][2] == 2)) ||

      ((spielspeicher[0][0] == 2) && (spielspeicher[1][0] == 2) && (spielspeicher[2][0] == 2)) ||
      ((spielspeicher[0][1] == 2) && (spielspeicher[1][1] == 2) && (spielspeicher[2][1] == 2)) ||
      ((spielspeicher[0][2] == 2) && (spielspeicher[1][2] == 2) && (spielspeicher[2][2] == 2)) ||

      ((spielspeicher[0][0] == 2) && (spielspeicher[1][1] == 2) && (spielspeicher[2][2] == 2)) ||
      ((spielspeicher[0][2] == 2) && (spielspeicher[1][1] == 2) && (spielspeicher[2][0] == 2))) {
      printf("Spieler 2 hat gewonnen");
      h = 0;
   }
   else{h = 1;}
   return h;
}

int draw(){
   int summ = 0;
   int summ_dd;
   int z = 1;

   for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
         summ =  spielspeicher[i][j];
         summ_dd += summ;
      }
   }
   if (summ_dd == 9) {
      printf("Unendschiden");
      z = 0;
   }

   return z;
}



int main(){
   int n = 1;
   int zeile;
   int spalte;
   int*zp;
   int*sp;
   int z = 0;
   int k = 0;


   printf("   Das Spiel beginnt");
   while(n != 0 || k != 0) {
      Feld();
      printf("   Spieler %d ist am Zug\n", zug[z]);
      Spielzug(zug[z]);
      z++;
      n = Gewonnen();
      k = draw();
   }
   Feld();




   return 0;
}
