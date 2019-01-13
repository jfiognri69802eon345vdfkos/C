
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "sort.h"

static HANDLE hConsole;
static int aktuellesMenu = 0;
static int arrayLenght = 0;

void displayMenu(){ // Übersicht anzeigen
   SetConsoleTextAttribute(hConsole, 240);
   printf("1) Array-Gr\x94%ce festlegen               4) Bubblesort (downwards)     \n2) Zahlen von der Tastertur einlesen   5) Mergesort                  \n3) Zufallszahlen erzeugen              6) Programm beenden           \n", 225);
}

int eingabepruefen(){ // menü eingaben kontrollieren
   displayMenu();
   int eingabe = 0;
   fflush(stdin);
   SetConsoleTextAttribute(hConsole, 15);
   printf("Eingabe: ");
   scanf("%i", &eingabe);
   if(eingabe > 0 && eingabe < 8) {
      return eingabe;
   }
   return 0;
}

int eingabepruefung(int von, int bis){ // kontrolle der restlichen eingaben
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

int*arrayGroesseAendern(int size){ // array für zahlen erstellen
   int*pointer;
   pointer = (int*) calloc(size, sizeof(int));
   arrayLenght = size;
   return pointer;
}


int main() {
   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   // aktuellesMenu = eingabepruefen();
   int*pointer = NULL;
   int skipeing = 0;
   while (aktuellesMenu != 6) { // durcklauf solange bis das Programm beendet wird
      SetConsoleTextAttribute(hConsole, 15);
      if (skipeing == 0) {
         aktuellesMenu = eingabepruefen();
      }
      skipeing = 0;
      switch (aktuellesMenu) { // wechseln der verschiedenen Menüs
      case 0:
         aktuellesMenu = eingabepruefen();
      case 1:
         if (arrayLenght > 0) { // falls der speicher noch belegt ist -> löschen
            SetConsoleTextAttribute(hConsole, 12);
            printf("Alten Speicher freigeben\n");
            free(pointer);
         }
         pointer = arrayGroesseAendern(eingabepruefung(1,100000)); // neues array anlegen
         aktuellesMenu = 0;
         aktuellesMenu = 3; // mit Zufallszahlen belegen
         skipeing = 1;
         break;
      case 2:
         if (arrayLenght > 0) { // eingaben in bestimmte stellen es Arrays
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
            for (int i = 0; i < arrayLenght; i++) { // ausgabe des aktuellen stands
               printf("%d, ", pointer[i]);
            }
            printf("\n");
         }else{ // Abbruch falls noch kein Array angelegt wurde
            SetConsoleTextAttribute(hConsole, 12);
            printf("Noch kein Array\n Array-Gr\x94%ce festlegen\n", 225);
            aktuellesMenu = 1;
            skipeing = 1;
         }
         break;
      case 3:
         if (arrayLenght > 0) {
            printf("Random wahl der Zahlen f\201r das Array\n");
            for (int i = 0; i < arrayLenght; i++) { // Random eintragen von Zahlen
               pointer[i] = (rand() % 1000) + 1;
            }
            SetConsoleTextAttribute(hConsole, 6);
            printf("Aktuelles Array\n");
            SetConsoleTextAttribute(hConsole, 15);
            for (int i = 0; i < arrayLenght; i++) { // ausgabe des aktuellen stands
               printf("%d, ", pointer[i]);
            }
            printf("\n");
         }else{ // Abbruch falls noch kein Array angelegt wurde
            SetConsoleTextAttribute(hConsole, 12);
            printf("Noch kein Array\n Array-Gr\x94%ce festlegen\n", 225);
            aktuellesMenu = 1;
            skipeing = 1;
         }
         break;
      case 4:
         if (arrayLenght > 0) { // sortieren durch Bubblesort
            Bubblesort(pointer, arrayLenght);
            SetConsoleTextAttribute(hConsole, 6);
            printf("Aktuelles Array\n");
            SetConsoleTextAttribute(hConsole, 15);
            for (int i = 0; i < arrayLenght; i++) {
               printf("%d, ", pointer[i]);
            }
            printf("\n");
         }else{ // Abbruch falls noch kein Array angelegt wurde
            SetConsoleTextAttribute(hConsole, 12);
            printf("Noch kein Array\n Array-Gr\x94%ce festlegen\n", 225);
            aktuellesMenu = 1;
            skipeing = 1;
         }
         break;
      case 5:
         if (arrayLenght > 0) { // sortieren durch Mergesort
            Mergesort(arrayLenght, pointer);
            SetConsoleTextAttribute(hConsole, 6);
            printf("Aktuelles Array\n");
            SetConsoleTextAttribute(hConsole, 15);
            for (int i = 0; i < arrayLenght; i++) { // ausgabe des aktuellen stands
               printf("%d, ", pointer[i]);
            }
            printf("\n");
         }else{ // Abbruch falls noch kein Array angelegt wurde
            SetConsoleTextAttribute(hConsole, 12);
            printf("Noch kein Array\n Array-Gr\x94%ce festlegen\n", 225);
            aktuellesMenu = 1;
            skipeing = 1;
         }
         break;
      case 7:
         if (arrayLenght > 0) {
            umdrehen(pointer, arrayLenght);
            SetConsoleTextAttribute(hConsole, 6);
            printf("Aktuelles Array\n");
            SetConsoleTextAttribute(hConsole, 15);
            for (int i = 0; i < arrayLenght; i++) { // ausgabe des aktuellen stands
               printf("%d, ", pointer[i]);
            }
            printf("\n");
         }else{ // Abbruch falls noch kein Array angelegt wurde
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
