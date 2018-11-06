#include <stdio.h>
#include <stdint.h>

int main(){
    uint16_t max  = 32768;
    uint16_t eingabe= 530;

while( max > 0){
        if (eingabe >= max){
            printf("1");
            eingabe = eingabe-max;
        }
        else{
            printf("0");
        }
        max = max/2;
    }
    printf("\n");
return 0;
}
