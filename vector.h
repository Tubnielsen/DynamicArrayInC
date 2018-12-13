#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

//-----------------------------------------------------------------------------
// Vector, a dynamic array using size doubling to achieve amortised constant time insertion.
// There are preconditions mentioned in each function description. The user has to make sure
// that these conditions are fulfilled before the function call. It may be a good idea to use
// the assert macro to check those conditions.
//-----------------------------------------------------------------------------

// forward declare structs and bring them from the tag namespace to the ordinary namespace
typedef struct Vector Vector;

// actually define the structs
struct Vector {
	size_t size;
	size_t usedSpace;
	int *parray;
};

// Initialize a vector to be empty.
// Pre: v != NULL
void Vector_ctor(Vector *v);

// Deallocate internal structures of the vector.
// Note: the user is responsible for deleting all values.
// Note: the user is responsible for deleting the actual vector if it was dynamically allocated.
void Vector_dtor(Vector *v);

// Insert a new element at the end of the vector.
// Pre: v != NULL
void Vector_push_back(Vector *v, void *value);

// Remove the last element in the vector.
// Pre: v != NULL && Vector_size(v) > 0
void Vector_pop_back(Vector *v);

// Return the number of elements in the vector.
// Pre: v != NULL
size_t Vector_size(const Vector *v);

// Return the current capacity of the vector.
// Pre: v != NULL
size_t Vector_capacity(const Vector *v);

// Return the value at the given index.
// Pre: v != NULL && index < Vector_size(v)
void *Vector_get(const Vector *v, size_t index);

// Return a pointer to the underlying array.
void **Vector_data(Vector *v);

#endif // VECTOR_H
