#include "scanner.h"
#include "evalstate.h"
#include "parser.h"
#include "expressiongraph.h"

#include <iostream>


int main()
{
    Scanner scn;
    scn.setInput("(x+10)*(x+10)+(y+1)*(y+1)");
    scn.setInput("x*x*y*y");
    EvalState state;
    state.setValue("x", 3);
    state.setValue("y", 2);
    ExpressionGraph g(ParseExpression(scn), state);
    std::cout << g.ForwardPass() << std::endl;
    return 0;
}
