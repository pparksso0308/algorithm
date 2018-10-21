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

	printf("\n [ %d단계 : pivot = %d ] \n", ++i, a[pivot]);
	while (L < R)
	{
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R] >= a[pivot]) && (L < R)) R--;
		if (L < R)
		{
			swap(&a[L], &a[R]);

			if (L == pivot)	// 위의 swap때문에 pivot의 위치가 R로 변경되기 때문에 현재의 피봇위치를 재설정 
				pivot = R;
		}
	}
	// L==R
	// R과 pivot 교환
	swap(&a[R], &a[pivot]);

	//현재 정렬 상태 출력
	for ( t = 0; t < size; t++)
	{
		printf(" %d", a[t]);
	}
	printf("\n");

	return R;	// 정렬되어 확정된 피봇의 위치
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

	printf("\n [초기 상태] \n");
	for (int i = 0; i < size - 1; i++)	printf("%4d", list[i]);
	printf("\n");

	quickSort(list, 0, size - 1);
	
	getchar();
}