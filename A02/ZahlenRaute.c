/*
 * EineZahlenrautemitdergrößtenZahlNinderMitte.
 */
#include <stdio.h>
#include <stdint.h>

int main(void){
   uint16_t N = 4; // Mittere Zahl
   int8_t ZIDR; // Zahlen in der Reihe
   int8_t ZL = 2*N - 1; // Zeilenlänge
   int8_t ZB; // Zählbeginn für die Reihe
   int8_t ZZ = 0; // Zeilenzähler
   int8_t aktuelleZahl = 0; // Hilfsvariabel hält den Wert der aktuell berechneten Zahl.

   // Schleife zur Darstellung aller Rauten Möglichkeiten
   for (int8_t r = 1; r < 10; r++) {
      N = r; // Zurücksetzen von den Variablen oder deren Neuberechnung.
      ZL = 2*N - 1;
      ZZ = 0;
      aktuelleZahl = 0;
      printf("Das ist die Zahlenraute f\x81r N = %d\n\n",N); // Ausgabe vondem was berechnet werden soll.

      //Kopfzeile für die Raute
      printf("    ");
      for(int8_t i = 1; i <= ZL; i++) {
         if (i > 9) { // Unterschiedliche Anzahl an Leerzeichen, damit alles in einer Linie steht.
            printf("%d",i);
         }else{
            printf("%d ",i);
         }
      }
      printf("\n\n");

      //Inhalt der Raute
      for(uint8_t y = 1; y < 2*N; y++) { // Schleife für die Zeilen
         ZIDR = (y - 1)*2 + 1;
         ZB = (ZL - ZIDR)/2;
         if (y > 9) { // Unterschiedliche Anzahl an Leerzeichen, damit alles in einer Linie steht.
            printf("%d  ",y);
         }else{
            printf("%d   ",y);
         }
         ZZ = (y - ZB);
         if(ZZ > (ZIDR/2) + 1) { // Verschiebung des Zählstarts nach der Hälfte
            ZZ = (2*(y - N));
         }else{
            ZZ = 0;
         }
         for(uint8_t x = 1; x < 2*N; x++) { // Schleife für die Spalten
            aktuelleZahl = (x - ZB); // Start berechnen

            if(aktuelleZahl > (ZIDR/2) + 1) { // Rückwärtszählen nach der Hälfte
               aktuelleZahl = aktuelleZahl - (2*(x - N));
            }
            aktuelleZahl -= ZZ; // Abziehen falls y über der Hälfte

            if(aktuelleZahl > 0) { // Zahl ausgeben oder...
               printf("%d ",aktuelleZahl);
            }else{ // Leerstelle
               printf("  ");
            }
         }
         printf("\n"); // Neue Zeile nach jeder Spalte
      }
      printf("\n\n"); // Viel Platz für die Überschrift des nächsten Durchlaufs.
   }
   printf("\n\nProgrammbeendet\n"); // Programmendeausgeben
   return(0);
}
