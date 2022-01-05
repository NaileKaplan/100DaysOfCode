#ifndef STUDENT_H
#define STUDENT_H


class Student
{
public:
    Student(int r);
    void fun() const;
    int getRoll();

private:
    int roll;
};

#endif // STUDENT_H
