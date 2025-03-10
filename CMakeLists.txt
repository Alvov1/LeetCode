cmake_minimum_required(VERSION 3.30)
project(LeetCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(LeetCode 297_Serialize_and_Deserialize_Binary_Tree.cpp)

target_compile_options(LeetCode PUBLIC -fsanitize=address -fsanitize=undefined)
target_link_options(LeetCode PUBLIC -fsanitize=address -fsanitize=undefined)
