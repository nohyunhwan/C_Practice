#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int nData;
	struct _node* pPrev;
	struct _node* pNext;
}NODE;
NODE* head = NULL;
NODE* tail = NULL;

void InsertNode(int _nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;
	pNewNode->nData = _nData;

	if (NULL == head) {
		head = pNewNode;
	}
	else {
		NODE* pNode = head;
		while (NULL != pNode->pNext) {
			pNode = pNode->pNext;
		}
		pNode->pNext = pNewNode;
		pNewNode->pPrev = pNode;
	}
	tail = pNewNode;
}

void PrintList_Head() {
	NODE* pNode = head;
	while (NULL != pNode) {
		printf("%d->", pNode->nData);
		pNode = pNode->pNext;
	}
	printf("NULL\n");
}

void PrintList_Tail() {
	NODE* pNode = tail;
	while (NULL != pNode) {
		printf("%d->", pNode->nData);
		pNode = pNode->pPrev;
	}
	printf("NULL\n");
}

int main(void) {
	InsertNode(1);
	InsertNode(2);
	InsertNode(3);
	InsertNode(4);
	InsertNode(5);
	PrintList_Head();
	PrintList_Tail();
	return 0;
}