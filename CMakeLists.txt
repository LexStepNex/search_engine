cmake_minimum_required(VERSION 3.28)
project("search_engine" VERSION 0.01)

set(CMAKE_CXX_STANDARD 20)

set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR})
file(COPY config.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY requests.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY answers.json DESTINATION ${CMAKE_BINARY_DIR})

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL
        https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(gtest_disable_pthreads on)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(src)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_subdirectory(tests)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(search_engine PUBLIC include)