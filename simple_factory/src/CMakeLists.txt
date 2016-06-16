INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
SET(SRC_LIST 
            OperationAdd.cpp
            Operation.cpp
            OperationDiv.cpp
            OperationFactory.cpp
            OperationMul.cpp
            OperationSub.cpp
            main.cpp
)
ADD_EXECUTABLE(simple_factory ${SRC_LIST})
