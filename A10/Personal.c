#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
   char Name[51];
   short Alter;
   char Geschlecht;
   struct Person*next;
};

struct Person*neuer_Person(struct Person*ptr_Liste_oben, struct Person*ptr_neues_Element) {
   ptr_neues_Element->next = ptr_Liste_oben;
   return ptr_neues_Element;
}

void PersonAusgeben(struct Person*ptr_Liste_oben) {
   int i = 0;
   while(ptr_Liste_oben != NULL) {
      i++;
      printf(" %3d) Person %p\n", i, ptr_Liste_oben);
      printf("|-> Name:       %s\n", ptr_Liste_oben->Name);
      printf("|-> Alter:      %d\n", ptr_Liste_oben->Alter);
      printf("|-> Geschlecht: %c\n", ptr_Liste_oben->Geschlecht);
      ptr_Liste_oben = ptr_Liste_oben->next;
   }
}


int main(int argc, char const*argv[]) {
   struct Person Person1;
   Person1.next = NULL;
   strcpy(Person1.Name, "Person1");
   Person1.Alter = 10;
   Person1.Geschlecht = 'm';
   struct Person Person2;
   strcpy(Person2.Name, "Person2");
   Person2.Alter = 20;
   Person2.Geschlecht = 'w';
   neuer_Person(&Person1, &Person2);
   struct Person Person3;
   strcpy(Person3.Name, "Person3");
   Person3.Alter = 30;
   Person3.Geschlecht = 'm';
   neuer_Person(&Person2, &Person3);
   PersonAusgeben(&Person3);
   return 0;
}
