/*
 * Annäherung an die Eulersche Zahl.
 */
#include <stdio.h>
#include <stdint.h>

int main() { // Start des Programms
   uint16_t zaehler = 0; // Variablen deklarieren.
   double fakultaetsSpeicher = 1.0;
   double eigentlicheZahl = 2.71828182845904523536028747135266249775724709369995;
   double ergd = 0.0;
   double ergvorherd = 0.0;
   printf("Double Ann\x84herung\n");
   printf("Nr.    Zahl                          Fakult\x84t der Nr.     Ungenauigkeit\n"); // Header für Übersichtlichkeit
   do { // Diese Schleife läutf solange durch bis sich die gespeicherte Zahl nicht mehr ändert.
      ergvorherd = ergd; // Wert des vorherigen Durchlaufs in eine Andere Variable speichern.
      ergd = ergd + (1.0/fakultaetsSpeicher); // Summenbildung wird weiter gerechnet.
      printf("%2d: %2.25f -> %20.1f - %3.2f \n", zaehler, ergd, fakultaetsSpeicher, ((eigentlicheZahl-ergd)/eigentlicheZahl)*100); // Ausgabe des aktuell Berechneten.
      zaehler++; // Runden Zähler wird immer +1 gerechnet.
      fakultaetsSpeicher = fakultaetsSpeicher * zaehler; // Fakultät wird weiter geführt. Ohne bei jedem Schleifendurchlauf neu zurechnen.
   } while(ergvorherd != ergd); // Am Schleifenende wird die Bedingung überprüft.

   printf("\nDie Eulersche Zahl als Doubleann\x84herung ist ca. %2.20f\nnach %d Schritten. Eigentliche Zahl: 2,71828182845904523536028747135266249775724709369995...\nGespeicherte Zahl: %2.20f\n", ergvorherd, (zaehler - 2), eigentlicheZahl); // Ausgebe des Endergebnisses.

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0); // Programm hatte keine internen Fehler.
   
}
