cmake_minimum_required(VERSION 3.28)
project("search_engine" VERSION 0.01)

set(CMAKE_CXX_STANDARD 20)

set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR})
file(COPY config.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY requests.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY answers.json DESTINATION ${CMAKE_BINARY_DIR})

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR})

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

add_subdirectory(nlohmann_json)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(search_engine PUBLIC include)