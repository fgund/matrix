cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
  message("TRAVIS_BUILD_NUMBER not defined. Setting its value to 1.")
  set(ENV{TRAVIS_BUILD_NUMBER} 1)
endif(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})

project(Otus_CPP_06 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)


enable_testing()

add_subdirectory(src)
add_subdirectory(matrix_lib)
#if(BUILD_TESTING)
  add_subdirectory(tests)
#endif()