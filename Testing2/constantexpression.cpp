//
//  constantexpression.cpp
//  Testing2
//
//  Created by AnthonyFPP on 31/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#include "constantexpression.h"

#include <stdio.h>

ConstantExpression::ConstantExpression(double val) : m_value(val) {}

double ConstantExpression::eval(EvalState& state) {
    return 1;
}

expressionType ConstantExpression::getType() { return kConstantExpression; }
