cmake_minimum_required(VERSION 3.13)
project(mcmc)
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O2")

add_subdirectory(external/eigen)
include_directories(include)
find_package(ifopt)
#xfind_package (Python COMPONENTS Interpreter Development)

#set(PYTHON_LIBRARY_DIR "~/opt/anaconda3/lib/python3.9/site-packages") 
#set(PYTHON_LIBRARY_DIR "/Users/bennysun/Code/mcmc_cpp/_skbuild/macosx-10.16-x86_64-3.9/cmake-install") 
#set(MUQ_USE_PYTHON ON)
#set(PYTHON_EXECUTABLE "~/opt/anaconda3/bin/python")

find_package(pybind11)

pybind11_add_module(${PROJECT_NAME} MODULE src/main.cpp src/barrier_walk.cpp src/central.cpp src/dikin_walk.cpp src/dikinls_walk.cpp src/john_walk.cpp src/vaidya_walk.cpp src/facial_reduction.cpp src/ball_walk.cpp src/random_walk.cpp src/hitrun.cpp)
#add_executable(${PROJECT_NAME} src/test.cpp src/barrier_walk.cpp src/central.cpp src/dikin_walk.cpp src/dikinls_walk.cpp src/john_walk.cpp src/vaidya_walk.cpp src/facial_reduction.cpp src/ball_walk.cpp src/random_walk.cpp src/hitrun.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC pybind11::module eigen ifopt::ifopt_ipopt) 
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION .
)