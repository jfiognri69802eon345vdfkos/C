/*
 * Interger in Binär umrechnen
 */
#include <stdio.h>
#include <stdint.h>

int main() {
   uint16_t eingabe = 15;   // Große Variable für die Eingabe.
   uint16_t msb     = 32768;// Wert des Bit 15 = 32758

   printf("\n\nF\x81r die Dezimalzahl %d \nErgebnis:\n -> ", eingabe); // Ausgabe von dem was berechnet werden soll.

   if ((eingabe > 0) && (eingabe <= ((2*msb) - 1))) { // Überprüfung ob die Eingabe gültig ist.
      for (uint8_t i = 0; i < 16; i++) {              // Schleife die für jedes Bit einmal durchläuft.
         if(eingabe >= msb) {                         // wenn Bit 15 = 1 ist dann soll eine 1 ausgegeben werden.
            printf("1 "); // Ausgabe 1
         }else{       // sonst stand dort eine 0
            printf("0 "); // Ausgabe 2
         }
         eingabe = eingabe * 2; // Shifting um eine Einheit nach links
      }
   }
   printf("\n\nProgramm beendet\n"); // Programmende ausgeben

   return(0);
}
