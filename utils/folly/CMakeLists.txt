cmake_minimum_required(VERSION 3.5)

file(GLOB_RECURSE folly_srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(
    ${FOLLY_LIB}
    ${folly_srcs}
    )


