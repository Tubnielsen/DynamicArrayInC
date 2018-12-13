#include <stdio.h>
#include "vector.h"

int main(void)
{
	printf("hello world\n");
	return 0;
};


void Vector_ctor(Vector *v){
	v->usedSpace = 0;
	v->size = 10;
	v->parray = (int *)malloc(size * sizeof(int));
};

void Vector_dtor(Vector *v){
	free(v->parray);
	v->parray = NULL;
	v->usedSpace = 0;
	v->size = 0;
};