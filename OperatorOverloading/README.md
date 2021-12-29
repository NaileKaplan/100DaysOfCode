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

**returnType** is the return type of the function.<br/>
**operator** is a keyword.<br/>
**symbol** is the operator we want to overload. Like: +, <, -, ++, etc.<br/>
**argument**s is the arguments passed to the function.<br/>

There are 4 operators that cannot be overloaded in C++. They are:

- __:: (scope resolution)__
- __. (member selection)__
- __.* (member selection through pointer to function)__
- __?: (ternary operator)__

**Note:** With operator overloading, you can redefine the way an operator works only for the user-defined types (objects, structures). You cannot use it for built-in types (float, char, int, etc.).
