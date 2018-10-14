#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//
////우선순위 큐 ADT()는 임의의 데이터 항못이 삽입되며, 일정한 순서에 의해 삭제되는 데이터 구조를 말한다.
////PQ-sort를 무순 리스트로 구현하면 선택정렬

void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

////선택정렬_앞에서부터_오름차순
//void selectionSort(int arr[], int size)
//{
//	int min;
//	int tmp;
//	int i, j;
//
//	printf("정렬할 원소들: ");
//	print(arr, size);
//
//	for (i = 0; i < size-1; i++)
//	{
//		min = i;
//		//제자리 정렬
//		for (j = i+1; j < size; j++)
//		{	
//			if (arr[j] < arr[min])
//			{
//				if (arr[j] < arr[min]) 
//					min = j; // 현재 가장 작은 숫자 찾기
//			}
//		}
//		//O(1)의 추가 공간 사용
//		swap(&arr[i], &arr[min]);
//		printf("\n%d단계 : ", i + 1);
//		print(arr, size);
//	}
//}


//선택정렬_앞에서부터_내림차순
void selectionSort(int arr[], int size)
{
	int max;
	int tmp;
	int i, j;

	printf("정렬할 원소들: ");
	print(arr, size);

	for (i = 0; i < size - 1; i++)
	{
		max = i;
		//제자리 정렬
		for (j = i+1; j < size; j++)
		{
			if (arr[j] > arr[max])
			{
					max = j; // 현재 가장 작은 숫자 찾기
			}
		}
		//O(1)의 추가 공간 사용
		swap(&arr[i], &arr[max]);
		printf("\n%d단계 : ", i + 1);
		print(arr, size);
	}
}

////선택정렬_뒤에서 부터_오름차순
//void selectionSortBack(int arr[], int size)
//{
//	int max;
//	int tmp;
//	int i, j;
//
//	printf("정렬할 원소들: ");
//	print(arr, size);
//	for (i = 0; i < size; i++)
//	{
//		max = size - 1 - i;
//		//제자리 정렬
//		for (j = 0; j < size - i; j++)
//		{
//			if (arr[j] > arr[max])
//			{
//				max = j;
//			}
//		}
//		//O(1)의 추가 공간 사용
//		swap(&arr[max], &arr[size-1-i]);
//		printf("\n%d단계 : ", i + 1);
//		print(arr, size);
//	}
//}


//선택정렬_뒤에서 부터_내림차순
void selectionSortBack(int arr[], int size)
{
	int min;
	int tmp;
	int i, j;

	printf("정렬할 원소들: ");
	print(arr, size);
	for (i = 0; i < size; i++)
	{
		min = size - 1 - i;
		//제자리 정렬
		for (j = 0; j < size - i; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		//O(1)의 추가 공간 사용
		swap(&arr[min], &arr[size - 1 - i]);
		printf("\n%d단계 : ", i + 1);
		print(arr, size);
	}
}



int main()
{
	int N, data;
	int *arr;

	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int)*N);//동적할당

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &data);
		arr[i] = data;
	}

	selectionSortBack(arr, N);
	print(arr, N);


}

