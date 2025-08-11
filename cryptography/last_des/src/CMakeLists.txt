add_library(
  project_lib
  bitop.cpp
  des.cpp
)

target_include_directories(
  project_lib
  PUBLIC
  ../include
)
