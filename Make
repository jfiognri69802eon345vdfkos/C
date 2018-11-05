all:
	gcc -std=c99 -pedantic -Wall -Wextra -o blatt01_1.exe blatt01_1.c
	blatt01_1.exe
	gcc -std=c99 -pedantic -Wall -Wextra -o blatt01_3.exe blatt01_3.c
	blatt01_3.exe
