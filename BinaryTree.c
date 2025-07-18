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

#include<stdio.h>
#include<stdlib.h>



struct btNode
{
    struct btNode *lchild;
    int data;
    struct btNode *rchild;
}*root =  NULL;

//declaration
void preOrderRecursiveTraversal(struct btNode *root);
void inOrderRecursiveTraversal(struct btNode *root);
void postOrderRecursiveTraversal(struct btNode *root);
struct btNode *makeTreeArraytoLinkList();



int main(){

    struct btNode *root = makeTreeArraytoLinkList(); 
    printf("\n");
    preOrderRecursiveTraversal(root);
    printf("\n");
    inOrderRecursiveTraversal(root);
    printf("\n");
    postOrderRecursiveTraversal(root);
    printf("\n");
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

