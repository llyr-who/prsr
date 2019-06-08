//
//  evalstate.hpp
//  Testing2
//
// Some future implementation might make this
// use a hetero container. That is, we are
// not just restricted to type T
//  Created by AnthonyFPP on 26/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef evalstate_hpp
#define evalstate_hpp

#include <stdio.h>
#include <map>
#include <string>
class EvalState{
public:
    EvalState();
   ~EvalState();
    void     setValue(std::string var, double val);
    double   getValue(std::string var);
    bool     isDefined(std::string var);
private:
    std::map<std::string, double> m_symbolTable;
};

#endif /* evalstate_hpp */
