#include "Queue.h"
#include <stdio.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	intNode* tmp;
	while (q->head != NULL) {
		tmp = q->head;
		q->head = q->head->next;
		free(tmp);
	}
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* p = (intNode*)malloc(sizeof(intNode));
	//check allocation code added here…
	p->data = data; // set element data
	p->next = NULL;
	if (!isEmpty(q)) q->tail->next = p; // not Empty?
	//Add after last:
	else q->head = p; // Otherwise – it becomes
	//first
	q->tail = p; // update queue tail
}

unsigned int dequeue(Queue* q)
{
	if (isEmpty(q))
	{
		printf("Cannot dequeue an empty queue!");
		return 0;
	}
	int temp = q->head->data;
	intNode* p = q->head;
	q->head = q->head->next;
	if (q->head == NULL) //if queue gets empty
		q->tail = NULL;//both front and rear NULL
	free(p);
	return temp;
}

int isEmptyQueue(const Queue* q)
{
	return q->head == NULL && q->tail == NULL;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// add your code here
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	// add your code here
}