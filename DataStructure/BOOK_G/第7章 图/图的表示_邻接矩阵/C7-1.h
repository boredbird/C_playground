// c7-1.h 图的数组(邻接矩阵)存储表示

#ifndef C7_1_H
#define C7_1_H

#include "C1.h"
#include "C3-2.h"          // 链队列的结构，BFSTraverse()用

#define INFINITY        INT_MAX  // 用整型最大值代替∞
#define MAX_VERTEX_NUM  50       // 最大顶点个数
#define MAX_NAME        5        // 顶点字符串的最大长度+1
#define MAX_INFO        20       // 相关信息字符串的最大长度+1

typedef int  VRType;   // 顶点关系类型
typedef char InfoType; // 相关信息类型
typedef char VertexType[MAX_NAME]; // 顶点类型

enum GraphKind {DG, DN, UDG, UDN};      // 有向图, 有向网, 无向图, 无向网

typedef struct
{
    VRType adj; // 顶点关系类型。对无权图，用1(是)或0(否)表示相邻否；对带权图，则为权值
    InfoType *info; // 该弧相关信息的指针(可无)
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 二维数组

struct MGraph
{
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点向量
    AdjMatrix  arcs;                 // 邻接矩阵
    int        vexnum;               // 图的当前顶点数
    int        arcnum;               // 图的当前弧数
    GraphKind  kind;                 // 图的种类标志
};


// 图的数组(邻接矩阵)存储的基本操作(17个)

int LocateVex(MGraph G, VertexType v);
// 初始条件：图G存在，u和G中顶点有相同特征
// 操作结果：若G中存在顶点u，则返回该顶点在图中位置；否则返回-1

void CreateFUDG(MGraph &G);
// 操作结果：采用数组(邻接矩阵)表示法，由文件构造没有相关信息的无向图G

void CreateFUDN(MGraph &G);
// 操作结果：采用数组(邻接矩阵)表示法，由文件构造没有相关信息的无向网G

void CreateGraph(MGraph &G);
// 操作结果：采用数组(邻接矩阵)表示法，构造图G

void DestroyGraph(MGraph &G);
// 初始条件：图G存在
// 操作结果：销毁图G

VertexType& GetVex(MGraph G, int v);
// 初始条件：图G存在，v是G中某个顶点的序号
// 操作结果：返回v的值

Status PutVex(MGraph &G, VertexType v, VertexType value);
// 初始条件：图G存在，v是G中某个顶点
// 操作结果：对v赋新值value

int FirstAdjVex(MGraph G, VertexType v);
// 初始条件：图G存在，v是G中某个顶点
// 操作结果：返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1

int NextAdjVex(MGraph G, VertexType v, VertexType w);
// 初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点
// 操作结果：返回v的(相对于w的)下一个邻接顶点的序号，若w是v的最后一个邻接顶点，则返回-1

void InsertVex(MGraph &G, VertexType v);
// 初始条件：图G存在，v和图G中顶点有相同特征
// 操作结果：在图G中增添新顶点v(不增添与顶点相关的弧，留待InsertArc()去做)

Status DeleteVex(MGraph &G, VertexType v);
// 初始条件：图G存在，v是G中某个顶点
// 操作结果：删除G中顶点v及其相关的弧

Status InsertArc(MGraph &G, VertexType v, VertexType w);
// 初始条件：图G存在，v和w是G中两个顶点
// 操作结果：在G中增添弧<v,w>，若G是无向的，则还增添对称弧<w,v>

Status DeleteArc(MGraph &G, VertexType v, VertexType w);
// 初始条件：图G存在，v和w是G中两个顶点
// 操作结果：在G中删除弧<v,w>，若G是无向的，则还删除对称弧<w,v>

void DFS(MGraph G, int v, void (*Visit)(VertexType));
// 操作结果：从第v个顶点出发递归地深度优先遍历图G

void DFSTraverse(MGraph G, void (*Visit)(VertexType));
// 初始条件：图G存在，Visit是顶点的应用函数
// 操作结果：从第1个顶点起，深度优先遍历图G，并对每个顶点调用函数Visit一次且仅一次

void BFSTraverse(MGraph G, void (*Visit)(VertexType));
// 初始条件：图G存在，Visit是顶点的应用函数
// 操作结果：从第1个顶点起，按广度优先非递归遍历图G,并对每个顶点调用函数Visit一次且仅一次

void Display(MGraph G);
// 操作结果：输出邻接矩阵存储表示的图G

// 图的高级算法

typedef int PathMatrix_DIJ[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 路径矩阵，二维数组
typedef int ShortPathTable[MAX_VERTEX_NUM];  // 最短距离表，一维数组
typedef int PathMatrix_FLOYD[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 3维数组
typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 2维数组

void MiniSpanTree_PRIM(MGraph G, VertexType u);
// 操作结果：用普里姆算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边

void ShortestPath_DIJ(MGraph G, int v0, PathMatrix_DIJ P, ShortPathTable D);
// 操作结果：用Dijkstra算法求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度
//           D[v]。若P[v][w]为TRUE，则w是从v0到v当前求得最短路径上的顶点。
//           final[v]为TRUE当且仅当v∈S，即已经求得从v0到v的最短路径

void ShortestPath_FLOYD(MGraph G, PathMatrix_FLOYD P, DistancMatrix D);
// 操作结果：用Floyd算法求有向网G中各对顶点v和w之间的最短路径P[v][w]及其带权长度D[v][w]
//           若P[v][w][u]为TRUE，则u是从v到w当前求得最短路径上的顶点

void Kruskal(MGraph G);
// 操作结果：克鲁斯卡尔算法求无向连通网的最小生成树


#endif
