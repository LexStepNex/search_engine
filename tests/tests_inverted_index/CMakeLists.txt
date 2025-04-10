cmake_minimum_required(VERSION 3.28)

add_library(inverted_index_lib ${SOURCE_DIR}/inverted_index.cpp)

add_executable(test_inverted_index test_inverted_index.cpp)

target_link_libraries(test_inverted_index PRIVATE gtest_main inverted_index_lib)

target_include_directories(inverted_index_lib PRIVATE ${INCLUDE_DIR})
target_include_directories(test_inverted_index PRIVATE ${INCLUDE_DIR})

include(GoogleTest)
gtest_discover_tests(test_inverted_index)