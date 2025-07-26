/*
Heap is a data structure with following properties
1. Strucutre property - complete binary tree
2. Heap order property - parent node key will always be
   greater then the child node key in Max Heap.

Since it is complete binary tree, using sequential representation(Array) 
will be more effecient than using a link list

root index = 1
node index in array= i
lchild index = 2i
rchild index = 2i+1
parent index = i/2

*/

#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 100
#define HEAP_SIZE 20


void display(int heapArray[],int heapSize);
void restoreUP(int heapArray[],int *lastNode);
void insert(int heapArray[],int key, int *lastNode);

int main(){
    int heap[HEAP_SIZE]={100000};// only 0th element is set to max value
    int lastNode = 0;

    return 0;
}

void display(int heapArray[], int heapSize)
{
    if(heapSize==0) {
        printf("Empty Heap!");
        return ;
    }
    for(int i=0;i<heapSize;i++){
        printf("%d ",heapArray[i]);
    }
    printf("\n");
}

void restoreUP(int heapArray[], int i)
{
    int k = heapArray[i];
    int parentNode = i/2;
    while(k>heapArray[parentNode]){
        heapArray[i] = heapArray[parentNode];
        i=parentNode;
        parentNode = parentNode/2;
    }
    heapArray[i]=k;
}

void insert(int heapArray[], int key, int *lastNode)
{
    *lastNode++;
    heapArray[*lastNode]=key;
    restoreUP(heapArray,*lastNode);
}
