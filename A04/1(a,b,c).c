#include <math.h>
#include <stdio.h>

int main(){

    double eingabe = 1; // Eingabewert
    double c1 = eingabe;
    double y = c1;
    double y_gg = y - 1;

 for (int j = 1; y_gg != y && j<200; j++) {
        y_gg = y; // Update des vorherigen Ergebnisses
        c1 = (-c1)*(eingabe*eingabe)/((2*j + 1)*(2*j)); // VorherigenWert aktualisieren
        y += c1; // Ergebnisse aufsummieren
        printf ("Zwischenergbnis -> %.21f \n", y);
    }
    printf("Der Sinus an der Stelle %f ist angenahert  %.21f \n",eingabe ,y);
    printf("Der Sinus aus der Mathe Bibliothek entsprcht %.21f\n", sin(eingabe));
    printf("Die Differenz entspricht %.21f\n", y-sin(eingabe));


    printf("\n\n\n");

    double vorherigerWert2 = eingabe;
    double Ergebnis2 = vorherigerWert2;
    double vorherigesEregebnis2 = Ergebnis2-1;

        if(eingabe>=(-1) && (eingabe<=1)){
        for (int k = 1;vorherigesEregebnis2 != Ergebnis2 && k<200;k++){
            vorherigesEregebnis2 = Ergebnis2;
            vorherigerWert2 = (-vorherigerWert2)*(eingabe*eingabe);
            Ergebnis2 += vorherigerWert2/(2*k+1);

            printf("Das zwischen Ergebnis bei %d entspricht -> %.20f\n", k  ,Ergebnis2);
        }

     printf ("Der arctang an der Stelle %f entspricht angenahert -> %.20f \n", eingabe, Ergebnis2);
     printf("Der arctang Bibliothek entspricht %.20f\n", sin(eingabe));
     printf("Die Differenz der Werte entspricht %.20f",sin(eingabe)-Ergebnis2);
    }
    else printf("der x Wert ist unzulassig");

printf("\n\n\n");




    double Ergebnis3 = eingabe-1;
    double vorherigersErgebnis3 = Ergebnis3-1;
    int vorzeichen3 = 1;
    double potenz3= eingabe-1;

if (eingabe>0 && eingabe<=2){ //Einschränkung der Werte die möglich sind
    for (int i = 2; vorherigersErgebnis3!=Ergebnis3;i++){
            vorherigersErgebnis3 = Ergebnis3;
           if (vorzeichen3==1){
            vorzeichen3= -1;}
           else {
            vorzeichen3 = 1;
           }
            potenz3 *=potenz3;
            Ergebnis3 += vorzeichen3*potenz3/i;
            printf("Das Zwischenergenis bei %d enspricht genahert -> %.17f\n", i, Ergebnis3);
    }

    printf("Der ln betragt angenahert an der Stelle  -> %.20f \n", Ergebnis3);
    printf("Der ln an der Stelle  betragt aus der Bibliothek -> %.20f\n", log10(eingabe));
}
else printf("Der x Wert ist unzulassig\n");



return 0;
}
