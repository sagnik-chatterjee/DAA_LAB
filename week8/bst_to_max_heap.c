#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node newNode(int data)
{
    struct Node* newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insertNode(struct Node *node,int key)
{
    if(node==NULL)
    return newNode(key);
    if(key <node->data)
    {
        node->left= insertNode(node->left,key);//insert intolef of the node 
    }
    else if(node > node->data)
    {
        node->right= insertNode(node->right,key);
    }
return node;
}

//an inorder traversal for it 
void inorder(struct Node *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d",node->data);
        inorder(node->right);
    }
}

//now for max heap ,do first the inorder traversal and copy the values into an arr 

int main()
{
    printf("Enter the number of testcases \n");
    int testcases;
    while(testcases-- >0)
    {
        printf("Enter the size of the array \n");
        int size;
        scanf("%d",&size);
        int *arr =(int*)malloc(sizeof(int)*size);
        printf("Now enter into the array \n");
        for(int i=0;i<size;i++)
        {
            scanf("%d",arr+i);
        }

    }
    return 0;
}