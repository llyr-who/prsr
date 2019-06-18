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
    if(isDefined(var)) return m_symbolTable[var];
    std::cout << "no var exists, consider using isDefined" << std::endl;
    return 0;
}

void EvalState::setGradient(std::string var, double val) {
    m_gradientTable[var] = val;
}

double EvalState::getGradient(std::string var) {
    if(isDefined(var)) return m_gradientTable[var];
    std::cout << "no var exists, consider using isDefined" << std::endl;
    return 0;
}

bool EvalState::isDefined(std::string var) {
    return m_symbolTable.find(var) != m_symbolTable.end();
}
