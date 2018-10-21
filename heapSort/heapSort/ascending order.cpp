# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�ִ� ��
#define MAX_ELEMENT 100
int heap[MAX_ELEMENT];
int heap_size;

void upHeap(int idx)
{
	int i = idx;
	int item = heap[i];
	int temp;

	if (i <= 1)//root�̸�
		return;
	if (heap[i] < heap[i / 2])	// �θ� �ڽĺ��� ũ��
		return;

	temp = heap[i];
	heap[i] = heap[i / 2];
	heap[i / 2] = temp;

	i /= 2;

	upHeap(i);
}

//��� ����
// ���� �Ʒ��� ����
void insertHeap(int item)
{
	int i;
	heap_size++; // ���� ���� 1 ����

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

//�� ���
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
		//�ڽĵ� ��
		if (child + 1 > N) flag = 1;
		if (heap[child] < heap[child + 1] && flag == 0)
		{
			child++;
			//�� �� ū ������ ����			
		}
	}
	// �θ�� �ڽ� �� ū ���� ��
	if (heap[parent] < heap[child])
	{
		temp = heap[parent];
		heap[parent] = heap[child]; // �Ʒ� ���Ұ� ���� �̵�
		heap[child] = temp;
		downHeap(child, N);
	}
}


void BuildHeap() // ����� ������� ����� �� ����
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
		swap(&heap[1], &heap[i]);	// root�� �� ���������� �̵�
		downHeap(1, i - 1);			// root���� heap_size-1 ������ downHeap
	}

}//n ���� Ű�� ������ ���� �迭�� ���ڸ� �� ����(��������)

int main()
{
	int N; // Ű�� ����
	int item;
	heap_size = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &item);
		insertHeap(item);
	}//�ִ��� ����
	inPlaceHeapSort();
	printArray();

}
