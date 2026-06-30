#include <assert.h>

#include "kkvector.h"

int main(void) {
	kkv_vector vec;
	assert(kkv_init(&vec, sizeof(int), 8) == 0);

	int x = 1;
	assert(kkv_push(&vec, &x) == 0);
	assert(vec.size == 1);
	assert(((int*)vec.data)[0] == 1);
	assert(x == 1);

	x = 2;
	assert(((int*)vec.data)[0] == 1);

	assert(kkv_push(&vec, &(int){2}) == 0);
	assert(vec.size == 2);
	assert(((int*)vec.data)[1] == 2);

	for (int i = 3; i <= 100; i++) {
		assert(kkv_push(&vec, &i) == 0);
		assert(vec.size == i);
		assert(((int*)vec.data)[i-1] == i);
	}

	for (int i = 1; i <= 100; i++) {
		assert(((int*)vec.data)[i-1] == i);
	}

	kkv_free(&vec);
	return 0;
}
