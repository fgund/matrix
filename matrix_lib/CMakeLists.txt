cmake_minimum_required(VERSION 3.2)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) 
#conan_basic_setup(TARGETS)

add_library(matrix_lib STATIC src/matrix.cpp)

set_target_properties(
	matrix_lib
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(matrix_lib PUBLIC ./include)

if (MSVC)
    target_compile_options(matrix_lib PRIVATE
        /W4 /MD
    )
else ()
    target_compile_options(matrix_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()