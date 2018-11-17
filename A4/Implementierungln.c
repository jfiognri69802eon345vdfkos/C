/*
 * Es werden Trigonometrischefunktionen durch Potenzreihen angenähert.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
double sinus(double);
double power(double, int16_t);

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

int main() {
   // Variablen deklarieren
   double eingabe = M_PI/8; // Eingabewert x ∈ (0,2]<
   double gesamtErgebnis = eingabe - 1;
   double gesamtErgebnisvorher = gesamtErgebnis - 1;
   int vorzeichen = 1;
   printf("Start\n\n");

   for (int i = 2; gesamtErgebnisvorher != gesamtErgebnis; i++) {
      gesamtErgebnisvorher = gesamtErgebnis;
      if (vorzeichen == 1) {
         vorzeichen = -1;
      }else{
         vorzeichen = 1;
      }
      gesamtErgebnis += vorzeichen*power(eingabe - 1, i)/i;
      printf("%3d -> %3.25f \n", i, gesamtErgebnis);
   }
   printf("\n");
   printf("Das Ergebnis vom nat\x81rlicher Logarithmus von %.5e betr\x84gt %.5e\n", eingabe, gesamtErgebnis);
   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
