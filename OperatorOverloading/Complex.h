#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
    Complex();

public :
    float real;
    float imag;

public:

    Complex operator+ (const Complex& c2);
    void input();
    void output();
};

#endif // COMPLEX_H
