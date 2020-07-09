#include "TupleExample.h"

#include<iostream>
#include<tuple> // for tuple



TupleExample::TupleExample()
{

    declareTuples();


}

void TupleExample::declareTuples()
{
    tupleEx1 = make_tuple('a', 5 , 1.6 );
    tupleEx2 = make_tuple('b', 0 , 11.2 );

    // Printing initial tuple values using get()
    cout << "The initial values of tuple1 are : ";
    cout << get<0>(tupleEx1) << " " << get<1>(tupleEx1);
    cout << " " << get<2>(tupleEx1) << endl;

    sizeOfTuples(tupleEx1);
    swappingTuples();

}

int TupleExample::sizeOfTuples(tuple<char,int, float> tuplee)
{
    // Use of size to find tuple_size of tuple
    cout << "The size of tuple is : ";
    cout << tuple_size<decltype(tuplee)>::value << endl;

}

// Swapping tup1 values with tup2
void TupleExample::swappingTuples()
{
    tupleEx1.swap(tupleEx2);
    // Printing 1st and 2nd tuple after swapping
    cout << "The first tuple elements after swapping are : ";
    cout <<  get<0>(tupleEx1) << " " << get<1>(tupleEx1) << " "
         << get<2>(tupleEx1) << endl;
    cout << "The second tuple elements after swapping are : ";
    cout <<  get<0>(tupleEx2) << " " << get<1>(tupleEx2) << " "
         << get<2>(tupleEx2) << endl;
}
