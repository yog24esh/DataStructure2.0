/*
    Circular Queue ADT implementation using C
    Array based
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int front=-1, rear=-1;
int QueueArray[MAX];

//Declaration
void Enqueue(int data);
int Dequeue();
int Peek();
void display();
int isFull();
int isEmpty();


int main(){

    while (1)
    {
        int userInput;
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        scanf("%d",&userInput);


        switch (userInput)
        {
        case 1:
            /* code */
            int case1Data;
            printf("Enter data to queue\n");
            scanf("%d",&case1Data);
            Enqueue(case1Data);
            break;
        case 2:
            Dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            Peek();
            break;
        
        default:
            break;
        }
    }
    
}

void Enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    if(rear==MAX-1){
        rear = 0;
    }else{
        rear = rear+1;
    }
    QueueArray[rear] = data;
}

int Dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return 0;
    }

    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front == MAX-1){
        front = 0;
    }else{
        front = front+1;
    }
    display();
    return 0;
}

int Peek()
{
    if(isEmpty()) return printf("Empty Queue");
    printf("First in the Queue is %d \n",QueueArray[front]);
    return 0;
}

void display()
{
    if (isEmpty())
    {
        printf("Empty Queue\n");
        return;
    }
    else{
        int i;
        printf("[");
        for (i = front; i!=rear; i++)
        {
            printf(" %d",QueueArray[i]);
            if(i==MAX-1){
                i = 0;
            }
        }

        if(front==rear || i==rear){ printf(" %d", QueueArray[rear]);}
        printf(" ]\n");
    }
    
}

int isFull()
{
    if( (front==0 && rear ==MAX-1) || front == rear+1){
        return 1;
    }else return 0;
}

int isEmpty()
{
    if(front==-1){
        return 1;
    }else return 0;
}
