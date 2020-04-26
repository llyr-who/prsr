#ifndef parser_hpp
#define parser_hpp

#include "expression.h"
#include "scanner.h"
#include "binaryoperation.h"
#include "constantexpression.h"
#include "variableexpression.h"

Expression *ParseExpression(Scanner& scanner, int prec = 0);
Expression *ReadExpression(Scanner& scanner, int prec = 0);
Expression *ReadTerm(Scanner& scanner);
int         Precedence(std::string token);

#endif /* parser_hpp */
