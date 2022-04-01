#include <helpers_assignment_2.h>

int main()
{
    printMenu
    cout << "Please choose an option: ";
    read(int, option)
    
    while (option != 9)
    {
        switch (option)
        {
        case 1:
        {
            enterText 
            char *anotherText = new char[100];
            cout << "The string copied was: " << Mystrcpy(anotherText, text) << endl;
            break;
        }
        case 2:
        {
            enterText 
            char *anotherText = new char[100];
            enterNumCharacter
            cout << "The string copied till n characters is: " << Mystrncpy(anotherText, text, num) << endl;
            break;
        }
        case 3:
        {
            enterText
            enterAnotherText
            cout << "The concatenated string is: " << Mystrcat(text, anotherText) << endl;
            break;
        }
        case 4:
        {
            enterText
            enterAnotherText
            enterNumCharacter
            cout << "The concatenated string till n characters is: " << Mystrncat(text, anotherText, num) << endl;
            break;
        }
        case 5:
        {
            enterText
            enterAnotherText 
            cout << ((Mystrcmp(text, anotherText) == 0) ? "The two strings are the same!\n\n" : \
            "The two strings are not the same.\n\n");
            break;
        }
        case 6:
        {
            enterText
            enterAnotherText
            enterNumCharacter 
            cout << ((Mystrncmp(text, anotherText, num) == 0) ? "The two strings are same till n characters!\n\n" :\
             "The two strings are not the same till n characters!\n\n");
            break;
        }
        case 7:
        {
            enterText
            cout << "The orginal string was: " << text << endl;
            const char delim = ',', empty = '\0';
            char *token = Mystrtok(text, &delim);
            cout << "The strings after seperation with the token ',' is: \n";
            for (;*token != empty; token = Mystrtok(text, &delim))
                cout << token << endl;
            break;
        }
        case 8:
        {
            enterText
            cout << "The lenght of string is: " << Mystrlen(text) << endl;
            break;
        }
        case 9:
            break;
        default:
            cout << "Invalid Input! Please re-enter!\n";
            break;
        }
        system("pause");
        cout << "\n\nPlease choose another option: ";
        printMenu
        validInput(option);
    }
    cout << "Program shutting down !!!\n\n";
}

