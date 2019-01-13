#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   char Vorname[51];
   char Name[51];
   int matrikel;
   char adresse[101];
   short int kurs;
};

void ausgabe(struct student array[]) { // Ausgeben von der Struktur als Tabelle
   printf("   | Vorname        | Nachname       | Matrikelnummer | Adresse                      | Pflichtkurse |\n");
   printf("---+----------------+----------------+----------------+------------------------------+--------------+\n");
   for (int i = 0; i < 3; i++) {
      printf("%2d |", i);
      printf(" %14s | %14s | %14d | %28s | %12d |\n", array[i].Vorname, array[i].Name, array[i].matrikel, array[i].adresse, array[i].kurs);
   }
   printf("\n");
}

void zeilenTausch(struct student*array, int zeile, int nach) { // Tauschen von 2 Zeilen
   struct student zwischen;
   strcpy(zwischen.Vorname, array[zeile].Vorname); // Zwischenspeichern der Werte
   strcpy(zwischen.Name, array[zeile].Name);
   zwischen.matrikel = array[zeile].matrikel;
   strcpy(zwischen.adresse, array[zeile].adresse);
   zwischen.kurs = array[zeile].kurs;

   strcpy(array[zeile].Vorname, array[nach].Vorname); // Überschreiben von der vorherigen Zeile
   strcpy(array[zeile].Name, array[nach].Name);
   array[zeile].matrikel = array[nach].matrikel;
   strcpy(array[zeile].adresse, array[nach].adresse);
   array[zeile].kurs = array[nach].kurs;

   strcpy(array[nach].Vorname, zwischen.Vorname); // Aus dem Zwischenspeicher die werte zurück eintragen
   strcpy(array[nach].Name, zwischen.Name);
   array[nach].matrikel = zwischen.matrikel;
   strcpy(array[nach].adresse, zwischen.adresse);
   array[nach].kurs = zwischen.kurs;
}

int main() {
   struct student array[3] = {{"Anna", "Musterfrau", 22222, "Am Schwarzenberg-Campus 3", 4},
                              {"Hans", "Peter", 44444, "Kasernenstrasse 12", 2},
                              {"Lisa", "Lustig", 66666, "Denickestrasse 15", 8}};
   ausgabe(array);
   zeilenTausch(array, 0, 2);
   ausgabe(array);

   return 0;
}
