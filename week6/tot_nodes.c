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
int findHeight(nodepointer root){
	
	int cnodes=1;
	if(root==NULL){
		return 0;
	}
	else{
		if(root->left!=NULL){
			cnodes+=findHeight(root->left);
		}
		if(root->right!=NULL){
			cnodes+=findHeight(root->right);
		}
	}
	return (cnodes);
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
	printf("\nT he total number of nodes in tree is:%d\n",findHeight(root));
}