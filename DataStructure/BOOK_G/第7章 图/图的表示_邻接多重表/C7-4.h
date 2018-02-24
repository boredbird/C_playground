// C7-4.h 无向图的邻接多重表存储表示

#ifndef C_7_4_H
#define C_7_4_H

#include "C1.h"

#define MAX_VERTEX_NUM 50 // 最大顶点数
#define MAX_NAME       5  // 顶点字符串的最大长度+1
typedef int  InfoType;             // 权值类型
typedef char VertexType[MAX_NAME]; // 字符串类型

enum VisitIf{unvisited, visited};

struct EBox
{
    VisitIf  mark;   // 访问标记
    int      ivex;   // 该边依附的第一个顶点的位置
    int      jvex;   // 该边依附的第二个顶点的位置
    EBox     *ilink; // 指向依附顶点i的下一条边
    EBox     *jlink; // 指向依附顶点j的下一条边
    InfoType *info;  // 该边信息指针，可指向权值或其他信息
};

struct VexBox
{
    VertexType data;       // 顶点值
    EBox       *firstedge; // 指向第一条依附该顶点的边
};

struct AMLGraph
{
    VexBox adjmulist[MAX_VERTEX_NUM];
    int    vexnum;  // 当前顶点数
    int    edgenum; // 当前边数
};


// 无向图的邻接多重表的基本函数类型

int LocateVex(AMLGraph G, VertexType u);
// 初始条件：无向图G存在，u和G中顶点有相同特征
// 操作结果：若G中存在顶点u，则返回该顶点在无向图中位置；否则返回-1

void CreateGraph(AMLGraph &G);
// 操作结果：采用邻接多重表存储结构，构造无向图G

VertexType& GetVex(AMLGraph G, int v);
// 初始条件：无向图G存在，v是G中某个顶点的序号
// 操作结果：返回v的值

Status PutVex(AMLGraph &G, VertexType v, VertexType value);
// 初始条件：无向图G存在，v是G中某个顶点
// 操作结果：对v赋新值value

int FirstAdjVex(AMLGraph G, VertexType v);
// 初始条件：无向图G存在，v是G中某个顶点
// 操作结果：返回v的第一个邻接顶点的序号，
//           若顶点在G中没有邻接顶点，则返回-1

int NextAdjVex(AMLGraph G, VertexType v, VertexType w);
// 初始条件：无向图G存在，v是G中某个顶点，w是v的邻接顶点
// 操作结果：返回v的(相对于w的)下一个邻接顶点的序号，
//           若w是v的最后一个邻接点，则返回-1

Status InsertVex(AMLGraph &G, VertexType v);
// 初始条件：无向图G存在，v和G中顶点有相同特征
// 操作结果：在G中增添新顶点v

Status DeleteArc(AMLGraph &G, VertexType v, VertexType w);
// 初始条件：无向图G存在，v和w是G中两个顶点
// 操作结果：在G中删除弧 <v, w> 

Status DeleteVex(AMLGraph &G, VertexType v);
// 初始条件：无向图G存在，v是G中某个顶点
// 操作结果：删除G中顶点v及其相关的边

void DestroyGraph(AMLGraph &G);
// 初始条件：有向图G存在
// 操作结果：销毁有向图G

Status InsertArc(AMLGraph &G, VertexType v, VertexType w);
// 初始条件：无向图G存在，v和W是G中两个顶点
// 操作结果：在G中增添弧 <v, w> 

void DFSTraverse(AMLGraph G, void(*visit)(VertexType));
// 初始条件：图G存在，Visit是顶点的应用函数
// 操作结果：从第1个顶点起，深度优先遍历图G，
//           并对每个顶点调用函数Visit一次且仅一次
 
void BFSTraverse(AMLGraph G, void(*Visit)(VertexType));
// 初始条件：图G存在，Visit是顶点的应用函数
// 操作结果：从第1个顶点起，按广度优先非递归遍历图G，并对每个顶点调用函数
//           Visit一次且仅一次。使用辅助队列Q和访问标志数组visite

void Display(AMLGraph G);
// 操作结果：输出无向图的邻接多重表G

#endif