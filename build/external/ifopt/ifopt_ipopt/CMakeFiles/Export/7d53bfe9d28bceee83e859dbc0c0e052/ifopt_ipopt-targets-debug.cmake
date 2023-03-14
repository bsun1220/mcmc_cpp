#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ifopt::ifopt_ipopt" for configuration "Debug"
set_property(TARGET ifopt::ifopt_ipopt APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ifopt::ifopt_ipopt PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libifopt_ipopt.dylib"
  IMPORTED_SONAME_DEBUG "@rpath/libifopt_ipopt.dylib"
  )

list(APPEND _cmake_import_check_targets ifopt::ifopt_ipopt )
list(APPEND _cmake_import_check_files_for_ifopt::ifopt_ipopt "${_IMPORT_PREFIX}/lib/libifopt_ipopt.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
