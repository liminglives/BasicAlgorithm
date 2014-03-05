#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

const int MIN_DATA = -(int)((~((unsigned int)0))>>1)-1;

typedef struct BinaryHeap
{
	int capacity;
	int size;
	int *data;
}PriorityQueue;

PriorityQueue * initilaze(int maxElements);
void insert(PriorityQueue *queue, int data);
int deleteMin(PriorityQueue *queue);
bool isEmpty(PriorityQueue *queue);
bool isFull(PriorityQueue *queue);

#endif