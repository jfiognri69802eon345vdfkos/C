#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Types {
   char buchstabe;
   short kurzeZahl;
   long langeZahl;
   double fliesskommaZahl;
   struct Types*next;
};

struct Types*neuer_Types(struct Types*ptr_Liste_oben, struct Types*ptr_neues_Element) {
   ptr_neues_Element->next = ptr_Liste_oben;
   return ptr_neues_Element;
}

void TypesAusgeben(struct Types*ptr_Liste_oben) {
   int i = 0;
   while(ptr_Liste_oben != NULL) {
      i++;
      printf(" %3d) Types %p\n", i, ptr_Liste_oben);
      printf("|-> %p char\n", &ptr_Liste_oben->buchstabe);
      printf("|-> %p short\n", &ptr_Liste_oben->kurzeZahl);
      printf("|-> %p long\n", &ptr_Liste_oben->langeZahl);
      printf("|-> %p double\n", &ptr_Liste_oben->fliesskommaZahl);
      ptr_Liste_oben = ptr_Liste_oben->next;
   }
}


int main(int argc, char const*argv[]) {
   struct Types Types1;
   Types1.next = NULL;
   struct Types Types2;
   neuer_Types(&Types1, &Types2);
   struct Types Types3;
   neuer_Types(&Types2, &Types3);
   TypesAusgeben(&Types3);
   return 0;
}
