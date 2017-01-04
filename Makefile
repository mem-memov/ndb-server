ndb: main.o Server.o Listener.o Connection.o Error.o Signal.o Application.o Request.o Response.o
	gcc main.o Server.o Listener.o Connection.o Error.o Signal.o Application.o Request.o Response.o -lndb -o ndb-server

main.o: main.c Server.h
	gcc -c main.c

Server.o: Server.c Server.h Listener.h Connection.h Request.h Response.h Application.h
	gcc -c Server.c

Listener.o: Listener.c Listener.h Connection.h Request.h Response.h Error.h
	gcc -c Listener.c

Connection.o: Connection.c Connection.h Request.h Response.h Error.h
	gcc -c Connection.c

Error.o: Error.c Error.h
	gcc -c Error.c

Signal.o: Signal.c Signal.h Server.h
	gcc -c Signal.c

Application.o: Application.c Application.h Request.h Response.h Error.h
	gcc -c Application.c

Request.o: Request.c Request.h
	gcc -c Request.c

Response.o: Response.c Response.h
	gcc -c Response.c

clean:
	rm --force *.o ndb-server

install:
	install ndb-server /usr/local/bin/ndb-server

uninstall:
	rm /usr/local/bin/ndb-server
