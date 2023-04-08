cmake_minimum_required(VERSION 3.13)
project(mcmc)
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(external/eigen)
include_directories(include)
find_package(ifopt)
find_package(pybind11)
pybind11_add_module(${PROJECT_NAME} src/main.cpp src/barrier_walk.cpp src/central.cpp src/dikin_walk.cpp src/dikinls_walk.cpp src/john_walk.cpp src/vaidya_walk.cpp src/facial_reduction.cpp src/ball_walk.cpp src/random_walk.cpp src/hitrun.cpp)
#add_executable(${PROJECT_NAME} src/test.cpp src/barrier_walk.cpp src/central.cpp src/dikin_walk.cpp src/dikinls_walk.cpp src/john_walk.cpp src/vaidya_walk.cpp src/facial_reduction.cpp src/ball_walk.cpp src/random_walk.cpp src/hitrun.cpp)


target_link_libraries(${PROJECT_NAME} PUBLIC pybind11::module eigen ifopt::ifopt_ipopt) 