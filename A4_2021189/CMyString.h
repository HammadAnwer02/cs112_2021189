#include <iostream>

#ifndef CMYSTRING_H
#define CMYSTRING_H

class CMyString
{
    friend std::ostream &operator<<(std::ostream &, const CMyString&);
    friend std::istream &operator>>(std::istream &, CMyString&);

private:
    char *text;
    int mystrcmp(const char *, const char *);
public:
    CMyString(int = 50);
    CMyString(const char *);
    int getStringSize() const;
    int getChArrSize() const;
    CMyString operator+(const CMyString&);
    CMyString& operator+=(const CMyString&);
    char &operator[](int);
    bool operator==(const CMyString&);
    bool operator!=(const CMyString&);
    bool operator>(const CMyString&);
    bool operator<(const CMyString&);
    CMyString operator()(int, int);
    void operator=(const CMyString&);
    CMyString operator<<(int);
    CMyString operator>>(int);
    ~CMyString();
};


#endif