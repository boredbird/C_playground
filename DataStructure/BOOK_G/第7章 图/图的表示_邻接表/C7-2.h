// C7-2.h ͼ���ڽӱ�洢��ʾ
#ifndef C_7_2_H
#define C_7_2_H

#include "C1.h"

typedef int InfoType;  // �û���������Ȩֵ����

struct ElemType 
{
    int      adjvex; // �û���ָ��Ķ����λ��
    InfoType *info;  // ����Ȩֵָ��
};

struct ArcNode
{
    ElemType data;     // ����������LNode�Ľṹ����
    ArcNode  *nextarc; // ָ����һ������ָ��
}; // �����

#define MAX_NAME 5                 // �����ַ�������󳤶�+1
#define MAX_VERTEX_NUM 50          // �û�������󶥵�����
typedef char VertexType[MAX_NAME]; // �û����嶥������Ϊ�ַ���

typedef struct
{
    VertexType data;      // ������Ϣ
    ArcNode    *firstarc; // ������ػ������ͷ���
} VNode, AdjList[MAX_VERTEX_NUM]; // ������

enum GraphKind {DG, DN, UDG, UDN}; // {����ͼ, ������, ����ͼ, ������}

struct ALGraph
{
    AdjList vertices;  // ͼ�Ķ�������
    int vexnum;        // ͼ�ĵ�ǰ������
    int arcnum;        // ͼ�ĵ�ǰ����
    GraphKind kind;    // ͼ�������־
}; // ͼ�ṹ

#define LNode    ArcNode   // ����Ϊ������Ľ������
#define next    nextarc    // ����Ϊ���������ָ����
typedef ArcNode *LinkList; // ����Ϊָ���������ָ��


// ͼ���ڽӱ�洢�Ļ�������(15��)
int LocateVex(ALGraph G, VertexType u);
// ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����
// �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ�ã����򷵻�-1

void CreateGraph(ALGraph &G);
// ��������������ڽӱ�洢�ṹ������û�������Ϣͼ����G(��һ����������4��ͼ)

void CreateGraphF(ALGraph &G);
// ��������������ڽӱ�洢�ṹ�����ļ�����û�������Ϣͼ����G(��һ����������4��ͼ)

void DestroyGraph(ALGraph &G);
// ��ʼ������ͼG����
// �������������ͼG

VertexType& GetVex(ALGraph G, int v);
// ��ʼ������ͼG���ڣ�v��G��ĳ����������
// �������������v��ֵ

Status PutVex(ALGraph &G, VertexType v, VertexType value);
// ��ʼ������ͼG���ڣ�v��G��ĳ������
// �����������v����ֵvalue

int FirstAdjVex(ALGraph G, VertexType v);
// ��ʼ������ͼG���ڣ�v��G��ĳ������
// �������������v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ��㣬�򷵻�-1

Status equalvex(ElemType a, ElemType b);
// DeleteArc()��DeleteVex()��NextAdjVex()Ҫ���õĺ���

int NextAdjVex(ALGraph G, VertexType v, VertexType w);
// ��ʼ������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
// �������������v��(�����w��)��һ���ڽӶ������š���w��v�����һ���ڽӵ㣬�򷵻�-1

void InsertVex(ALGraph &G, VertexType v);
// ��ʼ������ͼG���ڣ�v��ͼ�ж�������ͬ����
// �����������ͼG�������¶���v(�������붥����صĻ�������InsertArc()ȥ��)

Status DeleteVex(ALGraph &G, VertexType v);
// ��ʼ������ͼG���ڣ�v��G��ĳ������
// ���������ɾ��G�ж���v������صĻ�

Status InsertArc(ALGraph &G, VertexType v, VertexType w);
// ��ʼ������ͼG���ڣ�v��w��G����������
// �����������G������<v,w>����G������ģ�������Գƻ�<w,v>

Status DeleteArc(ALGraph &G, VertexType v, VertexType w);
// ��ʼ������ͼG���ڣ�v��w��G����������
// �����������G��ɾ����<v,w>����G������ģ���ɾ���Գƻ�<w,v>

void BFSTraverse(ALGraph G, void (*Visit)(char*));
// �����������������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited

void DFS(ALGraph G, int v, void (*Visit)(char*));
// ����������ӵ�v����������ݹ��������ȱ���ͼG�����������ڽӱ�洢�ṹ

void DFSTraverse(ALGraph G, void (*Visit)(char*));
// �����������ͼG��������ȱ�����DFS1�躯��ָ�����

void Display(ALGraph G);
// ������������ͼ���ڽӾ���G

// ͼ�ĸ߼��㷨

typedef VertexType TElemType; // ��������Ԫ������Ϊͼ�Ķ�������

typedef struct CSNode
{
    TElemType data;
    CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

void DFSTree(ALGraph G, int v, CSTree &T);
// ����������ӵ�v���������������ȱ���ͼG��������TΪ����������
    
void DFSForest(ALGraph G, CSTree &T);
// �����������������ͼG�������������ɭ�ֵ�(����)����(��)�ֵ�����T


void DFSArticul(ALGraph G, int v0);
// ����������ӵ�v0���������������ȱ���ͼG�����Ҳ�����ؽڵ�

void FindArticul(ALGraph G);
// �����������ͨͼG���ڽӱ����洢�ṹ�����Ҳ����G��ȫ���ؽڵ㡣ȫ����count�Է��ʼ���

void FindInDegree(ALGraph G, int indegree[]);
// ����������󶥵�����

Status TopologicalSort(ALGraph G);
// �������������ͼG�����ڽӱ�洢�ṹ����G�޻�·�������G�Ķ����һ���������в�����OK��
//           ���򷵻�ERROR
    
#include "C3-1.h"

Status TopologicalOrder(ALGraph G, SqStack &T);
// ���������������G�����ڽӱ�洢�ṹ����������¼������緢��ʱ��ve(ȫ�ֱ���)��TΪ��������
//           ����ջ, SΪ����ȶ���ջ����G�޻�·������ջT����G��һ����������, �Һ���ֵΪOK, ����ΪERROR

Status CriticalPath(ALGraph G);
// ���������GΪ�����������G�ĸ���ؼ��

#endif