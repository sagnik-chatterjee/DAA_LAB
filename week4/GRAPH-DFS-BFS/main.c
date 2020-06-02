#include <stdio.h>
#include "header/queue.h"
#include "header/stack.h"
#include "header/list.h"

//COMPARE FUNCTIONS TO HANDLE void* data types
int compareInt(void*,void*);
int compareVertex(void*,void*);
int compareVertexInt(void*,void*);

//VERTEX STRUCTURE USING ADJACENCY LIST
typedef struct vertex{
	
	int val;
	LIST adj_list;
	
} VERTEX;

VERTEX* createVertex(VERTEX *vertex, int vertexVal)
{
	vertex->val = vertexVal;
	createList(&vertex->adj_list);
	return vertex;
}

void deleteVertex(VERTEX *vertex)
{
	deleteList(&vertex->adj_list);
}

LIST createGraph(VERTEX *startVertex)
{
	int value,option=0;
	
	LIST vertexList;
	createList(&vertexList);
	
	do{
		printf("ENTER THE VALUE/NAME OF THE VERTEX\n");
		scanf("%d",&value);
		
		VERTEX *new_vertex = (VERTEX*) malloc(sizeof(VERTEX));
		_insert(&vertexList,createVertex(new_vertex,value));

		printf("ENTER ANOTHER VERTEX? input 0 for no\n");
		scanf("%d",&option);
		
	}while(option);
	
	ITERATOR *vertexListIterator = (ITERATOR*)(getIterator(&vertexList));
	ITERATOR *firstVertex = vertexListIterator;
	
	while(vertexListIterator !=  NULL)
	{
		option = 0;

		VERTEX* curr_vertex = (VERTEX*) (vertexListIterator->data);
		
		printf("CURRENT VERTEX = %d\n",curr_vertex->val);
		
		printf("INPUT THE ADJACENT VERTICES. press 0 if no more vertex in adjacecncy list\n");
		scanf("%d",&option);
		
		while(option != 0)
		{
			int* vertex_value  = (int*) malloc(sizeof(int));
			
			printf("INPUT THE NAME/VALUE OF THE ADJACENT VERTEX\n");
			scanf("%d",vertex_value);
			
			
			VERTEX *neighbour;
			NODE *neighbour_node = getNode(&vertexList,&value,&compareVertexInt);
			
			if(neighbour_node == NULL)
				neighbour = NULL;
			else
				*neighbour = *((VERTEX*)(neighbour_node->data));

			NODE* neighbour_node = (NODE*)(getNode(&vertexList,vertex_value,&compareVertexInt));
			VERTEX *neighbour = (VERTEX*)(neighbour_node->data);
			_insert(&curr_vertex->adj_list,neighbour);
			
			printf("INPUT THE ADJACENT VERTICES. press 0 if no more vertex in adjacecncy list\n");
			scanf("%d",&option);			
		}
		
		vertexListIterator = vertexListIterator->next;
	}

	if(startVertex != NULL)
		*startVertex = *((VERTEX*)(firstVertex->data));
	else
		createVertex(startVertex,-1);
	
	return vertexList;
}

void deleteGraph(LIST *vertex_list)
{
	ITERATOR* curr_vertex_node = getIterator(vertex_list);

	while(curr_vertex_node != NULL)
	{
		deleteVertex(curr_vertex_node->data);
		curr_vertex_node = curr_vertex_node->next;
	}
	
	deleteList(vertex_list);
}

void breadth_first_search(VERTEX *startVertex)
{
	LIST visited_list;
	createList(&visited_list);

	QUEUE vertex_queue;
	createQueue(&vertex_queue);
	enqueue(&vertex_queue,startVertex);
	
	while(!isQueueEmpty(&vertex_queue))
	{
		VERTEX *curr = (VERTEX*)(dequeue(&vertex_queue));
		ITERATOR *curr_node = (ITERATOR*)(getIterator(&curr->adj_list));
		
		printf("%d ",curr->val);
		
		while(curr_node != NULL)
		{
			if(_contains(&visited_list,curr_node->data,&compareVertex) == 0)
				enqueue(&vertex_queue,curr_node->data);
			
			curr_node = curr_node->next;
		}
	}
	
	
	deleteQueue(&vertex_queue);
	deleteList(&visited_list);
}

void depth_first_search(VERTEX *startVertex)
{
	LIST visited_list;
	createList(&visited_list);

	STACK vertex_stack;
	createStack(&vertex_stack);
	push(&vertex_stack,startVertex);
	
	while(!isStackEmpty(&vertex_stack))
	{
		VERTEX *curr = (VERTEX*)(pop(&vertex_stack));		
		ITERATOR *curr_node = (ITERATOR*)(getIterator(&curr->adj_list));

		printf("%d ",curr->val);

		while(curr_node != NULL)
		{
			if(_contains(&visited_list,curr_node->data,&compareVertex) == 0)
				push(&vertex_stack,curr_node->data);

			curr_node = curr_node->next;
		}
		
	}
	
	deleteStack(&vertex_stack);
	deleteList(&visited_list);	
}


int main()
{
	printf("CREATE A GRAPH\n\n\n");
	
	int option;
	VERTEX FirstVertex;
	LIST VertexList = createGraph(&FirstVertex);
	
	printf("CHOOSE 1. breadth first search 2. depth first search\n\n");
	scanf("%d",&option);
	
	switch(option)
	{
		case 1:
			breadth_first_search(&FirstVertex);
			break;
		case 2:
			depth_first_search(&FirstVertex);
			break;
		default:
			printf("INVALID OPTION\n\n");
			break;
	}
	
	deleteGraph(&VertexList);
	
	return 0;
}

int compareInt(void* val1,void* val2)
{
	int i1 = *(int*)val1;
	int i2 = *(int*)val2;
	
	if(i1 == i2)
		return 0;
	
	if(i1 < i2)
		return -1;
	
	return 1;
}

int compareVertex(void* val1,void* val2)
{
	VERTEX *vert1 = (VERTEX*)val1;
	VERTEX *vert2 = (VERTEX*)val2;
	
	return compareInt(&vert1->val,&vert2->val);
}

int compareVertexInt(void* val1,void* val2)
{
	int vertexValue = ((VERTEX*)val1)->val;
	
	return compareInt(&vertexValue,val2);
}
