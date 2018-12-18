#include <stdio.h>
#include <stdlib.h>

struct student {
   char Vorname[50];
   char Name[50];
   int matrikel;
   char adresse[100];
   short int kurs;
};

int main() {
   struct student array[3] = {{"Anna", "Musterfrau", 22222, "Am Schwarzenberg-Campus 3", 4},
                              {"Hans", "Peter", 44444, "Kasernenstrasse 12", 2},
                              {"Lisa", "Lustig", 66666, "Denickestrasse 15", 8}};
   // strcpy(array[0].Vorname, "Vorname");
   printf("   | Vorname        | Nachname       | Matrikelnummer | Adresse                      | Pflichtkurse |\n");
   printf("---+----------------+----------------+----------------+------------------------------+--------------+\n");
   for (int i = 0; i < 3; i++) {
     printf("%2d |", i);
     printf(" %14s | %14s | %14d | %28s | %12d |\n", array[i].Vorname, array[i].Name, array[i].matrikel, array[i].adresse, array[i].kurs);
   }
   return 0;
}
