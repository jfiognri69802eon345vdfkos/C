/*
 * Es werden Trigonometrischefunktionen durch Potenzreihen angenähert.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
double sinus(double);
double power(double, int16_t);
uint32_t fakultaet(uint16_t);

uint32_t fakultaet(uint16_t zahl){ // Fakultät einer Zahl
   uint32_t erg = 1; // Variable für das Ergebnis
   for (uint16_t i = 2; i <= zahl; i++) { // Solange die Laufvariable <= dem Ergebnis ist
      erg *= i; // Laufvariable mit dem vorherigen Wert multiplizieren.
   }
   return erg; // Rückgabe ses Ergebnisses
}

double power(double basis, int16_t exponent){ // basis ^ exponent
   double erg; // Lokale Variable Ergebnis
   bool minus = false; // Lokale Variable Vorzeichen
   if (exponent != 0) { // Falls der Exponent null ist, dann ist das Ergebnis immer 1
      erg = basis;
      if (exponent < 0) { // Überprüfen ob der Exponent negativ ist.
         exponent *= (-1);
         minus = true;
      }
      for (int16_t i = 1; i < exponent; i++) {
         erg *= basis;
      }
      if(minus) { // Hoch eine negative Zahl: 1/(basis ^ exponent)
         erg = 1/erg;
      }
      return erg; // Rückgabe des Ergebnisses
   }
   return 1.0; // Falls Exponent == 0
}

double sinus(double input){ // Funktion für die Sinusapproximation
   uint32_t k = 0; // Variablen deklarieren
   double erg = 0.0;
   double ergvorher = 0.0;
   int8_t vorzeichen = -1;
   do {
      if (vorzeichen > 0) { // Wechselndes Vorzeichen da jeder zweite Term abgezogen werden soll.
         vorzeichen = -1;
      }else{
         vorzeichen = 1;
      }
      ergvorher = erg; // Speichern des vorherigen Wertes von erg
      erg += vorzeichen * (power(input, 2*k + 1)/fakultaet(2*k + 1)); // Berechnung des Sinus
      k ++; // Laufvariable einen Schritt weiter setzen
      printf("%5d -> %e\n", k, erg); // Zwischenergebnis ausgeben
   } while(ergvorher != erg && k < 30); // Schleife solange sich das Ergebnis ändert.
   return ergvorher; // Rückgabe des Ergebnisses
}

int main() {
   // Variablen deklarieren
   float x = 3.14159/2.0;
   printf("Start\n");

   printf("Sinus von %f ist %f\n", x, sinus(x));

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
