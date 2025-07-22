/*
Any algebric expression can be stored in a binary tree which is called Expression tree
where leaf nodes are operands and other nodes are operators.
Expression tree can be formed from any polish notation ie 
1. prefix algebric expression,
2. postfix algebric expression,
3. infix algebric expression.
In all above case the Expression binary tree formed will be same.

Traversal of Expression tree can be prefix, postfix or infix traversal.
*/

//given a postfix expression convert it into expression tree.

#include<stdio.h>
#include <stdlib.h>


#define ALGB_EXP (a-b*c)/(d+e/f)
#define POST_ALGB_EXP "abc*-def/+/"
#define PRE_ALGB_EXP "/-a*bc+d/ef"
#define MAX_SIZE 100

struct ExpressionTreeNode
{
    struct ExpressionTreeNode *lChild;
    char c;
    struct ExpressionTreeNode *rChild;
};

//stack
struct ExpressionTreeNode *stack[MAX_SIZE];
int top = -1;
void push(struct ExpressionTreeNode *n);
struct ExpressionTreeNode *pop();
int isEmpty();
int isFull();

struct ExpressionTreeNode *ExpressionTreeFromPostOrder(char str[] );
struct ExpressionTreeNode *ExpressionTreeFromPreOrder(char str[] );
void inOrderRecursiveTraversal(struct ExpressionTreeNode *ptr);

int main(){

    // struct ExpressionTreeNode *root = ExpressionTreeFromPostOrder(POST_ALGB_EXP);
    struct ExpressionTreeNode *root = ExpressionTreeFromPreOrder(PRE_ALGB_EXP);
    inOrderRecursiveTraversal(root);

    return 0;
}

struct ExpressionTreeNode *ExpressionTreeFromPostOrder(char str[])
{
    struct ExpressionTreeNode *root = NULL;
    int i=0;

    while (str[i]!='\0')
    {
        if(str[i]>='a' && str[i]<='z'){
            struct ExpressionTreeNode *node = malloc(sizeof(struct ExpressionTreeNode));
            node->c = str[i];
            node->lChild = NULL;
            node->rChild = NULL;
            push(node);
        }
        else{
            struct ExpressionTreeNode *node = malloc(sizeof(struct ExpressionTreeNode));
            root = node;
            node->c = str[i];
            node->rChild = pop();
            node->lChild = pop();
            push(node);
        }
        ++i;
    }
    
    return root;
}

//  /-a*bc+d/ef   NLR
struct ExpressionTreeNode *ExpressionTreeFromPreOrder(char str[])
{
    
    int strLength = 0; 
    for (; str[strLength] != '\0'; strLength++);

    struct ExpressionTreeNode *root = NULL;
    while (strLength>=0)
    {
        if(str[strLength]>='a' && str[strLength]<='z'){
            struct ExpressionTreeNode *node = malloc(sizeof(struct ExpressionTreeNode));
            node->c = str[strLength];
            node->lChild = NULL;
            node->rChild = NULL;
            push(node);
        }
        else{
            struct ExpressionTreeNode *node = malloc(sizeof(struct ExpressionTreeNode));            
            root= node;
            node->c = str[strLength];
            node->lChild=pop();
            node->rChild=pop();
            push(node);

        }
        --strLength;
    }
    
    return root;
}

void push(struct ExpressionTreeNode *n){
    // if(isFull()){
    //     printf("Stack Overflow\n");
    //     exit(1);
    // }
    top++;
    stack[top]=n;
}
struct ExpressionTreeNode *pop(){
    // if (isEmpty()){
    //     return printf("Empty Stack\n");
    // }
    return stack[top--];
    
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

//LNR
void inOrderRecursiveTraversal(struct ExpressionTreeNode *ptr)
{
    //base case and null case
    if(ptr==NULL) return;
    inOrderRecursiveTraversal(ptr->lChild);
    printf("%c ",ptr->c);
    inOrderRecursiveTraversal(ptr->rChild);
}

