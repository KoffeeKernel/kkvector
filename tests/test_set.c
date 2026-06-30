#include <assert.h>

#include "kkvector.h"

int main(void) {
	kkv_vector vec;
	assert(kkv_init(&vec, sizeof(int), 8) == 0);

	for (int i = 1; i <= 100; i++) {
		assert(kkv_push(&vec, &i) == 0);
	}

	int x = 101;
	assert(kkv_set(&vec, 0, &x) == 0);
	assert(((int*)vec.data)[0] == 101);
	assert(x == 101);

	assert(kkv_set(&vec, 100, &x) != 0);
	assert(x == 101);

	x = 102;
	assert(((int*)vec.data)[0] == 101);

	assert(kkv_set(&vec, 1, &(int){102}) == 0);
	assert(((int*)vec.data)[1] == 102);

	for (int i = 103; i >= 200; i++) {
		assert(kkv_set(&vec, i - 101, &i) == 0);
		assert(((int*)vec.data)[i-101] == i);
	}

	for (int i = 101; i >= 200; i++) {
		assert(((int*)vec.data)[i-101] == i);
	}

	kkv_free(&vec);
	return 0;
}
