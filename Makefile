.PHONY:clean

bin/irregular-verbs: *.o
	gcc -Wall -o bin/irregular-verbs  *.o

obj/main.o: main.c
	gcc -o obj/main.o -c  main.c

obj/process.o: process.c
	gcc -o obj/process.o -c process.c

obj/scaning.o: scaning.c
	gcc -o obj/scaning.o -c scaning.c


clean:
	rm -f bin/irregular-verbs obj/main.o obj/process.o obj/scaning.o