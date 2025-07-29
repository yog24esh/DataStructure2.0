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
#define HEAP_SIZE 12


void display(int heapArray[],int heapSize);
void restoreUP(int heapArray[],int lastNode);
void insert(int heapArray[],int key, int *lastNode);
void delete(int heapArray[],int key, int *lastNode);
void restoreDown(int heapArray[],int index,int heapSize);
void buildHeap(int heapArray[],int size);
void buildHeapBottomUp(int heapArray[],int size);

int main(){
    int heap[HEAP_SIZE]={100000,25,35,18,9,46,70,48,23,78,12,95};// only 0th element is set to max value
    int hsize = HEAP_SIZE-1;
    buildHeap(heap,hsize);
    display(heap,hsize);
    // buildHeapBottomUp(heap,hsize-1);
    // display(heap,hsize);
    delete(heap,95,&hsize);
    display(heap,hsize);
    insert(heap,1,&hsize);
    display(heap,hsize);
    insert(heap,1,&hsize);
    delete(heap,25,&hsize);
    display(heap,hsize);

    
    

    return 0;
}

void display(int heapArray[], int heapSize)
{
    if(heapSize==0) {
        printf("Empty Heap!");
        return ;
    }
    for(int i=0;i<=heapSize;i++){
        printf("%d ",heapArray[i]);
    }
    printf("\n");
}

void restoreUP(int heapArray[], int i)
{
    int k = heapArray[i];
    int parentNode = i/2;
    while(heapArray[parentNode]<k){
        heapArray[i] = heapArray[parentNode];
        i=parentNode;
        parentNode = i/2;
    }
    heapArray[i]=k;
}

void insert(int heapArray[], int key, int *lastNode)
{
    if(*lastNode>=HEAP_SIZE-1){
        printf("Heap full! \n");
        return;
    }
    (*lastNode)++;
    heapArray[*lastNode]=key;
    restoreUP(heapArray,*lastNode);
}

void delete(int heapArray[],int key, int *p_hsize){
    int index=0;
    if(*p_hsize==0){
        printf("Empty Heap!");
        return;
    }
    for(int i=1;i<*p_hsize;i++){
        if(heapArray[i]==key){
            index=i;
            heapArray[index] = heapArray[*p_hsize];
            (*p_hsize)--;
            restoreDown(heapArray,index,*p_hsize);
        }
    }
    if(index==0){
        //case for not found
        printf("Key not found!");
        return;
    }
    
}

void restoreDown(int heapArray[], int index, int heapSize)
{
    int k = heapArray[index];
    int leftNode = index*2;
    int rightNode = index*2+1;
    while(rightNode<=heapSize){
        if (k>heapArray[leftNode]&&k>heapArray[rightNode]){
         heapArray[index] = k;
         return;
        }else if(heapArray[leftNode]>heapArray[rightNode]){
            heapArray[index] = heapArray[leftNode];
            index = leftNode;
        }else{
            heapArray[index] = heapArray[rightNode];
            index = rightNode;
        }
        leftNode = index*2;
        rightNode = index*2+1;
    }
    if(leftNode==heapSize && k<heapArray[leftNode]){
        heapArray[index] = heapArray[leftNode];
        index=leftNode;
    }
    heapArray[index] = k;
}
void buildHeap(int heapArray[],int size){
    int i;
    if(size==0){
        printf("Empty Array!");
        return;
    }
    for(i=2;i<=size;i++){
        restoreUP(heapArray,i);
    }
}

void buildHeapBottomUp(int heapArray[],int size){
    int i;
    for(i=size/2;i>0;i--){
        restoreDown(heapArray,i,size);
        }
}