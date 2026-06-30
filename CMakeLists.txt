cmake_minimum_required(VERSION 3.14)

project(kkvector
	VERSION      0.0
	DESCRIPTION  "A vector library in C"
	HOMEPAGE_URL "https://github.com/KoffeeKernel/kkvector"
	LANGUAGES    C
)

enable_testing()

function(make_test UNIT)
	add_executable(kkv_${UNIT} tests/test_${UNIT}.c)
	target_link_libraries(kkv_${UNIT} PRIVATE kkvector)
	add_test(NAME kkv_${UNIT} COMMAND kkv_${UNIT})
endfunction()
