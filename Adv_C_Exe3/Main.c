#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	initStack(s);
	destroyStack(s);
	s = (Stack*)malloc(sizeof(Stack));
	initStack(s);
	push(s, 'a');
	printf("push expects a='%c'\n", s->head->data);
	printf("pop expects a='%c'\n", pop(s));
	printf("isEmptyStack expects empty='%d'\n", isEmptyStack(s));
	printf("flipBetweenHashes expects=\"%s\"\n", "Remember this practice");
	flipBetweenHashes("Remem#reb# this#carp s#tice");
	push(s, 'm');
	push(s, 'a');
	push(s, 'd');
	push(s, 'a');
	push(s, 'm');
	printf("isPalindrom expects 1=%d", isPalindrome(s));
	pop(s);
	printf("isPalindrom expects 0=%d", isPalindrome(s));
	rotateStack(s, 3);
	printf("pop expects m='%c'\n", pop(s));
	printf("pop expects a='%c'\n", pop(s));
	printf("pop expects s='%c'\n", pop(s));
	printf("pop expects a='%c'\n", pop(s));

	/*

	initQueue
	destroyQueue
	enqueue
	dequeue
	isEmptyQueue
	rotateQueue
	cutAndReplace
	sortKidsFirst
	*/
}