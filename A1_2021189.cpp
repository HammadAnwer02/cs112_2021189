
#include "helpers_assignment_1.h"

int main()
{
    BookList bl1;
    StudentList std1;
    cout << setw(50) << setfill('_') << endl
         << "|" << setw(17) << setfill(' ') << "GIKI LIBRARY MANAGEMENT SYSTEMS"
         << "|"
         << setw(50) << setfill('_') << "\n\n\n\n";
    printMenu();
    int option;
    cout << "Please enter an option: ";
    validInput(option);
    while (option != 10)
    {
        switch (option)
        {
        case 1:
        {
            Student std;
            inputStudent(std);
            std1.addStudent(std);
            break;
        }
        case 2:
        {
            cout << "Please enter the ID of the student you want to delete (0-4): ";
            int index;
            validId(index);
            std1.deleteStudent(index);
            break;
        }
        case 3:
        {
            std1.printAll();
            break;
        }
        case 4:
        {
            Book b1;
            inputBooks(b1);
            cout << "Enter the index you want to enter the book at (0-4):";
            int index;
            validId(index);
            bl1.addNewBook(b1, index);
            break;
        }
        case 5:
        {
            bl1.deleteBook();
            break;
        }
        case 6:
        {
            int index;
            cout << "Enter the ID of the book you are trying to search(0-4):  ";
            validId(index);
            bl1.showBook(index);
            break;
        }
        case 7:
            bl1.printAll();
            break;
        case 8:
        {
            bl1.sortBooks(1);
            cout << "\nThe books have been sorted in ascending order.\n\n";
            break;
        }
        case 9:
        {
            bl1.sortBooks(2);
            cout << "\nThe books have been sorted in descending order.\n\n";
            break;
        }
        default:
            cout << "\nInvalid Option!\n\n";
        }
        system("pause");
        system("CLS");
        printMenu();
        cout << "Enter another option: ";
        validInput(option);
    }
    cout << "\n\nProgram shutting down!!!";
}
