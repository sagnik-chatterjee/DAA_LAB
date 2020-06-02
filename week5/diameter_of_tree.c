#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node *nodepointer;
typedef struct node{
	int data;
	nodepointer left,right;
}node;
void insert_iter(nodepointer *root,int data){
	nodepointer newnode,i;
	char str[10];
	newnode=(nodepointer)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	if(*root==NULL){
		*root=newnode;
		return;
	}
	for(i=*root;i!=NULL;){
		printf("Insert to the Left or Right:\n");
		scanf("%s",str);
		if(strcmp(str,"left")==0){
			if(i->left==NULL){
				i->left=newnode;
				break;
			}
			else{
				i=i->left;
			}
		}
		else{
			if(i->right==NULL){
				i->right=newnode;
				break;
			}
			else{
				i=i->right;
			}
		}
	}
}
int max(int a, int b)
{
  return (a >= b)? a: b;
}
int height(nodepointer node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;

   /* If tree is not empty then height = 1 + max of left
      height and right heights */
   return 1 + max(height(node->left), height(node->right));
}
int diameter(nodepointer tree)
{
   /* base case where tree is empty */
   if (tree == NULL)
     return 0;

  /* get the height of left and right sub-trees */
  int lheight = height(tree->left);
  int rheight = height(tree->right);

  /* get the diameter of left and right sub-trees */
  int ldiameter = diameter(tree->left);
  int rdiameter = diameter(tree->right);

  /* Return max of following three
   1) Diameter of left subtree
   2) Diameter of right subtree
   3) Height of left subtree + height of right subtree + 1 */
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
int main()
{
    int ele;
	nodepointer root;
	root=NULL;
	printf("\n Creating a Tree.....\n");
	do{
		printf("\n Enter a value for node:\n");
		scanf("%d",&ele);
		if(ele==-1){
			break;
		}
		else{
			insert_iter(&root,ele);
		}
	}while(ele!=-1);
	printf("\nDiameter of the tree is:%d\n",diameter(root));
}
