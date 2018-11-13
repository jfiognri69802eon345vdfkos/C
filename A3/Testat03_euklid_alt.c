#include <stdio.h>
#include <stdlib.h>

int main(){
    float a = 30.0;
    float b = 15.0;
    float ggt;
    float diff;
do {
    diff =(a - b); /*absolute differenz wird ermittelt*/
        if (diff < 0){
        diff = (diff * (-1)); /*der Betrag wird gebildet falls erforderlich*/
        }
        if (a > b){     /* Die größere Zahl wird durch die Differenc ersetzt*/
        a = diff;
    }
    else b = diff;
}
        while (a * b != 0);
if (a != 0){
        printf("der größte gemeinsame Teiler ist %f\n", a);}

else {
        printf("der größte gemeinsame Teiler ist %f\n", b);}








    return 0;
}
