#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

/*链式堆栈*/
typedef struct node /*堆栈元素 */
{
    char item[10];
    struct node *next;
}Node;

typedef struct stack    /*堆栈 */
{
    Node *top;
}Stack;

/*链式队列 */
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

Stack *CreateStack();			//建立堆栈
int StackEmpty(Stack *);		//判断堆栈是否为空
void Push(char *, Stack *);	//压栈
void Pop(char *, Stack *);		//出栈
void ClearStack(Stack *);		//清空堆栈
int StackSize(Stack *);			//得到堆栈大小
void StackTop(char *, Stack *);//取得栈顶元素
Node *MakeNode(char *);			//申请堆栈元素空间，生成堆栈元素节点

QueueNode *MakeQueueNode(char *);//申请队列元素空间，生成队列元素节点
Queue *CreateQueue();			//建立队列
int QueueEmpty(Queue *);		//判断队列是否为空
void Append(char *, Queue *);	//增加队列元素
void Serve(char *, Queue *);	//队列元素出队
int QueueSize(Queue *);			//得到队列大小
int ClearQueue(Queue *);		//清空队列
int QueueFront(char *, Queue *);//取得队首元素

int Priority(char);				//得到运算符优先级
void PrintQueue(Queue *);		//打印队列
void PrintStack(Stack *);		//打印堆栈
void Caculate(Queue *);			//计算结果


Stack *CreateStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s == NULL)
        exit(0);
    else
        s->top = NULL;
	return s;
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

Queue *CreateQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q == NULL)
        exit(0);
    else
        q->front = q->rear = NULL;
	return q;
} 

int QueueEmpty(Queue *q)
{
    if(!q->front)
        return 1;
    else
        return 0;
}    

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

void PrintQueue(Queue *q)
{
	QueueNode *pNode;

	if(!QueueEmpty(q))
	{
		printf("\nQueue:");
		pNode = q->front;
		while(pNode)
		{
			printf("%s,", pNode->item);
			pNode = pNode->next;
		}
		/*	printf("\n");*/
	}
}

void PrintStack(Stack *s)
{
	Node *pNode;

	if(!StackEmpty(s))
	{
		printf("\nStack:");
		pNode = s->top;
		while(pNode)
		{
			printf("%s,", pNode->item);
			pNode = pNode->next;
		}
	}
}

int Priority(char opr)
{
	switch(opr)
	{
		case '(':
		  return 0;
		case '-':
		case '+':
          return 1;
		case '*':
		case '/':
          return 2;
	}
}

void Caculate(Queue *q)
{
	char temp[20], opr[20], num[20];
	double fa, fb;
	Stack *stack_num = NULL;

	stack_num = CreateStack();
	
	while(!QueueEmpty(q))
	{
		Serve(opr, q); 
		if((opr[0] >= '0' && opr[0] <= '9')||(opr[0] == '.'))
			Push(opr, stack_num);
		else
		{
			Pop(num, stack_num);
			fb = atof(num);
			Pop(num, stack_num);
			fa = atof(num);

			switch(opr[0])
			{
				case '+':
					fa += fb;
					break;
				case '-':
					fa -= fb;
					break;
				case '*':
					fa *= fb;
					break;
				case '/':
					if(fb == 0)
					{
						printf("div by zero error.");
						exit(0);
					}
					else
						fa /= fb;
					break;
			}
			sprintf(num, "%f", fa);
			Push(num, stack_num);
		}

        PrintStack(stack_num);
	}

	Pop(num, stack_num);
    printf("\nThe result is:%s", num);
}

int main()
{
    char sExpression[200], temp[20], opr[20];
    int i, j, isNum;
    Stack *stack_opr = NULL;
    Queue *queue_exp = NULL;

    printf("\n请输入待计算的表达式（中缀式）:\n");
    gets(sExpression);
    printf("%s", sExpression);

    stack_opr = CreateStack();
	queue_exp = CreateQueue();

    i = 0;
    while(sExpression[i] != '\0')
    {
        isNum = j = 0;

		while(sExpression[i] >= '0' && sExpression[i] <= '9')
        {
            isNum = 1;
            temp[j++] = sExpression[i++];
        }

        if(isNum) /*是操作数 */
        {
            temp[j] = '\0';
            /*直接入队列*/
            Append(temp, queue_exp);
        }
        else /*是运算符 */
        {
            temp[0] = sExpression[i++];
            temp[1] = '\0';
            switch(temp[0])
            {
                case '(':
                    Push(temp, stack_opr);
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
					if(!StackEmpty(stack_opr))
						while(Priority(temp[0]) <= Priority(stack_opr->top->item[0]))
						{
							Pop(opr, stack_opr);
							Append(opr, queue_exp);
							if(StackEmpty(stack_opr))
								break;
						}
                    Push(temp, stack_opr);
                    break;
                case ')':
                    while(stack_opr->top->item[0] != '(')
                    {
                        Pop(opr, stack_opr);
                        Append(opr, queue_exp);
                    }
                    Pop(opr, stack_opr);
                    break;
            }
        }

        PrintStack(stack_opr);
        PrintQueue(queue_exp);
    }

    while(!StackEmpty(stack_opr))
    {
        Pop(opr, stack_opr);
        Append(opr, queue_exp);
    }

    PrintStack(stack_opr);
    PrintQueue(queue_exp);

	Caculate(queue_exp);
    //PrintStack(stack_opr);
    //PrintQueue(queue_exp);
    getch();
}
