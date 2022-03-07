#include "Constructors.h"
// Driver Code
int main()
{
    try {
        // Constructor with no arguments
        Mystring<char> a{};

        // Convert string literal to
        // char array
        char temp[] = "Hello and welcome";

        // Constructor with one argument
        Mystring<char> b{ temp };
        Mystring<char> b2{ temp };

        // Copy constructor
        Mystring<char> c{ b };

        char temp1[] = "World and so on";

        //Mystring<char> e{ b };

        // One arg constructor called,
        // then the move constructor
        Mystring<char> d{ Mystring<char>{ temp1 } };

        //init of some val n times
        char chara = 'l';
        Mystring<char> nTimes{ chara, 10 };
        //const int cosss = 3;
        //b.part(2, 5);
        a.isempty();
        cout << endl;
        cout << endl << nTimes + d;
        nTimes == d;
        b == b2;

        cout << endl << (b * 2);

        cout << (d.part(2, 4)).str;

        return 0;
    }
    catch (const char* exception)
    {
        cerr << "Error: " << exception << endl;
    }
}