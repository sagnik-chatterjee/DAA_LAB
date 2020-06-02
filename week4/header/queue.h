#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "node.h"

typedef struct queue {
	NODE *front;
	NODE *rear;
	
} QUEUE;

QUEUE* createQueue(QUEUE *queue)
{
	queue->front = NULL;
	queue->rear  = NULL;
	return queue;
}

void deleteQueue(QUEUE *queue)
{
	deleteAllNodes(queue->front);
}

int isQueueEmpty(QUEUE *queue)
{
	if(queue->front == NULL)
		return 1;
	else
		return 0;
}

void enqueue(QUEUE *queue, void* val)
{
	NODE *new_node = newNode(NULL,val);

	if(isQueueEmpty(queue))
	{
		queue->front = new_node;
		queue->rear  = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear  =  queue->rear->next;
	}
}

void* dequeue(QUEUE *queue)
{
	if(isQueueEmpty(queue))
		return NULL;
	else
	{
		void* top = queue->front->data;
		NODE *del_node = queue->front;
		queue->front = queue->front->next;
		
		if(queue->front == NULL)
			queue->rear = NULL;
		
		free(del_node);
		
		return top;
	}
}

#endif