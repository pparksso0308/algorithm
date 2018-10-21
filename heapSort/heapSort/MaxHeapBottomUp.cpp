//���� ����Ʈ���� ������ �켱���� ť��. ���⼭ ����Ʈ���� �迭�� �̿��� ����Ʈ�� ���·� , �Ǵ� ���Ḯ��Ʈ�� �̿��� ����Ʈ�� ���·� ������ �� �ִ�. 
//����Ʈ���� ������ ���� ����Ʈ��(�迭): ���ڸ� ���� ����, ����Ʈ���� ������ ���� ������(���Ḯ��Ʈ): ���ڸ� ���� �Ұ����̶�� �θ���.
//�� ������ �� ���� ����� �ִ�. 
//���Խ��� ��� Ű���� �̸� �־��� ���, Ű���� ���ʷ� �־����� ��� 
// ������� ��� Ű���� �̸� �־��� ��쿡�� ����.

// ����� �� ����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

//�ִ� ��
#define MAX_ELEMENT 100
int heap[MAX_ELEMENT];
int heap_size;


// ��Ʈ ����
//������ �� ��ȯ
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


void rBuildHeap(int root_index) // ��� ������� ����� �� ����
{
	int i = root_index;

	if (i <= heap_size)
	{
		rBuildHeap(2 * i);
		rBuildHeap(2 * i + 1);
		downHeap(i,heap_size);
	}
}

void BuildHeap()	// ����� ������� ����� �� ����
{
	int i = heap_size;
	for (i = i / 2; i >= 1; i--)
	{
		downHeap(i,heap_size);
	}


}



//�� ���
void printHeap()
{
	for (int i = 0; i < heap_size; i++)
	{
		printf(" %d", heap[i + 1]);
	}
	printf("\n");
}

int main()
{
	int item;

	scanf("%d", &heap_size);
	for (int i = 0; i < heap_size; i++)
	{
		scanf("%d", &item);
		heap[i + 1] = item;
	}

	BuildHeap();
	//rBuildHeap(1);

	printHeap();

}