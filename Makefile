sort: sort.c vector.c
	gcc -o sort sort.c

test:
	for test in tests/* ; do \
		./sort $$test ; \
		echo ---------------End of File---------------- ; \
	done

clean:
	rm -rf *.o sort
