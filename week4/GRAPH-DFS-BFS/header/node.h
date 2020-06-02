#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct node
{
	void* data;
	struct node *next;
} NODE;

typedef NODE ITERATOR;

NODE* newNode(NODE *nextNode, void* currData)
{
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	new_node->data = currData;
	new_node->next = nextNode;
}

void deleteAllNodes(NODE *head)
{
	if(head != NULL)
	{
		deleteAllNodes(head->next);
		free(head);
	}
}
#endif