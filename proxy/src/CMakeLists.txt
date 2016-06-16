INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
SET(SRC_LIST 
            main.cpp
            Proxy.cpp
            RealSubject.cpp
            Subject.cpp
)
ADD_EXECUTABLE(proxy ${SRC_LIST})
