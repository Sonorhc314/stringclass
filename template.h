#ifndef __TEMP__
#define __TEMP__
#include <cstring>
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

// Custom string class
template<class T>
class Mystring {

    // Initialise the char array
    //T* str;

public:
    T* str;
    // No arguments Constructor
    Mystring();

    // Constructor with 1 arguments/pointer to array
    Mystring(T* val);

    // Constructor with 2 arguments/pointer to array
    Mystring(T* val, T* val2);

    //same val init n times
    Mystring(T val, int n);

    // Copy Constructor
    Mystring(const Mystring& source);

    // Move Constructor
    Mystring(Mystring&& source);

    // Destructor
    ~Mystring() { delete str; }

    string operator+(Mystring<T> const& s1)
    {
        string output = "";
        output += str;
        output += s1.str;
        return output;
    }

    int operator==(Mystring<T> const& s1)
    {
        if (strcmp(str, s1.str) == 0)
        {
            cout << endl;
            cout << "same";
            return 1;
        }
        else
        {
            cout << endl;
            cout << "different";
            return 0;
        }
    }

    string operator * (int b) {
        if (b<=0) throw "b<=0 is realy bad dont pls."
        string output = "";
        while (b--) {
            output += str;
        }
        return output;
    }

    T& operator[](int const& index) const
    {
        if(index >= 0 && index < strlen(str)) throw "Invalid index";
        return str[index];
    }


    void erase()
    {
        delete[] str;
        str = nullptr;
        strlen(str) = 0;
    }

    int getlength()
    {
        return(strlen(str));
    }

    void copy(const Mystring& source)
    {
        str = new char[strlen(source.str) + 1];
        strcpy_s(str, strlen(source.str) + 1, source.str);
        str[strlen(source.str)] = '\0';
        cout << "The string passed is: "
            << str << endl;
    }

    int move(Mystring&& source)
    {
        str = source.str;
        source.str = nullptr;
        cout << "The string passed is: "
            << str << endl;
    }

    void isempty()
    {
        if (str[0] == '\0') {
            cout << "array is empty";
        }
        else
        {
            cout << "array is not empty";
        }
    }

    Mystring<T> part(int n1, int n2)
    {
        if (n1 > n2) throw "reversed indexes";
        Mystring<T> str1;
        str1.str = new T[n2 - n1+1];
        for (int i = 0; i < n2 - n1+1; i++)
        {
            str1.str[i] = str[i+n1];
        }
        return str1;
    }
};

#endif