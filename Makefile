run: main.c scanner.c
	cc -o scan -g main.c scanner.c
	./scan test

clean:
	rm -f main *.o
