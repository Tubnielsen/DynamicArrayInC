#include <stdio.h>
#include "vector.h"

int main(void)
{	
	Vector t;
	Vector *v;
	v = &t;
	Vector_ctor(v);
	Vector_push_back(v, 5);
	Vector_push_back(v, 7);
	Vector_push_back(v, 1);
	printf("%ls \n", v->parray);
	printf("%ld \n", v->size);
	printf("%ls \n", v->parray);
	
	return 0;
}

// Initialize a vector to be empty.
// Pre: v != NULL
void Vector_ctor(Vector *v){
	v->usedSpace = 0;
	v->size = 1;
	v->parray = (int *)malloc(v->size * sizeof(int));
}

// Deallocate internal structures of the vector.
// Note: the user is responsible for deleting all values.
// Note: the user is responsible for deleting the actual vector if it was dynamically allocated.
void Vector_dtor(Vector *v){
	free(v->parray);
	v->parray = NULL;
	v->usedSpace = 0;
	v->size = 0;
}

// Insert a new element at the end of the vector.
// Pre: v != NULL
void Vector_push_back(Vector *v, void *value){
	
	if(v->size <= ++v->usedSpace){
		v->size *= 2;
		realloc(v->parray, v->size * sizeof(int));
	}
    int *p = v->parray + v->usedSpace;
	p = value;
	

}

// Remove the last element in the vector.
// Pre: v != NULL && Vector_size(v) > 0
void Vector_pop_back(Vector *v){
	v->usedSpace--; //Content does not matter, it will be overwritten.
}
// Return the number of elements in the vector.
// Pre: v != NULL
size_t Vector_size(const Vector *v){
	return v->size;
}

// Return the current capacity of the vector.
// Pre: v != NULL
size_t Vector_capacity(const Vector *v){
	return v->usedSpace;
}

// Return the value at the given index.
// Pre: v != NULL && index < Vector_size(v)
void *Vector_get(const Vector *v, size_t index){
	return v->parray + (sizeof(int) * index);
}

// Return a pointer to the underlying array.
void **Vector_data(Vector *v){
	return v->parray;
}
