#ifndef __CONSTR__
#define __CONSTR__
#include "template.h"
// Function to illustrate Constructor
// with no arguments

template<class T>
Mystring<T>::Mystring()
    : str{ nullptr }
{
    str = new char[1];
    str[0] = '\0';
    cout << "The string passed is: "
        << str << endl;
}

// Function to illustrate Constructor
// with one arguments
template<class T>
Mystring<T>::Mystring(T* val)
{
    if (val == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }

    else {

        str = new char[strlen(val) + 1];

        // Copy character of val[]
        // using strcpy
        strcpy_s(str, strlen(val) + 1, val);
        str[strlen(val)] = '\0';

        cout << "The string passed is: "
            << str << endl;
    }
}

//two pointer constructor
template<class T>
Mystring<T>::Mystring(T* val, T* val2)
{
    if (val >= val2) throw "Invalid indexes";
    if (val == val2 == '\0') {
        str = new char[1];
        str[0] = '\0';
    }
    else {

        str = new char[strlen(val) + 1];

        // Copy character of val[]
        // using strcpy
        strcpy_s(str, strlen(val) + 1, val);
        str[strlen(val)] = '\0';

        cout << "The string passed is: "
            << str << endl;
    }
}


//same val init n times
template<class T>
Mystring<T>::Mystring(T val, int n)
{
    if (n < 0) throw "try a longer string";
    str = new char[n + 1];

    for (int i = 0; i < n; i++)
    {
        str[i] = val;
    }
    str[n] = '\0';

    cout << "The string passed is: "
        << str << endl;
}


// Function to illustrate
// Copy Constructor
template<class T>
Mystring<T>::Mystring(const Mystring& source)
{
    str = new char[strlen(source.str) + 1];
    strcpy_s(str, strlen(source.str) + 1, source.str);
    str[strlen(source.str)] = '\0';
    cout << "The string passed is: "
        << str << endl;
}

// Function to illustrate
// Move Constructor
template<class T>
Mystring<T>::Mystring(Mystring&& source)
{
    str = source.str;
    source.str = nullptr;
    cout << "The string passed is: "
        << str << endl;
}

#endif
