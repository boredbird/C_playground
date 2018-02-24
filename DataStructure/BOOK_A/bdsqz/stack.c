#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

//链式堆栈 
typedef struct node //堆栈元素 
{
    char item[10];
    struct node *next;
}Node;

typedef struct stack    //堆栈 
{
    Node *top;
}Stack;

void CreateStack(Stack *);
int StackEmpty(Stack *);
//int StackFull(Stack *);
void Push(char *, Stack *);
void Pop(char *, Stack *);
void ClearStack(Stack *);
int StackSize(Stack *);
void StackTop(char *, Stack *);
//void TraverseStack(Stack *, void(*Visit)());
Node *MakeNode(char *);

void CreateStack(Stack *s)
{
    s->top = NULL;
//    Stack *pStack;
//    pStack = (Stack *)malloc(sizeof(Stack));
//    if(pStack == NULL)
//        exit(0);
//    else
//    {
//        pStack->top = NULL;
//        s = pStack;
//    }
} 

int StackEmpty(Stack *s)
{
    if(!s)
    {
        printf("\nStack is not exit!"); 
        exit(0);
    }
    if(s->top == NULL)
        return 1;
    else
        return 0;    
} 

//int StackFull(Stack *s)
//{
//    return 1;
//}

Node *MakeNode(char *item)
{
    Node *pNode;
    pNode = (Node *)malloc(sizeof(Node));
    
    if(!pNode)
        exit(0);
    else
    {
        strcpy(pNode->item, item);
        pNode->next = NULL;
    }
    return pNode;
}        

void Push(char *item, Stack *s)
{
    Node *pNode = MakeNode(item);
    pNode->next = s->top;
    s->top = pNode;
}    
    
void Pop(char *item, Stack *s)
{
    Node *pNode;
    
    if(!StackEmpty(s))
    {
        pNode = s->top;
        strcpy(item, pNode->item);
        s->top = pNode->next;
        free(pNode);
    }     
}
    
void ClearStack(Stack *s)
{
    Node *pNode;
    
    while(!StackEmpty(s))
    {
        pNode = s->top;
        s->top = pNode->next;
        free(pNode);
    } 
}
    
int StackSize(Stack *s)
{
    int i = 0;
    Node *pNode;
    
    if(!StackEmpty(s))
    {
        for(pNode = s->top; !pNode; pNode = pNode->next)
            i++;        
    }    
    return i;    
}
    
void StackTop(char *item, Stack *s)
{
    if(!StackEmpty(s))
    {
        strcpy(item, s->top->item);
    }    
}    
