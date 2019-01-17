#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   char Vorname[51];
   char Name[51];
   int matrikel;
   char adresse[101];
   short int kurs;
   struct student*next;
   struct student*prev;
};

void*allocate(){ // Speicherplatz reservieren
   void*p;
   p = calloc(1, sizeof(struct student)); // Speicherplatz reservieren
   if(p == NULL) {
      printf("Memory error has successfully stop the program\n");
      exit(1); // wenn es fehl schlägt
   }
   return p;
}

struct student*neuer_Student(struct student*prev, const char vorname[51],const char name[51], int matrikelnr, const char adresse[101], int kurs){
   struct student*neuer = (struct student*)allocate();
   if(prev != NULL) {
      prev->next = neuer;
   }
   neuer->prev = prev;
   neuer->next = NULL;
   strcpy(neuer->Vorname, vorname);
   strcpy(neuer->Name, name);
   strcpy(neuer->adresse, adresse);
   neuer->matrikel = matrikelnr;
   neuer->kurs = kurs;
}

void ausgabe(struct student*start) {   // Ausgeben von der Struktur als Tabelle
   printf("   | Vorname        | Nachname       | Matrikelnummer | Adresse                      | Pflichtkurse |\n");
   printf("---+----------------+----------------+----------------+------------------------------+--------------+\n");
   int i = 0;
   while(start != NULL) {
      i++;
      printf("%2d |", i);
      printf(" %14s | %14s | %14d | %28s | %12d |\n", start->Vorname, start->Name, start->matrikel, start->adresse, start->kurs);
      start = start->next;
   }
   printf("\n");
}

void freeList(struct student*start) {
   int i = 0;
   start = start->next;
   while(start != NULL) {
      free(start->prev);
      start = start->next;
   }
   free(start);
   printf("speicher freigegeben\n");
}

struct student*zeilenTausch(struct student*start, struct student*nr1, struct student*nr2) {  // Tauschen von 2 Zeilen
   if(start == nr1) { // Start der Kette
      start = nr2;
   }else{
      if (start == nr2) { // Ende der Kette
         start = nr1;
      }
   }
   printf("Tauschen von %s und %s\n", nr1->Name, nr2->Name);
   if(nr2->next != nr1 && nr1->next != nr2) {
      if(nr1->prev != NULL) { // Zwischenelemente zuordnen
         nr1->prev->next = nr2;
      }
      if (nr1->next != NULL) {
         nr1->next->prev = nr2;
      }
      if (nr2->prev != NULL) {
         nr2->prev->next = nr1;
      }
      if (nr2->next != NULL) {
         nr2->next->prev = nr1;
      }
   }else{
      if(nr1->next == nr2) {
         if(nr1->prev != NULL) { // Zwischenelemente zuordnen
            nr1->prev->next = nr2;
         }
         if (nr2->next != NULL) {
            nr2->next->prev = nr1;
         }
      }else{
         if(nr2->next == nr1) {
            if (nr1->next != NULL) {
               nr1->next->prev = nr2;
            }
            if (nr2->prev != NULL) {
               nr2->prev->next = nr1;
            }
         }
      }
   }
   struct student*ptr_next = nr1->next;
   struct student*ptr_prev = nr1->prev;
   nr1->next = nr2->next;
   nr1->prev = nr2->prev;
   nr2->next = ptr_next;
   nr2->prev = ptr_prev;
   if(nr1->prev == nr1) {
      nr1->prev = nr2;
   }
   if(nr2->next == nr2) {
      nr2->next = nr1;
   }
   if(nr2->prev == nr2) {
      nr2->prev = nr1;
   }
   if(nr1->next == nr1) {
      nr1->next = nr2;
   }
   return start;
}

struct student*loeschenElement(struct student*start, struct student*elem) {
   if(start == elem) { // Start der Kette
      start = elem->next;
   }
   if(elem->prev != NULL && elem->next != NULL) { // Zwischenelemente zuordnen
      elem->prev->next = elem->next;
      elem->next->prev = elem->prev;
   }else{
      if (elem->next != NULL && elem->prev == NULL) {
         elem->next->prev = NULL;
      }else{
         if (elem->prev != NULL && elem->next == NULL) {
            elem->prev->next = NULL;
         }else{
            printf("Das ist keine List\n");
            freeList(start);
         }
      }
   }
   free(elem); // Speicherplatz freigeben
   return start;
}

struct student*flipElemente(struct student*start){
   struct student*newStart;
   struct student*durchlauf = start;
   while(durchlauf != NULL) {
      start = newStart = durchlauf;
      durchlauf = durchlauf->next;
      struct student*ptr = start->next;
      start->next = start->prev;
      start->prev = ptr;
   }
   return newStart;
}

struct student*Bubblesort(struct student*start, struct student*pointer, int size) {
   int getauscht = 0;
   pointer = pointer->next;
   for (int i = 0; i < size; i++) {
      getauscht = 0;
      pointer = start->next;
      for (int j = 0; pointer != NULL; j++) { // jedesmal eine position weniger da die letzte position richtig ist.
         if (strcmp(pointer->prev->Name, pointer->Name) > 0) { // tauschen nach größe
            getauscht++;
            start = zeilenTausch(start, pointer->prev, pointer);
         }
         pointer = pointer->next;
         if(pointer == NULL) {
            break;
         }
      }
      if (getauscht == 0) { // abbrechen wenn nichts mehr getauscht werden kann
         break;
      }
   }
   return start;
}

int main() {
   struct student*start = neuer_Student(NULL,"Anna", "Musterfrau", 22222, "Am Schwarzenberg-Campus 3", 4);
   struct student*next = neuer_Student(start,"Hans", "Peter", 44444, "Kasernenstrasse 12", 2);
   next = neuer_Student(next,"Lisa", "Lustig", 66666, "Denickestrasse 15", 8);
   next = neuer_Student(next,"Kurt", "ABC", 66666, "Denickestrasse 15", 7);
   next = neuer_Student(next,"Bert", "blahblah", 32798, "Irgenwo 15", 3);
   ausgabe(start);
   start = zeilenTausch(start, start->next, next);
   ausgabe(start);
   start = zeilenTausch(start, start->next, start->next->next);
   ausgabe(start);
   start = loeschenElement(start,start->next->next);
   ausgabe(start);
   start = flipElemente(start);
   ausgabe(start);
   start = Bubblesort(start, start, 5);
   ausgabe(start);
   freeList(start);
   return 0;
}
