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
   printf("Potenz    1+ (2^Potenz / 2)\n"); // Kopfzeile was die Spalten bedeuten.
   do {
      potenz--; // Potenz wird immer um 1 verringert.
      erg = 1 + pow(2, potenz)/2; // Berechnung von 1 + sehr klein
      printf("%5d -> %2.25f\n", potenz, erg);
   } while(erg > soll); // Die Schleife läuft so lange bis man keine kleinere Zahl nahe 1 mehr darstellen kann.
   printf("kleinste Zahl vor %d die Darstellbar ist ist: %2.20f\n", soll, (1 + pow(2, potenz + 1)/2));

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
