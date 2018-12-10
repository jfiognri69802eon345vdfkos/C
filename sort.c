#include <stdio.h>
#include <stdlib.h>
void mergeList(int*,int*,int*,int,int,int);

void flip(int*a, int*b){
   int c = *a; // Temporär zwischen speichern von a
   *a = *b; // a erstetzen mit b
   *b = c; // b mit wert a beschreiben
}

void Bubblesort(int*pointer, int size) {
   int getauscht = 0;
   for (int i = 0; i < size; i++) {
      getauscht = 0;
      for (int j = 0; j < size - i - 1; j++) { // jedesmal eine position weniger da die letzte position richtig ist.
         // printf("inhalt %4d zu %4d\n", pointer[j], pointer[j+1]);
         if (pointer[j] > pointer[j + 1]) { // tauschen nach größe
            // printf("tauschen\n");
            getauscht++;
            flip(&pointer[j],&pointer[j + 1]);
         }
      }
      if (getauscht == 0) { // abbrechen wenn nichts mehr getauscht werden kann
         break;
         // printf("eigentlich fertig\n");
      }
   }
}

void*allocate(int n){
   void*p;
   p = calloc(n, sizeof(int));
   if(p == NULL) {
      printf("Memory error has successfully stop the program\n");
      exit(1);
   }
   return p;
}

void Mergesort(int elemente, int*array){
   for (int i = 0; i < elemente; i++) {
      printf("%d, ", array[i]);
   }
   printf("\n");
   if (elemente <= 1) {
      return;
   }
   int*arrayerg = allocate(elemente);
   int links = (double) elemente / 2.0;
   int rechts = elemente - links;
   int*ilinks = allocate(links);
   int*irechts = allocate(rechts);
   for (int l = 0; l < links; l++) {
      ilinks[l] = array[l];
   }
   for (int r = 0; r < rechts; r++) {
      irechts[r] = array[links + r];
   }
   Mergesort(links, ilinks);
   Mergesort(rechts, irechts);
   mergeList(ilinks, irechts, arrayerg, elemente, links, rechts);
   for (int i = 0; i < elemente; i++) {
     array[i] = arrayerg[i];
     printf("%d, ", array[i]);
   }
   printf("\n");
   free(arrayerg);
   free(ilinks);
   free(irechts);
}

void mergeList(int*links, int*rechts, int*arrayerg, int elemente, int l, int r){
   int ilinks = 0;
   int irechts = 0;
   for (int i = 0; i < elemente; i++) {
      if ((links[ilinks] <= rechts[irechts] && ilinks < l) || irechts <= r) {
         arrayerg[i] = links[ilinks];
         ilinks++;
      } else {
         arrayerg[i] = rechts[irechts];
         irechts++;
      }
   }
}
