INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
SET(SRC_LIST 
            AddFactory.cpp
            Creator.cpp
            OperationAdd.cpp
            Operation.cpp
            OperationSub.cpp
            SubFactory.cpp
            main.cpp
)
ADD_EXECUTABLE(factory_method ${SRC_LIST})
