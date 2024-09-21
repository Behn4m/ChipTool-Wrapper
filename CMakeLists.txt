cmake_minimum_required(VERSION 3.10)

cmake_minimum_required(VERSION 3.10)
project(ChipToolWrapper)

set(CMAKE_CXX_STANDARD 11)

add_executable(ChipTool-Wrapper ./main.cpp ./ChipWrapper.cpp)

# Link with CHIP libraries
# target_link_libraries(chiptool-wrapper chip-sdk)