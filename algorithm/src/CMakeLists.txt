aux_source_directory(. SRC_LIST)
add_executable(algorithm ${SRC_LIST})
target_link_libraries(algorithm libgtest.a libgmock.a)
