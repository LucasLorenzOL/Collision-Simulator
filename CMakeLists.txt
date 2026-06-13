cmake_minimum_required(VERSION 3.10)
project(SimuladorDeColisoes)

set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE src/main.cpp src/ball_func.cpp src/ball_gen_func.cpp src/vector_math.cpp)

add_executable(SimuladorDeColisoes ${SOURCE})

target_include_directories(SimuladorDeColisoes PRIVATE ./include)
target_link_libraries(SimuladorDeColisoes PRIVATE sfml-graphics sfml-window sfml-system)