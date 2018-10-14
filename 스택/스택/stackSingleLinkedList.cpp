#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stackNode
{
	element data;
	struct stackNode * link;
}Node;

Node * top; //스택의 top 노드를 지정하는 포인터

Node * getNode()
{
	return (Node*)malloc(sizeof(Node));
}

//스택이 공백인지 확인하는 연산
int isEmpty()
{
	if (top == NULL) return 1; // 공백이면 1
	else return 0; // 공백이 아니면 0
}


// 스택의 top에 원소 삽입
void push(element item)
{
	Node * newNode = getNode();

	newNode -> data = item;
	newNode -> link = top;	// top 위에 newNode 연결
	top = newNode; // top의 위치를 newNode로 이동

}
//스택의 top에서 원소를 삭제하는 연산
element pop()
{
	element item;
	Node * temp = top;	// temp ==삭제할 노드

	if (isEmpty()) return 0;// 공백이면 끝
	
	item = temp->data;	
	top = temp->link;	// top의 위치를 하나 아래로 이동
	free(temp);	// 삭제된 노드의 메모리 반환
	return item;	//삭제된 원소 반환
}

//스택의  top 원소 검사
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

//스택의 원소를 출력
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