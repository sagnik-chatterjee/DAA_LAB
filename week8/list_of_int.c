#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void insert_heap(int heap[],int t_node,int data)
{
    static int k=1;
    int i,j;
    if(k<=t_node){
        heap[k++]=data;
        i=k-1;
        while((i!=1) && (heap[i] > heap[i/2])){
            swap(&heap[i/2],&heap[k-1]);
            i=i/2;
        }
    }
    else{
        printf("\n Heap is full can't insert\n");
        return;
    }
}
void Heapify(int heap[],int t_node)
{
    int i,j,k;
    int flag;
    int curr_node;
    for(i=t_node/2;i>=1;i--){
        k=i;
        curr_node=heap[k];
        flag=0;
        while((!flag) && (2*k <= t_node)){
            j=2*k;
            if(j<t_node){
             if(heap[j]<heap[j+1]){j=j+1;}
            }
            if(curr_node > heap[j]){
                flag=1;
            }
            else{
                heap[k]=heap[j];
                k=j;
            }
        }
        heap[k]=curr_node;
    }
}
 void Heap_sort(int heap[],int nodes)
{
    int temp;
    if(nodes > 1){
        temp=heap[1];
        heap[1]=heap[nodes];
        heap[nodes]=temp;
        nodes=nodes-1;
        Heapify(heap,nodes);
        Heap_sort(heap,nodes);
    }
}
int main()
{
    int *arr;
    int *result;
    int size;
    int n_val;
    printf("\n Enter the number of node to be present in the heap:\n");
    scanf("%d",&size);
    arr=(int *)calloc(size,sizeof(int));
    result=(int *)calloc(size,sizeof(int));
    while(1){
        printf("\n Enter node value:\n");
        scanf("%d",&n_val);
        if(n_val==-1){
            break;
        }
        else{
            insert_heap(arr,size,n_val);
        }
    }
    printf("\n The final heap created is:\n");
    for(int i=1;i<=size;i++){
        printf("%d\n",arr[i]);
    }
    Heap_sort(arr,size);
    printf("\n The final sorted heap is:\n");
    for(int i=1;i<=size;i++){
        printf("%d\n",arr[i]);
    }
}

