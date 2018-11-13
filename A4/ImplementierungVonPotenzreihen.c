/*
 * Es werden Trigonometrischefunktionen durch Potenzreihen angenähert.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t fakultaet(uint16_t zahl){
   uint32_t erg = 1;
   for (uint16_t i = 2; i <= zahl; i++) {
      erg *= i;
   }
   return erg;
}

double power(double basis, int16_t exponent){
   double erg;
   bool minus = false;
   if (exponent != 0) {
      erg = basis;
      if (exponent < 0) {
         exponent *= (-1);
         minus = true;
      }
      for (int16_t i = 1; i < exponent; i++) {
         erg *= basis;
      }
      if(minus) {
         erg = 1/erg;
      }
      return erg;
   }
   return 1.0;
}

double sinus(double input){
   uint32_t k = 0;
   double erg = 0;
   double ergvorher = 0;
   int8_t vorzeichen = -1;
   do {
      if (vorzeichen > 0) {
         vorzeichen = -1;
      }else{
         vorzeichen = 1;
      }
      ergvorher = erg;
      erg += vorzeichen * (power(input, 2*k + 1)/fakultaet(2*k + 1));
      k ++;
      printf("%5.20f\n", erg);
   } while(ergvorher != erg && k < 30);
   return erg;
}

int main() {
   // Variablen deklarieren
   float x = 1.6;
   printf("Start\n");

   printf("Sinus %f\n", sinus(x));

   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
