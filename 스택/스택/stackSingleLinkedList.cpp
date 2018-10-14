#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stackNode
{
	element data;
	struct stackNode * link;
}Node;

Node * top; //������ top ��带 �����ϴ� ������

Node * getNode()
{
	return (Node*)malloc(sizeof(Node));
}

//������ �������� Ȯ���ϴ� ����
int isEmpty()
{
	if (top == NULL) return 1; // �����̸� 1
	else return 0; // ������ �ƴϸ� 0
}


// ������ top�� ���� ����
void push(element item)
{
	Node * newNode = getNode();

	newNode -> data = item;
	newNode -> link = top;	// top ���� newNode ����
	top = newNode; // top�� ��ġ�� newNode�� �̵�

}
//������ top���� ���Ҹ� �����ϴ� ����
element pop()
{
	element item;
	Node * temp = top;	// temp ==������ ���

	if (isEmpty()) return 0;// �����̸� ��
	
	item = temp->data;	
	top = temp->link;	// top�� ��ġ�� �ϳ� �Ʒ��� �̵�
	free(temp);	// ������ ����� �޸� ��ȯ
	return item;	//������ ���� ��ȯ
}

//������  top ���� �˻�
element peek()
{
	if (isEmpty())
	{
		printf("Stack is empty\n");
		return 0;
	}
	else
		return (top->data);
}

//������ ���Ҹ� ���
void printStack()
{
	Node * temp;
	
	while (temp)
	{
		printf(" %d", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main()
{
	element item;
	top = NULL;
}