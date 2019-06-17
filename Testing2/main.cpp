#include "scanner.h"
#include "evalstate.h"
#include "parser.h"
#include "expressiongraph.h"

#include <iostream>


int main()
{
    Scanner scn;
    scn.setInput("(x+10)*(x+10)");
    // derivative 2*x + 20
    scn.setInput("x*x*2");
    EvalState state;
    state.setValue("x", 1);
    ExpressionGraph g(ParseExpression(scn), state);
    return 0;
}
