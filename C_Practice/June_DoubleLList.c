#include <stdio.h>
#include <stdlib.h>
/*
����: ����ũ�帮��Ʈ Ž�� ����ȭ
��հ��� ���ؼ�, Head���� Ž������, Tail���� Ž������ �Ǵ��ϱ�
//1.���� ����Ʈ�� ����� ���� ��,
2.�����Ϸ��� ���� ��պ��� �۰ų� ������, ������ Ž�� �� ���� //Comp Func CallBack??
3.�����Ϸ��� ���� ��պ��� ũ��, ���Ϻ��� Ž�� �� ����
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