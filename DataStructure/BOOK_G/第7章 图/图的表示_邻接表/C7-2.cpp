// C7-2.cpp 图的邻接表存储的基本操作(15个)

#include "C7-2.h" 
#include "C2-3.h" 

int LocateVex(ALGraph G, VertexType u)
{ 
    // 初始条件：图G存在，u和G中顶点有相同特征
    // 操作结果：若G中存在顶点u，则返回该顶点在图中位置；否则返回-1
    int i;
    for (i = 0; i < G.vexnum; ++i) {
        if (strcmp(u, G.vertices[i].data) == 0) {
            return i;
        }
    }
    return -1;
}

void CreateGraph(ALGraph &G)
{ 
    // 操作结果：采用邻接表存储结构，构造没有相关信息图或网G(用一个函数构造4种图)
    int i, k, arcnum; 
    VertexType va, vb; // 连接边或弧的2顶点
    printf("请输入图的类型(有向图:0, 有向网:1, 无向图:2, 无向网:3): ");
    scanf("%d", &G.kind);
    printf("请输入图的顶点数和边数(以空格作为间隔): ");
    scanf("%d%d", &G.vexnum, &arcnum);
    printf("请输入%d个顶点的值(少于%d个字符):\n", G.vexnum, MAX_NAME);
    for (i = 0; i < G.vexnum; ++i) { // 构造顶点向量
        scanf("%s", G.vertices[i].data);
        G.vertices[i].firstarc = NULL; // 初始化与该顶点有关的出弧链表
    }
    G.arcnum = 0;
    printf("请输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n");
    for (k = 0; k < arcnum; ++k) { // 依次增加弧
        scanf("%s%s", va, vb);
        InsertArc(G, va, vb);
    }
}

void CreateGraphF(ALGraph &G)
{ 
    // 操作结果：采用邻接表存储结构，由文件构造没有相关信息图或网G(用一个函数构造4种图)
    int i, j, k, w; // w是权值
    VertexType va, vb; // 连接边或弧的2顶点
    ElemType e;
    char filename[13];
    FILE *graphlist;
    printf("请输入数据文件名(f7-1.txt或f7-2.txt)：");
    scanf("%s",filename);
    printf("请输入图的类型(有向图:0,有向网:1,无向图:2,无向网:3): ");
    scanf("%d", &G.kind);
    graphlist = fopen(filename, "r"); // 以读的方式打开数据文件，并以graphlist表示
    fscanf(graphlist, "%d", &G.vexnum);
    fscanf(graphlist, "%d", &G.arcnum);
    for (i = 0; i < G.vexnum; ++i) { // 构造顶点向量
        fscanf(graphlist, "%s", G.vertices[i].data);
        G.vertices[i].firstarc = NULL; // 初始化与该顶点有关的出弧链表
    }
    for (k = 0; k < G.arcnum; ++k) { // 构造相关弧链表
        if (G.kind % 2) { // 网
            fscanf(graphlist, "%d%s%s", &w, va, vb);
        } else { // 图
            fscanf(graphlist, "%s%s", va, vb);
        }
        i = LocateVex(G, va); // 弧尾
        j = LocateVex(G, vb); // 弧头
        if (i < 0 || j < 0) { // 如果顶点不存在，则跳过本次循环
            continue;
        }
        e.info = NULL; // 给待插表结点e赋值，图无权
        e.adjvex = j; // 弧头
        if (G.kind % 2) { // 网
            e.info = (int *)malloc(sizeof(int)); // 动态生成存放权值的空间
            *(e.info) = w;
        }
        ListInsert(G.vertices[i].firstarc, 1, e); // 插在第i个元素(出弧)的表头
        if (G.kind >= 2) { // 无向图或网，产生第2个表结点，并插在第j个元素(入弧)的表头
            e.adjvex = i; // e.info不变，不必再赋值
            ListInsert(G.vertices[j].firstarc, 1, e); // 插在第j个元素的表头
        }
    }
    fclose(graphlist); // 关闭数据文件
}

void DestroyGraph(ALGraph &G)
{ 
    // 初始条件：图G存在
    // 操作结果：销毁图G
    int i;
    ElemType e;
    for (i = 0; i < G.vexnum; ++i) { // 对于所有顶点
        if (G.kind % 2) { // 网
            while (G.vertices[i].firstarc) { // 对应的弧或边链表不空
                ListDelete(G.vertices[i].firstarc, 1, e); // 删除链表的第1个结点，并将值赋给e
                if (G.kind >= 2 && e.adjvex > i) { // 保证无向网动态生成的权值空间只释放1次
                    free(e.info);
                }
            }
        } else { // 图
            DestroyList(G.vertices[i].firstarc); // 销毁弧或边链表
        }
    }
    G.vexnum=0; // 顶点数为0
    G.arcnum=0; // 边或弧数为0
}

VertexType& GetVex(ALGraph G, int v)
{ 
    // 初始条件：图G存在，v是G中某个顶点的序号
    // 操作结果：返回v的值
    if (v >= G.vexnum || v < 0) {
        printf("序号%d超出范围！\n", v);
        exit(ERROR);
    }
    return G.vertices[v].data;
}

Status PutVex(ALGraph &G, VertexType v, VertexType value)
{ 
    // 初始条件：图G存在，v是G中某个顶点
    // 操作结果：对v赋新值value
    int i = LocateVex(G, v);
    if (LocateVex(G, value) >= 0) { // 如果顶点已存在
        printf("顶点%s已存在！\n", value);
        return ERROR;
    }
    if (i < 0) {
        printf("顶点%s不存在！\n", v);
        return ERROR;
    }
    strcpy(G.vertices[i].data, value);
    return OK;
}

int FirstAdjVex(ALGraph G, VertexType v)
{ 
    // 初始条件：图G存在，v是G中某个顶点
    // 操作结果：返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1
    LinkList p;
    int v1;
    v1 = LocateVex(G, v); // v1为顶点v在图G中的序号
    if (v1 < 0) { // 顶点v不存在
        printf("顶点%s不存在！\n", v);
        return -1;
    }
    p = G.vertices[v1].firstarc;
    if (p) {
        return p->data.adjvex;
    } else {
        return -1;
    }
}

Status equalvex(ElemType a, ElemType b)
{ 
    // DeleteArc()、DeleteVex()和NextAdjVex()要调用的函数
    if (a.adjvex == b.adjvex) {
        return OK;
    } else {
        return ERROR;
    }
}

int NextAdjVex(ALGraph G, VertexType v, VertexType w)
{ 
    // 初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点
    // 操作结果：返回v的(相对于w的)下一个邻接顶点的序号。若w是v的最后一个邻接点，则返回-1
    LinkList p, p1; // p1在Point()中用作辅助指针
    ElemType e;
    int v1;
    v1 = LocateVex(G, v); // v1为顶点v在图G中的序号
    if (v1 < 0) { // 顶点v不存在
        printf("顶点%s不存在！\n", v);
        return -1;
    }
    e.adjvex = LocateVex(G, w); // e.adjvex为顶点w在图G中的序号
    p = Point(G.vertices[v1].firstarc, e, equalvex, p1); // p指向顶点v的链表中邻接顶点为w的结点
    if (!p || !p->next) { // 没找到w或w是最后一个邻接点
        return -1;
    } else { // p->data.adjvex==w
        return p->next->data.adjvex; // 返回v的(相对于w的)下一个邻接顶点的序号
    }
}

void InsertVex(ALGraph &G, VertexType v)
{ 
    // 初始条件：图G存在，v和图中顶点有相同特征
    // 操作结果：在图G中增添新顶点v(不增添与顶点相关的弧，留待InsertArc()去做)
    if (G.vexnum == MAX_VERTEX_NUM || LocateVex(G, v) >= 0) { // 如果顶点已存在
        printf("顶点已存在！\n");
        return;
    }
    strcpy(G.vertices[G.vexnum].data, v); // 构造新顶点向量
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum++; // 图G的顶点数加1
}

Status DeleteVex(ALGraph &G, VertexType v)
{ 
    // 初始条件：图G存在，v是G中某个顶点
    // 操作结果：删除G中顶点v及其相关的弧
    int i, j, k;
    ElemType e;
    LinkList p, p1;
    j = LocateVex(G, v); // j是顶点v的序号
    if (j < 0) { // v不是图G的顶点
        return ERROR;
    }
    i = ListLength(G.vertices[j].firstarc); // 以v为出度的弧或边数
    G.arcnum -= i; // 边或弧数-i
    if (G.kind % 2) { // 网
        while (G.vertices[j].firstarc) { // 对应的弧或边链表不空
            ListDelete(G.vertices[j].firstarc, 1, e); // 删除链表的第1个结点，并将值赋给e
            free(e.info); // 释放动态生成的权值空间
        }
    } else { // 图
            DestroyList(G.vertices[j].firstarc); // 销毁弧或边链表
    }
    G.vexnum--; // 顶点数减1
    for (i = j; i < G.vexnum; i++) { // 顶点v后面的顶点前移
        G.vertices[i] = G.vertices[i + 1];
    }
    for (i = 0; i < G.vexnum; i++) { // 删除以v为入度的弧或边且必要时修改表结点的顶点位置值
        e.adjvex = j;
        p = Point(G.vertices[i].firstarc, e, equalvex, p1); 
        if (p) { // 顶点i的邻接表上有v为入度的结点
            if (p1) { // p1指向p所指结点的前驱
                p1->next = p->next; // 从链表中删除p所指结点
            } else { // p指向首元结点
                G.vertices[i].firstarc = p->next; // 头指针指向下一结点
            }
            if (G.kind < 2) { // 有向
                G.arcnum--; // 边或弧数-1
                if (G.kind == 1) { // 有向网
                    free(p->data.info); // 释放动态生成的权值空间
                }
            }
            free(p); // 释放v为入度的结点
        }
        for (k = j + 1; k <= G.vexnum; k++) { // 对于adjvex域>j的结点，其序号-1
            e.adjvex = k;
            p = Point(G.vertices[i].firstarc, e, equalvex, p1); 
            if (p) {
                    p->data.adjvex--; // 序号-1(因为前移)
            }
        }
    }
    return OK;
}

Status InsertArc(ALGraph &G, VertexType v, VertexType w)
{ 
    // 初始条件：图G存在，v和w是G中两个顶点
    // 操作结果：在G中增添弧<v,w>，若G是无向的，则还增添对称弧<w,v>
    ElemType e;
    int i, j;
    i = LocateVex(G, v); // 弧尾或边的序号
    j = LocateVex(G, w); // 弧头或边的序号
    if (i < 0 || j < 0) {
        return ERROR;
    }
    G.arcnum++; // 图G的弧或边的数目加1
    e.adjvex = j;
    e.info = NULL; // 初值
    if (G.kind % 2) { // 网
        e.info = (int *)malloc(sizeof(int)); // 动态生成存放权值的空间
        printf("请输入弧(边)%s→%s的权值: ", v, w);
        scanf("%d", e.info);
    }
    ListInsert(G.vertices[i].firstarc, 1, e); // 将e插在弧尾的表头
    if (G.kind >= 2) { // 无向，生成另一个表结点
        e.adjvex = i; // e.info不变
        ListInsert(G.vertices[j].firstarc, 1, e); // 将e插在弧头的表头
    }
    return OK;
}

Status DeleteArc(ALGraph &G, VertexType v, VertexType w)
{ 
    // 初始条件：图G存在，v和w是G中两个顶点
    // 操作结果：在G中删除弧<v,w>，若G是无向的，则还删除对称弧<w,v>
    int i, j;
    Status k;
    ElemType e;
    i = LocateVex(G, v); // i是顶点v(弧尾)的序号
    j = LocateVex(G, w); // j是顶点w(弧头)的序号
    if (i < 0 || j < 0 || i == j) {
        return ERROR;
    }
    e.adjvex = j;
    k = DeleteElem(G.vertices[i].firstarc, e, equalvex); 
    if (k) { // 删除成功
        G.arcnum--; // 弧或边数减1
        if (G.kind % 2) { // 网
            free(e.info);
        }
        if (G.kind >= 2) { // 无向，删除对称弧<w,v>
            e.adjvex = i;
            DeleteElem(G.vertices[j].firstarc, e, equalvex);
        }
        return OK;
    } else { // 没找到待删除的弧
        return ERROR;
    }
}

Boolean visited[MAX_VERTEX_NUM]; // 访问标志数组(全局量)
#include "C3-2.h"          // 链队列的存储结构及基本操作

void BFSTraverse(ALGraph G, void (*Visit)(char*))
{
    // 操作结果：按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited
    int v, u, w;
    LinkQueue Q;
    for (v = 0; v < G.vexnum; ++v) {
        visited[v] = FALSE; // 置初值
    }
    InitQueue(Q); // 置空的辅助队列Q
    for (v = 0; v < G.vexnum; v++) { // 如果是连通图，只v=0就遍历全图
        if (!visited[v]) { // v尚未访问
            visited[v] = TRUE;
            Visit(G.vertices[v].data);
            EnQueue(Q, v); // v入队列
            while (!QueueEmpty(Q)) { // 队列不空
                DeQueue(Q, u); // 队头元素出队并置为u
                w = FirstAdjVex(G, G.vertices[u].data); 
                while (w >= 0) {
                    if (!visited[w]) { // w为u的尚未访问的邻接顶点
                        visited[w] = TRUE;
                        Visit(G.vertices[w].data);
                        EnQueue(Q, w); // w入队
                    }
                    w = NextAdjVex(G, G.vertices[u].data, G.vertices[w].data);
                }
            }
        }
    }
    printf("\n");
}

void DFS(ALGraph G, int v, void (*Visit)(char*))
{ 
    // 操作结果：从第v个顶点出发递归地深度优先遍历图G。仅适用于邻接表存储结构
    LinkList p; // p指向表结点
    visited[v] = TRUE; // 设置访问标志为TRUE(已访问)
    Visit(G.vertices[v].data); // 访问该顶点
    for (p = G.vertices[v].firstarc; p; p = p->next) { // p依次指向v的邻接顶点
        if (!visited[p->data.adjvex]) {
            DFS(G, p->data.adjvex, Visit); // 对v的尚未访问的邻接点递归调用DFS
        }
    }
}

void DFSTraverse(ALGraph G, void (*Visit)(char*))
{ 
    // 操作结果：对图G作深度优先遍历。DFS1设函数指针参数
    int v;
    for (v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE; // 访问标志数组初始化，置初值为未被访问
    }
    for (v = 0; v < G.vexnum; v++) { // 如果是连通图，只v=0就遍历全图
        if (!visited[v]) { // v尚未被访问
            DFS(G, v, Visit); // 对v调用DFS
        }
    }
    printf("\n");
}

void Display(ALGraph G)
{ 
    // 操作结果：输出图的邻接矩阵G
    int i;
    LinkList p;
    switch(G.kind) {
        case DG: 
            printf("有向图\n");
            break;
        case DN: 
            printf("有向网\n");
            break;
        case UDG:
            printf("无向图\n");
            break;
        case UDN:
            printf("无向网\n");
    }
    printf("%d个顶点：\n", G.vexnum);
    for (i = 0; i < G.vexnum; ++i) {
        printf("%s ", G.vertices[i].data);
    }
    printf("\n%d条弧(边):\n", G.arcnum);
    for (i = 0; i < G.vexnum; i++) {
        p = G.vertices[i].firstarc;
        while (p) {
            if (G.kind <= 1 || i < p->data.adjvex) { // 有向或无向两次中的一次
                printf("%s→%s ", G.vertices[i].data, G.vertices[p->data.adjvex].data);
                if (G.kind%2) { // 网
                    printf(":%d  ", *(p->data.info));
                }
            }
            p = p->next;
        }
        printf("\n");
    }
}

// 图的高级算法函数


void PreOrderTraverse(CSTree T, void(*Visit)(TElemType))
{ 
    // 操作结果：先根遍历孩子—兄弟二叉链表结构的树T
    if (T) {
        Visit(T->data); // 先访问根结点
        PreOrderTraverse(T->firstchild,  Visit); // 再先根遍历长子子树
        PreOrderTraverse(T->nextsibling, Visit); // 最后先根遍历下一个兄弟子树
    }
}


void DFSTree(ALGraph G, int v, CSTree &T)
{ 
    // 操作结果：从第v个顶点出发深度优先遍历图G，建立以T为根的生成树
    Boolean first = TRUE; 
    int w; 
    CSTree p, q; 
    visited[v] = TRUE; 
    w = FirstAdjVex(G, G.vertices[v].data); 
    while (w >= 0) { // w依次为v的邻接顶点
        if (!visited[w]) { // w顶点不曾被访问
            p = (CSTree) malloc(sizeof(CSNode));  // 分配孩子结点
            strcpy(p->data, G.vertices[w].data); 
            p->firstchild = NULL; 
            p->nextsibling = NULL; 
            if (first) {
                // w是v的第一个未被访问的邻接顶点
                T->firstchild = p; 
                first = FALSE;  // 是根的第一个孩子结点
            } else { // w是v的其它未被访问的邻接顶点
                q->nextsibling = p;  // 是上一邻接顶点的兄弟姐妹结点(第1次不通过此处，以后q已赋值)
            }
            q = p; 
            DFSTree(G, w, q);  // 从第w个顶点出发深度优先遍历图G，建立子生成树q
        }
        w = NextAdjVex(G, G.vertices[v].data, G.vertices[w].data);
    }
}

void DFSForest(ALGraph G, CSTree &T)
{ 
    // 操作结果：建立无向图G的深度优先生成森林的(最左)孩子(右)兄弟链表T
    CSTree p, q; 
    int v; 
    T = NULL; 
    for (v = 0; v < G.vexnum; ++v) {
        visited[v] = FALSE;  // 赋初值
    }
    for (v = 0; v < G.vexnum; ++v) { // 从第0个顶点找起
        if (!visited[v]) { // 第v个顶点不曾被访问
            // 第v顶点为新的生成树的根结点
            p = (CSTree)malloc(sizeof(CSNode));  // 分配根结点
            strcpy(p->data, G.vertices[v].data); 
            p->firstchild = NULL; 
            p->nextsibling = NULL; 
            if (!T) { // 是第一棵生成树的根(T的根)
                T = p;
            } else { // 是其它生成树的根(前一棵的根的＂兄弟＂)
                q->nextsibling = p;  // 第1次不通过此处，以后q已赋值
            }
            q = p;  // q指示当前生成树的根
            DFSTree(G, v, p);  // 建立以p为根的生成树
        }
    }
}


int count, lowcount = 1;  // 全局量count对访问顺序计数, lowcount对求得low值的顺序计数
int low[MAX_VERTEX_NUM], lowOrder[MAX_VERTEX_NUM]; 
// 全局数组，low[]存顶点的low值，lowOrder存顶点求得low值的顺序

void DFSArticul(ALGraph G, int v0)
{ 
    // 操作结果：从第v0个顶点出发深度优先遍历图G，查找并输出关节点
    int min, w; 
    ArcNode *p; 
    visited[v0] = min = ++count; 
    // v0是第count个访问的顶点，visited[]是全局变量, 在bo7-2.cpp中定义, min的初值为v0的访问顺序
    for (p = G.vertices[v0].firstarc; p; p = p->nextarc) { 
        // 依次对v0的每个邻接顶点检查
        w = p->data.adjvex;  // w为v0的邻接顶点位置
        if (visited[w] == 0) { // w未曾访问，是v0的孩子
            DFSArticul(G, w); 
            // 从第w个顶点出发深度优先遍历图G，查找并输出关节点。返回前求得low[w]
            if (low[w] < min) { // 如果v0的孩子结点w的low[]小，这说明孩子结点还与其它结点(祖先)相邻
                min = low[w];  // 取min值为孩子结点的low[]，则v0不是关节点
            } else if (low[w] >= visited[v0]) { // v0的孩子结点w只与v0相连，则v0是关节点
                printf("%d %s\n", v0, G.vertices[v0].data);  // 输出关节点v0
            }
        } else if (visited[w] < min) { // w已访问，则w是v0在生成树上的祖先，它的访问顺序必小于min
            min = visited[w];  // 故取min为visited[w]
        }
    }
    low[v0] = min;  // vo的low[]值为三者中的最小值
    lowOrder[v0] = lowcount++;  // 记录v0求得low[]值的顺序(附加), 总是在返回主调函数之前求得low[]
}

void FindArticul(ALGraph G)
{ 
    // 操作结果：连通图G以邻接表作存储结构，查找并输出G上全部关节点。全局量count对访问计数
    int i, v; 
    ArcNode *p; 
    count = 1;  // 访问顺序
    visited[0] = count;  // 设定邻接表上0号顶点为生成树的根，第1个被访问
    for (i = 1; i < G.vexnum; ++i) {
        visited[i] = 0;  // 其余顶点尚未访问，设初值为0
    }
    p = G.vertices[0].firstarc;  // p指向根结点的第1个邻接顶点
    v = p->data.adjvex;  // v是根结点的第1个邻接顶点的序号
    DFSArticul(G, v);  // 从第v顶点出发深度优先查找关节点
    if (count < G.vexnum) { // 由根结点的第1个邻接顶点深度优先遍历G，访问的顶点数少于G的顶点数
        // 说明生成树的根有至少两棵子树，则根是关节点
        printf("%d %s\n", 0, G.vertices[0].data);  // 根是关节点，输出根
        while (p->nextarc) { // 根有下一个邻接点
            p = p->nextarc;  // p指向根的下一个邻接点
            v = p->data.adjvex; 
            if (visited[v] == 0) { // 此邻接点未被访问
                DFSArticul(G, v);  // 从此顶点出发深度优先查找关节点
            }
        }
    }
}

void FindInDegree(ALGraph G, int indegree[])
{ 
    // 操作结果：求顶点的入度
    int i; 
    ArcNode *p; 
    for (i = 0; i < G.vexnum; i++) {
        indegree[i] = 0;  // 赋初值
    }
    for (i = 0; i < G.vexnum; i++) {
        p = G.vertices[i].firstarc; 
        while (p) {
            indegree[p->data.adjvex]++; 
            p = p->nextarc; 
        }
    }
}

Status TopologicalSort(ALGraph G)
{ 
    // 操作结果：有向图G采用邻接表存储结构。若G无回路，则输出G的顶点的一个拓扑序列并返回OK，
    //           否则返回ERROR
    int i, k, count = 0;  // 已输出顶点数，初值为0
    int indegree[MAX_VERTEX_NUM];  // 入度数组，存放各顶点当前入度数
    SqStack S; 
    ArcNode *p; 
    FindInDegree(G, indegree);  // 对各顶点求入度indegree[]
    InitStack(S);  // 初始化零入度顶点栈S
    for (i = 0; i < G.vexnum; ++i) { // 对所有顶点i
        if (!indegree[i]) { // 若其入度为0
            Push(S, i);  // 将i入零入度顶点栈S
        }
    }
    while (!StackEmpty(S)) { // 当零入度顶点栈S不空
        Pop(S, i);  // 出栈1个零入度顶点的序号，并将其赋给i
        printf("%s ", G.vertices[i].data);  // 输出i号顶点
        ++count;  // 已输出顶点数 + 1
        for (p = G.vertices[i].firstarc; p; p = p->nextarc) {
            // 对i号顶点的每个邻接顶点
            k = p->data.adjvex;  // 其序号为k
            if (!(--indegree[k])) { // k的入度减1，若减为0，则将k入栈S
                Push(S, k); 
            }
        }
    }
    if (count < G.vexnum) { // 零入度顶点栈S已空，图G还有顶点未输出
        printf("此有向图有回路\n"); 
        return ERROR; 
    } else {
        printf("为一个拓扑序列。\n"); 
        return OK; 
    }
}


int ve[MAX_VERTEX_NUM];  // 事件最早发生时间，全局变量

Status TopologicalOrder(ALGraph G, SqStack &T)
{ 
    // 操作结果：有向网G采用邻接表存储结构，求各顶点事件的最早发生时间ve(全局变量)。T为拓扑序列
    //           顶点栈, S为零入度顶点栈。若G无回路，则用栈T返回G的一个拓扑序列, 且函数值为OK, 否则为ERROR
    int i, k, count = 0;  // 已入栈顶点数，初值为0
    int indegree[MAX_VERTEX_NUM];  // 入度数组，存放各顶点当前入度数
    SqStack S; 
    ArcNode *p; 
    FindInDegree(G, indegree);  // 对各顶点求入度indegree[]，在func7-1.cpp中
    InitStack(S);  // 初始化零入度顶点栈S
    printf("拓扑序列："); 
    for (i = 0; i < G.vexnum; ++i) { // 对所有顶点i
        if (!indegree[i]) { // 若其入度为0
            Push(S, i);  // 将i入零入度顶点栈S
        }
    }
    InitStack(T);  // 初始化拓扑序列顶点栈
    for (i = 0; i < G.vexnum; ++i) { // 初始化ve[] = 0(最小值，先假定每个事件都不受其他事件约束)
        ve[i] = 0; 
    }
    while (!StackEmpty(S)) { // 当零入度顶点栈S不空
        Pop(S, i);  // 从栈S将已拓扑排序的顶点j弹出
        printf("%s ", G.vertices[i].data); 
        Push(T, i);  // j号顶点入逆拓扑排序栈T(栈底元素为拓扑排序的第1个元素)
        ++count;  // 对入栈T的顶点计数
        for (p = G.vertices[i].firstarc; p; p = p->nextarc) {
            // 对i号顶点的每个邻接点
            k = p->data.adjvex;  // 其序号为k
            if (--indegree[k] == 0) { // k的入度减1，若减为0，则将k入栈S
                Push(S, k); 
            }
            if (ve[i] + *(p->data.info) > ve[k]) { // *(p->data.info)是<i, k>的权值
                // 顶点k事件的最早发生时间要受其直接前驱顶点i事件的
                // 最早发生时间和 < i, k > 的权值约束。由于i已拓扑有序，故ve[i]不再改变
                ve[k] = ve[i] + *(p->data.info);  
            }
        }                  
    }
    if (count < G.vexnum) {
        printf("此有向网有回路\n"); 
        return ERROR; 
    } else {
        return OK; 
    }
}

Status CriticalPath(ALGraph G)
{ 
    // 操作结果：G为有向网，输出G的各项关键活动
    int vl[MAX_VERTEX_NUM];  // 事件最迟发生时间
    SqStack T; 
    int i, j, k, ee, el, dut; 
    ArcNode *p; 
    if (!TopologicalOrder(G, T)) { // 产生有向环
        return ERROR; 
    }
    j = ve[0];  // j的初值
    for (i = 1; i < G.vexnum; i++) {
        if (ve[i] > j) {
            j = ve[i];  // j = Max(ve[]) 完成点的最早发生时间
        }
    }
    for (i = 0; i < G.vexnum; i++) { // 初始化顶点事件的最迟发生时间
        vl[i] = j;  // 为完成点的最早发生时间(最大值)
    }
    while (!StackEmpty(T)) { // 按拓扑逆序求各顶点的vl值
        Pop(T, j);
        for (p = G.vertices[j].firstarc; p; p = p->nextarc) {
            // 弹出栈T的元素, 赋给j, p指向j的后继事件k, 事件k的最迟发生时间已确定(因为是逆拓扑排序)
            k = p->data.adjvex; 
            dut = *(p->data.info);  // dut=<j, k>的权值
            if (vl[k] - dut < vl[j]) {
                // 事件j的最迟发生时间要受其直接后继事件k的最迟发生时间
                // 和 < j, k > 的权值约束。由于k已逆拓扑有序，故vl[k]不再改变
                vl[j] = vl[k]-dut;  
            }
        } 
    }
    printf("\ni ve[i] vl[i]\n"); 
    for (i = 0; i < G.vexnum; i++) { // 初始化顶点事件的最迟发生时间
        printf("%d   %d     %d", i, ve[i], vl[i]); 
        if (ve[i] == vl[i]) {
            printf(" 关键路径经过的顶点"); 
        }
        printf("\n"); 
    }
    printf("j   k  权值  ee  el\n"); 
    for (j = 0; j < G.vexnum; ++j) { // 求ee，el和关键活动
        for (p = G.vertices[j].firstarc; p; p = p->nextarc) {
            k = p->data.adjvex; 
            dut = *(p->data.info);  // dut =  < j, k > 的权值
            ee = ve[j];  // ee = 活动 < j, k > 的最早开始时间(在j点)
            el = vl[k] - dut;  // el = 活动 < j, k > 的最迟开始时间(在j点)
            printf("%s→%s %3d %3d %3d ", G.vertices[j].data, G.vertices[k].data, dut, ee, el); 
            // 输出各边的参数
            if (ee == el) { // 是关键活动
                printf("关键活动"); 
            }
            printf("\n"); 
        }
    }
    return OK; 
}
