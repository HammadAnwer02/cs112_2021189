#include <iostream>

#ifndef CMYSTRING_H
#define CMYSTRING_H

class CMyString
{
    friend std::ostream &operator<<(std::ostream &, const CMyString&);
    friend std::istream &operator>>(std::istream &, CMyString &);

private:
    char *text;
    int strcmp(const char *, const char *);
    void myStrcpy(char *, const char *);
    int myStrlen(const char *);
public:
    CMyString(int = 50);
    CMyString(const char *);
    int getStringSize() const;
    int getChArrSize() const;
    CMyString operator+(const CMyString);
    CMyString& operator+=(CMyString);
    char &operator[](int);
    bool operator==(const CMyString);
    bool operator!=(const CMyString);
    bool operator>(const CMyString);
    bool operator<(const CMyString);
    CMyString operator()(int, int);
    void operator=(CMyString);
    CMyString operator<<(int);
    CMyString operator>>(int);
    ~CMyString();
};


#endif