CC=gcc
CFLAGS=-I".\SDL2\x86_64-w64-mingw32\include" -std=c99
LDFLAGS=-L".\SDL2\x86_64-w64-mingw32\lib" -lmingw32 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2 -lopengl32
LinFLAGS=-L".\SDL2\x86_64-w64-mingw32\lib" -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2 -pthread

all: run

Skat:
	$(CC) $(CFLAGS) -o Skat main.c rendern.c connection.c $(LDFLAGS)

build:
	$(CC) $(CFLAGS) -o Skat main.c rendern.c connection.c $(LDFLAGS)

build-linux:
	$(CC) $(CFLAGS) -o Skat main.c rendern.c connection.c menu.c spiel.c $(LinFLAGS)

run: Skat
	Skat
