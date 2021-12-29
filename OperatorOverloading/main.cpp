#include <iostream>
#include "Complex.h"

int main(int argc, char *argv[]) {

    Complex c1, c2, result;

    std::cout<<"Enter first complex number : "<<std::endl;
    c1.input();

    std::cout<<"Enter second complex number : "<<std::endl;
    c2.input();

    result = c1 + c2;
    result.output();

    return 0;

}
