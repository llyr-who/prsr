#include "variableexpression.h"
namespace {int count;}
VariableExpression::VariableExpression(std::string name) : name(name) {
    count = 0;
}


double VariableExpression::eval(EvalState& state) {
    if(!m_gotValue) {
        m_gotValue = true;
        m_value =  state.getValue(name);
    }
    return m_value;
}

void VariableExpression::grad(EvalState &state) {
    count++;
    if(count > otherParents.size()) {
        state.setGradient(name, m_grad);
    }
}

expressionType VariableExpression::getType() { return kVariableExpression; }

void VariableExpression::addParent(Expression* p){
    otherParents.push_back(p);
}
