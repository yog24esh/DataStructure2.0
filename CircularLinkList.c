/*
This Program shows operations on Circular link list using C.
Instead of storing START as in Single link list, in Circular link list we store the 
LAST pointer which give access to 'LAST node' and 'first node address'.
*/
#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *nextNode;
}*START=NULL,*LAST=NULL;


//Declarations
struct Node *createCircularLinkList();
void displayCircularLinkList();
struct Node *insertAtBegin(int data);
void insertInEmptyList(int data);
struct Node *insertAtEnd(int data);
void insertInBetweenList(int data,int position);
void deleteNode(int data);

int main(int argc, char const *argv[])
{
    START = NULL;
    int choice;
 
        /* code */
        while(1){
        printf("1. Create Circular nextNode List \n");
        printf("2. Display List\n");
        printf("3. Insert at beginning of the list\n");
        printf("4. Insert in an empty list\n");
        printf("5. Insert at the end of the list\n");
        printf("6. Insert in between the nodes\n");
        printf("7. Delete Node\n");
        printf("8. Press 8 for Exit\n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            /* code */
            START = createCircularLinkList();
            break;
        
        case 2:
            /* code */
            displayCircularLinkList();
            break;
        case 3:
            /* code */
            int case3Data;
            printf("Enter data ");
            scanf("%d",&case3Data);
            insertAtBegin(case3Data);
            break;
        case 4:
            int case4Data;
            printf("Enter data ");
            scanf("%d",&case4Data);
            insertInEmptyList(case4Data);
            break;
        case 5:
            /* code */
            int case5Data;
            printf("Enter data ");
            scanf("%d",&case5Data);
            insertAtEnd(case5Data);
            break;
        case 6:
            /* code */
             int case6Data,position;
            printf("Enter data \n");
            scanf("%d",&case6Data);
            printf("Enter position at which to add \n");
            scanf("%d",&position);
            insertInBetweenList(case6Data,position);
            break;
        
        case 7:
            int case7Data;
            printf("Enter data to delete\n");
            scanf("%d",&case7Data);
            deleteNode(case7Data);
            break;
        
        case 8:
            /* code */
            exit(1);//to come out of infinite loop
            break;
        
        
        default:
            printf("Wrong choice\n");
            break;
        }
    }


    return 0;
}


//Definition of Functions

struct Node *createCircularLinkList()
{
    
    int lengthOfDLL;
    printf("Enter databer of nodes\n");
    scanf("%d",&lengthOfDLL);
    int *arr= malloc(lengthOfDLL*sizeof(int));
    for(int i=0;i<lengthOfDLL;i++){
        printf("Enter data in node\n");
        scanf("%d",arr+i);
    }

    struct Node *firstNode = malloc(sizeof(struct Node)); 
    LAST = firstNode;
    firstNode->data = *arr;
    firstNode->nextNode=LAST;

    for (int i = 1; i < lengthOfDLL; i++)
    {
        struct Node *tmpr = malloc(sizeof(struct Node)); 
        tmpr->nextNode = LAST->nextNode;
        LAST->nextNode = tmpr;
        tmpr->data = arr [i];
        LAST = tmpr;
    }
    return LAST;
}

void displayCircularLinkList()
{
    struct Node *currentNode = LAST->nextNode;
    printf("LAST address is %p \n",LAST);
    printf("Data is %d\t",currentNode->data);
    printf("First address is %p \t", currentNode);
    printf("First address is pointing to %p \n", currentNode->nextNode);
    currentNode = currentNode->nextNode;
    while (currentNode != LAST->nextNode)
    {
        printf("Data is %d\t",currentNode->data);
        printf("Node address is %p\t",currentNode);
        printf("Next Node address is %p\n",currentNode->nextNode);
        currentNode = currentNode->nextNode;
    }
    
}
struct Node *insertAtBegin(int data){
    struct Node *tmpr = malloc(sizeof(struct Node));
    tmpr->data = data;
    tmpr->nextNode = LAST->nextNode;
    LAST->nextNode=tmpr;
    return LAST;
}
void insertInEmptyList(int data){
    struct Node *firstNode = malloc(sizeof(struct Node)); 
    LAST = firstNode;
    firstNode->data = data;
    firstNode->nextNode=LAST;    
}
struct Node *insertAtEnd(int data){
    struct Node *tmpr = malloc(sizeof(struct Node));
    tmpr->data = data;
    tmpr->nextNode = LAST->nextNode;
    LAST->nextNode = tmpr;
    LAST = tmpr;    
    return LAST;
}
void insertInBetweenList(int data,int position){
   
    if(LAST==NULL){
        //insertion in empty list
        insertAtBegin(data);
        return;
    }
    else{
        struct Node *currentNode;
        currentNode = LAST->nextNode ;
        for(int i=1; i<position-1;i++){
        currentNode = currentNode->nextNode;
       }
    struct Node *tmpr = malloc(sizeof(struct Node));
    tmpr->nextNode = currentNode->nextNode;
    tmpr->data = data;
    currentNode->nextNode = tmpr;
    }
    return;
    
}
void deleteNode(int data){
    struct Node *tmp,*q;
	if( LAST->nextNode == LAST && LAST->data == data)  /*Only one element*/
	{
		tmp = LAST;
		LAST = NULL;
		free(tmp);
		return;
	}
	q = LAST->nextNode;
	if(q->data == data)
	{
		tmp = q;
		LAST->nextNode = q->nextNode;
		free(tmp);
		return;
	}
	while(q->nextNode != LAST)
	{
		if(q->nextNode->data == data)     /*Element deleted in between*/
		{
			tmp = q->nextNode;
			q->nextNode = tmp->nextNode;
			free(tmp);
			printf("%d deleted\n",data);
			return;
		}
		q = q->nextNode;
	}/*End of while*/
	if(q->nextNode->data == data)    /*LAST element deleted q->nextNode=LAST*/
	{
		tmp = q->nextNode;
		q->nextNode = LAST->nextNode;
		free(tmp);
		LAST = q;
		return;
	}
	printf("Element %d not found\n",data);
}


