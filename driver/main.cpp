#include "prsr/src/evalstate.h"
#include "prsr/src/expressiongraph.h"
#include "prsr/src/parser.h"
#include "prsr/src/scanner.h"

#include <iostream>

int main() {
    Scanner scn;
    scn.setInput("x*y + x*y");
    EvalState state;
    state.setValue("x", 2);
    state.setValue("y", 3);
    ExpressionGraph g(ParseExpression(scn), state);
    std::cout << scn.getBuffer() << std::endl;
    state.output();
    return 0;
}
