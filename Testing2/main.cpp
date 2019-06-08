#include "scanner.h"
#include "evalstate.h"
#include "parser.h"
#include "graphutils.h"

#include <iostream>


int main()
{
    std::cout << "please type expression" << std::endl;
    Scanner scn;
    // We should write a method that takes
    // in s string and puts the parens in the
    // correct place.
    scn.setInput("(x+10)*(10+x) + (y+2)*(10*y)");
    std::cout << scn.getBuffer() << std::endl;
    Expression* parsed = ParseExpression(scn);
    
    fixExpressionGraph(parsed);
    
    std::cout << std::endl;
    
    auto m = returnMap();
    return 0;
}
