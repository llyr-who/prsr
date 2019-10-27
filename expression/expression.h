#ifndef EXPRESSION
#define EXPRESSION

#include "evalstate.h"

namespace PRSR {
namespace expression {

enum expressionType {
    kConstantExpression,
    kVariableExpression,
    kBinaryOperation,
    kUnaryOperation
};

class expression {
public:
    expression() : m_grad(0), m_value(0), m_gotValue(false), parent(nullptr){};
    virtual ~expression(){};
    void setParent(Expression* p) { m_parent = p; };
    expression* getParent() { return m_parent; };
    void setGrad(double grad) { m_grad = grad; };
    double getGrad() { return m_grad; }
    // pure virtual methods
    virtual double eval(EvalState& state) = 0;
    virtual void grad(EvalState& state) = 0;
    virtual expressionType getType() = 0;
    // virtual methods
    virtual Expression* getLHS() { return nullptr; }
    virtual Expression* getRHS() { return nullptr; }
    virtual std::string getName() { return ""; }

protected:
    expression* m_parent;
    double m_grad;    // gradient of node
    double m_value;   // the value of the node
    bool m_gotValue;  // have we already calculated value?
};
}  // namespace expression
}  // namespace PRSR
#endif
