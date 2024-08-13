all: listaEncadeada.o string.o
	gcc main.c tads/listaEncadeada.h listaEncadeada.o string.o my_string/string.h -o main

listaEncadeada.o: tads/listaEncadeada.h
	gcc -c tads/listaEncadeada.c

string.o: my_string/string.h
	gcc -c my_string/string.c

run: main
	./main

val: main
	valgrind ./main

rm: string.o listaEncadeada.o
	rm *.o