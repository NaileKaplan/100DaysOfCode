#ifndef TUPLEEXAMPLE_H
#define TUPLEEXAMPLE_H

#include <iostream>
#include<tuple> // for tuple
using namespace std;

class TupleExample
{
public:
    TupleExample();
    void declareTuples();
    int sizeOfTuples(tuple <char, int, float> tuplee);
    void swappingTuples();

private:
    tuple <char, int, float> tupleEx1;
    tuple <char, int, float> tupleEx2;
};

#endif // TUPLE_H
