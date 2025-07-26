add_library(
  project_lib
  bit_array.cpp
  scratchcode.cpp
  des.cpp
)

target_include_directories(
  project_lib
  PUBLIC
    ../include
)
