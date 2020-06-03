/*
program to implement stack and queue using circular doubly linked list 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>


struct node {
	int data ;
	struct node* link;
};

struct node* top;

void push(int data){
	struct node* temp =(struct node*)malloc(sizeof(struct node));
	
	if(!temp){
		print("Stack Overflow\n");
		return;
	}	 
	temp->data=data;
	temp->link=top;

	top=temp;
}

int isEmpty(){
	return top==NULL;
}

int peek(){ //this returns the top element of the stack
	//check for empty stack 
	if(!isEmpty()){
		return top->data;
	}
	else{
		return ;
	}
}

void pop(){
	//returns the top eleemnt from the stack 

	struct node* temp;

	if(top==NULL){
		printf("Stack overflow \n");
		return ;
	}
	else{
		//top assign into temp
		temp =top;

		//asign second node to top 
		top =top->link;

		//destroy connection bw first and second 
		temp->link =NULL;

		//release memory of top node 
		free(temp);

	}

}

void display(){
	//to disaply all elemnt sof the stack 
	struct node* temp;

	//checking for stack overflow 
	if(top==NULL){
		printf("%d",temp->data);
		temp=temp->link;
	}
}

int main(){

	//push and pop all the elemnts over here.
}