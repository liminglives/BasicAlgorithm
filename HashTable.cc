//hash table by separate chaining 
#include <iostream>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
}List;

typedef struct HashTableHead
{
    int size;
    List **table;
}HashTable;

HashTable * initilaze(int size)
{
    if (size < 0)
        return NULL;
    //todo: calculate the next prime of number size;
    HashTable *hashtable = (HashTable *)malloc(sizeof(HashTable));
    if (hashtable == NULL)
        return NULL;
    hashtable->size = size;
    hashtable->table = (List **)malloc(sizeof(List *)*hashtable->size);
    if (hashtable->table == NULL)
    {
        free(hashtable);
        return NULL;
    }
    //memset(hashtable->table, 0, sizeof(List *)*hashtable->size);
    for (int i=0; i<hashtable->size; ++i)
    {
        hashtable->table[i] = (List *)malloc(sizeof(List));
        if (hashtable->table[i] == NULL)
            std::cout<<"out of space"<<std::endl; 
        else
            hashtable->table[i]->next = NULL;
    }
    
    return hashtable;
}

void insert(HashTable *hash, int data)
{
    if (hash == NULL)
        return;
    int index = data % hash->size;
    List *prev = hash->table[index];
    List *cur = prev->next;

    while(cur)
    {
        prev = cur; 
        if (cur->data == data)
            return;
        cur = cur->next;
    }

    prev->next = (List *)malloc(sizeof(List));
    prev->next->data = data;
    prev->next->next = NULL;
}

List * find(HashTable *hash, int data)
{
    if (hash == NULL)
        return NULL;
    int index = data % hash->size;
    List *tmp = hash->table[index]->next;
    while(tmp)
    {
        if (tmp->data == data)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void printList(List *head)
{
    if (!head)
        return;
    List *tmp = head->next;
    while(tmp)
    {
        std::cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    std::cout<<std::endl;
}

void printHashTable(HashTable *hash)
{
    if (!hash)
        return;
    
    for (int i=0; i<hash->size; ++i)
        printList(hash->table[i]);
}

int main()
{
    int a[10] = {1, 2, 3, 5, 12, 8, 11, 6, 14, 10};
    HashTable *hashtable = initilaze(7);
    for (int i=0; i<10; ++i)
        insert(hashtable, a[i]);
    printHashTable(hashtable);
    return 0;
}



