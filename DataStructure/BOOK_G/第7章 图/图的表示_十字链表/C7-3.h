// C7-3.h 有向图的十字链表存储表示(与单链表的变量类型建立联系)
#ifndef C_7_3_H
#define C_7_3_H

#include "C1.h"

#define MAX_VERTEX_NUM  50  // 最大顶点个数
#define MAX_VERTEX_NAME 5   // 顶点字符串最大长度+1
typedef int  InfoType;      // 权值类型
typedef char VertexType[MAX_VERTEX_NAME];


struct ArcBox1 // 用来定义hlink的类型
{
    int      tailvex; // 尾顶点的位置
    int      headvex; // 头顶点的位置
    InfoType *info;   // 相关信息指针，可指向权值或其他信息
    ArcBox1  *hlink;  // 弧头相同的弧的链域
    ArcBox1  *tlink;  // 弧尾相同的弧的链域
};

struct ElemType
{
    int      tailvex; // 尾顶点的位置
    int      headvex; // 头顶点的位置
    InfoType *info;   // 相关信息指针，可指向权值或其他信息
    ArcBox1  *hlink;  // 弧头相同的弧的链域
};

struct ArcBox
{
    ElemType data;
    ArcBox   *tlink;
};

struct VexNode // 顶点结点
{
    VertexType data;
    ArcBox1    *firstin;  // 指向该顶点第一条入弧
    ArcBox     *firstout; // 指向该顶点第一条出弧
};

struct OLGraph
{
    VexNode xlist[MAX_VERTEX_NUM]; // 表头向量(数组)
    int     vexnum;                // 当前顶点数
    int     arcnum;                // 当前弧数
};

#define LNode  ArcBox     // 单链表的结点类型
#define next   tlink      // 单链表结点的指针域
typedef ArcBox *LinkList; // 指向单链表结点的指针

// 有向图或网的十字链表存储的基本函数(14个)

int LocateVex(OLGraph G, VertexType u);
// 操作结果：返回顶点u在有向图G中的位置(序号)，如不存在则返回-1

void CreateGraph(OLGraph &G);
// 操作结果：采用十字链表存储表示，构造有向图G

void DestroyGraph(OLGraph &G);
// 初始条件：有向图G存在
// 操作结果：销毁有向图G
 
VertexType& GetVex(OLGraph G, int v);
// 初始条件：有向图G存在，v是G中某个顶点的序号
// 操作结果：返回v的值

Status PutVex(OLGraph &G, VertexType v, VertexType value);
// 初始条件：有向图G存在，v是G中某个顶点
// 操作结果：对v赋新值value
 
int FirstAdjVex(OLGraph G, VertexType v);
// 初始条件：有向图G存在，v是G中某个顶点
// 操作结果：返回v的第一个邻接顶点的序号，
//           若顶点在G中没有邻接顶点，则返回-1

int NextAdjVex(OLGraph G, VertexType v, VertexType w);
// 初始条件：有向图G存在，v是G中某个顶点，w是v的邻接顶点
// 操作结果：返回v的(相对于w的)下一个邻接顶点的序号，
//           若w是v的最后一个邻接顶点，则返回-1

void InsertVex(OLGraph &G, VertexType v);
// 初始条件：有向图G存在，v和有向图G中顶点有相同特征
// 操作结果：在有向图G中增添新顶点v

Status DeleteVex(OLGraph &G, VertexType v);
// 初始条件：有向图G存在，v是G中某个顶点
// 操作结果：删除G中顶点v及其相关的弧

Status InsertArc(OLGraph &G, VertexType v, VertexType w);
// 初始条件：有向图G存在，v和w是G中两个顶点
// 操作结果：在G中增添弧<v, w>

Status DeleteArc(OLGraph &G, VertexType v, VertexType w);
// 初始条件：有向图G存在，v和w是G中两个顶点
// 操作结果：在G中删除弧<v, w>

void DFSTraverse(OLGraph G, void(*Visit)(VertexType));
// 初始条件：有向图G存在，v是G中某个顶点，Visit是顶点的应用函数
// 操作结果：从第1个顶点起，按深度优先递归遍历有向图G，
//           并对每个顶点调用函数Visit一次且仅一次

void BFSTraverse(OLGraph G, void(*Visit)(VertexType));
// 初始条件：有向图G存在，Visit是顶点的应用函数
// 操作结果：从第1个顶点起，按广度优先非递归遍历有向图G，
//           并对每个顶点调用函数Visit一次且仅一次

void Display(OLGraph G);
// 操作结果：输出图G
 
#endif