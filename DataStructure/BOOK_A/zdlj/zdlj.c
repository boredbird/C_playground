#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

#define DATA_FILE "data.dat"
#define MAX_COST 9999	//最大路径费用值

enum Boolean {false, true};

typedef struct road	//为了文件存取而定义
{
	char source[10];
	char destination[10];
	int cost;
}Road;

typedef struct linkage	//连线
{
	int id;
	int cost;
	struct linkage *nextLink;
}Linkage;

typedef struct node	//节点，邻接表描述图
{
	int id;
	char name[10];
	struct node *next;
	struct linkage *link;
}Node;

Node headNode;

Node *FindNodeByName(char *nodeName)
{
	Node *pNode;
	
	pNode = headNode.next;
	while(pNode)
	{
		if(strcmp(pNode->name, nodeName) == 0)
			break;
		pNode = pNode->next;
	}
	
	return pNode;
}

Node *FindNodeByID(int id)
{
	Node *pNode;
	
	pNode = headNode.next;
	while(pNode)
	{
		if(pNode->id == id)
			break;
		pNode = pNode->next;
	}
	
	return pNode;
}

Node *AddNode(char *nodeName)
{
	Node *pNode, *qNode;

	pNode = (Node *)malloc(sizeof(Node));
	pNode->id = headNode.id++;
	strcpy(pNode->name, nodeName);
	pNode->link = NULL;
	pNode->next = NULL;

	qNode = &headNode;
	while(qNode->next)
		qNode = qNode->next;
	qNode->next = pNode;

	return pNode;
}

void InputRoadData()
{
	char src[10], dst[10], ans;
	int cost;
	Node *srcNode, *dstNode;
	Linkage *pLink, *qLink;

	printf("\nPlease input the source port: ");
	scanf("%s", src);

	printf("\nPlease input the destination port: ");
	scanf("%s", dst);

	printf("\nPlease input the cost: ");
	scanf("%d", &cost);

	fflush(stdin);	//清理键盘缓冲区，windows用fflush(stdin);  Linux用setbuf(stdin, NULL);　

	printf("\n%s -> %s: %6d.\nAre you sure?[y/n]", src, dst, cost);
	ans = getchar(); 
//	scanf("%c", &ans);

	if(ans == 'y')
	{
		srcNode = FindNodeByName(src);
		if(!srcNode)
		{
			printf("\nSource port dosn't exit, create it now.");
			srcNode = AddNode(src);
		}

		dstNode = FindNodeByName(dst);
		if(!dstNode)
		{
			printf("\nDestination port dosn't exit, create it now.");
			dstNode = AddNode(dst);
		}

		qLink = srcNode->link;	//检查该条路径是否录入过
		if(qLink)
		{
			do
			{
				if(qLink->id == dstNode->id)
					break;
				qLink = qLink->nextLink;
			}while(qLink);
		}

		if(qLink)	//更新路径费用
		{
			qLink->cost = cost;
			printf("\nCost update");
		}
		else		//增加新的路径
		{
			pLink = (Linkage *)malloc(sizeof(Linkage));
			pLink->id = dstNode->id;
			pLink->cost = cost;
			pLink->nextLink = NULL;

			qLink = srcNode->link;
			if(!qLink)
				srcNode->link = pLink;
			else
			{
				while(qLink->nextLink)
					qLink = qLink->nextLink;
				qLink->nextLink = pLink;
			}

			printf("\nInput saved");
		}
	}
	else
		printf("\nInput cancelled");

	getch();
}

void ReadFile()
{
	FILE *fp;
	Road roadData;
	Node *srcNode, *dstNode;
	Linkage *pLink, *qLink;
	int size;

	fp = fopen(DATA_FILE, "rb");
	fseek(fp, 0, 2);	/*get the size of the file*/
	size = ftell(fp);
	rewind(fp);

	while(size != 0)
	{
		size -= sizeof(Road);

		if(fread(&roadData, sizeof(Road), 1, fp) != 1)
			exit(0);

		printf("\n%s -> %s: %6d.\n", roadData.source, roadData.destination, roadData.cost);

		srcNode = FindNodeByName(roadData.source);
		if(!srcNode)
			srcNode = AddNode(roadData.source);

		dstNode = FindNodeByName(roadData.destination);
		if(!dstNode)
			dstNode = AddNode(roadData.destination);

		pLink = (Linkage *)malloc(sizeof(Linkage));
		pLink->id = dstNode->id;
		pLink->cost = roadData.cost;
		pLink->nextLink = NULL;

		qLink = srcNode->link;
		if(!qLink)
			srcNode->link = pLink;
		else
		{
			while(qLink->nextLink)
				qLink = qLink->nextLink;
			qLink->nextLink = pLink;
		}
	}
	fclose(fp);

	printf("\nRead from file complete.");

	getch();
}

void WriteFile()
{
	FILE *fp;
	Road roadData;
	Node *pNode, *srcNode, *dstNode;
	Linkage *pLink;
	int dst;

	if((fp = fopen(DATA_FILE, "wb+")) == NULL)
	{
		printf("Cann't open file!\n");
		return;
	}

	pNode = headNode.next;
	while(pNode)
	{
		srcNode = pNode;

		pLink = srcNode->link;
		while(pLink)
		{
			dst = pLink->id;
			dstNode = FindNodeByID(dst);

			roadData.cost = pLink->cost;
			strcpy(roadData.source, srcNode->name);
			strcpy(roadData.destination, dstNode->name);

			if(fwrite(&roadData, sizeof(Road), 1, fp) != 1)
				printf("File write error!\n");
			
			pLink = pLink->nextLink;
		}
		pNode = pNode->next;
	}

	fclose(fp);

	printf("\nWrite to file complete.");

	getch();
}

void FindPath()
{
	int *path, *pathCost, nodeCount;//path[i][j]的值为Vsrc到Vi路径中经过Vj时，Vj所被访问的顺序，当j=src时为0，j=i时值最大，Vj不被访问则为-1
	int i, j, src, min, minCost;
	enum Boolean *pass;
	Node *srcNode;
	Linkage *pLink;
	char srcName[10];

	nodeCount = headNode.id;

	printf("\nPlease input the source port you want to find path: ");
	scanf("%s", srcName);
	fflush(stdin);

	srcNode = FindNodeByName(srcName);

	if(!srcNode)
	{
		printf("\nThis node dosn't exist!");
		return;
	}

	src = srcNode->id;

	path = (int *)malloc(sizeof(int) * nodeCount * nodeCount);
	pathCost = (int *)malloc(sizeof(int) * nodeCount);
	pass = (enum Boolean *)malloc(sizeof(enum Boolean) * nodeCount);

	for(i = 0; i < nodeCount; i++)
	{
		pathCost[i] = MAX_COST;
		pass[i] = false;
		for(j = 0; j < nodeCount; j++)
			path[i * nodeCount + j] = -1;
		path[i * nodeCount + src] = 0;	//存放下一访问节点的序号
	}
	pathCost[src] = 0;
	pass[src] = true;

	pLink = srcNode->link;
	while(pLink)
	{
		pathCost[pLink->id] = pLink->cost;
		path[pLink->id * nodeCount + pLink->id] = ++path[pLink->id * nodeCount + src];
		pLink = pLink->nextLink;
	}

	for(i = 0; i < nodeCount - 1; i++)
	{
		minCost = MAX_COST;
		min = -1;
		for(j = 0; j < nodeCount; j++)
		{
			if(pass[j])
				continue;
			else
			{
				if(pathCost[j] < minCost)
				{
					minCost = pathCost[j];
					min = j;
				}
			}
		}

		if(min == -1)
			continue;

		pass[min] = true;

		srcNode = FindNodeByID(min);
		pLink = srcNode->link;
		while(pLink)
		{
			if(!pass[pLink->id])
			{
				if(pathCost[pLink->id] > pathCost[min] + pLink->cost)
				{
					pathCost[pLink->id] = pathCost[min] + pLink->cost;

					for(j = 0; j < nodeCount; j++)
						path[pLink->id * nodeCount + j] = path[min * nodeCount + j];

					path[pLink->id * nodeCount + pLink->id] = ++path[pLink->id * nodeCount + src];
				}
			}

			pLink = pLink->nextLink;
		}
	}

	printf("%10s", "");
	for(i = 0; i < nodeCount; i++)
	{
		path[i * nodeCount + src] = 0;

		srcNode = FindNodeByID(i);
		printf("%10s", srcNode->name);
	}
	printf("\n");

	for(i = 0; i < nodeCount; i++)
	{
		srcNode = FindNodeByID(i);
		printf("%10s", srcNode->name);

		for(j = 0; j < nodeCount; j++)
		{
			printf("%10d", path[i * nodeCount + j]);
		}
		printf("%6d\n", pathCost[i]);
	}

	free(path);
	free(pathCost);
	free(pass);

	getch();

}

void Release()
{
	Node *pNode;
	Linkage *pLink;

	pNode = headNode.next;
	while(pNode)
	{
		headNode.next = pNode->next;

		pLink = pNode->link;
		while(pLink)
		{
			pNode->link = pLink->nextLink;
			free(pLink);
			pLink = pNode->link;
		}

		free(pNode);
		pNode = headNode.next;
	}
}

void main()
{
	int choice = 0;

	headNode.id = 0;
	strcpy(headNode.name, "");
	headNode.link = NULL;
	headNode.next = NULL;
	
	do
	{
		system("cls");	//clrscr();

		printf("---------------    Menu    ---------------\n");
		printf("------------------------------------------\n\n");
		printf("1. Input road data;\n");
		printf("2. Read road data from file;\n");
		printf("3. Write road data to file;\n");
		printf("4. Find the minimum cost path;\n");
		printf("0. Exit.\n");
		printf("------------------------------------------\n\n");
		printf("Please make a choice:");
		scanf("%d", &choice);

		switch(choice)
	  	{
	    	case 1:
				InputRoadData();
				break;
	     	case 2:
				ReadFile();
	    		break;
	    	case 3:
	    		WriteFile();
				break;
	     	case 4:
				FindPath();
	    		break;
			case 0:
				Release();
				break;
		    default:
	    		printf("Your choice must between 0 to 4!");
		}
	}while(choice != 0);
}