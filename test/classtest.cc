#include <iostream>
#include <vector>
using namespace std;

class Base {
public:
    Base():isNumber(0){cout<<"gouzao"<<endl; }
    Base(const Base &b):isNumber(b.isNumber)
    {
        cout<<"fuzhi"<<endl;
    }

private:
    bool isNumber;   
};

struct test
{
    long long a;
    char b;
    int c;
    char d[2];
    //static int e;
};

int main()
{
    cout<<sizeof(test)<<endl;
    Base a[5],*b[6];
    cout<<endl;
    vector<Base> c(4);
    return 0;
}
