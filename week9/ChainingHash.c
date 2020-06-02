#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodepointer;
typedef struct node
{
    int key;
    nodepointer link;
}node;
//Hash Table size is 10 and so mod value will be 10
void search(nodepointer *node,int key)
{
    nodepointer traverse;
    traverse = *node;
    if(*node == NULL){
        printf("\n The search key is not found\n");
        printf("\n The number of comparisons is 0\n");
        return;
    }
    int no_of_comparisons = 0;
    int flag = 1;
    while(traverse){
        if(traverse -> key == key){
            no_of_comparisons++;
            printf("\n The key is found after %d comparisons\n",no_of_comparisons);
            flag = 1;
            break;
        }
        else{
            flag = 0;
            traverse = traverse->link;
            no_of_comparisons++;
        }
    }
    if(flag == 0){
        printf("\n The key value is not present and total number of comparisons made is %d",no_of_comparisons);
    }
}

void insert_hash(nodepointer *node,int data)
{
    nodepointer newnode,i;
    newnode = (nodepointer)malloc(sizeof(node));
    newnode->key = data;
    newnode->link = NULL;
    if(*node == NULL){
        *node = newnode;
        return;
    }
    for(i = *node ; i->link != NULL ; i = i->link);
    i->link = newnode;
}
void display(nodepointer *node)
{
    nodepointer temp;
    temp = *node;
    while(temp){
        printf("%d\t",temp->key);
        temp = temp->link;
    }
}
int main()
{
    int value,search_key;
    int i,j,m;
    printf("\n Enter the size of the hash table:\n");
    scanf("%d",&m);
    nodepointer hash[m];
    for(i = 0; i < m; i++){
        hash[i] = NULL;
    }
    int hash_value;
    while(1){
        printf("\n Enter any value to be stored:\n");
        scanf("%d",&value);
        if(value == -1){break;}
        else{
            hash_value = value % m;
            insert_hash(&hash[hash_value],value);
        }
    }
    printf("\n Displaying the hash table:\n");
    for(i = 0; i < 10 ; i++){
        if(hash[i] == NULL){
            printf("\n No data exists for the given hash value\n");
        }
        else{
            printf("\n printing the value for hash[%d]:\n",i);
            display(&hash[i]);
        }
    }
    printf("\n Enter the search key that is to be found:\n");
    scanf("%d",&search_key);
    hash_value = search_key % m;
    search(&hash[hash_value],search_key);
}
