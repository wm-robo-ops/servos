all: setPos.c
	gcc -Wall -pthread -o setPos setPos.c -lpigpiod_if2 -lrt

clean:
	$(RM) setPos
