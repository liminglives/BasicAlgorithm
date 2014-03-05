#include "BinaryHeap.h"
#include <stdlib.h>
#include <iostream>

PriorityQueue * initilaze(int maxElements)
{
	if (maxElements < 0)
	{
		return NULL;
	}
	PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
	if (queue == NULL)
	{
		std::cout << "malloc failed" << std::endl;
		return NULL;
	}
	queue->capacity = maxElements;
	queue->size = 0;
	queue->data = (int *)malloc(sizeof(int) * (maxElements+1));
	if (queue->data == NULL)
	{
		std::cout << "malloc failed" << std::endl;
		free(queue);
		return NULL;
	}
	queue->data[0] = MIN_DATA;
	return queue;
}

bool isEmpty(PriorityQueue *queue)
{
	return queue->size == 0;
}
bool isFull(PriorityQueue *queue)
{
	return queue->size >= queue->capacity;  
}

void insert(PriorityQueue *queue, int data)
{
	if (queue->size >= queue->capacity)
		return;
	int i;
	for (i=++queue->size; data < queue->data[i/2]; i/=2)
	{
		queue->data[i] = queue->data[i/2];
	}
	queue->data[i] = data;
}

int deleteMin(PriorityQueue *queue)
{
	if (isEmpty(queue))
	{
		std::cout << "priority queue is empty" << std::endl;
		return queue->data[0];
	}
	int ret = queue->data[1];
	int last = queue->data[queue->size--];
	int i,child;
	for (i=1; i*2<=queue->size; i=child)
	{
		child = i*2;
		if (child != queue->size && queue->data[child] > queue->data[child+1])
			++child;
		if (last > queue->data[child])
			queue->data[i] = queue->data[child];
		else
			break;
	}
	queue->data[i] = last;
	return ret;
}

int main()
{
	std::cout << MIN_DATA << std::endl;
	PriorityQueue *q = initilaze(10);
	int a[10] = {12,3,6,4,1,11,26,14,27,8};
	std::cout << q->size << std::endl;
	for (int i=0; i<10; ++i)
		insert(q, a[i]);
	while (q->size > 0)
		std::cout << deleteMin(q) << " ";
	std::cout << q->size << std::endl;
	return 0;
}



