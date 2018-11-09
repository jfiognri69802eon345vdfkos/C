/*
 * Zur Ermittlung des größten gemeinsamen Teilers wird der modere Euklidische Algorithmus verwendet.
 */
#include <stdio.h>
#include <stdint.h>
uint16_t modulo(uint16_t, uint16_t);
uint16_t modulo_schnell(uint16_t, uint16_t);

uint16_t modulo(uint16_t divident, uint16_t divisor){ // Funktion für den Moduloopperator
   if (divident >= divisor) { // wenn der Divident größer als der Divisor ist lässt es sich mindestens 1 mal teilen.
      do {
         divident = divident - divisor; // abziehen vom Divisor
      } while(divident >= divisor); // bis nicht mehr teilbar
   }
   return divident; // Rest zurückgeben
}

uint16_t modulo_schnell(uint16_t divident, uint16_t divisor){
  if (divident >= divisor) { // wenn der Divident größer als der Divisor ist lässt es sich mindestens 1 mal teilen.
     int zahl = divident / divisor; // Nur den ganzzahligen Anteil beachten.
     divident = divident - divisor * zahl; // Rest berechnen, durch Abziehen von dem ganzzahlig teilbarem.
  }
  return divident; // Rest zurückgeben
}

int main() {
   // Variablen deklarieren
   uint16_t a = 44;
   uint16_t b = 12;
   uint16_t diff = 0;
   printf("%d / %d\n", a, b); // Ausgabe von welcher Aufgabe das Ergebnis kommt.
   do {
      diff = modulo_schnell(a, b); // Der Rest der Division von a/b wird berechnet.
      a = b;
      b = diff;
   } while(b != 0); // Die Schleife läutf solange bis eine der Zahlen = null ist.

   printf("Der gr\x94\xE1te gemeinsame Teiler ist: %d\n", a); // Ausgabe des ggT

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
