#include "Complex.h"


Complex::Complex() : real(0), imag(0)
{



}

Complex Complex::operator+(const Complex& c2) {

    Complex temp;
    temp.real = real + c2.real;
    temp.imag = imag + c2.imag;
    return temp;
}

void Complex::input() {

    std::cin>>real;
    std::cin>>imag;
}

void Complex::output() {

    if(imag < 0)
        std::cout<< "Output complex numbers: "<< real << imag << "i"<<std::endl;
    else
        std::cout<< "Output complex numbers: "<< real << "+" << imag <<"i"<<std::endl;
}
