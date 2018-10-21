#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

//최대 힙
#define MAX_ELEMENT 100
int heap[MAX_ELEMENT];
int heap_size;


//힙 출력
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
// 제일 아래에 삽입한 후, 부모(heap[i/2])와 비교
void insertHeap(int item)
{
	int i;
	heap_size++; // 원소 개소 1 증가

	i = heap_size;
	heap[i] = item;
	upHeap(i);
}

// 루트 삭제
//삭제한 값 반환


void downHeap(int idx)
{
	int parent = idx;
	int child = 2 * idx;
	int temp;

	if (child <= heap_size)
	{
		//자식들 비교

		if (heap[child] < heap[child + 1])
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
		downHeap(child);
	}
}

int deleteHeap()
{
	int item = heap[1];
	int temp = heap[heap_size];
	heap[1] = temp;
	heap_size = heap_size - 1; // 노드 삭제, temp가 노드 자리로 이동
	downHeap(1);

	return item; // 처음 루트값 반환
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
			//삽입
		case 'i':
			scanf("%d", &N);
			getchar();
			insertHeap(N);
			printf("0\n");
			break;

			//삭제
		case 'd':
			root = deleteHeap();
			printf("%d\n", root);
			break;

			//출력
		case 'p':
			printHeap();
			break;

			//종료
		case 'q':
			return 0;

		default:
			break;

		}

	}



}