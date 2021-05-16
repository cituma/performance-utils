cmake_minimum_required(VERSION 3.5)

file(GLOB mmult_srcs "${CMAKE_CURRENT_SOURCE_DIR}/mmult/*.cpp")
add_library(
    ${MMULT_LIB}
    ${mmult_srcs}
    )
add_executable(
    gemm_demo
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    )

target_link_libraries(
    gemm_demo
    ${MMULT_LIB}
    ${OpenCV_LIBRARIES}
    )
if(ANDROID)
    target_link_libraries(
        gemm_demo
        PUBLIC log
    )
endif()

