#include <stdio.h>
#include <stdlib.h>

int main(){
double e = 0.0;      /*Variabeln für e*/
double eold = 0.0;
int i=0;              /*index*/
double fspeicher = 1.0;

        do{
            eold = e;
            e = eold +(1.0/fspeicher);
            i ++;
            fspeicher = fspeicher * i;
            printf ("e entsprich nach %d schritten angenaehert %f\n", i , e);
        }while (e!=eold);


return 0;
}
