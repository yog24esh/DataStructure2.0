/*
Implementation of Abstract Data Type Double Link List using C language
Operation
1. Traversal of a double linked list
2. Searching an element
3. Insertion of an element
4. Deletion of an element
5. Creation of a double linked list
6. Reversal of a linked list
7. Display DLL
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*START=NULL;

//declaration
struct node *createDoubleLinkList();
void displayDLL();
struct node *insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtMid(int data, int position);
struct node *deleteAtBeginning();
void deleteAtEnd();
void deleteAtMid(int node);
struct node *reverseDLL();

int main(){
    int userInput;
    while(1){
        printf("1. Create a double link list\n");
        printf("2. Display a double link list\n");
        printf("3. Insert data at beginning\n");
        printf("4. Insert data at end\n");
        printf("5. Insert data at middle\n");
        printf("6. Delete node at beginning\n");
        printf("7. Delete data at end\n");
        printf("8. Delete data at middle\n");
        printf("9. Reverse double link list\n");
        

        scanf("%d",&userInput);


        switch (userInput)
        {
        case 1:
            /* code */
            createDoubleLinkList();
            break;
        
        case 2:
            displayDLL();
            break;
        
        case 3:
            int dataCase3; 
            printf("Enter data.\n");
            scanf("%d",&dataCase3);
            insertAtBeginning(dataCase3);
            break;

        case 4:
            int dataCase4; 
            printf("Enter data.\n");
            scanf("%d",&dataCase4);
            insertAtEnd(dataCase4);
            break;
        case 5:
            int dataCase5, position; 
            printf("Enter data.\n");
            scanf("%d",&dataCase5);
            printf("Position at which data to be added\n");
            scanf("%d",&position);
            insertAtMid(dataCase5,position);
            break;
        case 6:
            deleteAtBeginning();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            int dataCase8;
            printf("Enter which node to be deleted.\n");
            scanf("%d",&dataCase8);
            deleteAtMid(dataCase8);
            break;
        case 9:
            reverseDLL();
            break;
        default:
            printf("Wrong input. BYE!");
            break;
            exit(1);
        }
    }

}

struct node *createDoubleLinkList()
{
    int lengthOfDLL;
    printf("Enter number of nodes\n");
    scanf("%d",&lengthOfDLL);
    int *arr= malloc(lengthOfDLL*sizeof(int));
    for(int i=0;i<lengthOfDLL;i++){
        printf("Enter data in node\n");
        scanf("%d",arr+i);
    }

    struct node *firstNode = malloc(sizeof(struct node)); 
    START = firstNode;
    firstNode->prev = NULL;
    firstNode->data = *arr;
    firstNode->next = NULL;

    for (int i = 0; i < lengthOfDLL-1; i++)
    {
        struct node *tmpr = malloc(sizeof(struct node)); 
        tmpr->prev = firstNode;
        tmpr->data = arr [i+1];
        tmpr->next = NULL;
        tmpr->prev->next = tmpr;
        firstNode = tmpr;
    }
    return START;
}

void displayDLL()
{
    struct node *tmpr = START;
    if(START!=NULL){
        printf("START address is %p\n",START);
        printf("Previous node address is %p\t",tmpr->prev);
        printf("1. Node data is %d\t",tmpr->data);
        printf("Current node address is %p\t",tmpr);
        printf("Next node address is %p\n",tmpr->next);

        tmpr = tmpr->next;
    }else{
        printf("Empty double link list.\n");
        return;
    }
    for(int i=2;tmpr!=NULL;i++){
        printf("Previous node address is %p\t",tmpr->prev);
        printf("%d. Node data is %d\t",i,tmpr->data);
        printf("Current node address is %p\t",tmpr);
        printf("Next node address is %p\n",tmpr->next);
        tmpr = tmpr->next;
    }
    
}

struct node *insertAtBeginning(int data)
{   
    struct node *tmpr = malloc(sizeof(struct node));
    tmpr->next = START;
    tmpr->data = data;
    tmpr->prev = NULL;
    START->prev=tmpr;
    START = tmpr;
    return START;
}

void insertAtEnd(int data)
{
    struct node *p1,*tmpr = malloc(sizeof(struct node));
    p1 = START;
    while (p1->next!=NULL)
    {
        p1= p1->next;
    }
    tmpr->prev = p1;
    tmpr->data = data;
    tmpr->next = NULL;
    p1->next = tmpr;
    
}

void insertAtMid(int data, int position)
{
     struct node *p1,*tmpr = malloc(sizeof(struct node));
     p1 = START;
    for(int i=1;i<position;i++){
        p1 = p1->next;
    }
    tmpr->prev = p1->prev;
    tmpr->next = p1;
    tmpr->data = data;
    p1->prev->next = tmpr;
    p1->prev = tmpr;
     

}

struct node *deleteAtBeginning()
{
    struct node *tmpr;
    tmpr = START;
    START = tmpr->next;
    tmpr->next->prev = NULL;
    free(tmpr);
    return START;
}

void deleteAtEnd()
{
    struct node *tmpr;
    tmpr = START;
    while (tmpr->next!=NULL)
    {
        tmpr= tmpr->next;
    }
    tmpr->prev->next = NULL;
    free(tmpr);

}

void deleteAtMid(int node)
{
    struct node *tmpr;
    tmpr = START;
    for(int i=1;i<node;i++){
        tmpr = tmpr->next;
    }
    tmpr->prev->next = tmpr->next;
    tmpr->next->prev = tmpr->prev;
    free(tmpr);

}

struct node *reverseDLL()
{
    struct node *p1,*p2;
	p1=START;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev; /*next of p2 changed to prev */
	}
	START=p1;
    return START;
}
