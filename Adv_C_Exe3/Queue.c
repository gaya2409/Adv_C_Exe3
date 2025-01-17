#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

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
	//check allocation code added here�
	p->data = data; // set element data
	p->next = NULL;
	if (!isEmptyQueue(q)) q->tail->next = p; // not Empty?
	//Add after last:
	else q->head = p; // Otherwise � it becomes
	//first
	q->tail = p; // update queue tail
}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q))
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
	if (isEmptyQueue(q)) {
		return;
	}
	Queue* m = (Queue*)malloc(sizeof(Queue));
	initQueue(m);
	while (q->head != q->tail)
	{
		enqueue(m, dequeue(q));
	}
	while (!isEmptyQueue(m)) {
		enqueue(q, dequeue(m));
	}
}

void cutAndReplace(Queue* q)
{
	if (isEmptyQueue(q)) return;
	intNode* current = q->head;
	int counter = 0;
	//count items in queue
	while (current != NULL) {
		current = current->next;
		counter++;
	}
	//if item cound is odd, add the average to the end of the queue
	if (counter % 2 != 0) {
		float sum = 0;
		current = q->head;
		for (int i = 0; i < counter; i++) {
			sum = sum + current->data;
			current = current->next;
		}
		float newnum = sum / counter;
		enqueue(q, newnum);
		counter++;
	}
	Queue* m;
	m = (Queue*)malloc(sizeof(Queue));
	if (m == NULL) { printf("malloc failed"); return; }
	initQueue(m);

	for (int i = 0; i < counter / 2; i++) {
		enqueue(q, dequeue(q));
	}

	for (int j = 0; j < counter / 2; j++) {
		enqueue(m, dequeue(q));
	}
	intNode* newTail = m->head;
	m->head = reverse(m->head);
	m->tail = newTail;
	for (int k = 0; k < counter / 2; k++) {
		enqueue(q, dequeue(m));
	}
	for (int l = 0; l < counter / 2; l++) {
		enqueue(q, dequeue(q));
	}
}

intNode* reverse(intNode* head) {
	if (head == NULL || head->next == NULL) return head;
	intNode* prev = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return prev;
}

void sortKidsFirst(Queue* q)
{
	if (isEmptyQueue(q)) return;
	Queue* m = (Queue*)malloc(sizeof(Queue));
	initQueue(m);

	int counter = 0;

	intNode* current = q->head;
	while (current != NULL) {
		current = current->next;
		counter++;
	}

	while (!isEmptyQueue(q)) {
		int min = dequeue(q);
		counter--;
		for (int i = 0; i < counter; i++)
		{
			int val = dequeue(q);
			if (min >= val) {
				enqueue(q, min);
				min = val;
			}
			else {
				enqueue(q, val);
			}
		}
		enqueue(m, min);
	}
	while (!isEmptyQueue(m)) {
		enqueue(q, dequeue(m));
	}
}