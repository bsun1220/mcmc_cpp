# Install script for directory: /Users/bennysun/mcmc_cpp/external/eigen/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/bennysun/Installations")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/Cholesky"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/CholmodSupport"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/Core"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/Dense"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/Eigen"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/Eigenvalues"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/Geometry"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/Householder"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/IterativeLinearSolvers"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/Jacobi"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/LU"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/MetisSupport"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/OrderingMethods"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/PaStiXSupport"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/PardisoSupport"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/QR"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/QtAlignedMalloc"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/SPQRSupport"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/SVD"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/Sparse"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/SparseCholesky"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/SparseCore"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/SparseLU"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/SparseQR"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/StdDeque"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/StdList"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/StdVector"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/SuperLUSupport"
    "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/UmfPackSupport"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE DIRECTORY FILES "/Users/bennysun/mcmc_cpp/external/eigen/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

