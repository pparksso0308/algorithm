//#include <stdio.h>
//#include <stdlib.h>
//#define STACK_SIZE 100
//
//typedef int element;
//
//element stack[STACK_SIZE];
//int top = -1;
//
////������ �������� Ȯ���ϴ� ����
//int isEmpty() 
//{
//	if (top == -1) return 1; // �����̸� 1
//	else return 0; // ������ �ƴϸ� 0
//}
//
//// ������ ��ȭ���� Ȯ��
//int isFull()
//{
//	if (top == STACK_SIZE - 1)	return 1;
//	else return 0;
//}
//
//// ������ top�� ���� ����
//void push(element item)
//{
//	if (isFull())
//	{
//		printf("Stack is full\n");
//		return;
//	}
//	else
//	{
//		stack[++top] == item; // top�� ������Ų �� ���� top�� ���� ����
//	}
//
//}
//	//������ top���� ���Ҹ� �����ϴ� ����
//	element pop()
//	{
//		if (isEmpty())
//		{
//			printf("Stack is empty\n");
//			return 0;
//		}
//		else
//		{
//			return stack[top--];// ���� top���� ��ȯ ��, top ����
//		}
//	}
//
//	//������ top ���� �˻�
//	element peek()
//	{
//		if (isEmpty())
//		{
//			printf("Stack is empty\n");
//			return 0;
//		}
//		else
//			return stack[top];
//	}
//
//	//������ ���Ҹ� ���
//	void printStack()
//	{
//		for (int i = 0; i < top; i++)
//		{
//			printf(" %d", stack[i]);
//		}
//		printf("\n");
//	}
//
//	int main()
//	{
//		element item;
//	}
