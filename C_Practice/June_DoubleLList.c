#include <stdio.h>
#include <stdlib.h>
/*
과제: 더블링크드리스트 탐색 최적화
평균값을 구해서, Head부터 탐색할지, Tail부터 탐색할지 판단하기
//1.현재 리스트의 평균을 구한 후,
2.삽입하려는 값이 평균보다 작거나 같으면, 헤드부터 탐색 후 삽입 //Comp Func CallBack??
3.삽입하려는 값이 평균보다 크면, 테일부터 탐색 후 삽입
*/

typedef struct _node {
	int nData;
	struct _node* pPrev;
	struct _node* pNext;
}NODE;
NODE* head = NULL;
NODE* tail = NULL;
int avg = 0, count = 1;

int GetAverage() {
	int sum = 0;
	NODE* pNode = head;
	while (NULL != pNode) {
		sum += pNode->nData;
		pNode = pNode->pNext;
		count++;
	}
	avg = sum / count;
	return avg;
}

int FindNode(int _nData) {

}

void InsertNodeFromTail(int _nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;
	pNewNode->nData = _nData;

	if (NULL == tail) {
		head = pNewNode;
		tail = pNewNode;
	}
	else {
		NODE* pNode = tail;
		//Case by Case
		if (pNewNode->nData >= pNode->nData) {
			pNewNode->pNext = NULL;
			pNewNode->pPrev = pNode;
			pNode->pNext = pNewNode;
			tail = pNewNode;
		}
		else {
			//Mid
			while (NULL != pNode->pPrev) {
				if (pNewNode->nData >= pNode->pPrev->nData) {
					pNewNode->pNext = pNode;
					pNewNode->pPrev = pNode->pPrev;
					pNode->pPrev->pNext = pNewNode;
					pNode->pPrev = pNewNode;
					break;
				}
				pNode = pNode->pPrev;
			}
			if (pNode->pPrev == NULL) {
				pNewNode->pNext = pNode;
				pNode->pPrev = pNewNode;
				head = pNewNode;
			}
		}
	}
}

void InsertNodeFromHead(int _nData) {
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	pNewNode->pNext = NULL;
	pNewNode->pPrev = NULL;
	pNewNode->nData = _nData;

	if (NULL == head) {
		head = pNewNode;
		tail = pNewNode;
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
				tail = pNewNode;
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
	int input = 0;
	while (1) {
		printf("Input Data : ");
		scanf_s("%d", &input);
		if (input == EOF) break; //-1, Break

		if (input >= GetAverage()) {
			printf("\n Average = %d\n", GetAverage());
			InsertNodeFromTail(input);
		}
		else {
			printf("\n Average = %d\n", GetAverage());
			InsertNodeFromHead(input);
		}
	}
	PrintList_Head();
	PrintList_Tail();
	return 0;
}