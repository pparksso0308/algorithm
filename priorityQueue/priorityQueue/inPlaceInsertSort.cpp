//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
////우선순위 큐 ADT()는 임의의 데이터 항못이 삽입되며, 일정한 순서에 의해 삭제되는 데이터 구조를 말한다.
////PQ-sort를 순서리스트로 구현하면 삽입정렬


//
//void print(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf(" %d", arr[i]);
//	}
//	printf("\n");
//}
//

//void insertSort(int arr[], int size)
//{
//	int i, j;
//	int tmp;
//
//	// 오름차순
//	/*for (i = 1; i < size; i++)
//	{
//		tmp = arr[i];
//		j = i;
//
//		while (tmp < arr[j - 1])
//		{
//			arr[j] = arr[j - 1];
//			j--;
//
//		}
//		arr[j] = tmp;
//	}*/
//
//	//내림차순
//	for (i = 1; i < size; i++)
//	{
//		tmp = arr[i];
//		j = i;
//
//		while (tmp > arr[j - 1] && j>0)
//		{
//			arr[j] = arr[j - 1];
//			j--;
//		}
//		arr[j] = tmp;
//	}
//}
//
//void print(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf(" %d", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int N, data;
//	int *arr;
//
//	scanf("%d", &N);
//	arr = (int*)malloc(sizeof(int)*N);//동적할당
//
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &data);
//		arr[i] = data;
//	}
//
//	insertSort(arr, N);
//	print(arr, N);
//
//
//}