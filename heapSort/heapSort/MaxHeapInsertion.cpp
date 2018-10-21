#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

//�ִ� ��
#define MAX_ELEMENT 100
int heap[MAX_ELEMENT];
int heap_size;


//�� ���
void printHeap()
{
	int i;
	for (i = 0; i < heap_size; i++)
	{
		printf(" %d", heap[i + 1]);
	}
	printf("\n");
}

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
// ���� �Ʒ��� ������ ��, �θ�(heap[i/2])�� ��
void insertHeap(int item)
{
	int i;
	heap_size++; // ���� ���� 1 ����

	i = heap_size;
	heap[i] = item;
	upHeap(i);
}

// ��Ʈ ����
//������ �� ��ȯ


void downHeap(int idx)
{
	int parent = idx;
	int child = 2 * idx;
	int temp;

	if (child <= heap_size)
	{
		//�ڽĵ� ��

		if (heap[child] < heap[child + 1])
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
		downHeap(child);
	}
}

int deleteHeap()
{
	int item = heap[1];
	int temp = heap[heap_size];
	heap[1] = temp;
	heap_size = heap_size - 1; // ��� ����, temp�� ��� �ڸ��� �̵�
	downHeap(1);

	return item; // ó�� ��Ʈ�� ��ȯ
}

int main()
{
	int root;
	char op;
	int N;

	heap_size = 0;

	while (1)
	{
		scanf("%c", &op);
		getchar();

		switch (op)
		{
			//����
		case 'i':
			scanf("%d", &N);
			getchar();
			insertHeap(N);
			printf("0\n");
			break;

			//����
		case 'd':
			root = deleteHeap();
			printf("%d\n", root);
			break;

			//���
		case 'p':
			printHeap();
			break;

			//����
		case 'q':
			return 0;

		default:
			break;

		}

	}



}