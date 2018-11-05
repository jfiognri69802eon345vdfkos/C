/*
 * Zur Ermittlung des größten gemeinsamen Teilers wird der klassische Euklidische Algorithmus verwendet.
 */
#include <stdio.h>
#include <stdint.h>

int main() {
   // Variablen deklarieren
   float a = 18.0;
   float b = 12.0;
   float erg = 0.0;
   float diff = 0.0;
   printf("%3.1f / %3.1f\n", a, b);
   do {
      diff = a - b; // die absoluten Distanz wird berechnet.
      if (diff < 0) {
         diff *= (-1);
      }

      if (a > b) { // Die größere Zahl wird durch die Differenz ersetzt
         a = diff;
      } else {
         b = diff;
      }
   } while(a != 0 && b != 0); // Die Schleife läutf solange bis eine der Zahlen = null ist.

   if (a == 0) { // Die Zahl die nicht null ist, ist dann das Ergebniss.
      erg = b;
   }else{
      erg = a;
   }
   printf("Der gr\x94\xE1te gemeinsame Teiler ist: %f\n", erg);

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
