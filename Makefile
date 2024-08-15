all: main.o string/string.h string/string.o forca_bruta/forca_bruta.h forca_bruta/forca_bruta.o kmp/kmp.h kmp/kmp.o bmh/bmh.h bmh/bmh.o bmhs/bmhs.h bmhs/bmhs.o
	gcc main.o string/string.o forca_bruta/forca_bruta.o kmp/kmp.o bmh/bmh.o bmhs/bmhs.o -o tp3

main.o: main.c
	gcc -c main.c -o main.o

string/string.o: string/string.h
	gcc -c string/string.c -o string/string.o

forca_bruta/forca_bruta.o: forca_bruta/forca_bruta.h
	gcc -c forca_bruta/forca_bruta.c -o forca_bruta/forca_bruta.o

kmp/kmp.o: kmp/kmp.h
	gcc -c kmp/kmp.c -o kmp/kmp.o

bmh/bmh.o: bmh/bmh.h
	gcc -c bmh/bmh.c -o bmh/bmh.o

bmhs/bmhs.o: bmhs/bmhs.h
	gcc -c bmhs/bmhs.c -o bmhs/bmhs.o

rm: tp3 main.o string/string.o forca_bruta/forca_bruta.o kmp/kmp.o bmh/bmh.o bmhs/bmhs.o
	rm tp3 main.o string/string.o forca_bruta/forca_bruta.o kmp/kmp.o bmh/bmh.o bmhs/bmhs.o