cmake_minimum_required(VERSION 3.5)

#enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})

set(test_name unittest)

add_executable(
    ${test_name} 
    main.cpp
)
target_link_libraries(
    ${test_name}
    ${GTEST_BOTH_LIBRARIES}
    ${FOLLY_LIB}
)

set(target unittest)
set(result_xml unittest_result)
add_custom_command(
    TARGET ${target}
    COMMENT "Execute ${test_name}..."
    POST_BUILD
    COMMAND bash -c "${CMAKE_CURRENT_BINARY_DIR}/${test_name} --gtest_output=xml:${result_xml}"
)

