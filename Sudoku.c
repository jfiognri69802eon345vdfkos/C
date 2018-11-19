#include <stdio.h>
#include <stdbool.h>
void displayGame(void);

static int matrix[9][9] = {{4,1,0,0,6,5,0,0,7},
                           {0,0,6,0,0,7,4,8,0},
                           {2,0,7,4,9,0,0,0,6},
                           {0,6,0,0,7,0,1,0,0},
                           {3,0,1,5,0,0,0,7,2},
                           {0,9,0,0,4,2,3,0,8},
                           {1,0,8,6,0,0,0,2,9},
                           {0,2,0,0,1,8,6,4,0},
                           {6,0,0,3,0,0,0,1,0}};

void displayGame(){
   printf("   |  1  2  3  |  4  5  6  |  7  8  9  |\n");
   printf("----------------------------------------\n");
   for (int y = 0; y < 9; y++) { // alle Reihen
      printf("%2d |", y + 1);
      for (int x = 0; x < 9; x++) { // alle Spalten
         if(matrix[x][y] == 0) { // Leerzeichen statt 0, Übersichtlichkeit
            printf("   ");
         }else{
            printf("  %d", matrix[x][y]); // Wert anzeigen^^
         }
         if (x == 2 || x == 5) { // Zwischenlinien
            printf("  |");
         }
      }
      printf("  |\n"); // Nächste Zeile
      if (y == 2 || y == 5) {
         printf("----------------------------------------\n"); // Zwischenlinien
      }
   }
   printf("----------------------------------------\n"); // Ende der Grafik
}

void eingabeAbfragen(){
   int spalte = 0;
   int zeile = 0;
   int zahl = 0;
   printf("Spalte: ");
   scanf("%d", &spalte);
   if (spalte > 0 && spalte < 10) {
      printf(" Zeile: ");
      scanf("%d", &zeile);
      if (zeile > 0 && zeile < 10) {
         printf(" Zahl: ");
         scanf("%d", &zahl);
         if (zahl > 0 && zahl < 10) {
            matrix[spalte-1][zeile-1] = zahl;
         }else{
            printf("Inkorrekte Eingabe\n");
            eingabeAbfragen();
         }
      }else{
         printf("Inkorrekte Eingabe\n");
         eingabeAbfragen();
      }
   }else{
      printf("Inkorrekte Eingabe\n");
      eingabeAbfragen();
   }
}

int main() {
   bool solved = false;
   do {
      displayGame();
      eingabeAbfragen();
   } while(solved == false);
   printf("Spiel beendet\n");
   return 0;
}
