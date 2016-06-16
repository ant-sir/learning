INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
SET(SRC_LIST 
            CashContext.cpp
            CashNormal.cpp
            CashRebate.cpp
            CashReturn.cpp
            CashSuper.cpp
            main.cpp
)
ADD_EXECUTABLE(strategy ${SRC_LIST})
