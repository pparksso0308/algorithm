//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
////�켱���� ť ADT()�� ������ ������ �׸��� ���ԵǸ�, ������ ������ ���� �����Ǵ� ������ ������ ���Ѵ�.
////PQ-sort�� ��������Ʈ�� �����ϸ� ��������


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
//	// ��������
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
//	//��������
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
//	arr = (int*)malloc(sizeof(int)*N);//�����Ҵ�
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