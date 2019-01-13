/*
 * Es wird der Sinuswert eines Punktes durch eine Potenzreihe angenähert.
 */
#include <stdio.h>
#include <math.h>

int main() {
   // Variablen deklarieren
   double eingabe = M_PI/2.0; // Eingabewert
   double ergebnis = sin(eingabe);
   double vorherigerWert = eingabe;
   double gesamtErgebnis = vorherigerWert;
   double gesamtErgebnisvorher = gesamtErgebnis - 1;
   printf("Start\n\n");
   printf("Durchlauf   Zwischenergebnis         Abweichung\n");
   for (int i = 1; gesamtErgebnisvorher != gesamtErgebnis && i < 1000; i++) { // Schleife läuft bis genau genug oder zu lange
      gesamtErgebnisvorher = gesamtErgebnis; // Update des vorherigen Ergebnisses
      vorherigerWert = (-vorherigerWert)*(eingabe*eingabe)/((2*i + 1)*(2*i)); // VorherigenWert aktualisieren
      gesamtErgebnis += vorherigerWert; // Ergebnisse aufsummieren
      printf("%3d -> %.25f - %2.2f %%\n", i, gesamtErgebnis, ((ergebnis - gesamtErgebnis)/ergebnis)*100);
   }

   printf("\n");
   printf("Das Ergebnis vom Sinus von %.5e betr\x84gt %.5e\n", eingabe, gesamtErgebnis);
   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
