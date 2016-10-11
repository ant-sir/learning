include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(. SRC_LIST)
add_executable(decorator ${SRC_LIST})
