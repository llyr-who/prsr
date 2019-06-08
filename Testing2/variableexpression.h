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

#include <list>

class VariableExpression : public Expression {
public:
    VariableExpression(std::string name);
    virtual double           eval(EvalState& state);
    virtual expressionType   getType();
    
    std::string              getName() { return name; }
private:
    std::string name;    
};

#endif /* variableexpression_h */
