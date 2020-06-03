#include <stdio.h>

typedef struct
{
	int queue[100];
	int front;
	int rear;
	int size;

} que;

void push(que* pq, int item)
{
	pq -> queue[(pq -> front)++] = item;
	(pq -> size)++;
}

int isEmpty(que* pq)
{
	if ((pq -> size) == 0)
		return 1;
	else
		return 0;
}

int pop(que* pq)
{
	if (isEmpty(pq))
		return -1;

	int toReturn = pq -> queue[(pq -> rear)++];
	(pq -> size)--;

	return toReturn;
}

// void display(que* pq)
// {
// 	if (isEmpty(pq) == 0)
// 		for (int i = pq -> rear ; i < pq -> front ; ++i)
// 			printf(" %d ", pq -> queue[i] );
// }