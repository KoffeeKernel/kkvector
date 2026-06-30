#include <assert.h>

#include "kkvector.h"

int main(void) {
	kkv_vector vec;
	assert(kkv_init(&vec, sizeof(int), 8) == 0);

	kkv_clear(&vec);
	assert(vec.size == 0);

	for (int i = 1; i <= 100; i++) {
		assert(kkv_push(&vec, &i) == 0);
	}

	kkv_clear(&vec);
	assert(vec.size == 0);

	kkv_free(&vec);
	return 0;
}
