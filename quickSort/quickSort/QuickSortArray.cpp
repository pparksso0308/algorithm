#include <stdio.h>
typedef int element;
int size, i=0;


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(element a[], int begin, int end)
{
	int pivot, L, R, t;
	
	L = begin;
	R = end;
	pivot = (int)((L + R) / 2);

	printf("\n [ %d�ܰ� : pivot = %d ] \n", ++i, a[pivot]);
	while (L < R)
	{
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R] >= a[pivot]) && (L < R)) R--;
		if (L < R)
		{
			swap(&a[L], &a[R]);

			if (L == pivot)	// ���� swap������ pivot�� ��ġ�� R�� ����Ǳ� ������ ������ �Ǻ���ġ�� �缳�� 
				pivot = R;
		}
	}
	// L==R
	// R�� pivot ��ȯ
	swap(&a[R], &a[pivot]);

	//���� ���� ���� ���
	for ( t = 0; t < size; t++)
	{
		printf(" %d", a[t]);
	}
	printf("\n");

	return R;	// ���ĵǾ� Ȯ���� �Ǻ��� ��ġ
}

void quickSort(element a[], int begin, int end)
{
	int p;
	if (begin < end)
	{
		p = partition(a, begin, end);
		quickSort(a, begin, p - 1);
		quickSort(a, p + 1, end);
	}
}
int main()
{
	element list[8] = { 69,10,30,2,16,8,31,22 };
	size = 8;

	printf("\n [�ʱ� ����] \n");
	for (int i = 0; i < size - 1; i++)	printf("%4d", list[i]);
	printf("\n");

	quickSort(list, 0, size - 1);
	
	getchar();
}