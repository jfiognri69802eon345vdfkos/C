/*
 * Annäherung an die Eulersche Zahl.
 */
#include <stdio.h>
#include <stdint.h>

int main() { // Start des Programms
   uint16_t zaehler = 0; // Variablen deklarieren.
   double fakultaetsSpeicher = 1.0;
   double ergd = 0.0;
   double ergvorherd = 0.0;
   printf("Double Ann\x84herung\n");
   printf("Nr.    Zahl                          Fakult\x84t der Nr.\n"); // Header für Übersichtlichkeit
   do { // Diese Schleife läutf solange durch bis sich die gespeicherte Zahl nicht mehr ändert.
      ergvorherd = ergd; // Wert des vorherigen Durchlaufs in eine Andere Variable speichern.
      ergd = ergd + (1.0/fakultaetsSpeicher); // Summenbildung wird weiter gerechnet.
      printf("%2d: %2.25f -> %20.1f\n", zaehler, ergd, fakultaetsSpeicher); // Ausgabe des aktuell Berechneten.
      zaehler++; // Runden Zähler wird immer +1 gerechnet.
      fakultaetsSpeicher = fakultaetsSpeicher * zaehler; // Fakultät wird weiter geführt. Ohne bei jedem Schleifendurchlauf neu zurechnen.
   } while(ergvorherd != ergd); // Am Schleifenende wird die Bedingung überprüft.

   printf("\nDie Eulersche Zahl als Doubleann\x84herung ist ca. %2.20f\nnach %d Schritten. Eigentliche Zahl: 2,71828182845904523536028747135266249775724709369995...\n", ergvorherd, (zaehler - 2)); // Ausgebe des Endergebnisses.
   printf("\n\nFloat Ann\x84herung\n"); // Nächste berechnung
   zaehler = 0;
   fakultaetsSpeicher = 1.0;
   float ergf = 0.0;
   float ergvorherf = 0.0;
   printf("Nr.    Zahl                          Fakult\x84t der Nr.\n"); // Header für Übersichtlichkeit
   do { // Diese Schleife läutf solange durch bis sich die gespeicherte Zahl nicht mehr ändert.
      ergvorherf = ergf; // Wert des vorherigen Durchlaufs in eine Andere Variable speichern.
      ergf = ergf + (1.0/fakultaetsSpeicher); // Summenbildung wird weiter gerechnet.
      printf("%2d: %2.25f -> %20.1f\n", zaehler, ergf, fakultaetsSpeicher); // Ausgabe des aktuell Berechneten.
      zaehler++; // Runden Zähler wird immer +1 gerechnet.
      fakultaetsSpeicher = fakultaetsSpeicher * zaehler; // Fakultät wird weiter geführt. Ohne bei jedem Schleifendurchlauf neu zurechnen.
   } while(ergvorherf != ergf); // Am Schleifenende wird die Bedingung überprüft.

   printf("\nDie Eulersche Zahl als Floatann\x84herung  ist ca. %2.20f\nnach %d Schritten. Eigentliche Zahl: 2,71828182845904523536028747135266249775724709369995...\n", ergvorherf, (zaehler - 2)); // Ausgebe des Endergebnisses.

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0); // Programm hatte keine internen Fehler.
}
