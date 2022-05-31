#include <iostream>
#include <limits> // std::numeric_limits<std::streamsize>::max()
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds

using namespace std;

#define read(type, var) \
    type var;           \
    cin >> var;
#define readint(var) \
    int var;         \
    validInput(var);
void ignoreLine()
{
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

#define startScreen                                                                \
    cout << "_______________________________________________________________\n\n"  \
         << "Assignement No: 4\n"                                                  \
         << "By Hammad Anwer 2021189\n"                                            \
         << "Topic: Make a string Implentation using operator overloading\n\n"     \
         << "_______________________________________________________________\n\n"; \
    cout << "Enter any key to begin: ";                                           \
    char anykey;                                                                   \
    cin >> anykey;                                                                 \
    system("CLS");

#define printMenu                                                  \
    cout << "Please enter one of the options: \n"                  \
         << "1)  Concatenate two strings using + :\n"              \
         << "2)  Concatenate two strings using = : \n"             \
         << "3)  Get/set individual character's from a string: \n" \
         << "4)  Test string equality operation: \n"               \
         << "5)  Test string inequality operation: \n"             \
         << "6)  Test string '>' operation: \n"                    \
         << "7)  Test string '<' operation: \n"                    \
         << "8)  Get a substring using (): \n"                     \
         << "9)  Test assignment operator for the strings: \n"     \
         << "10) Test string left shift: \n"                       \
         << "11) Test string right shift: \n"                      \
         << "-1) Exit the program: \n";

#define enterTwoStrings                  \
    cout << "Enter the first string: ";  \
    ignoreLine();                        \
    cin >> c1;                           \
    cout << "Enter the second string: "; \
    ignoreLine();                        \
    cin >> c2;

#define enterOneString          \
    cout << "Enter a string: "; \
    ignoreLine();               \
    cin >> c1;

#define statusBeforeOperation                                    \
    cout << "\nBefore operation\nc1 = \"" << c1 << "\"" << endl; \
    cout << "c2 = \"" << c2 << "\"" << endl;

#define statusForOne \
 cout << "\nBefore operation\nc1 = \"" << c1 << "\"" << endl; \

void validInput(int &num)
{
    if (cin >> num)
    {
        return;
    }
    else
    {
        cout << "You can only enter integer values for the option:\nPlease re-enter: ";
        cin.clear();
        ignoreLine();
        validInput(num);
    }
}