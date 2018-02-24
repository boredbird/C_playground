// C7-2.h 图的邻接表存储表示
#ifndef C_7_2_H
#define C_7_2_H

#include "C1.h"

typedef int InfoType;  // 用户定义网的权值类型

struct ElemType 
{
    int      adjvex; // 该弧所指向的顶点的位置
    InfoType *info;  // 网的权值指针
};

struct ArcNode
{
    ElemType data;     // 满足链表结点LNode的结构定义
    ArcNode  *nextarc; // 指向下一条弧的指针
}; // 弧结点

#define MAX_NAME 5                 // 顶点字符串的最大长度+1
#define MAX_VERTEX_NUM 50          // 用户定义最大顶点数量
typedef char VertexType[MAX_NAME]; // 用户定义顶点类型为字符串

typedef struct
{
    VertexType data;      // 顶点信息
    ArcNode    *firstarc; // 顶点相关弧链表的头结点
} VNode, AdjList[MAX_VERTEX_NUM]; // 顶点结点

enum GraphKind {DG, DN, UDG, UDN}; // {有向图, 有向网, 无向图, 无向网}

struct ALGraph
{
    AdjList vertices;  // 图的顶点数组
    int vexnum;        // 图的当前顶点数
    int arcnum;        // 图的当前弧数
    GraphKind kind;    // 图的种类标志
}; // 图结构

#define LNode    ArcNode   // 定义为单链表的结点类型
#define next    nextarc    // 定义为单链表结点的指针域
typedef ArcNode *LinkList; // 定义为指向单链表结点的指针


// 图的邻接表存储的基本操作(15个)
int LocateVex(ALGraph G, VertexType u);
// 初始条件：图G存在，u和G中顶点有相同特征
// 操作结果：若G中存在顶点u，则返回该顶点在图中位置；否则返回-1

void CreateGraph(ALGraph &G);
// 操作结果：采用邻接表存储结构，构造没有相关信息图或网G(用一个函数构造4种图)

void CreateGraphF(ALGraph &G);
// 操作结果：采用邻接表存储结构，由文件构造没有相关信息图或网G(用一个函数构造4种图)

void DestroyGraph(ALGraph &G);
// 初始条件：图G存在
// 操作结果：销毁图G

VertexType& GetVex(ALGraph G, int v);
// 初始条件：图G存在，v是G中某个顶点的序号
// 操作结果：返回v的值

Status PutVex(ALGraph &G, VertexType v, VertexType value);
// 初始条件：图G存在，v是G中某个顶点
// 操作结果：对v赋新值value

int FirstAdjVex(ALGraph G, VertexType v);
// 初始条件：图G存在，v是G中某个顶点
// 操作结果：返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1

Status equalvex(ElemType a, ElemType b);
// DeleteArc()、DeleteVex()和NextAdjVex()要调用的函数

int NextAdjVex(ALGraph G, VertexType v, VertexType w);
// 初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点
// 操作结果：返回v的(相对于w的)下一个邻接顶点的序号。若w是v的最后一个邻接点，则返回-1

void InsertVex(ALGraph &G, VertexType v);
// 初始条件：图G存在，v和图中顶点有相同特征
// 操作结果：在图G中增添新顶点v(不增添与顶点相关的弧，留待InsertArc()去做)

Status DeleteVex(ALGraph &G, VertexType v);
// 初始条件：图G存在，v是G中某个顶点
// 操作结果：删除G中顶点v及其相关的弧

Status InsertArc(ALGraph &G, VertexType v, VertexType w);
// 初始条件：图G存在，v和w是G中两个顶点
// 操作结果：在G中增添弧<v,w>，若G是无向的，则还增添对称弧<w,v>

Status DeleteArc(ALGraph &G, VertexType v, VertexType w);
// 初始条件：图G存在，v和w是G中两个顶点
// 操作结果：在G中删除弧<v,w>，若G是无向的，则还删除对称弧<w,v>

void BFSTraverse(ALGraph G, void (*Visit)(char*));
// 操作结果：按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited

void DFS(ALGraph G, int v, void (*Visit)(char*));
// 操作结果：从第v个顶点出发递归地深度优先遍历图G。仅适用于邻接表存储结构

void DFSTraverse(ALGraph G, void (*Visit)(char*));
// 操作结果：对图G作深度优先遍历。DFS1设函数指针参数

void Display(ALGraph G);
// 操作结果：输出图的邻接矩阵G

// 图的高级算法

typedef VertexType TElemType; // 定义树的元素类型为图的顶点类型

typedef struct CSNode
{
    TElemType data;
    CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

void DFSTree(ALGraph G, int v, CSTree &T);
// 操作结果：从第v个顶点出发深度优先遍历图G，建立以T为根的生成树
    
void DFSForest(ALGraph G, CSTree &T);
// 操作结果：建立无向图G的深度优先生成森林的(最左)孩子(右)兄弟链表T


void DFSArticul(ALGraph G, int v0);
// 操作结果：从第v0个顶点出发深度优先遍历图G，查找并输出关节点

void FindArticul(ALGraph G);
// 操作结果：连通图G以邻接表作存储结构，查找并输出G上全部关节点。全局量count对访问计数

void FindInDegree(ALGraph G, int indegree[]);
// 操作结果：求顶点的入度

Status TopologicalSort(ALGraph G);
// 操作结果：有向图G采用邻接表存储结构。若G无回路，则输出G的顶点的一个拓扑序列并返回OK，
//           否则返回ERROR
    
#include "C3-1.h"

Status TopologicalOrder(ALGraph G, SqStack &T);
// 操作结果：有向网G采用邻接表存储结构，求各顶点事件的最早发生时间ve(全局变量)。T为拓扑序列
//           顶点栈, S为零入度顶点栈。若G无回路，则用栈T返回G的一个拓扑序列, 且函数值为OK, 否则为ERROR

Status CriticalPath(ALGraph G);
// 操作结果：G为有向网，输出G的各项关键活动

#endif