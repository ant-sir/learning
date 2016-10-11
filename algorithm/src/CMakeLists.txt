file(GLOB SRC_LIST *.cpp)
add_executable(algorithm ${SRC_LIST})
target_link_libraries(algorithm libgtest.a libgmock.a)
