//
//  expressiongraph.hpp
//  Testing2
//
//  Created by AnthonyFPP on 08/06/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef expressiongraph_hpp
#define expressiongraph_hpp

#include "expression.h"
#include "binaryoperation.h"
#include "variableexpression.h"
#include "constantexpression.h"

class ExpressionGraph {
private:
    Expression* graph;
    void fixExpressionGraph(Expression* node,
                            int side = 0);
    std::map< std::string, Expression* > symInfo;
    EvalState                            state;
public:
    ExpressionGraph(Expression* graph);
    ExpressionGraph(Expression* graph, EvalState& state);
    double ForwardPass();
    double BackwardPass();
};

#endif /* expressiongraph_hpp */
