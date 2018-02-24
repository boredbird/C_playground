#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

//链式队列 
typedef struct queueNode
{
    char item[10];
    struct queueNode *next;
}QueueNode;

typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
}Queue;

QueueNode *MakeQueueNode(char *);
void CreateQueue(Queue *);
int QueueEmpty(Queue *);
//int QueueFull(Queue *);
void Append(char *, Queue *);
void Serve(char *, Queue *);
int QueueSize(Queue *);
int ClearQueue(Queue *);
int QueueFront(char *, Queue *);
//void TraverseQueue(Queue *, void(* Visit)(char *));

QueueNode *MakeQueueNode(char *item)
{
    QueueNode *pNode;
    pNode = (QueueNode *)malloc(sizeof(QueueNode));
    
    if(pNode == NULL)
        exit(0);
    else
    {
        strcpy(pNode->item, item);
        pNode->next = NULL;
    }
    return pNode;
} 

void CreateQueue(Queue *q)
{
    q->front = q->rear = NULL;
}    

int QueueEmpty(Queue *q)
{
    if(!q->front && !q->rear)
        return 1;
    else
        return 0;
}    
//int QueueFull(Queue *);
void Append(char *item, Queue *q)
{
    QueueNode *pNode = MakeQueueNode(item);
    
    if(QueueEmpty(q))
        q->front = q->rear = pNode;
    else
    {
        q->rear->next = pNode;
        q->rear = pNode;
    }   
}    

void Serve(char *item, Queue *q)
{
    QueueNode *pNode;
    
    if(QueueEmpty(q))
        printf("出队错误，队列为空！");
    else
    {
        pNode = q->front;
        strcpy(item, pNode->item);
        q->front = pNode->next;
        free(pNode);
    }     
}    

int QueueSize(Queue *q)
{
    int i = 0;
    QueueNode *pNode;
    
    if(!QueueEmpty(q))
    {
        for(pNode = q->front; !pNode;pNode = pNode->next)
            i++;
    }
    
    return i;    
}
    
int ClearQueue(Queue *q)
{
    QueueNode *pNode;
    
    while(!QueueEmpty(q))
    {
        pNode = q->front;
        q->front = pNode->next;
        free(pNode);
    } 
}
    
int QueueFront(char *item, Queue *q)
{
    if(!QueueEmpty(q))
    {
        strcpy(item, q->front->item);
    }   
}       
