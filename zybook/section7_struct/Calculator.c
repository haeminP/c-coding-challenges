#include <stdio.h>
#include "Calculator.h"

Calculator InitCalculator()
{
   Calculator calc;
   calc.value = 0.0;
   return calc;
}

Calculator Add(double val, Calculator c)
{
    c.value += val;
    return c;
}
Calculator Subtract(double val, Calculator c)
{
    c.value -= val;
    return c;
}

Calculator Multiply(double val, Calculator c)
{
    c.value *= val;
    return c;
}
Calculator Divide(double val, Calculator c)
{
    c.value /= val;
    return c;
}
Calculator Clear(Calculator c)
{
    c.value = 0.0;
    return c;
}

double GetValue(Calculator c)
{
    return c.value;
}