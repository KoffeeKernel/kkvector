cmake_minimum_required(VERSION 3.14)
project(kkvector C)

enable_testing()

find_package(Doxygen)

file(GLOB TEST_SOURCES tests/test_*.c)

add_library(kkvector src/kkvector.c)
target_include_directories(kkvector PUBLIC include)
target_compile_features(kkvector PUBLIC c_std_99)
set_target_properties(kkvector PROPERTIES C_EXTENSIONS OFF)

foreach(TEST_SOURCE ${TEST_SOURCES})
	get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
	add_executable(${TEST_NAME} ${TEST_SOURCE})
	target_link_libraries(${TEST_NAME} kkvector)
	add_test(${TEST_NAME} ${TEST_NAME})
endforeach()

if(DOXYGEN_FOUND)
	doxygen_add_docs(docs include)
endif()
