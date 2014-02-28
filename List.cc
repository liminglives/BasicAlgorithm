#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode 
{
    int data;
    ListNode *next;
};

void deleteList(struct ListNode * head)
{
    struct ListNode *cur, *next;
    next = head->next;
    while (next != NULL)
    {
        cur = next;
        next = next->next;
        free(cur);
        cur = NULL;
    }
    head->next = NULL;
}

struct ListNode * createList()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (head == NULL)
    {
        cout << "malloc failed" << endl;
        return head;
    }
    head->next = NULL;
    struct ListNode *pre = head;
    for (int i=0; i<10; ++i)
    {
        //cout<<i<<endl;
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (tmp == NULL)
        {
            deleteList(head);
            return NULL;
        }
        tmp->data = i;
        tmp->next = NULL;
        pre->next = tmp;
        pre = tmp;
    }
    
    return head;
}

void print(struct ListNode *head)
{
    struct ListNode *p = head->next;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    struct ListNode *head = createList();
    print(head);
    deleteList(head);
    print(head);
    return 0;
}