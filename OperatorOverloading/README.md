## OPERATOR OVERLOADING

Using operator overloading in C++, you can specify more than one meaning for an operator in one scope.

```
class class_name
{
    ... .. ...
    public
       return_type operator symbol (argument(s))
       {
           ... .. ...
       } 
    ... .. ...
};
```
Here,

**returnType** is the return type of the function.<br/><br/><br/>
**operator** is a keyword.
**symbol** is the operator we want to overload. Like: +, <, -, ++, etc.
**argument**s is the arguments passed to the function.

There are 4 operators that cannot be overloaded in C++. They are:

- __:: (scope resolution)__
- __. (member selection)__
- __.* (member selection through pointer to function)__
- __?: (ternary operator)__

Note: We cannot use operator overloading for fundamental data types like **int**, **float**, **char** and so on.
