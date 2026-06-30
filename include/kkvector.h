#ifndef KKVECTOR_H
#define KKVECTOR_H

#include <stddef.h>

// Generic dynamically growable buffer.
typedef struct kkv_vector {
	size_t size;      // Number of elements currently stored.
	size_t stride;    // Element size in bytes.
	size_t capacity;  // Maximum storable elements before reallocation.
	char*  data;      // Raw byte buffer.
} kkv_vector;

// Initializes an empty vector with a given element size and initial capacity.
int kkv_init(kkv_vector* v, size_t stride, size_t capacity);

// Frees a vector.
void kkv_free(kkv_vector* v);

// Reserves space for a given number of elements.
int kkv_reserve(kkv_vector* v, size_t size);

// Pushes an element to the back.
int kkv_push(kkv_vector* v, const void* src);

// Pops the last element if it exists.
void kkv_pop(kkv_vector* v);

// Gets the element at a given index.
int kkv_get(kkv_vector* v, size_t index, void* dst);

// Sets the value of the element at a given index.
int kkv_set(kkv_vector* v, size_t index, const void* src);

// Clears the vector.
void kkv_clear(kkv_vector* v);

#endif  // KKVECTOR_H
