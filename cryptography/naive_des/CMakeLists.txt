cmake_minimum_required(VERSION 3.20)

project(
  naive_des
  LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
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
)
