#include "CMyString.h"
#include "macros.h"


int main(int argc, char const *argv[])
{
    startScreen 
    printMenu
    readint(option);
    CMyString c1("ABCDEFG");
    CMyString c2("1234567");
    while (option != -1)
    {
        switch (option)
        {
        case 1:
        {
            enterTwoStrings
            statusBeforeOperation
            cout << "After concatenation: \n" << "c1 + c2 = \"" << c1 + c2 << "\"" << endl;
            break;
        }
        case 2:
        {
            enterTwoStrings
            statusBeforeOperation
            cout << "After concatenation: \n" << "c1 += c2 = \"" << (c1 += c2) << "\"" << endl;
            break;
        }
        case 3:
        {
            enterOneString
            statusForOne
            cout << "Enter a valid index of the character you want to fetch: ";
            readint(index)
            try
            {
                cout << "c1[" << index << "] is: " << c1[index] << endl;
            }
            catch (out_of_range &ex)
            {
                cout << ex.what() << '\n';
            }

            try
            {
                cout << "Enter a valid index of the character you would like to set from c1: ";
                validInput(index);
                cout << "Enter the character you would like to set at that index: ";
                read(char, a)
                    c1[index] = a;
                cout << "After operation: \n"
                     << "c1 = \"" << c1 << "\"" << endl;
            }
            catch (out_of_range &ex)
            {
                cout << ex.what() << '\n';
            }

            break;
        }
        case 4:
        {
            enterTwoStrings
            statusBeforeOperation
            cout << "(c1 == c2) :" << ((c1 == c2) ? "True" : "False") << endl;
            cout << "(c1 == c1) :" << ((c1 == c1) ? "True" : "False") << endl;
            break;
        }
        case 5:
        {
            enterTwoStrings
            statusBeforeOperation
            cout << "(c1 != c2) " << ((c1 != c2) ? "True" : "False") << endl;
            cout << "(c1 != c1) " << ((c1 != c1) ? "True" : "False") << endl;
            break;
        }
        case 6:
        {
            enterTwoStrings
            statusBeforeOperation
            cout << "(c1 > c2) = " << ((c1 > c2) ? "True" : "False") << endl;
            break;
        }
        case 7:
        {
            enterTwoStrings
            statusBeforeOperation
            cout << "(c1 < c2) = " << ((c1 < c2) ? "True" : "False") << endl;
            break;
        }
        case 8:
        {
            enterTwoStrings
            statusForOne
            cout << "Enter the two valid index values to get a substring: ";
            readint(start) readint(end)
            try
            {
                cout << "c1(" << start << "," << end << ") = \"" << c1(start, end) << "\"" << endl;
            }
            catch (const invalid_argument &ex)
            {
                cout << ex.what() << '\n';
            }

            break;
        }
        case 9:
        {
            enterTwoStrings
            statusBeforeOperation
            cout << "After operation (c1 = c2)\n";
            c1 = c2;
            cout << "c1 = \"" << c1 << "\"" << endl;
            break;
        }
        case 10:
        {
            enterOneString
            statusForOne
            cout << "Enter the amount of left shift: ";
            readint(lshift)

            try
            {
                cout << "After operation: \n"
                    << "c1 << " << lshift << " = \"" << (c1 << lshift) << "\"" << endl
                    << "c1 = \"" << c1 << "\"" << endl;
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << '\n';
            }
            break;
        }
        case 11:
        {
            enterOneString
            statusForOne
            cout << "Enter the amount of right shift: ";
            readint(rshift)
            try
            {
                cout << "After operation: \n"
                    << "c1 >> " << rshift << " = \"" << (c1 >> rshift) << "\"\n"
                    << "c1 = \"" << c1 << "\"" << endl;
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << '\n';
            }

            break;
        }

        default:
            cout << "Invalid Option!\n\n";
            break;
        }
        system("pause");
        printMenu
        validInput(option);
    }

    cout << "Exiting Program: ";
    for (int i = 0; i < 5; i++)
    {
        cout << ". ";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    return 0;
}
