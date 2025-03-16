cmake_minimum_required(VERSION 3.30)
project(LeetCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(LeetCode 957_Prison_Cells_After_N_Days.cpp)

target_compile_options(LeetCode PUBLIC -fsanitize=address -fsanitize=undefined)
target_link_options(LeetCode PUBLIC -fsanitize=address -fsanitize=undefined)
