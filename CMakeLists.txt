cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

add_subdirectory(${PROJECT_SOURCE_DIR}/algorithm)
add_subdirectory(${PROJECT_SOURCE_DIR}/decorator)
add_subdirectory(${PROJECT_SOURCE_DIR}/facade)
add_subdirectory(${PROJECT_SOURCE_DIR}/factory_method)
add_subdirectory(${PROJECT_SOURCE_DIR}/prototype)
add_subdirectory(${PROJECT_SOURCE_DIR}/proxy)
add_subdirectory(${PROJECT_SOURCE_DIR}/simple_factory)
add_subdirectory(${PROJECT_SOURCE_DIR}/strategy)
add_subdirectory(${PROJECT_SOURCE_DIR}/template_method)
