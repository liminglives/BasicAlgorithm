#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
public:
    MyString():size(0),data(new char[size+1])
    {
        *data = '\0';
    }

    MyString(const char *str):size(strlen(str)), data(new char[size+1])
    {
        strcpy(data, str);
    }
    MyString(const MyString &s):size(s.getSize()),data(new char[size+1])
    {
        strcpy(data, s.cstr());    
    }
    MyString & operator=(const MyString &s)
    {
        if (this == &s)
            return *this;
        MyString tmp(s);
        size = tmp.getSize();
        char *t = data;
        data = tmp.data;
        tmp.data = t;
        return *this;
    }
    void swap(MyString &s)
    {
        char *tmp = data;
        data = s.data;
        s.data = tmp;
    }
    int getSize() const
    {
        return size;
    }
    const char * cstr() const
    {
        return data;
    }
    ~MyString()
    {
        delete [] data;
    }
private:
    int size;
    char *data;
    //char *size;
};

void foo(MyString x)
{}

void bar(MyString &x)
{}

MyString baz()
{
    MyString ret("hello");
    return ret; 
}

int main()
{
    MyString s0;
    MyString s1("world");
    MyString s2(s1);
    MyString s3 = s1;
    s2 = s1;

    foo(s1);
    bar(s1);
    baz();


    return 0;
}
