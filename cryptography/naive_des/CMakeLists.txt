cmake_minimum_required(VERSION 3.20)

project(
  naive_des
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
  ${PROJECT_NAME}
  app/main.cpp
)

add_subdirectory(
  src
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
    project_lib
    m
)
