//
//  parser.hpp
//  Testing2
//
//  Created by AnthonyFPP on 30/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef parser_hpp
#define parser_hpp

#include "expression.h"
#include "scanner.h"
#include "binaryoperation.h"
#include "constantexpression.h"
#include "variableexpression.h"
#include "unaryoperation.h"
Expression *ParseExpression(Scanner& scanner, int prec = 0);
Expression *ReadExpression(Scanner& scanner, int prec = 0);
Expression *ReadTerm(Scanner& scanner);
int         Precedence(std::string token);

#endif /* parser_hpp */
