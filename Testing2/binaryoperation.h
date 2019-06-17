//
//  binaryoperation.h
//  Testing2
//
//  Created by AnthonyFPP on 30/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef binaryoperation_h
#define binaryoperation_h
#include "expression.h"

class BinaryOperation : public Expression {
public:
    BinaryOperation(char operation,
                    Expression *lhs,
                    Expression *rhs);
    virtual double          eval(EvalState& state);
    virtual void          grad(EvalState& state);
    virtual expressionType  getType();
    
    Expression*     getLHS() { return lhs;}
    Expression*     getRHS() { return rhs;}
    void            setLHS(Expression* e);
    void            setRHS(Expression* e);
private:
    char op;
    Expression *lhs = nullptr, *rhs = nullptr;
};
#endif /* binaryoperation_h */
