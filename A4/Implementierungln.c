/*
 * Es wird der natürliche Logarithmus eines Punktes durch eine Potenzreihe angenähert.
 */
#include <stdio.h>
#include <math.h>

int main() {
   // Variablen deklarieren
   double eingabe = M_PI/8; // Eingabewert x ∈ (0,2]
   double ergebnis = log(eingabe);
   double potenz = eingabe-1;
   double potenzreihe = potenz;
   double gesamtErgebnis = eingabe - 1;
   double gesamtErgebnisvorher = gesamtErgebnis - 1;
   int vorzeichen = 1;
   printf("Start\n\n");
   printf("Durchlauf   Zwischenergebnis         Abweichung\n");
   for (int i = 2; gesamtErgebnisvorher != gesamtErgebnis && i < 1000; i++) { // Schleife läuft bis genau genug oder zu lange
      gesamtErgebnisvorher = gesamtErgebnis; // Update des vorherigen Ergebnisses
      if (vorzeichen == 1) { // Vorzeichenwechsel für jeden Durchlauf
         vorzeichen = -1;
      }else{
         vorzeichen = 1;
      }
      potenzreihe *= potenz; // VorherigenWert aktualisieren
      gesamtErgebnis += vorzeichen*potenzreihe/i; // Ergebnisse aufsummieren
      printf("%3d -> %3.25f - %2.9f %%\n", i, gesamtErgebnis, ((ergebnis - gesamtErgebnis)/ergebnis)*100);
   }
   printf("\n");
   printf("Das Ergebnis vom nat\x81rlicher Logarithmus von %.5e betr\x84gt %.5e\n", eingabe, gesamtErgebnis);
   printf("\n\nProgramm beendet\n"); // Programmende ausgeben
   return(0);
}
