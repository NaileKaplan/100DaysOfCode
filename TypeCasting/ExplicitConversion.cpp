#include "ExplicitConversion.h"
#include "Derived.h"
#include "Base.h"
#include "Student.h"

#include <iostream>

ExplicitConversion::ExplicitConversion()
{

}

void ExplicitConversion::doSomeConversion()
{
    /*Derived* d = new Derived;
    Base* b = static_cast<Base*>(d);*/
    std::cout<<" \n---- STATIC CAST ----"<<std::endl;
    Base *b = new Base();
    Derived *d = static_cast<Derived*>(b);

    d->printInfo();

    std::cout<<" \n---- DYNAMIC CAST ----"<<std::endl;
    Base b1;
    Derived d1;
    Base *pb = dynamic_cast<Base*>(&d1);
    //source type is not polymorphic error. base-to-derived conversions are not allowed with dynamic_cast.
    //if we make the Base class polymorphic by adding virtual function.
    //if -and only if- the pointed object is a valid complete object of the target type.
    Derived *pd = dynamic_cast<Derived*>(&b1);

    if(pd == nullptr)
        std::cout<<"null"<<std::endl;
    else
        std::cout<<"not null"<<std::endl;

    Base *pBDerived = new Derived;
    Base *pBBase = new Base;
    Derived *pd1;

    pd1 = dynamic_cast<Derived*>(pBDerived);
    if(pd1 == nullptr)
        std::cout<<"null pointer first type-cast"<<std::endl;
    pd1 = dynamic_cast<Derived*>(pBBase);
    if(pd1 == nullptr)
        std::cout<<"null pointer second type-cast"<<std::endl;

    std::cout<<" \n---- CONST CAST ----"<<std::endl;
    Student s(3);
    std::cout<<"Old roll number : "<<s.getRoll()<<std::endl;

    s.fun();
    std::cout<<"New roll number : "<<s.getRoll()<<std::endl;

    doConstCast();

}

void ExplicitConversion::doConstCast()
{
    const int val = 10;
    const int *ptr = &val;
    int *ptr1 = const_cast <int *>(ptr);
    fun(ptr1);

    //std::cout << "\n------ doConstCast val1 : "<<fun(ptr1)<<std::endl;
    std::cout << "\n------ doConstCast val2 : "<<val<<std::endl;
}

int ExplicitConversion::fun(int* ptr)
{
    *ptr = *ptr + 10;
    return (*ptr);
}

void ExplicitConversion::doReinterpretCast()
{
    std::cout<<"\n---- doReinterpretCast ----"<<std::endl;
    mystruct s;

    s.x = 5;
    s.y = 10;
    s.c = 'a';
    s.b = true;

    // converting the pointer of 's' to,
    // pointer of int type in 'p'.
    int* p = reinterpret_cast<int*>(&s);

    std::cout << sizeof(s) << std::endl;

    // printing the value currently pointed by *p
    std::cout << *p << std::endl;
    p++;

    // printing the next integer value
    std::cout << *p << std::endl;
    p++;

    // we are casting back char * pointed
    // by p using char *ch.
    char* ch = reinterpret_cast<char*>(p);

    // printing the character value
    // pointed by (*ch)
    std::cout << *ch << std::endl;
    ch++;

    /* since, (*ch) now points to boolean value,
    so it is required to access the value using
    same type conversion.so, we have used
    data type of *n to be bool. */

    bool* n = reinterpret_cast<bool*>(ch);
    std::cout << *n << std::endl;

    // we can also use this line of code to
    // print the value pointed by (*ch).
    std::cout << *(reinterpret_cast<bool*>(ch));



}
