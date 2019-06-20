//
//  unaryoperation.hpp
//  Testing2
//
//  Created by AnthonyFPP on 20/06/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef unaryoperation_hpp
#define unaryoperation_hpp

#include <iostream>
#include <string>
#include <set>
#include "expression.h"

namespace {
    std::set<std::string> availableUnaryOperations = {"sin",
                                                       "cos",
                                                       "exp"};
}

class UnaryOperation : public Expression {
public:
    UnaryOperation( std::string operation,
                    Expression *input);
    virtual double          eval(EvalState& state);
    virtual void            grad(EvalState& state);
    virtual expressionType  getType();
    
    Expression*    getInput() { return inputExpression; }
private:
    std::string operation;
    Expression *inputExpression;
};

#endif /* unaryoperation_hpp */
