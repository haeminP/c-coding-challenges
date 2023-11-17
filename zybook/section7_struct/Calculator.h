#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef struct Calculator_struct{
    double value;
} Calculator;

Calculator InitCalculator();
Calculator Add(double val, Calculator c);
Calculator Subtract(double val, Calculator c);
Calculator Multiply(double val, Calculator C);
Calculator Divide(double val, Calculator c);
Calculator Clear(Calculator c);
double GetValue(Calculator c);

#endif