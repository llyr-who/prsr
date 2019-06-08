//
//  evalstate.cpp
//  Testing2
//
//  Created by AnthonyFPP on 30/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#include "evalstate.h"

EvalState::EvalState() {};
EvalState::~EvalState() {};

void EvalState::setValue(std::string var, double val) {
    m_symbolTable[var] = val;
}

double EvalState::getValue(std::string var) {
    return m_symbolTable[var];
}

bool EvalState::isDefined(std::string var) {
    return m_symbolTable[var];
}
