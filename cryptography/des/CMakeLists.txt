cmake_minimum_required(VERSION 3.20)

project(
  des
  LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_REQUIRED_LIBRARIES m)

add_executable(
  des
  app/app.c
)

add_subdirectory(
  src
)

target_link_libraries(
  des
  PRIVATE
    project_lib
    m
)
