#include <iostream>
#include "ImplicitConversion.h"
#include "ExplicitConversion.h"

int main()
{
    ImplicitConversion imp;
    imp.doSomeConversion();

    ExplicitConversion exp;
    exp.doSomeConversion();
    exp.doReinterpretCast();


    return 0;
}
