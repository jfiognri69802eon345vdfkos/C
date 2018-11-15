/*
 * Es wird der Sinuswert eines Punktes durch eine Potenzreihe angenähert.
 */
#include <stdio.h>

int main() {
   // Variablen deklarieren
   double eingabe = 3.14159/2.0; // Eingabewert
   double vorherigerWert = eingabe;
   double gesamtErgebnis = vorherigerWert;
   double gesamtErgebnisvorher = gesamtErgebnis-1;
   printf("Start\n\n");

   for (int i = 0; gesamtErgebnisvorher != gesamtErgebnis; i++) {
     gesamtErgebnisvorher = gesamtErgebnis;
     vorherigerWert = (-vorherigerWert)*(eingabe*eingabe)/((2*i+1)*(2*i));
     gesamtErgebnis += vorherigerWert;
     printf("%3d -> %.25f\n", i, gesamtErgebnis);
   }

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
