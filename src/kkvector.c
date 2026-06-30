#include "kkvector.h"

#include <stdlib.h>

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
