#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string del(string s)
{
    string ret;
    //int s = 0;
    int len = s.size();
    if (len < 2)
    {
        //*score = 0;
        return s;
    }
    if (s[0] != s[1])
        ret += s[0];

    for (int i=1; i<len-1; ++i)
    {
        if (s[i]!=s[i-1] && s[i]!=s[i+1])
        {
            ret += s[i];
        }
    }
    if (s[len-1] != s[len-2])
        ret += s[len-1];
    return ret;
}

string dell(string s)
{
    string ss1;
    string ss2 = s;
    while ((ss1 = del(ss2)) != ss2)
    {
        ss2 = ss1;
    }
    return ss1;
    //string ss = del(s);
    //cout<< s <<":"<<ss<<" ";
    //if (ss == s)
    //    return ss;
    //else
    //    dell(ss); 
}

int calc(string &s)
{
    int ret = 0;
    if (s.size() == 0)
        return 0;
    string s1 = dell(s);
    cout<<s1<<" ";
    ret = s.size() - s1.size();
    for (int i=0; i<s1.size(); ++i)
    {
        string t = s1.substr(0, i);
        t += s1[i];
        t += s1.substr(i);
        string tt = dell(t);
        int n = s.size() - tt.size();
        //cout<<s.size()<<":"<<tt.size()<<":"<<tt<<" ";
        if (n > ret)
            ret = n;
    }
    //cout<<"slen:"<<s.size()<<" ";
    return ret+1;
}

void transfer()
{
    ifstream fin;
    fin.open("data.in");
    cin.rdbuf(fin.rdbuf());
}

int main()
{

    int n;
    ifstream fin;
    if (false)
    {
        fin.open("delchar.in");
        cin.rdbuf(fin.rdbuf());
    }
    cin >> n;
    cout<< n<<endl;
    while (n--)
    {
        string s;
        cin >> s;
        cout<<s<<" ";
        cout << calc(s) << endl;
    }

    return 0;
}
