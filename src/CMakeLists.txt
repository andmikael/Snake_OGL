cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-std=c++17")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(sources main.cpp Game.cpp GLGraphics.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${sources})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})