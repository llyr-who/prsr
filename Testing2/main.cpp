#include "scanner.h"
#include "evalstate.h"
#include "parser.h"
#include "expressiongraph.h"

#include <iostream>


int main()
{
    Scanner scn;
    scn.setInput("(x+10)*(10+x) + (y+2)*(10*y)");
    ExpressionGraph g(ParseExpression(scn));
    
    return 0;
}
