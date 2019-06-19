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

Expression *ParseExpression(Scanner& scanner, int prec)
{
    Expression *e = ReadExpression(scanner, prec);
    scanner.nextToken(); // burn last token - auto-saved from ReadExpression
    if(scanner.hasMoreTokens()) {
        std::string state = scanner.getBuffer();
        std::cout << "found more tokens " + state.substr(scanner.getCurrentIndex(),
                                                         state.length()) << std::endl;
    }
    return e;
}

Expression *ReadExpression(Scanner& scanner, int prec) {
    Expression *exp = ReadTerm(scanner);
    std::string token;
    while (true) {
        token = scanner.nextToken();
        int newPrec = Precedence(token);
        if (newPrec <= prec) {
            break;
        }
        Expression *rhs = ReadExpression(scanner, newPrec);
        exp = new BinaryOperation(token[0], exp, rhs);
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
        // search through list of unary functions
        // if(unary expression available) {
        //      1. exp = ReadExpression
        //      2. exp = new UnaryOperation(token, exp);
        //      3. if(token != ")") { complain!; }
        // } else {
        exp = new VariableExpression(token);
    } else if (token == "(") {
        exp = ReadExpression(scanner);
        token = scanner.nextToken();
        if (token != ")" && token != "") {
            std::cout << "Unbalanced parentheses in expression" << std::endl;
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


