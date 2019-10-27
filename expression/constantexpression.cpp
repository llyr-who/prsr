#include "expression/constantexpression.h"

using PRSR::expression::constantexpression

constantexpression::constantexpression(double val) {
    m_value = val;
    m_gotValue = true;
}

double constantexpression::eval(EvalState& state) {
    return m_value;
}

void constantexpression::grad(EvalState& state) {
}

expressionType constantexpression::getType() { return kConstantExpression; }
