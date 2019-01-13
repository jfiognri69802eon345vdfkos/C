/*
 * Zur Ermittlung des größten gemeinsamen Teilers wird der modere Euklidische Algorithmus verwendet.
 */
#include <stdio.h>
#include <stdint.h>

int main() {
   // Variablen deklarieren
   uint16_t a = 44;
   uint16_t b = 12;
   uint16_t diff = 0;
   printf("%d / %d\n", a, b); // Ausgabe von welcher Aufgabe das Ergebnis kommt.
   do {
      diff = a % b; // Der Rest der Division von a/b wird berechnet.
      a = b;
      b = diff;
   } while(b != 0); // Die Schleife läutf solange bis eine der Zahlen = null ist.

   printf("Der gr\x94\xE1te gemeinsame Teiler ist: %d\n", a); // Ausgabe des ggT

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
