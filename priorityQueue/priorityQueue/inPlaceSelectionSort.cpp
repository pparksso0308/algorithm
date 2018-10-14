#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//
////�켱���� ť ADT()�� ������ ������ �׸��� ���ԵǸ�, ������ ������ ���� �����Ǵ� ������ ������ ���Ѵ�.
////PQ-sort�� ���� ����Ʈ�� �����ϸ� ��������

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

////��������_�տ�������_��������
//void selectionSort(int arr[], int size)
//{
//	int min;
//	int tmp;
//	int i, j;
//
//	printf("������ ���ҵ�: ");
//	print(arr, size);
//
//	for (i = 0; i < size-1; i++)
//	{
//		min = i;
//		//���ڸ� ����
//		for (j = i+1; j < size; j++)
//		{	
//			if (arr[j] < arr[min])
//			{
//				if (arr[j] < arr[min]) 
//					min = j; // ���� ���� ���� ���� ã��
//			}
//		}
//		//O(1)�� �߰� ���� ���
//		swap(&arr[i], &arr[min]);
//		printf("\n%d�ܰ� : ", i + 1);
//		print(arr, size);
//	}
//}


//��������_�տ�������_��������
void selectionSort(int arr[], int size)
{
	int max;
	int tmp;
	int i, j;

	printf("������ ���ҵ�: ");
	print(arr, size);

	for (i = 0; i < size - 1; i++)
	{
		max = i;
		//���ڸ� ����
		for (j = i+1; j < size; j++)
		{
			if (arr[j] > arr[max])
			{
					max = j; // ���� ���� ���� ���� ã��
			}
		}
		//O(1)�� �߰� ���� ���
		swap(&arr[i], &arr[max]);
		printf("\n%d�ܰ� : ", i + 1);
		print(arr, size);
	}
}

////��������_�ڿ��� ����_��������
//void selectionSortBack(int arr[], int size)
//{
//	int max;
//	int tmp;
//	int i, j;
//
//	printf("������ ���ҵ�: ");
//	print(arr, size);
//	for (i = 0; i < size; i++)
//	{
//		max = size - 1 - i;
//		//���ڸ� ����
//		for (j = 0; j < size - i; j++)
//		{
//			if (arr[j] > arr[max])
//			{
//				max = j;
//			}
//		}
//		//O(1)�� �߰� ���� ���
//		swap(&arr[max], &arr[size-1-i]);
//		printf("\n%d�ܰ� : ", i + 1);
//		print(arr, size);
//	}
//}


//��������_�ڿ��� ����_��������
void selectionSortBack(int arr[], int size)
{
	int min;
	int tmp;
	int i, j;

	printf("������ ���ҵ�: ");
	print(arr, size);
	for (i = 0; i < size; i++)
	{
		min = size - 1 - i;
		//���ڸ� ����
		for (j = 0; j < size - i; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		//O(1)�� �߰� ���� ���
		swap(&arr[min], &arr[size - 1 - i]);
		printf("\n%d�ܰ� : ", i + 1);
		print(arr, size);
	}
}



int main()
{
	int N, data;
	int *arr;

	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int)*N);//�����Ҵ�

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &data);
		arr[i] = data;
	}

	selectionSortBack(arr, N);
	print(arr, N);


}

