INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
SET(SRC_LIST 
            TestPaperA.cpp
            TestPaperB.cpp
            TestPaper.cpp
            main.cpp
)
ADD_EXECUTABLE(template_method ${SRC_LIST})
