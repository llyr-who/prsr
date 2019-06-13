//
//  parser.cpp
//  Testing2
//
//  Created by AnthonyFPP on 30/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#include <iostream>

#include "parser.h"

#include <cctype>

// Bugs

// When we encounter an operator that has lesser precendence than the
// last one encountered in the same recursion layer, we need to ignore
// it at force it to appear higher up in the tree.
// For example x*x+y*y.
// When the * is discovered we encounter the + in the same recursion layer
// where prec = 0.


Expression *ParseExpression(Scanner& scanner, int prec)
{
    Expression *e = ReadExpression(scanner, prec);
    if(scanner.hasMoreTokens()) {
        std::cout << "found more tokens " + scanner.nextToken() << std::endl;
    }
    return e;
}

Expression *ReadExpression(Scanner& scanner, int prec) {
    Expression *exp = ReadTerm(scanner);
    std::string token;
    while (true) {
        std::cout << scanner.getBuffer() << std::endl;
        token = scanner.nextToken();
        int newPrec = Precedence(token);
        std::cout << newPrec << " " << prec << std::endl;
        std::cout << token << "operation encountered" << std::endl;
        if (newPrec <= prec) {
            std::cout << "breaking" << std::endl;
            break;
        }
        Expression *rhs = ReadExpression(scanner, newPrec);
        exp = new BinaryOperation(token[0], exp, rhs);
        std::cout << token << "operation created" << std::endl;
    }
    scanner.saveToken(token);
    return exp;
}


// This needs to be altered to deal with possible unary operators
Expression *ReadTerm(Scanner& scanner) {
    Expression *exp;
    std::string token = scanner.nextToken();
    if (isdigit(token[0])) {
        exp = new ConstantExpression(std::stoi(token));
    } else if (isalpha(token[0])) {
        exp = new VariableExpression(token);
    } else if (token == "(") {
        exp = ReadExpression(scanner);
        token = scanner.nextToken();
        if (token != ")" && token != "") {
            std::cout << "Unbalanced parentheses in expression" << std::endl;
            std::cout << token << std::endl;
        }
    } else if (token == "" ) {
        exp = nullptr;
    } else {
        exp = nullptr;
        std::cout << "Illegal term in expression " << token << std::endl;
    }
    return exp;
}

bool IsOperator(std::string token) {
    if (token.length() != 1) return false;
    switch (token[0]) {
        case '+': case '-': case '*': case '/': case '=':
            return true;
        default:
            return false;
    }
}

int Precedence(std::string token) {
    if (token.length() > 1) return 0;
    switch (token[0]) {
        case '=': return 1;
        case '+': case '-': return 2;
        case '*': case '/': return 3;
        default:  return 0;
    }
}


