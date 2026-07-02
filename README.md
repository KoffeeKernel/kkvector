# kkvector

![Version 1.0](https://img.shields.io/badge/Version-1.0-green)
![MIT License](https://img.shields.io/badge/License-MIT-blue)

**kkvector** is a vector library in C.

This is a learning project for the author. Feel free to integrate it within
your own builds if ever it finds use.

## Usage

### Initializing a vector
```c
kkv_vector vec;
kkv_init(&vec, sizeof(int), 8);
```

### Operating on elements
```c
int x = 1;
kkv_push(&vec, &x);

int y = 0;
kkv_get(&vec, 0, &y);  // y == 1

// works with compound literals
kkv_set(&vec, 0, &(int){2});

kkv_pop(&vec);
```

### Cleaning up
```c
kkv_free(&vec);
```

## Integration

### Requirements
- CMake 3.14 or higher
- C99-compliant compiler

### Using FetchContent
```cmake
include(FetchContent)

FetchContent_Declare(kkvector
	GIT_REPOSITORY https://github.com/KoffeeKernel/kkvector.git
	GIT_TAG        [tag (recommended), commit_hash, or branch]
)
FetchContent_MakeAvailable(kkvector)

target_link_libraries([target] PRIVATE kkvector)
```

## License
Distributed under the MIT License. See `LICENSE` for more information.
