all: main.c tads/listaEncadeada.c tads/listaEncadeada.h tads/pilha.c tads/pilha.h my_string/string.c my_string/string.h forca_bruta/forca_bruta.c forca_bruta/forca_bruta.h kmp/kmp.c kmp/kmp.h bmh/bmh.c bmh/bmh.h bmhs/bmhs.c bmhs/bmhs.h
	gcc main.c tads/listaEncadeada.c tads/pilha.c my_string/string.c forca_bruta/forca_bruta.c kmp/kmp.c bmh/bmh.c bmhs/bmhs.c -o main

# all: listaEncadeada.o string.oz
# 	gcc main.c tads/listaEncadeada.h listaEncadeada.o string.o my_string/string.h -o main

# listaEncadeada.o: tads/listaEncadeada.h
# 	gcc -c tads/listaEncadeada.c

# string.o: my_string/string.h
# 	gcc -c my_string/string.c

# run: main
# 	./main

# val: main
# 	valgrind ./main

# rm: string.o listaEncadeada.o
# 	rm *.o