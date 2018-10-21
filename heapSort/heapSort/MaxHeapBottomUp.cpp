//힙은 이진트리로 구현된 우선순위 큐다. 여기서 이진트리는 배열을 이용한 순차트리 형태로 , 또는 연결리스트를 이용한 연결트리 형태로 구현할 수 있다. 
//순차트리로 구현된 힙을 순차트리(배열): 제자리 정렬 가능, 연결트리로 구현된 힙을 연결힙(연결리스트): 제자리 정렬 불가능이라고 부른다.
//힙 생성은 두 가지 방식이 있다. 
//삽입식은 모든 키들이 미리 주어진 경우, 키들이 차례로 주어지는 경우 
// 상향식은 모든 키들이 미리 주어진 경우에만 가능.

// 상향식 힙 생성
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

//최대 힙
#define MAX_ELEMENT 100
int heap[MAX_ELEMENT];
int heap_size;


// 루트 삭제
//삭제한 값 반환
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


void rBuildHeap(int root_index) // 재귀 방식으로 상향식 힙 생성
{
	int i = root_index;

	if (i <= heap_size)
	{
		rBuildHeap(2 * i);
		rBuildHeap(2 * i + 1);
		downHeap(i,heap_size);
	}
}

void BuildHeap()	// 비재귀 방식으로 상향식 힙 생성
{
	int i = heap_size;
	for (i = i / 2; i >= 1; i--)
	{
		downHeap(i,heap_size);
	}


}



//힙 출력
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