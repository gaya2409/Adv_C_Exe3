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


	void removeItem(charNode **head) {
		if (*head == NULL) return; //if stack empty
		charNode* tmp = *head;
		*head = (*head)->next;
		free(tmp);
}


int isEmptyStack(const Stack* s)
{
	return (!(s->head));

	// add your code here
}



void display(Stack*s)
{
	print(s->head);
}

void print(charNode* head)
{
	charNode* tmp;
	tmp = head;
	while (tmp != NULL) {
		printf(" % d ", tmp->data);
		tmp = tmp->next;
	}
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack* reverse;
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
	// add your code here
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}