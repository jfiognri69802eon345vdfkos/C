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
         if (pointer[j] > pointer[j + 1]) { // tauschen nach größe
            getauscht++;
            flip(&pointer[j],&pointer[j + 1]);
         }
      }
      if (getauscht == 0) { // abbrechen wenn nichts mehr getauscht werden kann
         break;
      }
   }
}

void*allocate(int n){ // Speicherplatz reservieren
   void*p;
   p = calloc(n, sizeof(int)); // Speicherplatz reservieren
   if(p == NULL) {
      printf("Memory error has successfully stop the program\n");
      exit(1); // wenn es fehl schlägt
   }
   return p;
}

void Mergesort(int elemente, int*array){ // sortieren durch splitten
   if (elemente <= 1) { // wenn nur noch ein Element über ist return
      return;
   }
   int*arrayerg = allocate(elemente); // arrays erstellen
   int links = (double) elemente / 2.0; // spliten in 2 arrays
   int rechts = elemente - links;
   int*ilinks = allocate(links);
   int*irechts = allocate(rechts);
   for (int l = 0; l < links; l++) {
      ilinks[l] = array[l];
   }
   for (int r = 0; r < rechts; r++) {
      irechts[r] = array[links + r];
   }
   Mergesort(links, ilinks); // splitten des linken Teils
   Mergesort(rechts, irechts); // splitten des rechten Teils
   mergeList(ilinks, irechts, arrayerg, elemente, links, rechts);
   for (int i = 0; i < elemente; i++) { // übertragen in das array, ein layer oben.
     array[i] = arrayerg[i];
   }
   free(arrayerg); // Speicherplatz wiederfreigeben
   free(ilinks);
   free(irechts);
}

void mergeList(int*links, int*rechts, int*arrayerg, int elemente, int l, int r){
   int ilinks = 0;
   int irechts = 0;
   for (int i = 0; i < elemente; i++) {
      if ((links[ilinks] <= rechts[irechts] && ilinks < l) || irechts >= r) { // mergen der Arrays zum übernehmen.
         arrayerg[i] = links[ilinks];
         ilinks++;
      } else {
         arrayerg[i] = rechts[irechts];
         irechts++;
      }
   }
}
