//
//  variableexpression.cpp
//  Testing2
//
//  Created by AnthonyFPP on 01/06/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#include "variableexpression.h"

VariableExpression::VariableExpression(std::string name) : name(name) {}


double VariableExpression::eval(EvalState& state) {
    return 1;
}

expressionType VariableExpression::getType() { return kVariableExpression; }
