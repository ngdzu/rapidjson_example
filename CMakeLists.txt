cmake_minimum_required(VERSION 3.0)
project(test)

find_package(RapidJSON  CONFIG REQUIRED)


add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_17)
# target_link_libraries(tutorial_compiler_flags INTERFACE RapidJSON )

add_executable(main main.cpp)

target_link_libraries(main PUBLIC tutorial_compiler_flags)

