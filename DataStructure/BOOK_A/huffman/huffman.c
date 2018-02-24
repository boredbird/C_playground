#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_SIZE 128

enum Boolean {false, true};

typedef struct treeNode	//二叉树节点
{
	char character;
	int weight;
	struct treeNode *parent;
	struct treeNode *left;
	struct treeNode *right;
	struct treeNode *next;
}TreeNode;

char codec[MAX_SIZE][MAX_SIZE - 1];//编解码器，哈夫曼编码最长为MAX_SIZE - 1
//如codec['a']即为字符a的哈夫曼编码

TreeNode *headNode, *headTreeNode;	
//逻辑上存在两个头节点，一个头节点组成了一条链表（排序），另一个头节点组成了一棵二叉树

char filename[50];

void Destory()
{
	TreeNode *pNode;

	while(headTreeNode)
	{
		pNode= headTreeNode;
		headTreeNode = headTreeNode->next;
		free(pNode);		
	}
	headNode = NULL;
}

TreeNode *FindNode(char c)
{
	TreeNode *pNode;

	pNode = headNode;
	while(pNode)
	{
		if(pNode->character == c)
			break;
		else
			pNode = pNode->next;
	}
	return pNode;
}

TreeNode *AddNode(char c)
{
	TreeNode *pNode;

	pNode = (TreeNode *)malloc(sizeof(TreeNode));
	pNode->character = c;
	pNode->parent = NULL;
	pNode->left = NULL;
	pNode->right = NULL;
	pNode->weight = 0;
	pNode->next = NULL;

	if(headNode)
	{
		pNode->next = headNode;
	}
	headNode = pNode;

	return pNode;
}

void AddWeitht(char c)
{
	TreeNode *pNode;

	pNode = FindNode(c);
	if(!pNode)
		pNode = AddNode(c);
	pNode->weight++;
}

TreeNode *Add2Sort(TreeNode *hNode, TreeNode *pNode)
{
	TreeNode *qNode;

	if(!hNode)
		return pNode;

	if(pNode->weight < hNode->weight)
	{
		pNode->next = hNode;
		hNode = pNode;		
	}
	else
	{
		qNode = hNode;

		while(qNode->next)
		{
			if(pNode->weight > qNode->next->weight)
			{
				qNode = qNode->next;
			}
			else
			{
				pNode->next = qNode->next;
				qNode->next = pNode;
				break;
			}
		}

		if(!qNode->next)
			qNode->next = pNode;
	}
	return hNode;
}

void SortNode()
{
	TreeNode *hNode, *pNode;

	hNode = headNode;
	headNode = headNode->next;
	hNode->next = NULL;

	while(headNode)
	{
		pNode = headNode;
		headNode = headNode->next;
		pNode->next = NULL;

		hNode = Add2Sort(hNode, pNode);
	}

	headNode = hNode;
}

void BuileTree()
{
	TreeNode *pNode, *qNode, *rNode;

	while(1 == 1)
	{
		pNode = headNode;
		qNode = pNode->next;

		if(qNode)	//qNode is not null
		{
			headNode = qNode->next;
		}
		else	//qNode is null
		{
			headTreeNode = headNode;
			break;
		}

		pNode->next = NULL;
		qNode->next = NULL;

		rNode = (TreeNode *)malloc(sizeof(TreeNode));
		rNode->character = 255;
		rNode->parent = NULL;
		rNode->left = pNode;
		rNode->right = qNode;
		rNode->weight = pNode->weight + qNode->weight;
		rNode->next = NULL;

		pNode->parent = rNode;
		qNode->parent = rNode;

		headNode = Add2Sort(headNode, rNode);
	}	
}

void SetCodec(TreeNode *pNode)
{
	int i, j;
	char s[MAX_SIZE - 1];
	TreeNode *oNode, *qNode;
	
	if(headTreeNode == pNode)
	{
		codec[pNode->character][0] = '0';
		return;
	}

	oNode = pNode;
	qNode = pNode->parent;

	i = 0;
	while(qNode)
	{
		if(qNode->left == pNode)
			s[i++] = '0';
		else
			s[i++] = '1';
		pNode = qNode;
		qNode = qNode->parent;
	}

	for(j = 0; j < i; j++)
		codec[oNode->character][j] = s[i - j - 1];
}

void Traverse(TreeNode *pNode)
{
	if(pNode)
	{
		Traverse(pNode->left);
		Traverse(pNode->right);
		if((!pNode->left)&&(!pNode->right))	//pNode为叶子节点
			SetCodec(pNode);
	}
}

void WriteCodecFile()
{
	char codecFileName[60];
	FILE *fpCodec;
//	int i;

	strcpy(codecFileName, filename);
	strcat(codecFileName, ".cdc");

	if((fpCodec = fopen(codecFileName, "wb")) == NULL)
	{
		printf("Can not write codec file!\n");
		exit(0);
	}

	if(fwrite(codec, sizeof(char) * MAX_SIZE, MAX_SIZE - 1, fpCodec) != MAX_SIZE - 1)
		printf("Codec file write error!\n");
	else
		printf("Codec file has been writed down!\n");

	fclose(fpCodec);
}

void EncodeAFile()
{
	FILE *fp, *out;
	char ch, outFileName[60];
	int i, j;

	printf("Please input the file name you want to encode:");
	scanf("%s", filename);

	if((fp = fopen(filename, "r")) == NULL)
	{
		printf("Can not open this file!\n");
		exit(0);
	}

	ch = fgetc(fp);
	while(ch != EOF)
	{
		//putchar(ch);
		AddWeitht(ch);
		ch = fgetc(fp);
	}

	SortNode();

	BuileTree();

	for(i = 0; i < MAX_SIZE; i++)
		for(j = 0; j < MAX_SIZE - 1; j++)
			codec[i][j] = '\0';

	Traverse(headTreeNode);

	strcpy(outFileName, filename);
	strcat(outFileName, ".ecd");

	if((out = fopen(outFileName, "w")) == NULL)
	{
		printf("Can not write destination file!\n");
		exit(0);
	}

	rewind(fp);
	ch = fgetc(fp);
	while(ch != EOF)
	{
		fputs(codec[ch], out);
		AddWeitht(ch);
		ch = fgetc(fp);
	}

	fclose(fp);
	fclose(out);

	WriteCodecFile();

	Destory();

	getch();
}

void ReadCodecFile()
{
	char codecFileName[60];
	FILE *fpCodec;

	strcpy(codecFileName, filename);
	strcat(codecFileName, ".cdc");

	if((fpCodec = fopen(codecFileName, "rb")) == NULL)
	{
		printf("Can not read codec file!\n");
		exit(0);
	}

	if(fread(codec, sizeof(char) * MAX_SIZE, MAX_SIZE - 1, fpCodec) != MAX_SIZE - 1)
		printf("Codec file read error!\n");
	else
		printf("Codec file has been read down!\n");

	fclose(fpCodec);
}

void RetrieveNode(int index)
{
	TreeNode *pNode, *qNode;
	int i, len;

	len = strlen(codec[index]);

	if(!headTreeNode)
	{
		headTreeNode = (TreeNode *)malloc(sizeof(TreeNode));
		headTreeNode->parent = NULL;
		headTreeNode->left = NULL;
		headTreeNode->right = NULL;
		headTreeNode->next = NULL;
		headTreeNode->character = 255;
		headTreeNode->weight = 0;
	}

	qNode = headTreeNode;

	for(i = 0; i < len; i++)
	{
		if(codec[index][i] == '0')
			pNode = qNode->left;
		else
			pNode = qNode->right;

		if(!pNode)
		{
			pNode = (TreeNode *)malloc(sizeof(TreeNode));
			pNode->parent = qNode;
			pNode->left = NULL;
			pNode->right = NULL;
			pNode->next = NULL;
			pNode->character = 255;
			pNode->weight = 0;


			if(codec[index][i] == '0')
				qNode->left = pNode;
			else
				qNode->right = pNode;			
		}
		qNode = pNode;
	}

	qNode->character = index;
}

void RebuileTree()
{
	int i, j;
	char ch[MAX_SIZE - 1];

	for(i = 0; i < MAX_SIZE; i++)
	{
		if(strlen(codec[i]) > 0)
			RetrieveNode(i);
		//printf("%c->%s", i, codec[i]);
	}
}

void DecodeAFile()
{
	FILE *in, *out;
	char ch, inFileName[50], outFileName[60];
	int i, j;
	TreeNode *pNode, *qNode, *rNode;

	printf("Please input the file name you want to decode:");
	scanf("%s", filename);

	ReadCodecFile();

	RebuileTree();

	strcpy(inFileName, filename);
	strcat(inFileName, ".ecd");

	if((in = fopen(inFileName, "r")) == NULL)
	{
		printf("Can not read source file!\n");
		exit(0);
	}

	strcpy(outFileName, filename);
	strcat(outFileName, ".dcd");

	if((out = fopen(outFileName, "w")) == NULL)
	{
		printf("Can not write destination file!\n");
		exit(0);
	}

	pNode = headTreeNode;

	ch = fgetc(in);
	while(ch != EOF)
	{
		if(ch == '0')
			pNode = pNode->left;
		else
			pNode = pNode->right;

		if((!pNode->left)&&(!pNode->right))	
		{
			//putchar(pNode->character);
			fputc(pNode->character, out);
			pNode = headTreeNode;
		}
		
		ch = fgetc(in);
	}

	fclose(in);
	fclose(out);

	Destory();

	getch();
}


void main()
{
	int choice = 0;

	headNode = headTreeNode = NULL;
	
	do
	{
		system("cls");	//clrscr();

		printf("---------------    Menu    ---------------\n");
		printf("------------------------------------------\n\n");
		printf("1. Encode a file;\n");
		printf("2. Decode a file;\n");
		printf("0. Exit.\n");
		printf("------------------------------------------\n\n");
		printf("Please make a choice:");
		scanf("%d", &choice);

		switch(choice)
	  	{
	    	case 1:
	    		EncodeAFile();
				break;
	     	case 2:
				DecodeAFile();
	    		break;
			case 0:
				break;
		    default:
	    		printf("Your choice must between 0 to 2!");
		}
	}while(choice != 0);
}
