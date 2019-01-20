#include <stdio.h>
#include <stdlib.h>
/*
링크드 리스트 ordered insert / find / delete 구현
*/
typedef struct _node {
	int nData;
	struct _node* pNext;
}NODE;

NODE* head = NULL;

void FindNode(int _nData) {
	//if found, print Node index, data
	//if not, print "Not Found"
	NODE* pNode = head;
	int nIndex = 1;
	while (NULL != pNode) {
		if (_nData == pNode->nData) {
			printf("Node Index: %d, Data: %d\n", nIndex, _nData);
			return;
		}
		else {
			pNode = pNode->pNext;
			++nIndex;
		}
	}
	printf("Not Found!\n");
}

void DeleteNode(int _nData) {

}
//Insert a Node(Ordered)
void InsertNode_Ordered(int _nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE)); //Allocation memory to New Node
	pNewNode->nData = _nData; //Initialization
	pNewNode->pNext = NULL;

	if (NULL == head) {
		head = pNewNode;
	}
	else {
		NODE* pNode = head;
		while (NULL != pNode->pNext) {
			pNode = pNode->pNext;
		}
		pNode->pNext = pNewNode;
	}
}


//Insert a Node
void InsertNode(int _nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE)); //Allocation memory to New Node
	pNewNode->nData = _nData; //Initialization
	pNewNode->pNext = NULL;

	if (NULL == head) {
		head = pNewNode;
	}
	else {
		NODE* pNode = head;
		while (NULL != pNode->pNext) {
			pNode = pNode->pNext;
		}
		pNode->pNext = pNewNode;
	}
}

void PrintList() {
	NODE* pNode = head;
	while (NULL != pNode) {
		printf("%d -> ", pNode->nData);
		pNode = pNode->pNext;
	}
	printf("NULL\n");
}

void ClearList() {
	NODE* pNode = head;
	while (NULL != pNode) {
		NODE* tmpNode = pNode;
		pNode = pNode->pNext;
		free(tmpNode);
		tmpNode = NULL;
	}
}
int main(void) {
	InsertNode(10);
	InsertNode(7);
	InsertNode(5);
	PrintList();
	FindNode(5);
	ClearList();
	return 0;
}