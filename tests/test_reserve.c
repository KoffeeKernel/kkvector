#include <assert.h>

#include "kkvector.h"

int main(void) {
	kkv_vector vec;
	assert(kkv_init(&vec, sizeof(int), 8) == 0);

	assert(kkv_reserve(&vec, 0) == 0);
	assert(vec.capacity == 8);

	assert(kkv_reserve(&vec, 4) == 0);
	assert(vec.capacity == 8);

	assert(kkv_reserve(&vec, 8) == 0);
	assert(vec.capacity == 8);

	assert(kkv_reserve(&vec, 16) == 0);
	assert(vec.capacity >= 16);

	kkv_free(&vec);
	return 0;
}
