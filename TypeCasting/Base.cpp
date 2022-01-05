#include "Base.h"

#include <iostream>

Base::Base()
{

}

void Base::printInfo()
{
    std::cout<<"I'm Base Class.."<<std::endl;
}

void Base::print()
{
    std::cout<<"Virtual Base class func.."<<std::endl;
}
