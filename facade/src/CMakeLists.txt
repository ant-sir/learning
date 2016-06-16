INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
SET(SRC_LIST Cipher.cpp
             Facade.cpp
             Reader.cpp
             Writer.cpp
             main.cpp
)
ADD_EXECUTABLE(facade ${SRC_LIST})
