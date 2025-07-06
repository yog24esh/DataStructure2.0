// This Program shows operations on single link list using C



#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *nextNode;
};


//Declarations
struct Node *createSingleLinkList(struct Node *START);
void display singleLinkList(struct Node *START);
void countNode(struct Node *START);
void searchData(struct Node *START, int Data);
struct Node *addNodeAtPos(struct Node *START, int position);
struct Node *deleteNodeAtPos(struct Node *START, int position);
struct Node *reverseSingleLinkList(struct Node *START);


int main(int argc, char const *argv[])
{
    struct Node *START = NULL;
    int choise;
 
        /* code */
        while(1){
        printf("1. Create Single Link List \n");
        printf("2. Display Link List");
        printf("3. Count Number of Node in the List");
        printf("4. Search Specific Value/Data");
        printf("5. Add Node at Position");
        printf("6. Delete Node at Position");
        printf("7. Reverse List");
        printf("8. Press 0 for Exit")
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            /* code */
            START = createSingleLinkList(START);
            break;
        
        case 2:
            /* code */
            display singleLinkList(START);
            break;
        case 3:
            /* code */
            countNode(START);
            break;
        case 4:
            /* code */
            int data;
            scanf("%d",data);
            searchData(START,data);
            break;
        case 5:
            /* code */
            int position;
            scanf("%d",position);
            START = addNodeAtPos(START,position);
            break;
        case 6:
            /* code */
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









