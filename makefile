all: plumb.o
	gcc -o plumb plumb.o
plumb.o: plumb.c
	gcc -c plumb.c
run:
	./plumbing
clean:
	rm *.o
	rm plumb
