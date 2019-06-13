#include "scanner.h"
#include "evalstate.h"
#include "parser.h"
#include "expressiongraph.h"

#include <iostream>


int main()
{
    Scanner scn;
    scn.setInput("x*x+y*y");
    EvalState state;
    state.setValue("x", 1);
    state.setValue("y", 2);
    ExpressionGraph g(ParseExpression(scn), state);
    //std::cout << g.ForwardPass() << std::endl;
    return 0;
}
