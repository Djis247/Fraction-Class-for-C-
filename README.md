# Fraction-Class-for-C++
This is a Fraction class for C++.
Designed for those who think that C++ is not compatible with fraction Math and
other things that require the use of fractions.

## Contents
- [How to use this class!](#how-to-use-the-fraction-class)
	- [Creating a fraction](#1)
	- [Fraction Arithmetic](#2)
	- Functions
		- [Special Functions](#3)
		- [Object Functions](#4)
	- [Signs](#5)
	- [Comparison](#6)


### How to use the Fraction class.
- How to set it up.

If you don't know how to install or use C++ classes, than you probably don't belong here.
Otherwise, continue.
# -------------------------------------------------------------------
###### 1
- Creating a fraction.

To create a fraction after you included the class `#include <Fraction.h>` you must declare the following:
```
Fraction fraction; //For an undefined fraction
Fraction fraction2{ 2, 3 }; //For the fraction 2/3
```
If you do not specify the denominator, do not despair it will put an automatic 1 for it.
```
Fraction fraction3{ 5 }; //Will be 5/1
```
Though giving a denominator of 0 to a fraction will result in an error because it will be mathematically undefined.
```
Fraction fraction4{ 8, 0 }; //Will result in an error
```
All of the above examples **will work with `const` objects.**

If you use a console interface you may input and output using `std::cin` and `std::cout`.
For example:
```
#include <iostream>

int main() {
	std::cout << "Enter a fraction: ";
	Fraction test;
	std::cin >> test;
	std::cout << "You have entered the fraction: " << test;
}
```
When the program runs:
```
Enter a fraction: 2/3
You have entered the fraction: 2/3
```
# -------------------------------------------------------------------
###### 2
- Fraction Arithmetic

To do simple arithmetic processes simply add, subtract, multiply, or divide each `Fraction` with either another `Fraction` or `int`.
```
Fraction f1{ 1, 2 };
Fraction f2{ 4 };
Fraction f3 = f1 * f2; //The Fraction f3 will equal 2 because 1/2 of 4 equals 2
```
# -------------------------------------------------------------------
###### 3
- Special functions

This class comes with special functions that can be used with `int`'s.
Such as:
```
//This function returns the Greatest Common Factor of two ints
Fraction::gcf(4, 8); //It will return 4 because 4 can 'fit' into 4 and 8

//This function returns the Least Common Denominator (or Multiple, same thing) of two ints
Fraction::lcd(6, 7); //It will return 42 because it is the smallest number both 6 and 7 can 'fit' into
```

# -------------------------------------------------------------------
###### 4
- Object functions
There are some functions that come with this class that work with the functions.
Such as:
```
Fraction test{ 6, 9 }; //Our fraction named test

//Notice when doing arithmetic with Fraction's they auto-reduce 
test.reduce(); //Will reduce this fraction to 2/3

//Notice that it is a double value, and therefore rounds decimals
test.evaluate(); //Returns a double value that equals the Fraction. In this case: .666667

test.getNum(); //Returns the numerator of the Fraction. In this case: 2

test.getDen(); //Returns the denominator of the Fraction. In this case: 3

test.set( 9, 10 ); //Sets the fraction to 9/10 after initialization
```
**If you want to turn off auto-reduce set this global variable false `Fraction::autoReduce = false;`**

**Fractions can be `static_cast<double>()`.**

# -------------------------------------------------------------------
###### 5
- Signs

To set a different sign to a `Fraction` just add either a `+` or a `-` in front of the `Fraction`;
```
Fraction test{ 2, 3 };
+test; //Returns a +2/3
-test; //Return a -2/3

Fraction test2{ `2, 3 };
-test; //Returns a +2/3
//Because in Math two negatives equals a positive
```

# -------------------------------------------------------------------
###### 6
- Comparison

You may Compare either a `Fraction` with a `Fraction`, a `Fraction` with an `int`, or an `int` with a `Fraction`.

Using all of the following: `>`, `<`, `>=`, `<=`, `==`, or `!=`
