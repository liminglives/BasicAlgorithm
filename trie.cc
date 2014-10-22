#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

struct Node
{
    int num;
    map<char, Node *> *child;
    Node(int n=0):num(n),child(new map<char, Node *>()) {}
};

void build(Node *root, string &s, int n)
{
    if (n == s.size())
        return;

    map<char, Node *>::const_iterator it = root->child->find(s[n]);
    if (it == root->child->end())
    {
        root->num++;
        Node *tmp = new Node();
        root->child->insert(pair<char, Node *>(s[n], tmp));
        build(tmp, s, ++n);
    }
    else
    {
        root->num++;
        build(it->second, s, ++n);
    }
}

int search(Node *root, string &s)
{
    Node *t = root;
    int ret = 0;
    map<char, Node *>::const_iterator it;
    for (int i=0; i<s.size(); ++i)
    {
        it = t->child->find(s[i]);
        if (it == t->child->end())
            return 0;
        else
        {
            t = it->second;
            ret = t->num;
        }
    }
    return t->num;
}

int main()
{
    int n,m;
    string s;
    ifstream fin;
    //streambuf *backup;
    if (false)
    {
        fin.open("data.in");
        //backup = cin.rdbuf();
        cin.rdbuf(fin.rdbuf());
    }
    //cout<<"input n:";
    cin>>n;
    Node *root = new Node(0);
    for (int i=0; i<n; ++i)
    {
        cin>>s;
        build(root, s, 0);
    }
    //cout<<"input m: ";
    //cout<<"root num:"<<root->num<<endl;
    cin>>m;
    for (int i=0; i<m; ++i)
    {
        cin>>s;
        //cout<<"search "<<s<<" : ";
        cout<<search(root, s)<<endl;
    }
    //cout<<"end"<<endl;
    return 0;
}

