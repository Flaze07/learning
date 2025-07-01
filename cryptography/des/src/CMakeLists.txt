add_library(
  project_lib
  bitop.c
  bitio.c
  scratchcode.c
  des.c
)

target_include_directories(
  project_lib
  PUBLIC
    ../include
)
