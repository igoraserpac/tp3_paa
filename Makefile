all: my_string/listaEncadeada.o my_string/string.o
	gcc main.c my_string/listaEncadeada.h listaEncadeada.o string.o my_string/string.h -o main

my_string/listaEncadeada.o: my_string/listaEncadeada.h
	gcc -c my_string/listaEncadeada.c

my_string/string.o: my_string/string.h
	gcc -c my_string/string.c

run: main
	./main

val: main
	valgrind ./main

rm: string.o listaEncadeada.o
	rm string.o listaEncadeada.o