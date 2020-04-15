cmake_minimum_required(VERSION 3.2)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) 
#conan_basic_setup(TARGETS)

add_executable(matrix_usage main.cpp)

set_target_properties(
	matrix_usage
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(matrix_usage PRIVATE
    matrix_lib
)

if (MSVC)
    target_compile_options(matrix_usage PRIVATE
        /W4 /MD
    )
else ()
    target_compile_options(matrix_usage PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

if (MSVC)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/)
endif()
install(TARGETS matrix_usage RUNTIME DESTINATION bin)

if (MSVC)
    set(CPACK_GENERATOR NSIS)
else ()
    set(CPACK_GENERATOR DEB)
endif()

set(CPACK_PACKAGE_NAME "matrix")

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)
set(CPACK_RESOURCE_FILE_README ${CMAKE_SOURCE_DIR}/README.md)

include(CPack)
