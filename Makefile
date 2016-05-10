.PHONY:clean

bin/irregular-verbs: obj/main.o obj/process.o obj/scaning.o
	gcc -Wall -o bin/irregular-verbs obj/main.o obj/process.o obj/scaning.o

obj/main.o: scr/main.c
	gcc -o obj/main.o -c  scr/main.c

obj/process.o: scr/process.c
	gcc -o obj/process.o -c scr/process.c

obj/scaning.o: scr/scaning.c
	gcc -o obj/scaning.o -c scr/scaning.c

clean:
	rm -f bin/irregular-verbs obj/main.o obj/process.o obj/scaning.o 