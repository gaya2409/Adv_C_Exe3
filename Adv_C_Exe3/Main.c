#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if (s == NULL) return;
	initStack(s);
	destroyStack(s);
	s = (Stack*)malloc(sizeof(Stack));
	initStack(s);
	push(s, 'a');
	printf("push expects a='%c'\n", s->head->data);
	printf("pop expects a='%c'\n", pop(s));
	printf("isEmptyStack expects empty='%d'\n", isEmptyStack(s));
	printf("flipBetweenHashes should print \"%s\"\n", "Remember this practice");
	flipBetweenHashes("Remem#reb# this#carp #tice");
	printf("\n");
	push(s, 'm');
	push(s, 'a');
	push(s, 'd');
	push(s, 'a');
	push(s, 'm');
	printf("isPalindrom expects 1=%d\n", isPalindrome(s));
	push(s, 'a');
	push(s, 'd');
	push(s, 'a');
	push(s, 'm');
	printf("isPalindrom expects 0=%d\n", isPalindrome(s));
	destroyStack(s);
	s = (Stack*)malloc(sizeof(Stack));
	initStack(s);
	push(s, 'a');
	push(s, 'b');
	push(s, 'c');
	push(s, 'd');
	rotateStack(s, 3);
	printf("pop expects c='%c'\n", pop(s));
	printf("pop expects b='%c'\n", pop(s));
	printf("pop expects a='%c'\n", pop(s));
	printf("pop expects d='%c'\n", pop(s));
	destroyStack(s);
	free(s);

	 // initQueue
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL) return;
	initQueue(q);
	destroyQueue(q);
	q = (Queue*)malloc(sizeof(Queue));
	initQueue(q);
	enqueue(q, 1);
	printf("enqueue expects 1='%d'\n", q->head->data);
	printf("dequeue expects 1='%d'\n", dequeue(q));
	printf("isEmptyQueue expects empty='%d'\n", isEmptyQueue(q));
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	rotateQueue(q);
	printf("dequeue expects 4='%d'\n", dequeue(q));
	printf("dequeue expects 1='%d'\n", dequeue(q));
	printf("dequeue expects 2='%d'\n", dequeue(q));
	printf("dequeue expects 3='%d'\n", dequeue(q));
	enqueue(q, 6);
	enqueue(q, 1);
	enqueue(q, 5);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 1);
	enqueue(q, 9);
	cutAndReplace(q);
	printf("dequeue expects 3='%d'\n", dequeue(q));
	printf("dequeue expects 9='%d'\n", dequeue(q));
	printf("dequeue expects 1='%d'\n", dequeue(q));
	printf("dequeue expects 3='%d'\n", dequeue(q));
	printf("dequeue expects 6='%d'\n", dequeue(q));
	printf("dequeue expects 1='%d'\n", dequeue(q));
	printf("dequeue expects 5='%d'\n", dequeue(q));
	printf("dequeue expects 2='%d'\n", dequeue(q));

	enqueue(q, 6);
	enqueue(q, 1);
	enqueue(q, 5);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 1);
	enqueue(q, 9);
	sortKidsFirst(q);
	printf("dequeue expects 1='%d'\n", dequeue(q));
	printf("dequeue expects 1='%d'\n", dequeue(q));
	printf("dequeue expects 2='%d'\n", dequeue(q));
	printf("dequeue expects 3='%d'\n", dequeue(q));
	printf("dequeue expects 5='%d'\n", dequeue(q));
	printf("dequeue expects 6='%d'\n", dequeue(q));
	printf("dequeue expects 9='%d'\n", dequeue(q));

	destroyQueue(q);
	free(q);
}