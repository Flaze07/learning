add_library(
  project_lib
  bitop.c
)

target_include_directories(
  project_lib
  PUBLIC
    ../include
)
