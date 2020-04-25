cmake_minimum_required(VERSION 3.10)

project(prsr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
# for completion in vim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_subdirectory(src)
add_subdirectory(driver)
