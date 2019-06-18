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
    if(state.isDefined(name)) {
        return state.getValue(name);
    }
    std::cout << "corrupt state" << std::endl;
    return 0;
}

void VariableExpression::grad(EvalState &state) {
    if(!m_gotGrad){
        m_gotGrad = true;
        state.setGradient(name, m_grad);
    }
}

expressionType VariableExpression::getType() { return kVariableExpression; }

void VariableExpression::addParent(Expression* p){
    otherParents.push_back(p);
}
