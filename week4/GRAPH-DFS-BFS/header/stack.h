#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "node.h"

typedef struct stack{
	NODE *top;
	
} STACK;

STACK* createStack(STACK *stack)
{
	stack->top = NULL;
	return stack;
}

void deleteStack(STACK *stack)
{
	deleteAllNodes(stack->top);
}

int isStackEmpty(STACK *stack)
{
	if(stack->top == NULL)
		return 1;
	else
		return 0;
}

void push(STACK *stack, void *val)
{
	stack->top = newNode(stack->top,val);
}

void* pop(STACK *stack)
{
	if(isStackEmpty(stack))
		return NULL;
	else
	{
		void* top_val = stack->top->data;
		NODE *del_node = stack->top;
		
		stack->top = stack->top->next;
		
		free(del_node);
		
		return top_val;
	}
}

#endif