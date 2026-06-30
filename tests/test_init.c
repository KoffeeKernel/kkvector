#include <assert.h>

#include "kkvector.h"

int main(void) {
	kkv_vector vec = {
		.size     = 1,
		.stride   = sizeof(char),
		.capacity = 1,
		.data     = NULL
	};

	assert(kkv_init(&vec, 0, 8) != 0);
	assert(vec.size     == 1);
	assert(vec.stride   == sizeof(char));
	assert(vec.capacity == 1);
	assert(vec.data     == NULL);

	assert(kkv_init(&vec, sizeof(int), 0) != 0);
	assert(vec.size     == 1);
	assert(vec.stride   == sizeof(char));
	assert(vec.capacity == 1);
	assert(vec.data     == NULL);

	assert(kkv_init(&vec, sizeof(int), 8) == 0);
	assert(vec.size     == 0);
	assert(vec.stride   == sizeof(int));
	assert(vec.capacity == 8);
	assert(vec.data     != NULL);

	kkv_free(&vec);
	return 0;
}
