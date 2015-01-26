================================
  Cyberbit Game Coding Standards
================================

This files contains the information about coding standards that the developers
of cyberbit game must follow and comply.

Code Implementation
-------------------

1. Properly document your code, so that doxygen can produce the documentation
of your code.

A proper example can be found below:

```
/**
 * A test class. A more elaborate class description.
 */
class Test
{
public:
/**
 * An enum.
 * More detailed enum description.
 */
enum TEnum {
TVal1, /**< enum value TVal1. */
TVal2, /**< enum value TVal2. */
TVal3 /**< enum value TVal3. */
}
*enumPtr, /**< enum pointer. Details. */
enumVar; /**< enum variable. Details. */
/**
 * A constructor.
 * A more elaborate description of the constructor.
 */
Test();
/**
 * A destructor.
 * A more elaborate description of the destructor.
 */
~Test();
/**
 * a normal member taking two arguments and returning an integer value.
 * @param a an integer argument.
 * @param s a constant character pointer.
 * @see Test() - the function is dependent on constructor
 * @see ~Test() - the function is dependent on destructor
 * @see testMeToo() - the function is dependent on testMeToo
 * @see publicVar() - the function is dependent on publicVar
 * @return The test results
 */
int testMe(int a,const char *s);
/**
 * A pure virtual member.
 * @see testMe()
 * @param c1 the first argument.
 * @param c2 the second argument.
 */
virtual void testMeToo(char c1,char c2) = 0;
/**
 * a public variable.
 * Details.
 */
int publicVar;
/**
 * a function variable.
 * Details.
 */
int (*handler)(int a,int b);
};
```

2. Use definitions and macros with meaningful names, so that they are easy to
    understand and work.

3. Whenever there is a need to use a constant that can be use globally, make
   make sure you define the constant in file named constants.h

4. Whenever the application is failed to process anything, it must return an
   error code, and every error code must be defined in errors.h file.

5. The name of class must be same as of the file, so that the classes are easy
   to locate and work.

6. Don't delete any piece of code, if you need to comment out any piece of code,
   make sure to add your github username. Ex, considering user as 'cyberbit'
   ```
   /**
    * user/cyberbit
    */
   ```

7. Every function must return some value, so that it's easy to track and write
   tests for them whether they run successfully or failed.

Class Functions/Methods Naming Conventions
------------------

1. Method names for every class must start with the name of class for easy
   tracking. Ex, if the class name is Foo, then the method named bar, must be
   defined like this:

   ```
   Class Foo {
    int Foo_bar();
   }
   ```
3. All header files must be defined in cyberbitGame.h.


Syntax and indentation
----------------------

1. Restrict to comments of only this type /* */ and avoid using comments that
   are made by using forward slashes or any other style.

2. Be generous with whitespace and braces. The tab width must be of size 4. The
   set of statement defined inside the loop must start the curly brace from
   same line, EX:

   ```
    if (foo) {
        bar;
    }
    ```
    and every loop must be defined in the braces.

    Bad:
    if (foo) bar; /** without braces */

    whereas, every method/function must be defined like this

    ```
    className_methodName()
    {
        definition;
    }
    ```

Testing
-------

1. Tests follow the same pattern as the source code, and test files must start
   with test-TestFile.cpp structure.

Documentation
-------------

1. You can add add more information and example by your functions to the website
   [wiki](http://cyberbitgame.com/wiki/index.php?title=Main_Page) as a help guide.
