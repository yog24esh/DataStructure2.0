/*
    DEQUE ADT implementation using C
    It can insert and delete from any endpoints.
*/

#include<stdio.h>

#define MAX 10

int front=-1, rear=-1;
int deque_Array[MAX];

//declarations
void display();
int insertAtFront(int data);
int insertAtRear(int data);
int deleteAtFront();
int deleteAtRear();
int isEmpty();
int isFull();


int main(){

    while (1)
    {
        int userInput;
        printf("1. Display\n");
        printf("2. Insert at beginning(PUSH)\n");
        printf("3. Insert at end(INJECT)\n");
        printf("4. delete at beginning(POP)\n");
        printf("5. delete at end(EJECT)\n");
        scanf("%d",&userInput);

        switch (userInput)
        {
        case 1:
            display();
            break;
        case 2:
            int case2Data;
            scanf("%d",&case2Data);
            insertAtFront(case2Data);
            break;
        case 3:
            int case3Data;
            scanf("%d",&case3Data);
            insertAtRear(case3Data);
            break;
        case 4:
            deleteAtFront();
            break;
        case 5:
            deleteAtRear();
            break;
        
        default:
            exit(1);
            break;
        }
    }
    
    
}

//definition
// void display(){
//    int front_pos = front,rear_pos = rear;
// 	if(front == -1)
// 	{
// 		printf("Queue is empty\n");
// 		return;
// 	}
// 	printf("Queue elements :\n");
// 	if( front_pos <= rear_pos )
// 	{
// 		while(front_pos <= rear_pos)
// 		{
// 			printf("%d ",deque_Array[front_pos]);
// 			front_pos++;
// 		}
// 	}
// 	else
// 	{
// 		while(front_pos <= MAX-1)
// 		{
// 			printf("%d ",deque_Array[front_pos]);
// 			front_pos++;
// 		}
// 		front_pos = 0;
// 		while(front_pos <= rear_pos)
// 		{
// 			printf("%d ",deque_Array[front_pos]);
// 			front_pos++;
// 		}
// 	}/*End of else */
// 	printf("\n");
    
//     }
   
int insertAtFront(int data){
    if (isFull())
    {
        printf("Overflow Deque\n");
        return 0;
    }
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }else if(front==0){
        front = MAX-1;
    }else{
        front = front-1;
    }
    deque_Array[front] = data;
    return 0;
}

int insertAtRear(int data){
    if(isFull()){
        printf("Overflow Deque\n");
        return 0;
    }
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }else if(rear==MAX-1){
        rear = 0;
    }else{
        rear = rear+1;
    }
    deque_Array[rear] = data;
    return 0;
}
int deleteAtFront(){
    int item;
    if(isEmpty()){
        printf("Deque underflow\n");
        return 0;
    }
    item = deque_Array[front];
    if (front==rear) //only one element in Deque
    {
        front=-1;
        rear=-1;
    }
    else{
       if(front==MAX-1){
        front=0;
       }
       else{
        front = front+1;
       }
    }
    return 0;
}
int deleteAtRear(){
    int item;
    if(isEmpty()){
        printf("Deque underflow\n");
        return 0;
    }
    item = deque_Array[rear];
    if (front==rear) //only one element in Deque
    {
        front=-1;
        rear=-1;
    }
    else{
       if(rear==0){
        rear = MAX-1;
       }
       else{
        rear = rear-1;
       }
    }
    return 0;
}

int isEmpty(){
    if(front==-1) return 1;
    else return 0;
}
int isFull(){
    if(front=rear+1 || (front==0 && rear==MAX-1) ) return 1;
    else return 0;
}

