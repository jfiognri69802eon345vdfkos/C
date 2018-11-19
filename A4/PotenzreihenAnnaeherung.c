/*
 * Es wird der Funktionswert eines Punktes durch eine Potenzreihe angenähert.
 */
#include <stdio.h>
#include <math.h>
void Sinus(double);
void ArkusTangens(double);
void Logarithmus(double);


void Logarithmus(double eingabe){
   if (eingabe <= 2 && eingabe > 0) {
      // Variablen deklarieren
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
         printf("%3d -> %3.25f - %3.9f %%\n", i, gesamtErgebnis, ((ergebnis - gesamtErgebnis)/ergebnis)*100);
      }
      printf("\n");
      printf("Das Ergebnis vom nat\x81rlicher Logarithmus von %.5e betr\x84gt %.5e\n", eingabe, gesamtErgebnis);
   } else {
      printf("Au\xE1 erhalb vom Eingabebereich \x28 0, 2 \x5D vom Logarithmus\n");
   }
} /* Logarithmus */

void ArkusTangens(double eingabe){
   if (eingabe <= 1 && eingabe >= -1) {
      // Variablen deklarieren
      double ergebnis = atan(eingabe);
      double vorherigerWert = eingabe;
      double gesamtErgebnis = vorherigerWert;
      double gesamtErgebnisvorher = gesamtErgebnis - 1;
      printf("Start\n\n");
      printf("Durchlauf   Zwischenergebnis         Abweichung\n");
      for (int i = 1; gesamtErgebnisvorher != gesamtErgebnis && i < 1000; i++) { // Schleife läuft bis genau genug oder zu lange
         gesamtErgebnisvorher = gesamtErgebnis; // Update des vorherigen Ergebnisses
         vorherigerWert = (-vorherigerWert)*(eingabe*eingabe); // VorherigenWert aktualisieren
         gesamtErgebnis += vorherigerWert/(2*i + 1); // Ergebnisse aufsummieren
         printf("%3d -> %3.25f - %3.9f %%\n", i, gesamtErgebnis, ((ergebnis - gesamtErgebnis)/ergebnis)*100);
      }

      printf("\n");
      printf("Das Ergebnis vom Arkustangens von %.5e betr\x84gt %.5e\n", eingabe, gesamtErgebnis);
   } else {
      printf("Au\xE1 erhalb vom Eingabebereich \x5B\x2D 1, 1 \x5D vom Arkustangens\n");
   }
}


void Sinus(double eingabe){
   // Variablen deklarieren
   double ergebnis = sin(eingabe);
   double vorherigerWert = eingabe;
   double gesamtErgebnis = vorherigerWert;
   double gesamtErgebnisvorher = gesamtErgebnis - 1;
   printf("Start\n\n");
   printf("Durchlauf   Zwischenergebnis         Abweichung\n");
   for (int i = 1; gesamtErgebnisvorher != gesamtErgebnis && i < 1000; i++) { // Schleife läuft bis genau genug oder zu lange
      gesamtErgebnisvorher = gesamtErgebnis; // Update des vorherigen Ergebnisses
      vorherigerWert = (-vorherigerWert)*(eingabe*eingabe)/((2*i + 1)*(2*i)); // VorherigenWert aktualisieren
      gesamtErgebnis += vorherigerWert; // Ergebnisse aufsummieren
      printf("%3d -> %.25f - %3.9f %%\n", i, gesamtErgebnis, ((ergebnis - gesamtErgebnis)/ergebnis)*100);
   }
   printf("\n");
   printf("Das Ergebnis vom Sinus von %.5e betr\x84gt %.5e\n", eingabe, gesamtErgebnis);
} /* Sinus */

int main() {
   double eingabe = M_PI/8.0; // Eingabewert
   Sinus(eingabe);
   ArkusTangens(eingabe);
   Logarithmus(eingabe);
   return 0;
}
