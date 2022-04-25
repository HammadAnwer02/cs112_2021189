#include <iostream>
#include "CMyString.h"

using namespace std;

int main(int argc, char const *argv[])
{
    CMyString c1("ABCDEFG");
    CMyString c2("1234567");
    CMyString c3;

    cout << "\nTesting out inserstion and extraction operation: ";
    cout << "Enter your string: ";
    cin >> c3;
    cout << "The string you entered was: " << c1 << endl;
    cout << c3;

    // cout << "\nBefore concatenating:\n";
    // cout << "c1 = \"ABCDEFG\"; c2 = \"1234567\"" << endl;
    // cout << "After concatenating :\n";
    // cout << "c1 + c2 = " << c1 + c2 << endl;

    // cout << "\nBefore concatenating:\n";
    // cout << "c1 = \"ABCDEFG\"; c2 = \"1234567\"" << endl;
    // cout << "After concatenating :\n";
    // cout << "c1 += c2; c1 = " << (c1 += c2) << endl; 

    // // CMyString c3;
    // // c3 = c1 >> 7;

    // cout << "\nBefore get and set operation:\n" << endl;
    // cout << "c1 = \"ABCDEFG\"; c2 = \"1234567\"" << endl;
    // cout << "c1[1] = " << c1[1] << endl;
    // c1[4] =  '1';
    // cout << "c1[4] = '1'; c1 = " << c1 << endl;

    // cout << "\nString equality operation\n";
    // cout << "(c1 == c2) " << ((c1 == c2) ? "True" : "False") << endl;
    // cout << "(c1 == c1)" << ((c1==c1) ? "True" : "False") << endl;

    // cout << "\nString inequality operation\n";
    // cout << "(c1 != c2) " << ((c1 == c2) ? "True" : "False") << endl;
    // cout << "(c1 != c1)" << ((c1==c1) ? "True" : "False") << endl;

    // cout << "\nString substring function\n";
    // cout << "c1(0, 3) = " << c1(0, 3) << endl;

    // cout << "\nString assignment operation\n";
    // cout << "c2 = c1\n";
    // cout << "c2 = " << c2 << endl;

    // cout << "\nBefore left shift operation:\n";
    // cout << "c1 = \"" << c1 << "\"" << endl;
    // cout << "c1 << 1 = " << (c1 << 1) << endl;
    // cout << "c1 now : " << c1 << endl;

    //  cout << "\nBefore left shift operation:\n";
    // cout << "c2 = \"" << c2 << "\"" << endl;
    // cout << "c2 >> 3 = " << (c2 << 3) << endl;
    // cout << "c1 now : " << c2 << endl;



    return 0;
}
