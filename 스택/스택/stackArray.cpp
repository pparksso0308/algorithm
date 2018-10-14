//#include <stdio.h>
//#include <stdlib.h>
//#define STACK_SIZE 100
//
//typedef int element;
//
//element stack[STACK_SIZE];
//int top = -1;
//
////스택이 공백인지 확인하는 연산
//int isEmpty() 
//{
//	if (top == -1) return 1; // 공백이면 1
//	else return 0; // 공백이 아니면 0
//}
//
//// 스택이 포화인지 확인
//int isFull()
//{
//	if (top == STACK_SIZE - 1)	return 1;
//	else return 0;
//}
//
//// 스택의 top에 원소 삽입
//void push(element item)
//{
//	if (isFull())
//	{
//		printf("Stack is full\n");
//		return;
//	}
//	else
//	{
//		stack[++top] == item; // top을 증가시킨 후 현재 top에 원소 삽입
//	}
//
//}
//	//스택의 top에서 원소를 삭제하는 연산
//	element pop()
//	{
//		if (isEmpty())
//		{
//			printf("Stack is empty\n");
//			return 0;
//		}
//		else
//		{
//			return stack[top--];// 현재 top원소 반환 후, top 감소
//		}
//	}
//
//	//스택의 top 원소 검사
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
//	//스택의 원소를 출력
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
