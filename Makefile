output: vector.o
	gcc vector.o -output

vector.o: vector.c
	gcc -c vector.c

clean:
	rm *.o output
