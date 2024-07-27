cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-std=c++17")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(sources main.cpp Game.cpp GLGraphics.cpp Shader.cpp Snake.cpp)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${sources})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLM_LIBRARIES})