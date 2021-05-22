cmake_minimum_required(VERSION 3.5)

#enable_testing()
find_package(GTest REQUIRED)
find_package(GFLAGS REQUIRED)
find_package(GLOG REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})

set(TEST_LIBS 
    ${GTEST_BOTH_LIBRARIES}
    gflags
    glog
)

set(test_main main_ut)
add_executable(
    ${test_main} 
    main.cpp
)
target_link_libraries(
    ${test_main}
    ${GTEST_BOTH_LIBRARIES}
)

set(test_rwspinlock rwspinlock_ut)
add_executable(
    ${test_rwspinlock} 
    RWSpinLockTest.cpp
)
target_link_libraries(
    ${test_rwspinlock} 
    ${TEST_LIBS}
    ${FOLLY_LIB}
)

#set(target unittest)
#set(result_xml unittest_result)
#add_custom_command(
#    TARGET ${target}
#    COMMENT "Execute ${test_main}..."
#    POST_BUILD
#    COMMAND bash -c "${CMAKE_CURRENT_BINARY_DIR}/${test_main} --gtest_output=xml:${result_xml}"
#)

