//
//  binaryoperation.cpp
//  Testing2
//
//  Created by AnthonyFPP on 31/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#include <stdio.h>
#include "binaryoperation.h"

BinaryOperation::BinaryOperation(char operation,
                                 Expression *lhs,
                                 Expression *rhs)
                                : op(operation),
                                  lhs(lhs),
                                  rhs(rhs) {}

double BinaryOperation::eval(EvalState& state) {
    if(!m_gotValue) {
        m_gotValue = true;
        if(op == '+') {
            m_value = lhs->eval(state) + rhs->eval(state);
        } else if(op == '*') {
            m_value = lhs->eval(state) * rhs->eval(state);
        } else if(op == '/') {
            m_value = lhs->eval(state) / rhs->eval(state);
        } else {
            m_value = lhs->eval(state) - rhs->eval(state);
        }
    }
    return m_value;
}

void BinaryOperation::grad(EvalState& state) {
    if(op == '*') {
        //std::cout << lhs->eval(state) << std::endl;
        lhs->setGrad(lhs->getGrad() + m_grad*rhs->eval(state));
        rhs->setGrad(rhs->getGrad() + m_grad*lhs->eval(state));
    } else if (op == '+') {
        lhs->setGrad(lhs->getGrad() + m_grad*1);
        rhs->setGrad(rhs->getGrad() + m_grad*1);
    }
    lhs->grad(state);
    rhs->grad(state);
}

void BinaryOperation::setLHS(Expression* e) { lhs = e;}
void BinaryOperation::setRHS(Expression* e) { rhs = e;}



expressionType BinaryOperation::getType() { return kBinaryOperation; }
