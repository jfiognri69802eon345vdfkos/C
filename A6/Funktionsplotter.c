#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "libBMP.h"

int main() {
   uint32_t data[] = {COLOR_RED, COLOR_BLUE, COLOR_GREEN, COLOR_WHITE};
   bmp_create("pic.bmp",data, 2,2);
   return 0;
}
