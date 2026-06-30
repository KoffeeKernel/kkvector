cmake_minimum_required(VERSION 3.14)

project(kkvector
	VERSION      0.7
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

add_library(kkvector src/kkvector.c)
target_include_directories(kkvector PUBLIC include)
target_compile_features(kkvector PUBLIC c_std_99)
set_target_properties(kkvector PROPERTIES C_EXTENSIONS OFF)

make_test(init)
make_test(reserve)
make_test(push)
make_test(pop)
make_test(get)
make_test(set)
make_test(clear)
