//
//  expression.h
//  Testing2
//
//  Created by AnthonyFPP on 26/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef Expression_hpp
#define Expression_hpp

#include "evalstate.h"

enum expressionType {kConstantExpression,
                     kVariableExpression,
                     kBinaryOperation,
                     kUnaryOperation};

class Expression {
public:
    Expression();
    virtual ~Expression();
    void                     setParent(Expression* p);
    Expression*              getParent();
    void                     setGrad(double grad);
    double                   getGrad() { return m_grad; }
    // pure virtual methods
    virtual double           eval(EvalState & state) = 0;
    virtual void             grad(EvalState & state) = 0;
    virtual expressionType   getType() = 0;
    // virtual methods
    virtual Expression*      getLHS() { return nullptr; }
    virtual Expression*      getRHS() { return nullptr; }
    virtual std::string      getName() { return ""; }
protected:
    Expression* parent = nullptr;
    double      m_grad;             // gradient of node
    double      m_value;            // the value of the node
    bool        m_gotValue;         // have we already calculated value?
    bool        m_gotGrad;             // already calculated grad;
};

#endif /* Expression_hpp */
