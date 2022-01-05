## **TYPE CONVERSION** ##

C++ allows us to convert data of one type to that of another. This is known as type conversion.

There are two types of type conversion in C++.

- Implicit Conversion <br/>
- Explicit Conversion (also known as Type Casting)

### **Implicit Type Conversion** ###

The implicit conversion is automatically done by compiler. This conversion does not require any operator. 
They are automatically performed when a value is copied to a compatible type.

***Data Loss During Conversion (Narrowing Conversion)***

It is possible for implicit conversions to lose information, signs can be lost (when signed is implicitly converted to unsigned), and overflow can occur (when long long is implicitly converted to float).

long double -> double -> float -> long -> int -> short -> char -> bool (data loss) <br/>
bool -> char -> short -> int -> long -> float -> double -> long double (no data loss)

```
 short a=2000;
 int b;
 b=a;

```
### **Explicit Type Conversion** ###

When the user manually changes data from one type to another, this is known as explicit conversion. This type of conversion is also known as type casting.

There are three major ways in which we can use explicit conversion in C++. They are:

1. C-style type casting (also known as cast notation)
2. Function notation (also known as old C++ style type casting)
3. Type conversion operators

***1.C-style Type Casting***
```
   //example
   int sum = (int)m + 1;
```
***2.Function-style Casting***
```
   //example
   num_double = double(num_int);
```
***3.Type conversion operators***
- static_cast
- dynamic_cast
- const_cast
- reinterpret_cast

#### Static Cast ####

It is a compile time cast.It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions (or implicit ones).
```
   int n = static_cast<int>(m);
```
#### Dynamic Cast ####

dynamic_cast can only be used with pointers and references to classes (or with void*). Polymorphism is handled with this cast. It’s only necessary to use when casting to a derived class. In C++, dynamic casting is mainly used for safe downcasting at run time. To work on dynamic_cast there must be one virtual function in the base class.

```
   dynamic_cast <new_type>(Expression)
```
#### Const Cast ####

const_cast is used to cast away the constness of variables. Inside a const member function, non-const class members can be modified with the cast.

#### Reinterpret Cast ####

reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other. All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked. It doesn’t have any return type. It simply converts the pointer type.
