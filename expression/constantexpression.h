#ifndef CONSTANTEXPRESSION
#define CONSTANTEXPRESSION

#include "core/evalstate.h"
#include "expression/expression.h"
namespace PRSR {
namespace expression {
class constantexpression : public expression {
public:
    constantexpression(double val);
    virtual double eval(EvalState& state);
    virtual void grad(EvalState& state);
    virtual expressionType getType();
    double getValue();
};
}  // namespace expression
}  // namespace PRSR
#endif
