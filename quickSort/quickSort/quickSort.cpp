#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choosePivot(int frontPos, int backPos)
{

	if (backPos - frontPos < 3)
		return backPos;

	int n1, n2, n3;
	int middle;
	srand(time(NULL));

	n1 = rand() % (backPos - frontPos + 1) + frontPos;
	n2 = rand() % (backPos - frontPos + 1) + frontPos;
	n3 = rand() % (backPos - frontPos + 1) + frontPos;

	if (n1 > n2)
	{
		if (n2 > n3)
			middle = n2;
		else
		{// n1>n2, n2 < n3
			if (n1 > n3)
				middle = n3;
			else
				middle = n1;
		}
	}
	else
	{
		//n1<n2
		if (n2 < n3)
			middle = n2;
		else
		{
			//n1<n2, n2>n3
			if (n1 < n3)
				middle = n3;
			else
				middle = n1;
		}
	}

	return middle;

}

void swap(int * a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

int partition(int * arr, int frontPos, int backPos)
{

	int pivot = choosePivot(frontPos, backPos);

	int i, j;

	//pivotÀ» ¸Ç ¸¶Áö¸·À¸·Î ¿Å±è == hiden pivot
	swap(&arr[pivot], &arr[backPos]);

	i = frontPos;
	j = backPos - 1;

	while (i <= j)
	{
		while (i <= j && arr[i] <= arr[backPos])
			i++;
		while (i <= j && arr[j] >= arr[backPos])
			j--;
		if (i < j)
			swap(&(arr[i]), &arr[j]);

	}

	//ÇÇº¿°ú arr[i]¸¦ ¹Ù²Þ
	swap(&arr[i], &arr[backPos]);

	return i;
}

void print(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}

	printf("\n");
}

void inPlaceQuickSort(int *arr, int frontPos, int backPos)
{
	if (frontPos < backPos)
	{
		int p;
		p = partition(arr, frontPos, backPos);
		inPlaceQuickSort(arr, frontPos, p - 1);
		inPlaceQuickSort(arr, p + 1, backPos);
	}


}

int main()
{
	int * quick;
	int N;
	int elem;

	scanf("%d", &N);
	quick = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &elem);
		quick[i] = elem;
	}

	inPlaceQuickSort(quick, 0, N - 1);
	print(quick, N);


}