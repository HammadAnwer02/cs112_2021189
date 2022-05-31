

#include "macros.h"
#include "CMyString.h"

/**
 * @brief Construct a new CMyString::CMyString object
 *
 * @param _size
 */

int CMyString::mystrcmp(const char *a, const char *b)
{

    for (; *a; a++, b++)
        if (*a != *b)
            break;
    return *(const unsigned char *)a - *(const unsigned char *)b;
}

/**
 * @brief Construct a new CMyString::CMyString object
 *
 * @param c Takes as parameter a character pointer to assign to our text
 */
int myStrlen(const char *temp)
{
    int i = 0;
    for (; temp[i] != '\0'; i++)
        ;     // iterate until you reach the end of the string
    return i; // return i which is the length of the string
}

void myStrcpy(char *dest, const char *source)
{
    int i = 0;
    for (; source[i] != '\0'; i++) // copy data from source to destination until you reach the end
    {
        dest[i] = source[i];
    }
    dest[i] = '\0'; // specify the end of the string data
}

CMyString::CMyString(const char *c)
{
    // this contructor allows us to create a new instance of our class by passing another text as  a parameter
    text = new char[myStrlen(c) + 1]; // initialize the size of our class array to the size of the char array passed
    myStrcpy(text, c);                // copy the contents of the text from the text passed to the text in our class
    text[myStrlen(c)] = '\0';         // specify the end of the string
}
CMyString::CMyString(int _size)
{
    text = new char[_size];
}

/**
 * @brief Compare the strings by comparing each character from the first string to the second string
 *
 * @param a
 * @param b
 * @return int
 */


int CMyString::getStringSize() const
{

    int i = 0;
    for (; text[i] != '\0'; i++)
        ;
    return i;
}

int CMyString::getChArrSize() const
{
    return sizeof(text) / sizeof(text[0]); // return the number of elements that can be stored in our array
}

CMyString CMyString::operator+(const CMyString &str)
{
    // get lenght of both strings
    int length1 = this->getStringSize();
    int length2 = str.getStringSize();

    // create a new dynamic array to store the text from both strings
    char *temp = new char[length1 + length2 + 1];
    int i = 0;

    // copy text from first string
    for (; i < length1; i++)
    {
        temp[i] = this->text[i];
    }
    // copy text from second string adding onto the previous string
    for (int j = 0; j < length2; j++, i++)
    {
        temp[i] = str.text[j];
    }

    temp[i] = '\0'; // specify the end of the string

    CMyString concat(temp); // create an instance of the class that has to be returned
    return concat;
}

CMyString &CMyString::operator+=(const CMyString &cstr)
{
    // this is almost the same as + operation with the difference we are adding to the end of first string
    // rather than creating another string

    int length1 = this->getStringSize();
    int length2 = cstr.getStringSize();
    char *temp = this->text + length1;
    int i = 0;
    for (; cstr.text[i] != '\0'; i++)
    {
        temp[i] = cstr.text[i];
    }
    temp[i] = '\0';

    return *this; // since we are modifying the current class we will be returning the pointer to itself
}

char &CMyString::operator[](int i)
{
    // check if the index entered is within the string size if not give exception
    if (i >= 0 && i <= myStrlen(this->text))
    {
        return this->text[i];
    }
    else
    {
        throw out_of_range("Index is out of range from the current string");
    }
}

/**
 * @brief Below are comparission operator for which I used a helper function to handle all the comparissions
 *
 * @return true if comparission is valid
 * @return false if comparission is not valid
 */
bool CMyString::operator==(const CMyString &cstr)
{
    return (mystrcmp(text, cstr.text) == 0) ? true : false;
}

bool CMyString::operator!=(const CMyString &cstr)
{
    return (mystrcmp(text, cstr.text) != 0) ? true : false;
}

bool CMyString::operator>(const CMyString &cstr)
{
    return (mystrcmp(text, cstr.text) > 0) ? true : false;
}

bool CMyString::operator<(const CMyString &cstr)
{
    return (mystrcmp(text, cstr.text) < 0) ? true : false;
}

/**
 * @brief
 *
 * @param start The index from which we will be getting the first character from. It is inclusive
 * @param end   THe last index of the character till which we have to get a substring. It is inclusive.
 * @return the instance of the substring
 */
CMyString CMyString::operator()(int start, int end)
{
    if (start > end || start < 0 || (start > this->getStringSize()) || end < 0 || (end > this->getStringSize()))
    {
        throw invalid_argument("Invalid substring indexes entered!");
    }
    char *temp = new char[end - start + 2]; // create a new array to store the substring

    int j = 0;
    for (int i = start; i <= end; i++, j++)
    {
        temp[j] = text[i];
    }
    temp[j] = '\0';

    CMyString substring(temp);
    return substring;
}

/**
 * @brief Assign the text in the first string to this text.
 *
 * @param cstr
 */

void CMyString::operator=(const CMyString &cstr)
{
    char *temp = new char[myStrlen(cstr.text) + 1]; // dynamic array to store text from parameter string
    myStrcpy(temp, cstr.text);                      // copy contents from parameter string to the temp array
    delete[] this->text;                            // free up memory of current stored text
    this->text = temp;                              // assign the address of the array we just made to text of this string
}

/**
 * @brief Will be used to shift the characters in the strings from the left
 * This will also reduce the size of the original string
 *
 *
 * @param leftShift The amount of left shift to be done
 * @return THe instance of the string that has been shifted
 *
 */
CMyString CMyString::operator<<(int leftShift)
{
    if (leftShift > this->getStringSize())
    {
        throw invalid_argument("The string is not big enough for this left shift");
    }
        // store the text that is extracted from the left shift
        char *temp = new char[leftShift + 1];
        int i = 0;
        for (; i < leftShift; i++)
        {
            temp[i] = this->text[i];
        }
        temp[i] = '\0';
        CMyString lshift(temp);
        char *temp2 = new char[this->getStringSize() - leftShift];
        // store the text that is left after the shift
        int j = 0;
        for (; i < (leftShift + this->getStringSize()); j++, i++)
        {
            temp2[j] = this->text[i];
        }
        temp2[j] = '\0';
        delete[] this->text;
        this->text = temp2;
        delete[] temp;
        return lshift;
}

/**
 * @brief Will be used to shift the characters in the strings from the left
 * This will also reduce the size of the original string
 *
 *
 * @param rightShift The amount of left shift to be done
 * @return THe instance of the string that has been shifted
 *
 */

CMyString CMyString::operator>>(int rightShift)
{
    int length1 = this->getStringSize();
    if (rightShift > length1)
    {
        throw invalid_argument("String is not large enough for this right shift!");
    }
        // stores the text that is extracted from the right shift
        char *temp = new char[rightShift + 1];
        int length = length1 - 1;
        int i = length;
        int j = 0;
        for (; i > length - rightShift; i--, j++)
        {
            temp[j] = text[i];
        }
        temp[j] = '\0';
        CMyString rshift(temp);
        // Stores the text that is left in the original string after the left shift
        char *temp2 = new char[length1 - rightShift + 1];

        for (j = 0; j <= i; j++)
        {
            temp2[j] = text[j];
        }
        temp2[j] = '\0';
        delete[] this->text;
        delete[] temp; // free up memory from the used up space of the extracted string
        this->text = temp2;
        return rshift;
    
}

/**
 * @brief Destroy the CMyString::CMyString object
 *
 */
CMyString::~CMyString()
{
    cout << "Destructor called!" << endl;
    delete[] text;
}

/**
 * @brief Allow our class to be outputted using the output stream
 *
 * @param output
 * @param cstr
 * @return ostream&
 */
ostream &operator<<(ostream &output, const CMyString &cstr)
{
    output << cstr.text;
    return output;
}

/**
 * @brief Allows us to dynamically take input of an instance of our class using the input stream
 *
 * @param input
 * @param cstr
 * @return istream&
 */
istream &operator>>(istream &input, CMyString &cstr)
{
    input.get(cstr.text, numeric_limits<std::streamsize>::max(), '\n');
    int length = myStrlen(cstr.text);
    if (length >= cstr.getChArrSize())
    {
        char *temp = new char[length * 2];
        myStrcpy(temp, cstr.text);
        temp[length] = '\0';
        delete[] cstr.text;
        cstr.text = temp;
    }

    return input;
}

int main(int argc, char const *argv[])
{
    startScreen int option;
    printMenu
        validInput(option);
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
