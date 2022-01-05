#include "Student.h"

Student::Student(int r) : roll(r)
{

}

void Student::fun() const
{
    ( const_cast <Student*> (this) )->roll = 5;
}

int Student::getRoll()
{
    return roll;
}
