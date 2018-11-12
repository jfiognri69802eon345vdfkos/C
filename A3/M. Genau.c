#include <stdio.h>
#include <stdlib.h>

int main(){
   double e = 2.0;

   do {
      e = e / 2;
   } while (1 + (e) > 1); // Hier sollte man nicht noch mal teilen, da es sonst nicht im Ergebnis berücksichtigt wird.
   printf("%e", e);

   return (0);
}
