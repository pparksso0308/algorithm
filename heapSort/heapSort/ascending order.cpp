# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//최대 힙
#define MAX_ELEMENT 100
int heap[MAX_ELEMENT];
int heap_size;

void upHeap(int idx)
{
	int i = idx;
	int item = heap[i];
	int temp;

	if (i <= 1)//root이면
		return;
	if (heap[i] < heap[i / 2])	// 부모가 자식보다 크면
		return;

	temp = heap[i];
	heap[i] = heap[i / 2];
	heap[i / 2] = temp;

	i /= 2;

	upHeap(i);
}

//노드 삽입
// 제일 아래에 삽입
void insertHeap(int item)
{
	int i;
	heap_size++; // 원소 개소 1 증가

	i = heap_size;
	heap[i] = item;
	upHeap(i);
}

void swap(int *A, int *B)
{
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

//힙 출력
void printArray()
{
	int i;
	for (i = 0; i < heap_size; i++)
	{
		printf(" %d", heap[i + 1]);
	}
	printf("\n");
}

void downHeap(int idx, int N)
{
	int parent = idx;
	int child = 2 * idx;
	int temp;
	int flag = 0;

	if (child > N && child + 1 > N) return;
	if (child <= N)
	{
		//자식들 비교
		if (child + 1 > N) flag = 1;
		if (heap[child] < heap[child + 1] && flag == 0)
		{
			child++;
			//둘 중 큰 것으로 선택			
		}
	}
	// 부모와 자식 중 큰 놈을 비교
	if (heap[parent] < heap[child])
	{
		temp = heap[parent];
		heap[parent] = heap[child]; // 아래 원소가 위로 이동
		heap[child] = temp;
		downHeap(child, N);
	}
}


void BuildHeap() // 비재귀 방식으로 상향식 힙 생성
{
	int i = heap_size;
	for (i = i / 2; i >= 1; i--)
	{
		downHeap(i, heap_size);
	}
}

void inPlaceHeapSort()
{
	int i, j;
	int temp;
	BuildHeap();
	for (i = heap_size; i > 1; i--)
	{
		swap(&heap[1], &heap[i]);	// root를 맨 마지막으로 이동
		downHeap(1, i - 1);			// root부터 heap_size-1 번까지 downHeap
	}

}//n 개의 키로 구성된 무순 배열을 제자리 힙 정렬(오름차순)

int main()
{
	int N; // 키의 개수
	int item;
	heap_size = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &item);
		insertHeap(item);
	}//최대힙 생성
	inPlaceHeapSort();
	printArray();

}
