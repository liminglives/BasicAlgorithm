#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct StackNode 
{
    int data;
    StackNode *next;
}Node;

class Stack{
public:
    Stack():count(0),bottom(NULL),top(NULL){};
    void pop();
    void push(int);
    void push(Node *);
    Node * peek();
    void print();
    ~Stack() { deleteStack(); };
    void deleteStack();
private:
    int count;
    Node *bottom;
    Node *top;
};

void Stack::deleteStack()
{
    Node *cur = top;
    Node *next = NULL;
    while(cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    top = bottom = NULL;
    count = 0;
}

void Stack::push(int data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    if (tmp == NULL)
    {
        cout << "malloc failed" << endl;
        return;
    }
    tmp->data = data;
    tmp->next = top;
    top = tmp;
    if (count == 0)
        bottom = tmp;
    ++count;
}

void Stack::push(Node *node)
{
    if (node == NULL)
    {
        cout << "input is null" << endl;
        return;
    }
    node->next = top;
    top = node;
    if (bottom == NULL)
        bottom = node;
    ++count;
}

void Stack::pop()
{
    if (top == NULL)
        return;
    Node *tmp = top;
    top = top->next;
    free(tmp);
    --count;
    if (count == 0)
        top = bottom = NULL;
}

Node * Stack::peek()
{
    if (count > 0)
        return top;
    else
        return NULL;
}

void Stack::print()
{
    Node *tmp = top;
    while(tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp=tmp->next;
    }
}

int main()
{
    Stack s;
    for (int i=0; i<10; ++i)
    {
        s.push(i);
    }
    s.print();
}