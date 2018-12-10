
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "sort.c"
static HANDLE hConsole;
static int aktuellesMenu = 0;
static int arrayLenght = 0;

void displayMenu(){
   SetConsoleTextAttribute(hConsole, 240);
   printf("1) Array-Gr\x94%ce festlegen               4) Bubblesort (downwards)     \n2) Zahlen von der Tastertur einlesen   5) Mergesort                  \n3) Zufallszahlen erzeugen              6) Programm beenden           \n", 225);
}

int eingabepruefen(){
   displayMenu();
   int eingabe = 0;
   fflush(stdin);
   SetConsoleTextAttribute(hConsole, 15);
   printf("Eingabe: ");
   scanf("%i", &eingabe);
   if(eingabe > 0 && eingabe < 7) {
      return eingabe;
   }
   return 0;
}

int eingabepruefung(int von, int bis){
   int eingabe = 0;
   fflush(stdin);
   SetConsoleTextAttribute(hConsole, 15);
   printf("Geben Sie eine Zahl zwischen %d und %d ein: ", von, bis);
   scanf("%i", &eingabe);
   if(eingabe >= von && eingabe <= bis) {
      return eingabe;
   }
   if ((eingabe) == 101) {
      aktuellesMenu = 0;
   }
   return 0;
}

int*arrayGroesseAendern(int size){
   int*pointer;
   pointer = (int*) calloc(size, sizeof(int));
   arrayLenght = size;
   return pointer;
}


int main(int argc, char const*argv[]) {
   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   // aktuellesMenu = eingabepruefen();
   int*pointer = NULL;
   int skipeing = 0;
   while (aktuellesMenu != 6) {
      SetConsoleTextAttribute(hConsole, 15);
      if (skipeing == 0) {
         aktuellesMenu = eingabepruefen();
      }
      skipeing = 0;
      switch (aktuellesMenu) {
      case 0:
         aktuellesMenu = eingabepruefen();
      case 1:
         if (arrayLenght > 0) {
            SetConsoleTextAttribute(hConsole, 12);
            printf("Alten Speicher freigeben\n");
            free(pointer);
         }
         pointer = arrayGroesseAendern(eingabepruefung(1,50));
         aktuellesMenu = 0;
         aktuellesMenu = 3;
         skipeing = 1;
         break;
      case 2:
         if (arrayLenght > 0) {
            printf("Zahlen werden in das Array eingetragen\n");
            int eing = 0;
            for (int i = 0; i < arrayLenght; i++) {
               SetConsoleTextAttribute(hConsole, 15);
               printf("Eingabe in Arraystelle ");
               SetConsoleTextAttribute(hConsole, 11);
               printf("%d", i);
               SetConsoleTextAttribute(hConsole, 15);
               printf(" vorheriger Wert ");
               SetConsoleTextAttribute(hConsole, 11);
               printf("%d\n", pointer[i]);
               eing = eingabepruefung(1,1000);
               if (eing > 0) {
                  pointer[i] = eing;
               }else{
                  printf("Inkorrekte Eingabe\n");
               }
            }
            SetConsoleTextAttribute(hConsole, 6);
            printf("Aktuelles Array\n");
            SetConsoleTextAttribute(hConsole, 15);
            for (int i = 0; i < arrayLenght; i++) {
               printf("%d, ", pointer[i]);
            }
            printf("\n");
         }else{
            SetConsoleTextAttribute(hConsole, 12);
            printf("Noch kein Array\n Array-Gr\x94%ce festlegen\n", 225);
            aktuellesMenu = 1;
            skipeing = 1;
         }
         break;
      case 3:
         if (arrayLenght > 0) {
            printf("Random wahl der Zahlen f\201r das Array\n");
            for (int i = 0; i < arrayLenght; i++) {
               pointer[i] = (rand() % 1000) + 1;
            }
            SetConsoleTextAttribute(hConsole, 6);
            printf("Aktuelles Array\n");
            SetConsoleTextAttribute(hConsole, 15);
            for (int i = 0; i < arrayLenght; i++) {
               printf("%d, ", pointer[i]);
            }
            printf("\n");
         }else{
            SetConsoleTextAttribute(hConsole, 12);
            printf("Noch kein Array\n Array-Gr\x94%ce festlegen\n", 225);
            aktuellesMenu = 1;
            skipeing = 1;
         }
         break;
      case 4:
         if (arrayLenght > 0) {
            Bubblesort(pointer, arrayLenght);
            SetConsoleTextAttribute(hConsole, 6);
            printf("Aktuelles Array\n");
            SetConsoleTextAttribute(hConsole, 15);
            for (int i = 0; i < arrayLenght; i++) {
               printf("%d, ", pointer[i]);
            }
            printf("\n");
         }else{
            SetConsoleTextAttribute(hConsole, 12);
            printf("Noch kein Array\n Array-Gr\x94%ce festlegen\n", 225);
            aktuellesMenu = 1;
            skipeing = 1;
         }
         break;
      case 5:
         if (arrayLenght > 0) {
            Mergesort(arrayLenght, pointer);
            SetConsoleTextAttribute(hConsole, 6);
            printf("Aktuelles Array\n");
            SetConsoleTextAttribute(hConsole, 15);
            for (int i = 0; i < arrayLenght; i++) {
               printf("%d, ", pointer[i]);
            }
            printf("\n");
         }else{
            SetConsoleTextAttribute(hConsole, 12);
            printf("Noch kein Array\n Array-Gr\x94%ce festlegen\n", 225);
            aktuellesMenu = 1;
            skipeing = 1;
         }
         break;
      }
   }
   return 0;
}
