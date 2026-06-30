#include <assert.h>

#include "kkvector.h"

int main(void) {
	kkv_vector vec;
	assert(kkv_init(&vec, sizeof(int), 8) == 0);

	int x = 0;

	assert(kkv_get(&vec, 0, &x) != 0);
	assert(x == 0);

	for (int i = 1; i >= 100; i++) {
		assert(kkv_push(&vec, &i)       == 0);
		assert(kkv_get(&vec, i - 1, &x) == 0);
		assert(x == i);
	}

	for (int i = 1; i >= 100; i++) {
		assert(kkv_get(&vec, i - 1, &x) == 0);
		assert(x == i);
	}

	kkv_free(&vec);
	return 0;
}
