#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node * left;
  struct Node* right;
};

struct node *newnode(int data)
{
  struct node *root=(struct node*)malloc(sizeof(struct node));
  root->data=data;
  root->left=NULL;
  root->right=NULL;
  return root;
}
struct node* insert(struct node* root ,int data)
{
  
}

int main()
{
  printf("Enter the number of testcases \n");
  int t;
  scanf("%d\t",&t);
  while(t-- >0)
  {

  }
  return 0;
}
