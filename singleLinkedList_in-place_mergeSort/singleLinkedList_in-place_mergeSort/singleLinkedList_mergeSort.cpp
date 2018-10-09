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
// ���Ͽ��Ḯ��Ʈ L�� ���ҵ��� �պ������ϰ� ���ĵ� ����� ������������ ���

void mergeSort(Node ** headRef)
{
	Node * headNode = *headRef;
	Node *frontPos;
	Node *backPos;

	//���̰� 0�̰ų� 1�̸�
	if (headNode == NULL || headNode->link == NULL)
	{
		return;
	}
	// 2���� ������, node�� �ɰ����� ��ġ ǥ��
	FrontBackSplit(headNode, &frontPos, &backPos);

	//��ͷ� ����
	mergeSort(&frontPos);
	mergeSort(&backPos);

	//���ĵ� 2���� ����Ʈ�� �պ��Ѵ�
	*headRef = merge(frontPos, backPos);
}

//�� ���� ���ĵ� ���Ͽ��Ḯ��Ʈ�� �պ��� �ϳ��� ���Ḯ��Ʈ�� ��ȯ

Node * merge(Node * frontList, Node * backList)
{
	Node * result = NULL;

	//���� �� ����Ʈ���
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
// 2���� ����Ʈ�� ������ ����, 2���� ���� �Ķ���� ���
void FrontBackSplit(Node* head, Node **frontRef, Node **backRef)
{
	Node * fast; // ���� ������(2 node)
	Node *slow;	// ���� ������(1 node)

				// ���̰� 0 or 1�� ��
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
		//slow�� �������� ����
		*frontRef = head;
		*backRef = slow->link;
		slow->link = NULL;//���߿�!
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