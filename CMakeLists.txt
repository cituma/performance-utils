cmake_minimum_required(VERSION 3.5)
project(PerformanceUtils LANGUAGES C CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED 14)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE release CACHE STRING "Choose the type of build" FORCE)
endif()

# cmake tools 
include(${PROJECT_SOURCE_DIR}/cmake/utils.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

## add OpenCV
#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR})

set(MMULT_LIB mmult)
add_subdirectory(cpu_gemm)
add_subdirectory(unittest)

# print
function(string_status text value)
    set(status_placeholder_length 24)
    string(RANDOM LENGTH ${status_placeholder_length} ALPHABET " " status_placeholder)
    string(LENGTH "${text}" status_text_length)
    if(status_text_length LESS status_placeholder_length)
        string(SUBSTRING "${text}${status_placeholder}" 0 ${status_placeholder_length} status_text)
    else()
        set(status_text "${text}")
    endif()
    string(TOLOWER ${value} status_value)
    message(STATUS "${status_text}  : ${status_value}")
endfunction()
message("===============================================================================")
string_status("C compiler"                     ${CMAKE_C_COMPILER})
string_status("C++ compiler"                   ${CMAKE_CXX_COMPILER})
#string_status("opencv libs"                    ${OpenCV_LIBRARIES})
#string_status("opencv include"                 ${OpenCV_INCLUDE_DIRS})
message("===============================================================================")



