#include <stdio.h>
#include "vector.h"

int main(void)
{
	printf("hello world\n");
	return 0;
};

// Initialize a vector to be empty.
// Pre: v != NULL
void Vector_ctor(Vector *v){
	v->used = 0;
	v->size = 0;
};