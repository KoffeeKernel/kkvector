#include <assert.h>

#include "kkvector.h"

int main(void) {
	kkv_vector vec;
	assert(kkv_init(&vec, sizeof(int), 8) == 0);

	kkv_pop(&vec);
	assert(vec.size == 0);

	for (int i = 1; i <= 100; i++) {
		assert(kkv_push(&vec, &i) == 0);
	}

	for (int i = 99; i > 1; i--) {
		kkv_pop(&vec);
		assert(vec.size == i);
		assert(((int*)vec.data)[i-1] == i);
	}

	kkv_free(&vec);
	return 0;
}
