# Install script for directory: /Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/AdolcForward"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/AlignedVector3"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/ArpackSupport"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/AutoDiff"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/BVH"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/EulerAngles"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/FFT"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/IterativeSolvers"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/KroneckerProduct"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/LevenbergMarquardt"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/MatrixFunctions"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/MoreVectorization"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/MPRealSupport"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/NonLinearOptimization"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/NumericalDiff"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/OpenGLSupport"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/Polynomials"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/Skyline"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/SparseExtra"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/SpecialFunctions"
    "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/Splines"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "/Users/bennysun/mcmc_cpp/external/eigen/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/bennysun/mcmc_cpp/build/external/eigen/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()

