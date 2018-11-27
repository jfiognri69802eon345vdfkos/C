#include <stdio.h>
#include <stdlib.h>

const int SUDOKU[9][9] =  //besser als #define, da typsicher
{
   {0,1,2,0,0,0,5,7,0},
   {6,0,0,5,0,1,0,0,4},
   {4,0,0,0,2,0,0,0,8},
   {0,2,0,0,1,0,0,5,0},
   {0,0,4,9,0,7,8,0,0},
   {0,7,0,0,8,0,0,1,0},
   {7,0,0,0,9,0,0,0,5},
   {5,0,0,4,0,8,0,0,6},
   {0,3,8,0,0,0,9,4,0}
};
int FELD[9][9];//Spielfeld

/*regelchek �berpr�ft die 3 Regeln des Sudoku.
   Sobald eine gebrochen wird, gibt das Programm eine dementsprechende Fehlermeldung aus.
 */
int regelcheck (int lul)
{
   for(int wert = 1; wert <= 9; wert++)
   {
      int spz[9] = {0,0,0,0,0,0,0,0,0};  //spaltenz�hler
      int qdz[3][3] = {{0,0,0},{0,0,0},{0,0,0}};  //quadratz�hler
      for(int zeile = 0; zeile < 9; zeile++) { //initialisierung zeile
         int zlz = 0;                          //zeilenz�hler
         for(int spalte = 0; spalte < 9; spalte++) {//initialisierung spalte
            if(FELD[zeile][spalte] == wert) {    //�berpr�ft
               if(++zlz > 1) {                   //Aufkommen in der Zeile
                  if(lul) {
                     printf("Fehler in Zeile %d, Spalte %d. %d kommt in dieser Zeile mehr als ein mal vor!\n",zeile + 1,spalte + 1,wert);
                  }
                  return 0;
               }
               if(++spz[spalte] > 1) {           //�berpr�ft Aufkommen in der Spalte
                  if(lul) {
                     printf("Fehler in Zeile %d, Spalte %d. %d kommt in dieser Spalte mehr als ein mal vor!\n",zeile + 1,spalte + 1,wert);
                  }
                  return 0;
               }
               if(qdz[zeile / 3][spalte / 3] > 1) { //�berpr�ft Aufkommen im 3x3 Quadrat
                  if(lul) {
                     printf("Fehler in Zeile %d, Spalte %d. %d kommt in diesem Quadrat mehr als ein mal vor!\n", zeile + 1,spalte + 1,wert);
                  }
                  return 0;
               }
            }
         }
      }
   }
   return 0;
}

void description()
{
    printf("**********************************************************\n");
    printf("*                        SUDOKU                          *\n");
    printf("*      Geben Sie Zeile, Spalte und Ziffer ein.           *\n");
    printf("*      Bsp. : 123 f\x81r Zeile 1, Spalte 2, Eingabe 3.      *\n");
    printf("*      Zum beenden geben Sie bitte 1337 ein.             *\n");
    printf("*                                                        *\n");
    printf("**********************************************************\n\n\n");
/*  L�sung:
    |9|1|2|8|4|6|5|7|3|
    |6|8|3|5|7|1|2|9|4|
    |4|5|7|3|2|9|1|6|8|
    |8|2|9|6|1|3|4|5|7|
    |1|6|4|9|5|7|8|3|2|
    |3|7|5|2|8|4|6|1|9|
    |7|4|6|1|9|2|3|8|5|
    |5|9|1|4|3|8|7|2|6|
    |2|3|8|7|6|5|9|4|1|
*/
}

/*feld_ausgabe gibt das Feld, inklusive Zeilen und Spaltenangaben aus*/
void feld_ausgabe(){
   printf("    1  2  3   4  5  6   7  8  9 \n");
   printf("  +---------+---------+---------+\n");

   for(int zeile = 0; zeile < 9; zeile++) { //Gibt Feld aus
      printf("%d |", zeile + 1);
      /*Gibt ein zuvor mit 0 gef�lltes Feld als leeres Feld aus oder druckt die vordefinierte Zahl*/
      for(int spalte = 0; spalte < 9; spalte++) {
         if(FELD[zeile][spalte] == 0) {
            printf("   ");
         }       else{
            printf(" %d ", FELD[zeile][spalte]);
         } /*Spalten/Quadratbegrenzung*/
         if((spalte + 1) % 3 == 0) {
            printf("|");
         }
      } /*Zeilen/Quadratbegrenzung*/
      printf("\n");
      if((zeile + 1) % 3 == 0) {
         printf("  +---------+---------+---------+\n");
      }
   }
}


int main()
{
   for(int zeile = 0; zeile < 9; zeile++) {
      for(int spalte = 0; spalte < 9; spalte++) {
         FELD[zeile][spalte] = SUDOKU[zeile][spalte];
      }
   }
   description();
   feld_ausgabe();
   printf("Eingabe: \n");

   int eingabe = 0;
   char puffer[100];
   while(1) { //Schleife mit definiertem Ende
      fgets(puffer, 100, stdin);
      sscanf(puffer, "%d", &eingabe);
      if(eingabe == 1337) { //Abbruchbedingung
         break;   //Abbruch
      }
      /*Pr�ft ob der eingegebene Wert in Ordnung ist. (zwischen 111 und 999*/
      int zeile  = (eingabe % 1000) / 100;//Pr�ft Zeile 1-9
      int spalte = (eingabe % 100) / 10; //Pr�ft Spalte 1-9
      int wert   = (eingabe % 10);       //Pr�ft den Wert/ die Ziffer
      if((eingabe > 999) || (eingabe < 111) || (zeile == 0) || (spalte == 0)) {
         feld_ausgabe();
         printf("Fehlerhafte Eingabe!\nEingabe:\n");
         continue;
      }
      /*Pr�ft nachdem der Wert als g�ltig Erkannt wurde, ob er in das angegebene Feld einsetzbar ist
         Z.B. k�nnte das Feld bereits gef�llt sein*/
      if (SUDOKU[zeile - 1][spalte - 1] != 0) {
         feld_ausgabe();
         printf("Sie d\201rfen in Feld %d %d nichts eintragen!\nEingabe:\n",zeile,spalte );
      }
      FELD[zeile - 1][spalte - 1] = wert;
      feld_ausgabe();
      if(regelcheck(1)) {
         printf("\n\nEingabe: \n");
         return 0;
      }

   }
   printf("Sie haben das Spiel beendet.\n");
   return 0;
}
