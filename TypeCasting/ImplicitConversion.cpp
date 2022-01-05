#include "ImplicitConversion.h"

ImplicitConversion::ImplicitConversion()
{
    b = true;
    c = 'X';
    d = 1234.5;
    i = 123;
    s = 98;
}

void ImplicitConversion::doSomeConversion()
{
    // Statements
    std::cout<<"bool + char is char: "<<b + c<<std::endl;
    std::cout<<"int * short is int: "<< i * s<<std::endl;
    std::cout<<"float * char is float: "<<d * c<<std::endl;

    // bool promoted to char
    c = c + b;

    // char promoted to float
    d = d + c;

    b = false;

    // float demoted to bool
    b = -d;

    std::cout<<"\nAfter execution "<<std::endl;
    std::cout<<"char + true: "<<c<<std::endl;
    std::cout<<"float + char: "<<d<<std::endl;
    std::cout<<"bool = -float: "<<b<<std::endl;
}
