#include "scanner.h"
#include "evalstate.h"
#include "parser.h"
#include "expressiongraph.h"

#include <iostream>

int main()
{
    Scanner scn;
    scn.setInput("sin( + y*y*y");
    EvalState state;
    state.setValue("sin(", 2);
    state.setValue("y", 2);
    ExpressionGraph g(ParseExpression(scn), state);
    std::cout << scn.getBuffer() << std::endl;
    state.output();
    return 0;
}
