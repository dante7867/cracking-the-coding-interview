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


enable_testing() 

add_executable(
  chapter2
  chapter2.cc
)

target_link_libraries(
  chapter2
  gtest_main
)

target_include_directories(chapter2 PRIVATE "Chapters/01 Arrays and Strings" "Chapters/02 Linked Lists")

include(GoogleTest)
gtest_discover_tests(chapter2)
