/* 
    Tree implementation using C. Tree is having a root node and disjointed subtrees.
    Ternary, Quaternary,... tree are complex and has less application.
    Binary Tree whose parent node has atmost 0-2 child node. 
    Binary Tree type
    1. Stricly binary tree
    2. Extended binary tree
    3. Full binary tree
    4. Complete binary tree
    5. Expression tree
    6. Binary search tree
    7. Threaded binary tree
    8. AVL tree
    9. Reb Black tree
    10. Heap
    11. Huffman tree
    12. General tree
    13. Multiway search tree
    14. B tree
    15. B+ tree
    16. Digital search tree

    Operation
    1. Logical representation of Binary tree
        a. linear list ie Array, effecient for Complete binary tree and Full binary tree
        b. dynamic link list using structure, pointers
    2. Traversal 
        a. linear, suitable for Array type Binary tree representation
        b. recurssive, suitable for dynamic Binary tree representation
        b. Non-recursive, dynamic traversing using stack,queue
    3. Sequence of traversal, 6 ways but standard are 3 ways starting from left side
        1. PreOrder: ParentnNode->LeftSubtree->RightSubtree
        2. InOrder: Left Subtree->ParentNode->RightSubtree
        3. PostOrder: Left Subtree->RightSubtree->ParentNode
        4. LevelOrder: Level 0, Level 1, Level 2....Level N;

    Sample binary tree
              2
           /     \
         4         0
        / \     /   \
       5   1    9     9
        \      /     / \
         7    6     0   3

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100




struct btNode
{
    struct btNode *lchild;
    int data;
    struct btNode *rchild;
}*root =  NULL;

struct btNode *stack[MAX_SIZE];
int top = -1;
struct btNode *queue[MAX_SIZE];
int front = -1,rear = -1;

//declaration
struct btNode *makeTreeArraytoLinkList();
void preOrderRecursiveTraversal(struct btNode *root);
void inOrderRecursiveTraversal(struct btNode *root);
void postOrderRecursiveTraversal(struct btNode *root);

void preOrderNONRecursiveTraversal(struct btNode *root);
void inOrderNONRecursiveTraversal(struct btNode *root);
void postOrderNONRecursiveTraversal(struct btNode *root);
void levelOrderTraversal(struct btNode *root);

void push(struct btNode *n);
struct btNode *pop();
int isEmpty();
int isFull();

void enque(struct btNode *n);
struct btNode *deque();
int isEmptyQueue();
int isFullQueue();



int main(){

    struct btNode *root = makeTreeArraytoLinkList(); 
    printf("\n");
    preOrderRecursiveTraversal(root);
    printf("\n");
    inOrderRecursiveTraversal(root);
    printf("\n");
    postOrderRecursiveTraversal(root);
    printf("\n");
    preOrderNONRecursiveTraversal(root);
    printf("\n");
    inOrderNONRecursiveTraversal(root);
    printf("\n");
    postOrderNONRecursiveTraversal(root);
    printf("\n");
    levelOrderTraversal(root);
}

//NLR
void preOrderRecursiveTraversal(struct btNode *ptr)
{
    //base case and null case
    if(ptr==NULL || ptr->data==99) return;
    printf("%d ",ptr->data);
    preOrderRecursiveTraversal(ptr->lchild);
    preOrderRecursiveTraversal(ptr->rchild);
}

//LNR
void inOrderRecursiveTraversal(struct btNode *ptr)
{
    //base case and null case
    if(ptr==NULL || ptr->data==99) return;
    inOrderRecursiveTraversal(ptr->lchild);
    printf("%d ",ptr->data);
    inOrderRecursiveTraversal(ptr->rchild);
}

//LRN
void postOrderRecursiveTraversal(struct btNode *ptr)
{
    //base case and null case
    if(ptr==NULL || ptr->data==99) return;
    postOrderRecursiveTraversal(ptr->lchild);
    postOrderRecursiveTraversal(ptr->rchild);
    printf("%d ",ptr->data);
    
}

void preOrderNONRecursiveTraversal(struct btNode *root)
{
    struct btNode *ptr = root;  

    if(ptr == NULL) {
        printf("Tree is empty\n");
        exit(1);
    }
    push(ptr);
    while (!isEmpty()){
        ptr = pop();
        if(ptr->data != 99) printf("%d ",ptr->data);
        if(ptr->rchild!=NULL) push(ptr->rchild);
        if(ptr->lchild!=NULL) push(ptr->lchild);
    }
}

//LNR
void inOrderNONRecursiveTraversal(struct btNode *root){
    struct btNode *ptr = root;  
    if(ptr == NULL) {
        printf("Tree is empty\n");
        exit(1);
    }
    while (1){
        while (ptr->lchild!=NULL && ptr->lchild->data != 99){
            push(ptr);
            ptr = ptr->lchild;
        }
        while (ptr->rchild==NULL || ptr->rchild->data == 99){
            printf("%d ",ptr->data);
            if(isEmpty()) return;
            ptr = pop();
        }
        printf("%d ",ptr->data);
        ptr = ptr->rchild;
        
        
    }
    

}

//LRN
void postOrderNONRecursiveTraversal(struct btNode *root){
    struct btNode *ptr = root;  
    struct btNode *l = root;   
    
    if(ptr == NULL) {
        printf("Tree is empty\n");
        exit(1);
    }
    while (1)
    {
        while (ptr->lchild!=NULL && ptr->lchild->data != 99 ){
            push(ptr);
            ptr = ptr->lchild;
        }
        while(ptr->rchild==NULL || ptr->rchild->data==99 || ptr->rchild == l){
            printf("%d ",ptr->data);
            l=ptr;
            if(isEmpty()) return;
            ptr = pop();
        }
        push(ptr);
        ptr = ptr->rchild;
    }
    

}

void levelOrderTraversal(struct btNode *root)
{
    struct btNode *ptr = root;
    if(ptr==NULL) return printf("Empty tree\n");
    enque(ptr);
    while (!isEmptyQueue())
    {
        ptr = deque();
        printf("%d ",ptr->data);
        if(ptr->lchild!=NULL && ptr->lchild->data!=99)enque(ptr->lchild);
        if(ptr->rchild!=NULL && ptr->rchild->data!=99)enque(ptr->rchild);
        
    }
    
    
}

struct btNode *makeTreeArraytoLinkList()
{
    struct btNode *root = NULL; 
    // 99 means null 
    //array representation of binary tree
    //0 is not used, so we start from index 1
    //this is a complete binary tree
    //if we use 0, then we can use 2*i and 2*i+1 to find left and right child respectively
    int arr[16] = {99,2,4,0,5,1,9,9,99,7,99,99,6,99,0,3};

    struct btNode *nodes[16];
    for(int i=1;i<16;i++){
        
        nodes[i] = malloc(sizeof(struct btNode));
        nodes[i]->data = arr[i];
        nodes[i]->lchild = NULL;
        nodes[i]->rchild = NULL;
        
    }
    //linking nodes
    //parent node is at index i, left child is at 2*i, right child is at 2*i+1
    //for example, node 1 is parent, node 2 is left child, node 3 is right child
    //so, for node 2, left child is at 4, right child is at 5
    //for node 3, left child is at 6, right child is at 7
    for(int i=1;i<16;i++){
        if( 2*i < 16 ) nodes[i]->lchild = nodes[2*i];
        if( 2*i+1 < 16 ) nodes[i]->rchild = nodes[2*i+1];
    }
    root = nodes[1]; //root node is at index 1
    return root;
}

void push(struct btNode *n){
    if(isFull()){
        printf("Stack Overflow");
        exit(1);
    }
    top++;
    stack[top]=n;
}
struct btNode *pop(){
    if (isEmpty()){
        return printf("Empty Stack");
    }
    return stack[top--];
    
}

void enque(struct btNode *n)
{
    if(rear == MAX_SIZE-1) return printf("Queue overflow");
    if(front == -1){
        front=0;
    }
    rear++;

    queue[rear]= n;

}
struct btNode *deque()
{
    struct btNode *ptr;
    if(isEmptyQueue()){
        return printf("Empty Queue");
    }  
    ptr = queue[front];
    front++;
    return ptr;
}
int isEmptyQueue()
{
    if(front==-1 || front==rear+1) return 1;
    else return 0;
}



int isEmpty()
{
    if(top==-1) return 1;
    else return 0;
}
int isFull(){
    if(top==MAX_SIZE-1) return 1;
    else return 0;
}







