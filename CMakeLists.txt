cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/9406a60c7839052e4944ea4dbc8344762a89f9bd.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(
    SOURCES 
    "Chapters/01 Arrays and Strings/01 IsUnique.h" 
    "Chapters/01 Arrays and Strings/02 CheckPermutation.h"
    "Chapters/01 Arrays and Strings/03 Urlify.h"
    "Chapters/01 Arrays and Strings/04 Palindrome permutation.h"
)

enable_testing() 


add_executable(
  unittest
  unittest.cc
  ${SOURCES}
)

target_link_libraries(
  unittest
  gtest_main
)

target_include_directories(unittest PRIVATE "Chapters/01 Arrays and Strings")

include(GoogleTest)
gtest_discover_tests(unittest)
