cmake_minimum_required(VERSION 3.20)

project(
  last_des
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
  last_des
  app/app.cpp
)

add_subdirectory(
  src
)

target_link_libraries(
  last_des
  project_lib
)
