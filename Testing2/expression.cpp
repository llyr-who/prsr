//
//  expression.cpp
//  Testing2
//
//  Created by AnthonyFPP on 31/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#include <stdio.h>

#include "expression.h"

Expression::Expression() : m_grad(0),
                           m_value(0),
                           m_gotValue(false),
                           m_gotGrad(false)
                            { /* Empty */ }

Expression::~Expression() { /* Empty */ }

void Expression::setParent(Expression* p) {
    parent = p;
}

void Expression::setGrad(double grad){
    m_grad = grad;
}

Expression* Expression::getParent() {
    return parent;
}
