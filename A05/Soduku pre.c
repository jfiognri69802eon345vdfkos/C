#include <stdio.h>
#include <stdlib.h>






    int pZ(int eingabeZeile){
      int a = eingabeZeile;
       if (a==1337){
        a=1337;}
        if (a%10==0 && a!=0){
            a = a;}
            if (a<1 || a>9){
                a=33;}
    return a;}


    int pS(int eingabeSpalte){
        int b = eingabeSpalte;
        if (b==1337){
          b=1337;}
          if(b%10==0 && b!=0){
            b = b;}
            if (b<1 || b>9){
                b = 33;}
            return b;
          }


        int pW(int eingabeWert){
        int c = eingabeWert;
        if (c ==1337){
            c=1337;}
            if (c%10==0 && c!=0){
                c=c;}
                if (c<1 || c>9){
                    c = 33;}
                return c;
        }





/*static int feldA[9][9] = {{6,3,5,7,2,1,8,4,9},      //Rätsel 1 //static davor schreiben = global lverfügbar
                    {2,7,8,9,4,5,1,6,3},
                    {9,1,4,6,8,3,7,2,5},
                    {4,9,7,8,5,2,6,3,1},
                    {3,8,6,1,9,4,2,5,7},
                    {1,5,2,3,7,6,9,8,4},
                    {5,4,1,2,6,7,3,9,8},
                    {7,6,9,4,3,8,5,1,2},
                    {8,2,3,5,1,9,4,7,6}};*/

static int feldAstart[9][9] =  {{6,3,5,7,2,1,8,4,9},      //Rätsel 1 anfang
                            {0,0,8,9,4,5,1,6,3},
                            {0,1,4,6,8,3,7,2,5},
                            {0,9,7,8,0,2,6,3,1},
                            {3,8,6,1,9,4,2,5,7},
                            {1,5,2,3,7,6,0,8,4},
                            {5,4,1,0,6,7,3,9,8},
                            {7,6,9,4,3,8,5,1,2},
                            {8,2,3,5,1,9,4,7,6}};






void SpielStart(){
printf("   |  1  2  3  |  4  5  6  |  7  8  9  |\n");
printf("---+-----------+-----------+-----------+\n");

for(int i=0;i<9;i++){
   if (i==3 || i==6){
                    printf("---+-----------+-----------+-----------+\n");}
    printf("  %d|", i+1);
    for(int j=0;j<9;j++){
        if(feldAstart[i][j] == 0){
            printf("   ");}
        else{
        printf("  %d", feldAstart[i][j]);}

       if (j==2 || j==5 || j==8){
        printf("  |");}
        if (j == 9){
            printf("\n");}
         }printf("\n");}

     printf("---+-----------+-----------+-----------+\n");
}

int main (){
    int eingabeZeile;
    int eingabeSpalte;
    int eingabeWert;
    int Z, S;
    int W;
    int i = 0;

SpielStart();
while(i<=1000) {




printf("To exit type 1337\n");
printf("Eingabe fur Zeile \n");
    scanf("%d", &eingabeZeile);
       if (pZ(eingabeZeile)==1337){
            exit (0);}
            if (pZ(eingabeZeile)==33){
                printf("Eingabe fur Zeile ungultig\n");
                    printf("To exit type 1337\n");
                    printf("Eingabe fur Zeile \n");
                    scanf("%d", &eingabeZeile);}
        else{Z = pZ(eingabeZeile-1);}



printf("Eingabe fur Spalte\n");
   scanf("%d", &eingabeSpalte);
        if(pS(eingabeSpalte)==1337){
            exit (0);}
            if (pS(eingabeSpalte)==33){
                printf("Eingabe fur Spalte ungultig \n");
                    printf("To exit type 1337\n");
                    printf("Eingabe fur Spalte\n");
                    scanf("%d", &eingabeSpalte);}

        else {S = pS(eingabeSpalte-1);}



printf("Eingabe fur Wert\n");
    scanf("%d", &eingabeWert);
       if (pW(eingabeWert) == 1337){
        exit(0);}
        if(pW(eingabeWert)==33){
            printf("Eingabe fur Wert ungultig \n");
                printf("To exit type 1337\n");
                printf("Eingabe fur Wert\n");
                scanf("%d", &eingabeWert);}
            else{ W = (pW(eingabeWert));}




    feldAstart [Z][S]= W;
    SpielStart();
    printf("\n");
    i+=1;
}
return 0;
}
