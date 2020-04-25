set(HDRS
    binaryoperation.h
    constantexpression.h
    evalstate.h
    expressiongraph.h
    expression.h
    parser.h
    scanner.h
    variableexpression.h)

set(SRCS
    binaryoperation.cpp
    constantexpression.cpp
    evalstate.cpp
    expressiongraph.cpp
    expression.cpp
    parser.cpp
    scanner.cpp
    variableexpression.cpp)

add_library(src_lib ${SRCS} ${HDRS})
