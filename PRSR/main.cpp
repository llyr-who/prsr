#include "scanner.h"
#include "evalstate.h"
#include "parser.h"
#include "expressiongraph.h"

#include <iostream>

int main()
{
    Scanner scn;
    scn.setInput("sin(x) + y*y*y");
    EvalState state;
    state.setValue("x", 9287349);
    state.setValue("y", 2);
    ExpressionGraph g(ParseExpression(scn), state);
    std::cout << scn.getBuffer() << std::endl;
    state.output();
    return 0;
}
