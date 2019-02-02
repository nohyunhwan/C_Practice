#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 5
int count = 0;
typedef struct _node {
	int nData;
	struct _node* pNext;
}NODE;
NODE* head = NULL;
NODE* tail = NULL;

void push(int nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	pNewNode->nData = nData;
	pNewNode->pNext = NULL;

	if (count > STACK_SIZE) {
		printf("STACK OVERFLOW\n");
		return;
	}
	if (NULL == head) {
		head = pNewNode;
		tail = pNewNode;
		count++;
	}
	else {
		NODE* pNode = tail;
		pNode->pNext = pNewNode;
		tail = pNewNode;
		count++;
	}
}

int pop() {
	NODE* pNode = head;
	printf("Pop : %d\n", pNode->nData);
	head = pNode->pNext;
	count--;
}

int main() {
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	//Over
	push(5);
	push(5);
	push(5);

	pop();
	pop();
	pop();
	pop();
	pop();
	return 0;
}