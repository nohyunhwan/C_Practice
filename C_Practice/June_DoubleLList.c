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
		//Case by Case
		if (pNewNode->nData <= pNode->nData) {
			pNewNode->pNext = pNode;
			pNode->pPrev = pNewNode;
			head = pNewNode;
		}
		else {
			//Mid
			while (NULL != pNode->pNext) {
				if (pNewNode->nData <= pNode->pNext->nData) {
					pNewNode->pNext = pNode->pNext;
					pNewNode->pPrev = pNode;
					pNode->pNext->pPrev = pNewNode;
					pNode->pNext = pNewNode;
					break;
				}
				pNode = pNode->pNext;
			}
			if (pNode->pNext == NULL) {
				pNewNode->pPrev = pNode;
				pNode->pNext = pNewNode;
			}
		}
	}
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
	InsertNode(10);
	InsertNode(7);
	InsertNode(4);
	InsertNode(5);
	PrintList_Head();
	PrintList_Tail();
	return 0;
}