#include <iostream>
#include <limits>

#include "CMyString.h"

using namespace std;

CMyString::CMyString(int _size)
{
    text = new char[_size];
}

int CMyString::strcmp(const char *a, const char *b)
{
    for (; *a; a++, b++)
        if (*a != *b)
            break;
    return *(const unsigned char *)a - *(const unsigned char *)b;
}

CMyString::CMyString(const char *c)
{
    text = new char[myStrlen(c) + 1];
    myStrcpy(text, c);
    text[myStrlen(c)] = '\0';
}

void CMyString::myStrcpy(char *temp, const char *copy)
{
    int i = 0;
    for (; copy[i] != '\0'; i++)
    {
        temp[i] = copy[i];
    }
    temp[i] = '\0';
}

int CMyString::myStrlen(const char *temp)
{
    int i = 0;
    for (; temp[i] != '\0'; i++)
        ;
    return i;
}

int CMyString::getStringSize() const
{

    int i = 0;
    for (; text[i] != '\0'; i++)
        ;
    return i;
}

int CMyString::getChArrSize() const
{
    return sizeof(text) / sizeof(text[0]);
}

CMyString CMyString::operator+(const CMyString str)
{
    int getLength1 = this->getStringSize();
    int getLength2 = str.getStringSize();

    char *temp = new char[getLength1 + getLength2 + 1];
    int i = 0;

    for (; i < getLength1; i++)
    {
        temp[i] = this->text[i];
    }
    for (int j = 0; j < getLength2; j++, i++)
    {
        temp[i] = str.text[j];
    }
    temp[i] = '\0';
    CMyString concat(temp);
    return concat;
}

CMyString &CMyString::operator+=(CMyString cstr)
{
    int getLength1 = this->getStringSize();
    int getLength2 = cstr.getStringSize();

    char *temp = new char[getLength1 + getLength2 + 1];
    int i = 0;

    for (; i < getLength1; i++)
    {
        temp[i] = this->text[i];
    }
    for (int j = 0; j < getLength2; j++, i++)
    {
        temp[i] = cstr.text[j];
    }
    temp[i] = '\0';
    delete[] this->text;
    this->text = temp;
    return *this;
}

char &CMyString::operator[](int i)
{
    if (i >= 0  && i <= myStrlen(text)) {
        return this->text[i];
    }
    else{
        throw out_of_range("Index is out of range from the current string");
    }
 
}

bool CMyString::operator==(const CMyString cstr)
{
    return (strcmp(text, cstr.text) == 0) ? true : false;
}

bool CMyString::operator!=(const CMyString cstr)
{
    return (strcmp(text, cstr.text) != 0) ? true : false;
}

bool CMyString::operator>(const CMyString cstr)
{
    return (strcmp(text, cstr.text) > 0) ? true : false;
}

bool CMyString::operator<(const CMyString cstr)
{
    return (strcmp(text, cstr.text) < 0) ? true : false;
}

CMyString CMyString::operator()(int start, int end)
{
    char *temp = new char[end - start + 2];
    int j = 0;
    for (int i = start; i <= end; i++, j++)
    {
        temp[j] = text[i];
    }
    temp[j] = '\0';
    CMyString substring(temp);
    return substring;
}
void CMyString::operator=(CMyString cstr)
{
    char *temp = new char[myStrlen(cstr.text) + 1];
    myStrcpy(temp, cstr.text);
    delete[] text;
    text = temp;
}

CMyString CMyString::operator<<(int leftShift)
{

    char *temp = new char[leftShift + 1];
    int i = 0;
    for (; i < leftShift; i++)
    {
        temp[i] = this->text[i];
    }
    temp[i] = '\0';
    CMyString lshift(temp);
    char *temp2 = new char[this->getStringSize() - leftShift];

    int j = 0;
    for (; i < (leftShift + this->getStringSize()); j++, i++)
    {
        temp2[j] = text[i];
    }
    temp2[j] = '\0';
    delete[] text;
    this->text = temp2;
    delete[] temp;

    return lshift;
}
CMyString CMyString::operator>>(int rightShift)
{
    char *temp = new char[rightShift + 1];
    int length = getStringSize() - 1;
    int i = length;
    int j = 0;
    for (; i > length - rightShift; i--, j++)
    {
        temp[j] = text[i];
    }
    temp[j] = '\0';
    CMyString rshift(temp);
    delete[] temp;
    char *temp2 = new char[this->getStringSize() - rightShift + 1];

    for (j = 0; j <= i; j++)
    {
        temp2[j] = text[j];
    }
    temp2[j] = '\0';
    delete[] text;
    this->text = temp2;
    return rshift;
}

CMyString::~CMyString()
{
    delete[] text;
}

ostream &operator<<(ostream &output, const CMyString& cstr)
{
    output << cstr.text;
    return output;
}

istream &operator>>(istream &input, CMyString& cstr)
{ 
    input.get(cstr.text,numeric_limits<std::streamsize>::max() , '\n');
//     int size = 10;
//     char *s;
//     s = new char[size];
//   char c;
//   int len = 0;
//   while (input >> c) {
//       if (c == '\n') {
//           break;
//       }
//     s[len++] = c;
//     if (len >= size) {
//       // need to allocate more space
//       char *temp = new char[size * 2];
//       for ( int i = 0; i < size; i++) {
//           temp[i] = s[i];
//       }
//       delete [] s;
//       s = temp;
//       size *= 2;
//     }
//   }
//   s[len++] = '\0';
//   delete [] cstr.text;
//   cstr.text = s;

    return input;
}
