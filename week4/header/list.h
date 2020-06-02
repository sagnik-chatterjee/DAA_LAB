#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "node.h"

typedef struct list {
	NODE *head;
} LIST;

LIST* createList(LIST *list)
{
	list->head = NULL;
	return list;
}

void deleteList(LIST *list)
{
	deleteAllNodes(list->head);
}

int isListEmpty(LIST *list)
{
	if(list->head == NULL)
		return 1;
	else
		return 0;
}

NODE* getIterator(LIST *list)
{
	return list->head;
}

void _insert(LIST *list, void* val)
{
	NODE *new_node = newNode(NULL,val);
	
	if(list->head == NULL)
		list->head = new_node;
	else
	{
		ITERATOR *curr = list->head;
		
		while(curr->next != NULL)
			curr = curr->next;
		
		curr->next = new_node;
	}
}

void* getNode(LIST *list, void* key, int (*comp)(void*,void*))
{
	ITERATOR *curr = list->head;
	
	while(curr != NULL)
		if((*comp)(curr->data,key)==0)
			return curr;
		else
			curr = curr->next;
	
	return NULL;
}

int _contains(LIST *list, void* key, int (*comp)(void*,void*))
{
	
	if(getNode(list,key,comp) == NULL)
		return 0;
	else
		return 1;
}

void _delete(LIST *list, void* val, int (*comp)(void*,void*))
{
	NODE *del_node;
	
	if(list->head == NULL)
		return;
	
	if((*comp)(list->head->data,val)==0)
	{
		del_node   = list->head;
		list->head = list->head->next;
		return;
	}
	
	ITERATOR *prev = list->head;
	ITERATOR *curr = list->head->next;
	
	while(curr != NULL)
	{
		if((*comp)(curr->data,val)==0)
		{
			del_node = curr;
			prev->next = curr->next;
			
			free(del_node);
			return;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	return;
}

#endif