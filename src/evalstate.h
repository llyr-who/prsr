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

#include <iostream>
#include <map>
#include <string>

class EvalState {
public:
    EvalState();
   ~EvalState();
    void     setValue(std::string var, double val);
    double   getValue(std::string var);
    void     setGradient(std::string var, double val);
    double   getGradient(std::string var);
    bool     isDefined(std::string var);
    
    void output() {
        std::cout << "values: " << std::endl;
        for(auto& var : m_symbolTable) {
            std::cout << var.first << " " << var.second << std::endl;
        }
        std::cout << "gradients: " << std::endl;
        for(auto& var : m_gradientTable) {
            std::cout << var.first << " " << var.second << std::endl;
        }
    }
    
private:
    std::map<std::string, double> m_symbolTable;
    std::map<std::string, double> m_gradientTable;

};

#endif /* evalstate_hpp */
