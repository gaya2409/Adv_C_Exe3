#include "Stack.h"
#include <stdio.h>



//typedef struct charNode {
//	char data;
//	struct charNode* next;
//} charNode;
//typedef struct Stack {
//	charNode* head;
//} Stack;
/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;

}

void destroyStack(Stack* s)
{
	charNode* tmp;
	while (s->head != NULL) {
		tmp = s->head;
		s->head = s->head->next;
		free(tmp);
	}
}

void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode == NULL) {
		printf("push: memory allocation problem\n");
		return;
	}
	newnode->data = data;
	s->head = addToHead(s->head, newnode);

}

charNode* addToHead(charNode* head, charNode* toAdd) {
	toAdd->next = head;
	head = toAdd;
	return head;
}

char pop(Stack* s) {

	char res;
	if (isEmptyStack(s)) { printf("\nSTACK IS EMPTY"); return 0; }
	res = s->head->data;
	removeItem(&(s->head));//pop it from the stack 
	return(res);
}


void removeItem(charNode** head) {
	if (*head == NULL) return; //if stack empty
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}


int isEmptyStack(const Stack* s)
{
	return (!(s->head));
}

void print(charNode* head)
{
	charNode* tmp;
	tmp = head;
	while (tmp != NULL) {
		printf(" %d ", tmp->data);
		tmp = tmp->next;
	}
}

void display(Stack* s)
{
	print(s->head);
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack* reverse = (Stack*)malloc(sizeof(Stack));
	initStack(reverse);
	for (int i = 0; i < strlen(sentence); i++) {

		if (sentence[i] == '#') {
			int j = 0;

			while (sentence[j] != '#') {
				push(reverse, reverse->head->data);
				j++;
			}
			display(reverse);
		}
		else printf("%d", sentence[i]);
	}
}



int isPalindrome(Stack* s)
{
	Stack* x;
	x = (Stack*)malloc(sizeof(Stack));
	initStack(x);
	charNode* current = s->head;
	while (current != NULL) {
		push(x, current->data);
		current = current->next;
	}
	while (!isEmptyStack(s)) {
		if (pop(s) != pop(x))  return 0;
	}
	return 1;
}


void rotateStack(Stack* s, int n)
{

	if (n < 0 || isEmptyStack(s)) return;

	charNode* current = s->head;
	int counter = 0;
	while (current != NULL) {
		current = current->next;
		counter++;
	}
	if (n > counter) return;

	Stack* x = (Stack*)malloc(sizeof(Stack*));
	if (x == NULL) {
		return 0;
	}
	Stack* d = (Stack*)malloc(sizeof(Stack*));
	if (d == NULL) {
		return 0;
	}
	for (int i = 0; i < counter - n; i++) {
		push(x, pop(s));
	}
	for (int j = 0; j < n; j++) {
		push(d, pop(s));
	}
	for (int c = 0; c < counter - n; c++) {
		push(s, pop(x));
	}
	for (int l = 0; l < n; l++) {
		push(s, pop(d));
	}
	//to do free
}