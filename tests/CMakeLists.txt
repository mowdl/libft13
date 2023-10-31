cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Include the directory containing libft.a and libft.h
include_directories(${CMAKE_SOURCE_DIR}/../libft)

# Add your libft library (assuming it's named libft.a)
add_library(libft STATIC IMPORTED)
set_target_properties(libft PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../libft/libft.a)

add_executable(
  hello_test
  hello_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
  libft # Link with your libft library
)

include(GoogleTest)
gtest_discover_tests(hello_test)
