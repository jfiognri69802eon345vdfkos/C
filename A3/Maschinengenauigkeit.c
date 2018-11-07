/*
 * Annäherung an eine Zahl die nicht diese Zahl ist.
 * Hier bei wird probiert bis die Genauigkeit nicht mehr ausreicht.
 */
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
   // Variablen deklarieren
   int16_t potenz = 2;
   int16_t soll = 1;
   double erg = 0.0;
   double ergvorher = 0.0;
   printf("  double  \n");
   printf("Potenz    1+ (2^Potenz / 2)\n"); // Kopfzeile was die Spalten bedeuten.
   do {
      ergvorher = erg;
      potenz--; // Potenz wird immer um 1 verringert.
      erg = 1 + pow(2, potenz)/2; // Berechnung von 1 + sehr klein
      printf("%5d -> %2.25f\n", potenz, erg);
   } while(erg > soll); // Die Schleife läuft so lange bis man keine kleinere Zahl nahe 1 mehr darstellen kann.
   printf("kleinste Zahl vor %d die Darstellbar ist mit double ist: %2.20f\n", soll, ergvorher);

   potenz = 2; // zurücksetzen der Variable
   printf("\n\n  float  \n");
   float ferg = 0.0;
   float fergvorher = 0.0; // Variablen für float definieren.
   printf("Potenz    1+ (2^Potenz / 2)\n"); // Kopfzeile was die Spalten bedeuten.
   do {
      fergvorher = ferg;
      potenz--; // Potenz wird immer um 1 verringert.
      ferg = 1 + pow(2, potenz)/2; // Berechnung von 1 + sehr klein
      printf("%5d -> %2.25f\n", potenz, ferg);
   } while(ferg > soll); // Die Schleife läuft so lange bis man keine kleinere Zahl nahe 1 mehr darstellen kann.
   printf("kleinste Zahl vor %d die Darstellbar ist mit float ist: %2.20f\n", soll, fergvorher);
   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
