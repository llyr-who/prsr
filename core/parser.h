#ifndef parser_hpp
#define parser_hpp

#include "expression/expression.h"
#include "core/scanner.h"
#include "operator/binaryoperator.h"
#include "constantexpression.h"
#include "variableexpression.h"
#include "unaryoperation.h"
Expression *ParseExpression(Scanner& scanner, int prec = 0);
Expression *ReadExpression(Scanner& scanner, int prec = 0);
Expression *ReadTerm(Scanner& scanner);
int         Precedence(std::string token);

#endif /* parser_hpp */
