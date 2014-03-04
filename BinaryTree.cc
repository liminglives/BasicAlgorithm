#include <iostream>
#include <stdlib.h>

using namespace std;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}Node;

Node * MakeEmpty()
{
    Node *tmp = (Node *)malloc(sizeof(Node));

}

Node * find(Node *node, int data)
{
    if (node != NULL)
    {
        if (node->data == data)
            return node;
        if (data < node->data)
            return find(node->left, data);
        if (data > node->data)
            return find(node->right, data);
    }
    return NULL;
}

int getHeight(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return max(getHeight(node->left), getHeight(node->right)) + 1;
}

Node * insert(Node *node, int data)
{
    if (node == NULL)
    {
        node = (Node *)malloc(sizeof(Node));
        if (node == NULL)
        {
            cout << "malloc failed" << endl;
            return NULL;
        }
		
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else
    {
        if (data < node->data)
            node->left = insert(node->left, data);
        else if(data > node->data)
            node->right = insert(node->right, data);
    }
    return node;
}

Node *findMin(Node *node)
{
    if (node == NULL)
        return NULL;
    else if (node->left == NULL)
        return node;
    else
        return findMin(node->left);
}

Node *findMax(Node *node)
{
    if (node == NULL)
        return NULL;
    while(node->right != NULL)
        node = node->right;
    return node;
}

Node *deleteNode(Node *node, int data)
{
    if (node == NULL)
        return NULL;
    if (node->data > data)
        node->left = deleteNode(node->left, data);
    else if (node->data < data)
        node->right = deleteNode(node->right, data);
    else
    {
        if (node->left && node->right)
        {
            Node *t = findMin(node->right);
            node->data = t->data;
            node->right = deleteNode(node->right, t->data);
        }
        else if (node->left)
        {
            Node *t = node;
            node = node->left;
            free(t);
        }
        else if (node->right)
        {
            Node *t = node;
            node = node->right;
            free(t);
        }
        else
        {
            free(node);
            node = NULL;
        }
    }

    return node;
}

void printTree(Node *node)
{
	if (node != NULL)
	{
		printTree(node->left);
		cout << node->data << " ";
		printTree(node->right);
	}
}

int main()
{
	int a[10] = {12,3,6,4,1,11,26,14,27,8};
	Node *root = NULL;
	for (int i=0; i<10; ++i)
	{
		root = insert(root, a[i]);
	}
	printTree(root);
	cout<<getHeight(root)<<endl;
	root = deleteNode(root, 12);
	printTree(root);
	return 0;
}



