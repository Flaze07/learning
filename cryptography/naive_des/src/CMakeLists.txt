add_library(
  project_lib
  bit_array.c
  scratchcode.c
)

target_include_directories(
  project_lib
  PUBLIC
    ../include
)
