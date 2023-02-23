cmake_minimum_required(VERSION 3.0.0)
project(dodgy_array VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(dodgy_array main.cpp)
target_compile_options(dodgy_array PRIVATE -Werror -Wall -Wextra)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
