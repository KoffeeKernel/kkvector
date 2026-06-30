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

#endif  // KKVECTOR_H
