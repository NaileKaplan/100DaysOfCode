**TYPE CONVERSION**

C++ allows us to convert data of one type to that of another. This is known as type conversion.

There are two types of type conversion in C++.

-Implicit Conversion
-Explicit Conversion (also known as Type Casting)

***Implicit Type Conversion***

The implicit conversion is automatically done by compiler. This conversion does not require any operator. 
They are automatically performed when a value is copied to a compatible type.

***Data Loss During Conversion (Narrowing Conversion)***

It is possible for implicit conversions to lose information, signs can be lost (when signed is implicitly converted to unsigned), and overflow can occur (when long long is implicitly converted to float).

long double -> double -> float -> long -> int -> short -> char (data loss)
char -> short -> int -> long -> float -> double -> long double (no data loss)

```
 short a=2000;
 int b;
 b=a;

```
