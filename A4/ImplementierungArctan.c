/*
 * Es wird der Arcustangenswert eines Punktes durch eine Potenzreihe angenähert.
 */
#include <stdio.h>
#include <math.h>

int main() {
   // Variablen deklarieren
   double eingabe = M_PI/8; // Eingabewert
   double vorherigerWert = eingabe;
   double gesamtErgebnis = vorherigerWert;
   double gesamtErgebnisvorher = gesamtErgebnis-1;
   printf("Start\n\n");

   for (int i = 1; gesamtErgebnisvorher != gesamtErgebnis; i++) {
     gesamtErgebnisvorher = gesamtErgebnis;
     vorherigerWert = (-vorherigerWert)*(eingabe*eingabe);
     gesamtErgebnis += vorherigerWert/(2*i+1);
     printf("%3d -> %3.25f\n", i, gesamtErgebnis);
   }

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
