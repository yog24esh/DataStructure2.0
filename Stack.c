/*
    Stack ADT implementation using C
    Array based
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int stack_arr[MAX];
int top = -1;

//declaration
int push(int data);
int pop();
int isEmptyStack();
int isFullStack();
int peek();
void displayStack();

int main(){
    int inputFromUser;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        scanf("%d",&inputFromUser);

        switch (inputFromUser)
        {
        case 1:
            int case1Data;
            printf("Enter item to add\n");
            scanf("%d",&case1Data);
            push(case1Data);
            break;
        
        case 2:
            pop();
            break;
            
        case 3:
            peek();
            break;
            
        case 4:
            displayStack();
            break;

        default:
            exit(1);
            break;
        }

    }

    

}

int push(int data)
{
    if(isFullStack()){
        printf("Stack Overflow\n");
        return 0;
    }
    top = top+1;
    stack_arr[top] = data;
    displayStack();
    return stack_arr[top];
}

int pop()
{
    int item;
    if(isEmptyStack()){
        printf("Stack Uderflow\n");
        return 0;
    }
    item = stack_arr[top];
    top = top - 1;
    printf("Popped item is %d\n",item);
    printf("New Stack is ");
    displayStack();
    return item;
}

int isEmptyStack()
{
    if(top==-1){
        return 1;
    }
    return 0;
}

int isFullStack()
{
    if(top==MAX-1){
        return 1;
    }
    return 0;
}

int peek()
{
    printf("Top item is %d\n",stack_arr[top]);
    return stack_arr[top];
}

void displayStack()
{
    if (isEmptyStack())
    {
        printf("Empty stack\n");
        return;
    }
    printf("[");
    for (int i = top; i >= 0; i--)
    {
        printf(" %1.d",stack_arr[i]);   
    }
    printf(" ]\n");
    
}
