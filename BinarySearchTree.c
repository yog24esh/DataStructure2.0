/*
    Binary Search Tree is a 'Binary Tree' which also has 
    1. left subtree key less than the node
    2. right subtree key more than the node
    3. left and right subtree are also binary search tree

    Inorder traveral gives ascending key order.
    Every key is unique in BST.

*/

#include<stdio.h>
#include<stdlib.h>


struct BinarySearchTree
{
    struct BinarySearchTree *lchild;
    int key;
    struct BinarySearchTree *rchild;
}*root=NULL;


struct BinarySearchTree *insertionInBST(int key);
struct BinarySearchTree *searchKey(int key,struct BinarySearchTree *root);
struct BinarySearchTree *deleteKey(int key,struct BinarySearchTree *root);
void inOrderRecursiveTraversal(struct BinarySearchTree *ptr);
void printTreeHorizontal(struct BinarySearchTree* root, int space);

int main(){
    insertionInBST(5);
    insertionInBST(3);
    insertionInBST(7);
    insertionInBST(6);
    insertionInBST(1);
    inOrderRecursiveTraversal(root);
    printf("\n");
    printTreeHorizontal(root,0);
    printf("\n");
    deleteKey(3,root);
    printTreeHorizontal(root,0);
    return 0;
}

struct BinarySearchTree *insertionInBST(int key)
{

    if(root==NULL){
        //root node //1st node
        struct BinarySearchTree *node = malloc(sizeof(struct BinarySearchTree));
        root = node;
        node->lchild = NULL;
        node->key = key;
        node->rchild = NULL;            
    }else{
        struct BinarySearchTree *ptr = root;
        while (1)
        {
            if(key < ptr->key && ptr->lchild!=NULL){
                ptr=ptr->lchild;
            }else if(key > ptr->key && ptr->rchild!=NULL){
                ptr=ptr->rchild;
            }else if(key == ptr->key){
                //duplicate key
                return printf("Duplicate key");
            }else break;
        }
        struct BinarySearchTree *node = malloc(sizeof(struct BinarySearchTree));
        node->key = key;        
        node->lchild = NULL;
        node->rchild = NULL;
        
        if (key < ptr->key)
        {
            ptr->lchild = node;
        }else{
            ptr->rchild = node;
        }
        
        
    }

    return root;
}

struct BinarySearchTree *searchKey(int key,struct BinarySearchTree *root)
{
    struct BinarySearchTree *ptr = root;
    //base case
    if(ptr==NULL){ printf("Key not found."); return NULL;}
    if(ptr->key==key){ printf("Key founded! at pointer %p \n",ptr); return ptr;}
    if (ptr->key < key)
    {
        searchKey(key,ptr->rchild);
    }
    else{
        searchKey(key,ptr->lchild);
    }    
    
}

struct BinarySearchTree *deleteKey(int key,struct BinarySearchTree *root)
{
    struct BinarySearchTree *ptr = root;
    struct BinarySearchTree *parentNode=NULL;
    struct BinarySearchTree *leftestNode=NULL;
    while (ptr!=NULL)
    {
        if(ptr->key==key){
            if(ptr->lchild!=NULL&&ptr->rchild!=NULL){
                //2 child
                leftestNode=ptr;
                while(leftestNode->lchild!=NULL){
                    parentNode = leftestNode;
                    leftestNode = leftestNode->lchild;
                }
                ptr->key=leftestNode->key;
                parentNode->lchild = NULL;
                free(leftestNode);
                return root;

            }else if(ptr->lchild==NULL&&ptr->rchild==NULL){
                //leaf node
                if(parentNode->key > key){ parentNode->lchild=NULL; free(ptr);}
                else if(parentNode->key < key){parentNode->rchild=NULL; free(ptr);}
                return root;
            }else{
                //1 child
                if(ptr->rchild==NULL) {
                    if(parentNode->key < key ) parentNode->rchild = ptr->lchild;
                    else  parentNode->lchild = ptr->lchild;
                    free(ptr);
                }else{
                    leftestNode = ptr->rchild;
                    while(leftestNode->lchild!=NULL) {
                        parentNode = leftestNode;
                        leftestNode=leftestNode->lchild;
                    }
                    ptr->key = leftestNode->key;
                    parentNode->lchild = NULL;
                    free(leftestNode);
                }
                return root;
            }
        }else if(ptr->key > key){
            parentNode = ptr;
            ptr= ptr->lchild;
        }else if(ptr->key < key){
            parentNode = ptr;
            ptr= ptr->rchild;
        }

    }
    if(ptr==NULL) printf("Key not found!");
    
    
    return root;
}

//LNR
void inOrderRecursiveTraversal(struct BinarySearchTree *ptr)
{
    //base case and null case
    if(ptr==NULL) return;
    inOrderRecursiveTraversal(ptr->lchild);
    printf("%d ",ptr->key);
    inOrderRecursiveTraversal(ptr->rchild);
}


void printTreeHorizontal(struct BinarySearchTree* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += 5; // You can adjust this value for more or less spacing

    // Process right child first
    printTreeHorizontal(root->rchild, space);

    // Print current node after space count
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);

    // Process left child
    printTreeHorizontal(root->lchild, space);
}


