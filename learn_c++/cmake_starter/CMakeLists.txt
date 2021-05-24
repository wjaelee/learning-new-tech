cmake_minimum_required(VERSION 3.14)

# 프로젝트 정보
project(
  wungjaelee
  VERSION 0.1
  DESCRIPTION "예제 프로젝트"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# output library file to build/lib/
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# output executable to build/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(tests)
