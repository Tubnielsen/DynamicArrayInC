all: sort.c vector.c
	gcc -o sort sort.c

.PHONY: test

test:
	for t in test/* ; do \
		./sort $$t ; \
		echo ---------------End of File---------------- ; \
	done

clean:
	rm -rf *.o sort