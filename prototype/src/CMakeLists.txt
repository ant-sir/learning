INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
SET(SRC_LIST 
            ConcretePrototypeA.cpp
            ConcretePrototypeB.cpp
            Prototype.cpp
            main.cpp
)
ADD_EXECUTABLE(prototype ${SRC_LIST})
