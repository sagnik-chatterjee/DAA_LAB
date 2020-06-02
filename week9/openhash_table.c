/***
 * Implementing an open hashtable --> 
 * uses linked list to store values if collision occurs 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

//structure for linked list 
struct Node{
    int data;
    struct Node* next;
    struct Node* down;
};


struct Node* createNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node*));
    node->data=data;
    node->next=NULL;
    node->down=NULL;
    return node;
}
struct Node* addNode(struct Node* node,int data){
    //adding nodes 
}

int hashFunc(int data,int size){
    //data is the data to be hashed 
    //and size is the size of the linked list in whcih 
    //it has to be hashed in 
    return data%size;
}

void traverseHorizontal(struct Node* node,int data){
    //this will traverse the node horizontally till which the data is required
    struct Node* p;
    p=node;

    if(p!=NULL){
        if(p->data!=data){
        p=p->next;
        }
    }
    //means that p points to the data to be inserted
}
void traverseVertical(struct Node* node,int data){
    //this will traverse the node vertically till which the data is reuqired
    struct Node* p;
    p=node;
    if(p!=NULL){
        if(p->data!=data){
        p=p->down;
        }
    }
}


void searchKey(struct Node* node,int key){

}

void 





int main(){
    int t;
    scanf("%d",&t);
    while(t-->0){

    }
    return 0;
}