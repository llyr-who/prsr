//
//  graphutils.hpp
//  Testing2
//
//  Created by AnthonyFPP on 04/06/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef graphutils_h
#define graphutils_h

#include "expression.h"

#include <iostream>
#include <map>
#include <string>

namespace {
    std::map< std::string, Expression* > repeatedSyms;
    Expression* parent;
}

// this function fixes duplicate variables. 
// -1, 1 indicate that we are calling
// the function recursively on the
// LHS and RHS respectively. If we introduce
// unary operations then we pass 0
void fixExpressionGraph(Expression* node, int side = 0) {
    if(node->getType() == kBinaryOperation) {
        node->getLHS()->setParent(node);
        node->getRHS()->setParent(node);
        fixExpressionGraph(node->getLHS(), -1);
        fixExpressionGraph(node->getRHS(),  1);
    }
    else if(node->getType() == kVariableExpression) {
        std::string name = node->getName();
        auto it = repeatedSyms.find(name);
        if(it != repeatedSyms.end()) {
            if(side == -1) {
                static_cast<BinaryOperation*>( node->getParent() )->setLHS(repeatedSyms[name]);
            } else if(side == 1) {
                static_cast<BinaryOperation*>( node->getParent() )->setRHS(repeatedSyms[name]);
            } else if(side == 0) {
                
            } else {}
            // this is essential for back prop
            static_cast<VariableExpression*>(repeatedSyms[name])->addParent(node->getParent());
            // the following line of code
            // does nothing at the moment. I think.
            delete node;
        } else {
            repeatedSyms[name] = node;
        }
    }
}


std::map< std::string, Expression* > returnMap() {
    return repeatedSyms;
}

#endif /* graphutils_hpp */
