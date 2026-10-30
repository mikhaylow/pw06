all:
	mkdir -p bin
	gcc -Wall src/pw06-1.c -o bin/pw06-1
	gcc -Wall src/pw06-2.c -o bin/pw06-2
	gcc -Wall src/pw06-3.c -o bin/pw06-3
#	gcc src/pw06-4.c -o bin/pw06-4
#	gcc src/pw06-5.c -o bin/pw06-5