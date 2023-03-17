cmake_minimum_required(VERSION 3.13)
project(MCMC)
set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME} main.cpp facial_reduction.cpp)
add_subdirectory(external/eigen)
add_subdirectory(external/ifopt)
add_subdirectory(external/pybind)
find_package(ifopt)
find_package(pybind11)
target_link_libraries(${PROJECT_NAME} eigen ifopt::ifopt_ipopt pybind11::module) 


