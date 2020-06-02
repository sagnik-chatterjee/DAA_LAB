#include<stdio.h>
#include<stdlib.h>
void display_table(int table[],int size)
{
    int i = 0;
    while(i < size){
        printf("%d\t",table[i]);
        i++;
    }
}
void insert_hash(int hash[],int data,int size)
{
    int hash_value;
    hash_value = data % size;
    printf("\n the hash value is :%d\n",hash_value);
    if(hash[hash_value] == -1){
        hash[hash_value] = data;
        return;
    }
    int i;
    i = hash_value+1;
    while(i < size){
        if(hash[i] == -1){
            hash[i] = data;
            return;
        }
        else{
            i++;
            if(i == size){
                i = 0;
            }
        }
        if(i == hash_value){
            printf("\n The hash table is full\n");
            return;
        }
    }
}
int main()
{
    int m,i,j,value;
    printf("\n Enter the size of the hash table:\n");
    scanf("%d",&m);
    int hash_table[m];
    for(i = 0; i < m ; i++){
        hash_table[i] = -1;
    }
    while(1){
        printf("\n Enter any value to be stored:\n");
        scanf("%d",&value);
        if(value == -1){break;}
        else{
            insert_hash(hash_table,value,m);
        }
    }
    printf("\n Displaying the hash table:\n");
    display_table(hash_table,m);

}
