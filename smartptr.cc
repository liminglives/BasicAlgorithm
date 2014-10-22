#include <iostream>
#include <string>
using namespace std;

class Count
{
private:    
    int used;
public:
    Count(int c):used(c){}
    int add() {return ++used;}
    int sub() {return --used;}
    int get() {return used;}
};
// should judge the NULL point
template <class T>
class SmartPtr
{
private:
    T *ptr;
    Count *c;
public:
    explicit SmartPtr(T *p):ptr(p),c(new Count(1)){}
    //explicit SmartPtr():ptr(NULL),c(NULL){}
    ~SmartPtr()
    {
        if (c->sub() == 0) //if c is null?
        {
            delete ptr;
            delete c;
        }
    }
    SmartPtr(const SmartPtr<T> &rhs):ptr(rhs.ptr),c(rhs.c)
    {
        c->add(); // null point
    }
    SmartPtr & operator=(const SmartPtr<T> rhs)
    {
        T *tmpP = ptr;
        ptr = rhs.ptr;
        rhs.ptr = tmpP;

        Count *t = c;
        c = rhs.c;
        rhs.c = t;
        c->add();
    }
    T * operator->()
    {
        return ptr;
    }
    T & operator*() { return *ptr;  }
    
};

int main()
{
    return 0;
}
