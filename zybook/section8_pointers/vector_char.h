// TODO: Modify the code so that the vector holds characters instead of integers -- a flexible string

#ifndef VECTOR_H
#define VECTOR_H

#include "string.h"                          // for conversion

typedef struct vector_struct {
    char* elements;
    unsigned int size;
} vector;

// Initialize vector
void vector_create(vector* v, unsigned int vectorSize);

// Destroy vector
void vector_destroy(vector* v);

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize);

// Return pointer to element at specified index
char* vector_at(vector* v, unsigned int index);

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, char value);

// Insert new value at end of vector
void vector_push_back(vector* v, char value);

// Erase (remove) value at specified index
void vector_erase(vector* v, unsigned int index);

// Return number of elements within vector
int vector_size(vector* v);

// Convert an ordinary string to a vector
void vector_from_string(vector* v, char* string);

// Print the vector as if it were a string
void vector_print(vector* v);


#endif
