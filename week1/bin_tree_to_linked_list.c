#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
 struct node{
	int data ;
	struct node* left;
	struct node* right;
};
 
 //queue required for the level order traversal and storage 

struct queue{
	int front ,rear ,size;
	unsigned capacity;
	int* array;
};
  
// function to create a queue of given capacity.  
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  
// Queue is full when size becomes equal to the capacity  
int isFull(struct Queue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int isEmpty(struct Queue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    printf("%d enqueued to queue\n", item); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
int front(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
int rear(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
}  



struct node* createNode(int data){
	struct node* node =(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

struct node* insertNode(struct node* node,int data){
	if(node==NULL){
		return createNode(data);
	}
	char ch;
	printf("Enter choice of node ,L OR T");
	scanf("%c",&ch);
	if(ch=='L'){
		node->left=insertNode(node->left,data);
	}
	else if(ch=='T'){
		node->right=insertNode(node->right,data);
	}
	else{
		printf("Please enter according to the format ");
	}
	return node;
}
//now since no order is given we use a queue for the storing 
//of the values 


void levelOrder(struct node *node){
	if(node==NULL){
		return ;
	}
	//use the queue 
	node *curr;
	queue.enqueue(node);
	queue.dequeue(NULL);

	while(queue.size() >1){
		curr =queue.front();
		queue.dequeue();

		//condition to checek occurence of next level
		if(curr==NULL){
			queue.enqueue(NULL);
			printf("\n");
		}
		else{
			//pushing left child of the current node 
			if(curr->left){
				queue.enqueue(curr->left);
			}
			//pushing right child of the current node 
			if(curr->right){
				queue.enqueue(curr->right);

			}	
			printf("%d\n",curr->data);
			
		}

	}

}

//now push this to a linked list 

int main(){

}
*/

//simplest solution is to do inorder traversal 
//of the bianry tree and while doing it keep track of the pre-
//viosuly visiteed node in avariable 
//for evevy visited node make it next of prev and previous 
//of this node as prev 

struct node{
	int data ;
	struct node* left ;
	struct node* right;
};

//simple recursive function to convert a given bin tree to doubly liked list 
void bintreeConversion(struct node* root ,struct node** head){
	//base case 
	if(root==NULL){
		return ;
	}
	//initiliaze previouslly visited node as null 
	//this is static so that same value is accessible in all 
	//recursive calls 

	static struct node* prev=NULL;

	bintreeConversion(root->left,head);

	//now convert his node 
	if(prev==NULL){
		*head=root;
	}
	else{
		root->left =prev;
		prev->right=root;
	}
	prev=root;

	bintreeConversion(root->right,head);

}

//helper function that will allocate a new node with the 
//given data and NULL left and right pointers 
struct node* newNode(int data){
	struct node* root =(struct node*)malloc(sizeof(struct node*));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}


//print nodes of given doubly linked list 
void printList(struct node* root){
	while(root!=NULL){
		printf("%d\n" ,root->data);
		root=root->right;
	}
}

int main(){
	int t;
	scanf("%d\n",&t);
	while(t-->0){
		int p ;
		printf("Enter node value ");
		scanf("%d",&p);
		node *root= newNode(p);
		int size;
		
		printf("Enter the size of the other values ");
		scanf("%d",&size);
		
		int *arr =(int*)malloc(sizeof(int)*size);

		for(int i=0;i<size;i++){
			scanf("%d",(arr+i));

		}
		//and now pass on them like 
		//eg root->left =somae array value 
		//root->left ->right=some other value 
		

	}
	return 0;
}