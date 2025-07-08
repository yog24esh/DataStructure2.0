// This Program shows operations on single link list using C



#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *nextNode;
}*START;


//Declarations
struct Node *createSingleLinkList(struct Node *START);
void displaysingleLinkList(struct Node *START);
int countNode(struct Node *START);
void searchData(struct Node *START, int Data);
struct Node *addNodeAtPos(struct Node *START, int position, int data);
struct Node *deleteNodeAtPos(struct Node *START, int position);
struct Node *reverseSingleLinkList(struct Node *START);


int main(int argc, char const *argv[])
{
    START = NULL;
    int choice;
 
        /* code */
        while(1){
        printf("1. Create Single Link List \n");
        printf("2. Display Link List\n");
        printf("3. Count Number of Node in the List\n");
        printf("4. Search Specific Value/Data\n");
        printf("5. Add Node at Position\n");
        printf("6. Delete Node at Position\n");
        printf("7. Reverse List\n");
        printf("8. Press 8 for Exit\n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            /* code */
            START = createSingleLinkList(START);
            break;
        
        case 2:
            /* code */
            displaysingleLinkList(START);
            break;
        case 3:
            /* code */
            countNode(START);
            break;
        case 4:
            /* code */
            int data;
            scanf("%d",&data);
            searchData(START,data);
            break;
        case 5:
            /* code */
            int position,dataCase5;
            printf("Enter position\n");
            scanf("%d",&position);
            printf("Enter data\n");
            scanf("%d",&dataCase5);
            START = addNodeAtPos(START,position,dataCase5);
            break;
        case 6:
            /* code */
            int dataCase6;
            printf("Enter Node position.\n");
            scanf("%d",&dataCase6);
            START = deleteNodeAtPos(START,position);
            break;
        case 7:
            /* code */
            START = reverseSingleLinkList(START);
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

struct Node *createSingleLinkList(struct Node *START)
{
    
    struct Node *tempNode = malloc(sizeof(struct Node));
    (*tempNode).data = 1;
    tempNode->nextNode = NULL; 
    
    START = tempNode;
    return START;
}

void displaysingleLinkList(struct Node *START)
{
    struct Node *currentNode = START;
    printf("START address is %p \n", &START);
    printf("START address is pointing to %p \n", START);
    while (currentNode != NULL)
    {
        /* code */
        printf("Data is %d\t",currentNode->data);
        printf("Node address is %p\t",currentNode);
        printf("Next Node address is %p\n",currentNode->nextNode);
        currentNode = currentNode->nextNode;
    }
    
}

int countNode(struct Node *START)
{
    struct Node *temp = START;
    int node = 0;
    while (temp != NULL)
    {
        node++;
        temp = temp->nextNode;
    }
    printf("Total Node  %d\n",node);
    return node;
}

void searchData(struct Node *START, int Data)
{
    struct Node *ptr = START;
	int pos = 1;
	while(ptr!=NULL)
	{
		if(ptr->data==Data)
		{
			printf("Item %d found at position %d\n",Data,pos);
			return;
		}
		ptr = ptr->nextNode;
		pos++;
	}
	if(ptr == NULL)
		printf("Item %d not found in list\n",Data);
}

struct Node *addNodeAtPos(struct Node *START, int position,int data)
{
    struct Node *currentNode = START;
    if(START==NULL){
        createSingleLinkList(START);
    }
    else if (position==1)
    {
        /* code */
        struct Node *tmpr = malloc(sizeof(struct Node));
        tmpr->data = data;
        tmpr->nextNode = START;
        START = tmpr;
    }
    else{
       for(int i=1; i<position-1;i++){
        currentNode = currentNode->nextNode;
       }
    struct Node *tmpr = malloc(sizeof(struct Node));
    tmpr->nextNode = currentNode->nextNode;
    tmpr->data = data;
    currentNode->nextNode = tmpr;
    }
    return START;
}

struct Node *deleteNodeAtPos(struct Node *START, int position)
{
    struct Node *tmp = START;
    if(position==1){
        START = tmp->nextNode;
        free(tmp);
    }
    else{
        for (int i = 1; i < position-1; i++)
        {
            /* code */
            tmp = tmp->nextNode;
        }
        if (position==countNode(START)){
            //for last node
            tmp->nextNode=NULL;
        }
        else{
            tmp->nextNode=tmp->nextNode->nextNode;
        }
        
    }
    return START;
}

struct Node *reverseSingleLinkList(struct Node *START)
{
    struct Node *p1,*p2,*p3;
	if(START->nextNode==NULL)  return START; 

	p1=START;
	p2=p1->nextNode;
	p3=p2->nextNode;
	p1->nextNode=NULL;
	p2->nextNode=p1;
	while(p3!=NULL)
	{
		p1=p2;
		p2=p3;
		p3=p3->nextNode;
		p2->nextNode=p1;
	}
	START=p2;
    return START;
}
