//
//  expressiongraph.cpp
//  Testing2
//
//  Created by AnthonyFPP on 08/06/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#include "expressiongraph.h"

namespace {
std::map<std::string, Expression*> repeatedSyms;
}

ExpressionGraph::ExpressionGraph(Expression* graph, EvalState& state)
    : graph(graph), state(state) {
    fixExpressionGraph(graph);
    ForwardPass();
    BackwardPass();
}

// This function fixes duplicate variable nodes by
// replacing repeated variables with the first encountered
// one. Then adding parents of the duplicate variable nodes
// to the original.
//
// Notes:
// -1, 1 indicate that we are calling
// the function recursively on the
// LHS and RHS respectively. If we introduce
// unary operations then we pass 0
void ExpressionGraph::fixExpressionGraph(Expression* node, int side) {
    if (node->getType() == kBinaryOperation) {
        node->getLHS()->setParent(node);
        node->getRHS()->setParent(node);
        fixExpressionGraph(node->getLHS(), -1);
        fixExpressionGraph(node->getRHS(), 1);
    } else if (node->getType() == kVariableExpression) {
        std::string name = node->getName();
        auto it = repeatedSyms.find(name);
        if (it != repeatedSyms.end()) {
            if (side == -1) {
                static_cast<BinaryOperation*>(node->getParent())
                    ->setLHS(repeatedSyms[name]);
            } else if (side == 1) {
                static_cast<BinaryOperation*>(node->getParent())
                    ->setRHS(repeatedSyms[name]);
            } else if (side == 0) {
            } else {
            }
            // this is essential for back prop
            static_cast<VariableExpression*>(repeatedSyms[name])
                ->addParent(node->getParent());
            // the following line of code
            // does nothing at the moment. I think.
            delete node;
        } else {
            repeatedSyms[name] = node;
        }
    }
}

double ExpressionGraph::ForwardPass() { return graph->eval(state); }

double ExpressionGraph::BackwardPass() {
    graph->setGrad(1);
    graph->grad(state);
    return 1.0;
}
