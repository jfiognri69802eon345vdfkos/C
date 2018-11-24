#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
void displayGame(void);
void eingabeAbfragen(void);
void gueltigeEingabe(int, int, int);
void loesen(void);
int fortschritt(void);
bool fertig(void);

static int matrix[6][9][9] = {{{4,1,0,0,6,5,0,0,7}, // Rätsel 1
                               {0,0,6,0,0,7,4,8,0},
                               {2,0,7,4,9,0,0,0,6},
                               {0,6,0,0,7,0,1,0,0},
                               {3,0,1,5,0,0,0,7,2},
                               {0,9,0,0,4,2,3,0,8},
                               {1,0,8,6,0,0,0,2,9},
                               {0,2,0,0,1,8,6,4,0},
                               {6,0,0,3,0,0,0,1,0}},
                              {{0,2,0,0,0,7,0,5,1}, // Rätsel 2
                               {4,1,8,0,0,5,0,0,7},
                               {0,0,3,6,4,0,0,0,9},
                               {5,6,0,0,0,0,0,0,0},
                               {0,8,2,5,0,9,0,0,0},
                               {0,0,0,0,0,8,0,0,0},
                               {2,0,1,0,0,4,7,6,5},
                               {8,0,7,0,0,6,0,9,0},
                               {6,0,5,0,1,3,0,8,0}},
                              {{0,2,0,0,3,0,0,0,4}, // Rätsel 3
                               {0,6,0,0,0,0,0,0,9},
                               {0,0,1,4,0,6,0,2,0},
                               {0,0,0,9,0,7,8,0,0},
                               {0,9,4,0,6,0,0,5,7},
                               {8,0,2,0,0,0,0,0,0},
                               {0,4,3,2,0,5,0,1,8},
                               {2,0,0,6,0,9,0,7,3},
                               {0,0,7,8,4,0,5,6,2}},
                              {{5,3,4,6,7,8,9,1,2}, // Fertiges Rätsel 4
                               {6,7,2,1,9,5,3,4,8},
                               {1,9,8,3,4,2,5,6,7},
                               {8,5,9,7,6,1,4,2,3},
                               {4,2,6,8,0,3,7,9,1},
                               {7,1,3,9,2,4,8,5,6},
                               {9,6,1,5,3,7,2,8,4},
                               {2,8,7,4,1,9,6,3,5},
                               {3,4,5,2,8,6,1,7,9}}};
static int Raetselgrund[9][9] = {{0,0,0,0,0,0,0,0,0}, // Rätsel speicher
                                 {0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0}};
static int Raetsel = 4;
static bool geht[3] = {true, true, true};
static HANDLE hConsole;

void uebertragRaetsel(){ // Rätsel speichern zur Prüfung von bearbeiteten Werten.
   for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
         Raetselgrund[x][y] = matrix[Raetsel][x][y];
      }
   }
}

void displayGame(){
   printf("   |  1  2  3  |  4  5  6  |  7  8  9  |\n");
   printf("---+-----------+-----------+-----------|\n");
   for (int y = 0; y < 9; y++) { // alle Reihen
      printf("%2d |", y + 1);
      for (int x = 0; x < 9; x++) { // alle Spalten
         if(matrix[Raetsel][x][y] == 0) { // Leerzeichen statt 0, Übersichtlichkeit
            printf("   ");
         }else{
            if (Raetselgrund[x][y] != 0) {
               SetConsoleTextAttribute(hConsole, 6);
               printf("  %d", matrix[Raetsel][x][y]); // Wert anzeigen^^
            }else{
               printf("  %d", matrix[Raetsel][x][y]); // Wert anzeigen^^
            }
            SetConsoleTextAttribute(hConsole, 15);
         }
         if (x == 2 || x == 5) { // Zwischenlinien
            printf("  |");
         }
      }
      printf("  |\n"); // Nächste Zeile
      if (y == 2 || y == 5) {
         printf("---+-----------+-----------+-----------|\n"); // Zwischenlinien
      }
   }
   printf("---+-----------+-----------+-----------|\n"); // Ende der Grafik
}

void eingabeAbfragen(){
   // fflush(stdin);
   SetConsoleTextAttribute(hConsole, 15); // farbe wählen
   int spalte = 0;
   int zeile = 0;
   int zahl = 0;
   printf("Spalte: ");
   scanf("%i", &spalte);
   if (spalte > 0 && spalte < 10) {
      printf(" Zeile: ");
      scanf("%i", &zeile);
      if (zeile > 0 && zeile < 10) {
         printf("  Zahl: ");
         scanf("%i", &zahl);
         if (zahl > 0 && zahl < 10) {
            if (Raetselgrund[spalte - 1][zeile - 1] == 0) {
               matrix[Raetsel][spalte - 1][zeile - 1] = zahl;
               gueltigeEingabe(spalte - 1, zeile - 1, zahl);
               if(geht[0] != true || geht[1] != true || geht[2] != true) {
                  matrix[Raetsel][spalte - 1][zeile - 1] = 0;
               }
            }else{
               printf("Dieser Wert darf nicht ge\x84ndert werden!\n");
            }
         }else{
            printf("Inkorrekte Eingabe\n");
            // eingabeAbfragen();
         }
      }else{
         printf("Inkorrekte Eingabe\n");
         // eingabeAbfragen();
      }
   }else{
      if(spalte == 20) {
         loesen();
      }else{
         printf("Inkorrekte Eingabe\n");
      }
      // eingabeAbfragen();
   }
   // fflush(stdin);
}

bool fertig(){
   for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
         if (matrix[Raetsel][x][y] == 0) {
            return false;
         }
      }
   }
   return true;
}
int fortschritt(){
   int fehlt = 9*9;
   for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
         if (matrix[Raetsel][x][y] != 0) {
            fehlt--;
         }
      }
   }
   return fehlt;
}


void gueltigeEingabe(int spalte, int zeile, int eingabe){
   geht[0] = true;
   geht[1] = true;
   geht[2] = true;
   if (eingabe != 0) {
      // Spalte überprüfen
      int zahler[9] = {0,0,0,0,0,0,0,0,0};
      for (int y = 0; y < 9; y++) {
         if( matrix[Raetsel][spalte][y] != 0) {
            zahler[matrix[Raetsel][spalte][y] - 1]++;
            if (zahler[matrix[Raetsel][spalte][y] - 1] == 2) {
               geht[0] = false;
               // printf("Spaltenfehler\n");
               return;
            }
         }
      }
      // Zeile überprüfen
      int zaehler1[9] = {0,0,0,0,0,0,0,0,0};
      for (int x = 0; x < 9; x++) {
         if(matrix[Raetsel][x][zeile] != 0) {
            zaehler1[matrix[Raetsel][x][zeile] - 1]++;
            if (zaehler1[matrix[Raetsel][x][zeile] - 1] == 2) {
               geht[1] = false;
               // printf("Zeilenfehler\n");
               return;
            }
         }
      }
      // Kasten überprüfen
      int startX = spalte - (spalte % 3);
      int startY = zeile - (zeile % 3);
      // printf("spalte %d zeile %d\n", startX, startY);
      int zahler2[9] = {0,0,0,0,0,0,0,0,0};
      for (int y = 0; y < 3; y++) {
         for (int x = 0; x < 3; x++) {
            // printf("x-%d y-%d %d%d%d%d%d%d%d%d%d\n", x,y, zahler2[0],zahler2[1],zahler2[2],zahler2[3],zahler2[4],zahler2[5],zahler2[6],zahler2[7],zahler2[8]);
            if(matrix[Raetsel][x + startX][y + startY] != 0) {
               zahler2[(matrix[Raetsel][x + startX][y + startY] - 1)]++;
               if (zahler2[(matrix[Raetsel][x + startX][y + startY] - 1)] == 2) {
                  geht[2] = false;
                  // printf("Kastenfehler\n");
                  return;
               }
            }
         }
      }
   }
} /* gueltigeEingabe */

void loesen(){
   int probiert[9][9][9]; // {x, y, moegliche zahlen zum eintragen}
   int position[3] = {0,0,0};
   int moegliche = 0;
   int laufvar = 0;
   for (int y = 0; y < 9; y++) { // Zurücksetzen der Vars
      for (int x = 0; x < 9; x++) {
         for (int zahl = 0; zahl < 9; zahl++) {
            probiert[x][y][zahl] = 0;
         }
      }
   }
   do {
      laufvar ++; // Abbruch falls nach n schritten keine Lösung gefunden wurde.
      for (int y = 0; y < 9; y++) {
         for (int x = 0; x < 9; x++) {
            for (int zahl = 1; zahl < 10; zahl++) { // Durchprobierten ob diese Zahl in der Zelle möglich wäre.
               if (matrix[Raetsel][x][y] == 0) {
                  matrix[Raetsel][x][y] = zahl;
                  gueltigeEingabe(x,y,zahl);
                  if(geht[0] != true || geht[1] != true || geht[2] != true) {
                     matrix[Raetsel][x][y] = 0;
                     probiert[x][y][zahl - 1] = 0;
                  }else{
                     matrix[Raetsel][x][y] = 0;
                     probiert[x][y][zahl - 1]++;
                  }
               }
            }
         }
      }
      for (int y = 0; y < 9; y++) {
         for (int x = 0; x < 9; x++) {
            moegliche = 0;
            for (int zahl = 1; zahl < 10; zahl++) {
               if(probiert[x][y][zahl - 1] > 0) { // Sehen wie viele mögliche Zahlen für diese Zelle vorhanden sind
                  moegliche++;
                  position[0] = x;
                  position[1] = y;
                  position[2] = zahl;
               }
            }
            if (moegliche == 1) { // Falls in der Zelle nur eine Zahl stehen kann wird diese eingetragen.
               printf(" .");
               matrix[Raetsel][position[0]][position[1]] = position[2];
            }
         }
      }

      for (int y = 0; y < 9; y++) { // Zurücksetzen der Vars
         for (int x = 0; x < 9; x++) {
            for (int zahl = 0; zahl < 0; zahl++) {
               probiert[x][y][zahl] = 0;
            }
         }
      }
      printf("\n");
   } while(fertig() == false && laufvar < 10);
   printf("\n" );
   if (laufvar >= 10) {
     printf("nicht l\x94sbar\n");
   }
}

int main() {
   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   Raetsel = 0;
   printf("Sudoku:\nR\204tsel w\204hlbar von 1 bis 4.\nAngeben von Spalte und Zeile, danach Zahl.\nZum l\224sen 20 eingeben.\n");
   do {
     printf("R\204tsel: ");
     scanf("%i", &Raetsel);
   } while(Raetsel < 1 || Raetsel > 4);
   Raetsel--;
   uebertragRaetsel();
   do {
      displayGame();
      eingabeAbfragen();
   } while(fertig() == false);
   printf("\n\n - - Herzlichen Gl\201ckwunsch - - \n");
   displayGame();
   printf("\nSpiel beendet\n");
   return 0;
}
