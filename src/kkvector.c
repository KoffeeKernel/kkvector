#include "kkvector.h"

#include <stdlib.h>
#include <string.h>

int kkv_init(kkv_vector* v, size_t stride, size_t capacity) {
	if (stride == 0 || capacity == 0) return 1;

	char* data = malloc(capacity * stride);
	if (!data) return 1;

	v->size     = 0;
	v->stride   = stride;
	v->capacity = capacity;
	v->data     = data;
	return 0;
}

void kkv_free(kkv_vector* v) {
	free(v->data);
}

int kkv_reserve(kkv_vector* v, size_t size) {
	if (v->capacity >= size) return 0;

	size_t m        = (size + v->capacity - 1) / v->capacity;
	size_t capacity = v->capacity * m;

	char* data = realloc(v->data, capacity * v->stride);
	if (!data) return 1;

	v->capacity = capacity;
	v->data     = data;
	return 0;
}

int kkv_push(kkv_vector* v, const void* src) {
	if (kkv_reserve(v, v->size + 1) != 0) return 1;

	memcpy(v->data + v->size * v->stride, src, v->stride);
	v->size++;
	return 0;
}

void kkv_pop(kkv_vector* v) {
	if (v->size > 0) v->size--;
}
