#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct __node
{
	int elem;
	struct __node *link;
}Node;



void FrontBackSplit(Node* head, Node **frontRef, Node **backRef);
Node * merge(Node * frontList, Node * backList);



Node* getNode(void)
{
	return (Node*)malloc(sizeof(Node));
}



void insertNode(Node ** head, int x)
{
	Node * newNode = getNode();

	newNode->elem = x;
	newNode->link = (*head);

	(*head) = newNode;

}
void printList(Node * head)
{

	while (head != NULL)
	{
		printf(" %d", head->elem);
		head = head->link;
	}
	printf("\n");
}
// 단일연결리스트 L의 원소들을 합병정렬하겨 정렬된 결과를 오름차순으로 출력

void mergeSort(Node ** headRef)
{
	Node * headNode = *headRef;
	Node *frontPos;
	Node *backPos;

	//길이가 0이거나 1이면
	if (headNode == NULL || headNode->link == NULL)
	{
		return;
	}
	// 2개로 나누기, node로 쪼개지는 위치 표현
	FrontBackSplit(headNode, &frontPos, &backPos);

	//재귀로 정렬
	mergeSort(&frontPos);
	mergeSort(&backPos);

	//정렬된 2개의 리스트를 합병한다
	*headRef = merge(frontPos, backPos);
}

//두 개의 정렬된 단일연결리스트를 합병한 하나의 연결리스트를 반환

Node * merge(Node * frontList, Node * backList)
{
	Node * result = NULL;

	//만약 빈 리스트라면
	if (frontList == NULL)
		return backList;
	else if (backList == NULL)
		return frontList;

	if (frontList->elem < backList->elem)
	{
		result = frontList;
		result->link = merge(frontList->link, backList); // in-place
	}
	else
	{
		result = backList;
		result->link = merge(frontList, backList->link); // in-plac
	}
	return result;

}
// 2개의 리스트로 나누기 위해, 2개의 참조 파라메터 사용
void FrontBackSplit(Node* head, Node **frontRef, Node **backRef)
{
	Node * fast; // 빠른 포인터(2 node)
	Node *slow;	// 느린 포인터(1 node)

				// 길이가 0 or 1일 때
	if (head == NULL || head->link == NULL)
	{
		*frontRef = head;
		*backRef = NULL;
	}
	else
	{
		slow = head;
		fast = head->link;

		while (fast != NULL)
		{
			fast = fast->link;
			if (fast != NULL)
			{
				slow = slow->link;
				fast = fast->link;
			}
		}
		//slow를 기준으로 나눔
		*frontRef = head;
		*backRef = slow->link;
		slow->link = NULL;//중중요!
	}

}

int main()
{
	int N, i, j, k;
	int elem;

	Node * head = NULL;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &elem);
		insertNode(&head, elem);
	}


	mergeSort(&head);

	printList(head);
	getchar();
}