//
//  variableexpression.h
//  Testing2
//
//  Created by AnthonyFPP on 30/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef variableexpression_h
#define variableexpression_h

#include "evalstate.h"
#include "expression.h"

#include <vector>

class VariableExpression : public Expression {
public:
    VariableExpression(std::string name);
    virtual double           eval(EvalState& state);
    virtual void             grad(EvalState& state);
    virtual expressionType   getType();
    void                     addParent(Expression*);
    std::string              getName() { return name; }
private:
    std::string name;
    std::vector<Expression* > otherParents;
};

#endif /* variableexpression_h */
