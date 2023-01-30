cmake_minimum_required(VERSION 3.21)
project(snake_game)

set(CMAKE_CXX_STANDARD 23)

file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${PROJECT_BINARY_DIR})

include_directories($ENV{SFML_ROOT}/include)
link_directories($ENV{SFML_ROOT}/lib)

add_executable(snake_game main.cpp GameEngine.cpp RenderingEngine.cpp Snake.cpp Settings.cpp Game.cpp)
target_link_libraries(snake_game sfml-system sfml-graphics sfml-window)
