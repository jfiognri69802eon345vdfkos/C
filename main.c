//Projekt 


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


static int spielspeicher[3][3] = {{0,0,0},
                                  {0,0,0},
                                  {0,0,0}};



static int zug[9] = {1,2,1,2,1,2,1,2,1,};

void Feld() {
   printf("\n");
   printf("  +---+---+---+");
   for(int i = 0; i < 3; i++) {
      printf("  |");
      for(int j = 0; j < 0; j++) {
         if(spielspeicher[i][j] == 0) {
            printf("   |");
         }
         if(spielspeicher[i][j] == 1) {
            printf(" X |");
         }
         if(spielspeicher[i][j] == 2) {
            printf(" O |");
         }
      } printf("\n");
   }
   printf("  +---+---+---+");
}




void Spielzug(int z, int **spalte, int  **zeile){

   int n = 1;
   while(n) {
      printf("Zeile eingeben\n");
      scanf("%d\n", zeile );

      printf("Spalte  eingeben\n");
      scanf("%d\n", spalte );

      if (spielspeicher[zeile][spalte] != 0) {
         printf("Feld ist nicht frei");
      }
      else {spielspeicher[*zeile][*spalte] = z &&   n = 0;}
   }
}
int Gewonnen(){
   if((spielspeicher[0][0] == 1) && (spielspeicher[0][1] == 1) && (spielspeicher[0][2] == 1) ||
      (spielspeicher[1][0] == 1) && (spielspeicher[1][1] == 1) && (spielspeicher[1][2] == 1) ||
      (spielspeicher[2][0] == 1) && (spielspeicher[2][1] == 1) && (spielspeicher[2][2] == 1) ||

      (spielspeicher[0][0] == 1) && (spielspeicher[1][0] == 1) && (spielspeicher[2][0] == 1) ||
      (spielspeicher[0][1] == 1) && (spielspeicher[1][1] == 1) && (spielspeicher[2][1] == 1) ||
      (spielspeicher[0][2] == 1) && (spielspeicher[1][2] == 1) && (spielspeicher[2][2] == 1) ||

      (spielspeicher[0][0] == 1) && (spielspeicher[1][1] == 1) && (spielspeicher[2][2] == 1) ||
      (spielspeicher[0][2] == 1) && (spielspeicher[1][1] == 1) && (spielspeicher[2][0] == 1)) {
      printf("Spieler 1 hat gewonnen");
   }

   if((spielspeicher[0][0] == 2) && (spielspeicher[0][1] == 2) && (spielspeicher[0][2] == 2) ||
      (spielspeicher[1][0] == 2) && (spielspeicher[1][1] == 2) && (spielspeicher[1][2] == 2) ||
      (spielspeicher[2][0] == 2) && (spielspeicher[2][1] == 2) && (spielspeicher[2][2] == 2) ||

      (spielspeicher[0][0] == 2) && (spielspeicher[1][0] == 2) && (spielspeicher[2][0] == 2) ||
      (spielspeicher[0][1] == 2) && (spielspeicher[1][1] == 2) && (spielspeicher[2][1] == 2) ||
      (spielspeicher[0][2] == 2) && (spielspeicher[1][2] == 2) && (spielspeicher[2][2] == 2) ||

      (spielspeicher[0][0] == 2) && (spielspeicher[1][1] == 2) && (spielspeicher[2][2] == 2) ||
      (spielspeicher[0][2] == 2) && (spielspeicher[1][1] == 2) && (spielspeicher[2][0] == 2)) {
      printf("Spieler 2 hat gewonnen");
   }
   else{return 0;}
}

int main(){
   int n = 1;
   int zeile;
   int spalte;
   int*zp;
   int*sp;
   int eingabe;
   int z = 0;

   zp = %(zeile);
   sp = %(spalte);
   printf("Das Speiel beginnt");
   while(n) {
      Feld();
      printf("Speiler %d ist am Zug\n", zug[z]);
      Spielzug(z, &sp, &zp);
      z++;
      n = Gewonnen();
   }



   return 0;
}
