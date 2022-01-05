#ifndef EXPLICITCONVERSION_H
#define EXPLICITCONVERSION_H


class ExplicitConversion
{
public:
    ExplicitConversion();
    void doSomeConversion();
    void doConstCast();
    void doReinterpretCast();
    int fun(int* ptr);


    // creating structure mystruct
    struct mystruct {
        int x;
        int y;
        char c;
        bool b;
    };
};

#endif // EXPLICITCONVERSION_H
