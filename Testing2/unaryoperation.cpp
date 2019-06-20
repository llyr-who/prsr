//
//  unaryoperation.cpp
//  Testing2
//
//  Created by AnthonyFPP on 31/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#include "unaryoperation.h"

UnaryOperation::UnaryOperation(std::string operation,
                               Expression *input)
: operation(operation),
inputExpression(input) {}

double UnaryOperation::eval(EvalState& state) {

    return m_value;
}

void UnaryOperation::grad(EvalState& state) {
}

expressionType UnaryOperation::getType() { return kUnaryOperation; }
