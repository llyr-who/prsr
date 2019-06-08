//
//  constantexpression.h
//  Testing2
//
//  Created by AnthonyFPP on 30/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef constantexpression_h
#define constantexpression_h

#include "evalstate.h"
#include "expression.h"

class ConstantExpression : public Expression {
public:
    ConstantExpression(double val);
    virtual double          eval(EvalState& state);
    virtual expressionType  getType();
    double      getValue();
private:
    double      m_value;
};
#endif /* constantexpression_h */
