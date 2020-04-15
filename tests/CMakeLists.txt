cmake_minimum_required(VERSION 3.2)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) 
conan_basic_setup(TARGETS)

add_executable(test_matrix test_matrix.cpp)

set_target_properties(
	test_matrix
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_matrix
    matrix_lib
    CONAN_PKG::gtest
)


if (MSVC)
    target_compile_options(test_matrix PRIVATE
        /W4 /MD
    )
else ()
    target_compile_options(test_matrix PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

enable_testing()

add_test(test_matrix "bin/test_matrix")