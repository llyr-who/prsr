//
//  expression.cpp
//  Testing2
//
//  Created by AnthonyFPP on 31/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#include <stdio.h>

#include "expression.h"

Expression::Expression() { /* Empty */ }
Expression::~Expression() { /* Empty */ }

void Expression::setParent(Expression* p) {
    parent = p;
}
Expression* Expression::getParent() {
    return parent;
}
