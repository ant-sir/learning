include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_LIST *.cpp)
add_executable(decorator ${SRC_LIST})
