#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Spieler {
   struct Spieler*next;
};

struct Spieler*neuer_Spieler(struct Spieler*ptr_Liste_oben, struct Spieler*ptr_neues_Element) {
   ptr_neues_Element->next = ptr_Liste_oben;
   return ptr_neues_Element;
}

void SpielerAusgeben(struct Spieler*ptr_Liste_oben) {
   int i = 0;
   while(ptr_Liste_oben != NULL) {
      i++;
      printf(" %3d) Spieler %p\n", i, ptr_Liste_oben);
      ptr_Liste_oben = ptr_Liste_oben->next;
   }
}


int main(int argc, char const*argv[]) {
   struct Spieler spieler1;
   spieler1.next = NULL;
   struct Spieler spieler2;
   neuer_Spieler(&spieler1, &spieler2);
   struct Spieler spieler3;
   neuer_Spieler(&spieler2, &spieler3);
   SpielerAusgeben(&spieler3);
   return 0;
}
