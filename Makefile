ndb: main.o Server.o
	gcc main.o Server.o -o ndb-server

main.o: main.c Server.h
	gcc -c main.c

Server.o: Server.c Server.h
	gcc -c Server.c

clean:
	rm *.o ndb-server

