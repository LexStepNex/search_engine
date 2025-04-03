cmake_minimum_required(VERSION 3.28)

add_executable(test_search_engine test_search_engine.cpp)

target_link_libraries(test_search_engine PRIVATE gtest_main)

target_include_directories(test_search_engine PRIVATE ${MY_INCLUDE_DIR})
target_include_directories(test_search_engine PRIVATE ${CMAKE_SOURCE_DIR}/nlohmann_json/include)

include(GoogleTest)
gtest_discover_tests(test_search_engine)
