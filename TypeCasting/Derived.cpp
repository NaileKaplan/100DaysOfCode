#include "Derived.h"

#include <iostream>

Derived::Derived()
{

}

void Derived::printInfo()
{
    std::cout<<"I'm Derived Class.."<<std::endl;
}

void Derived::print()
{
    std::cout<<"Virtual Derived class func.."<<std::endl;
}
