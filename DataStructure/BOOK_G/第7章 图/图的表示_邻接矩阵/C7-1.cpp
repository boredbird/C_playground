// C7-1.cpp 图的数组(邻接矩阵)存储的基本操作(17个)

#include "C7-1.h"

Boolean visited[MAX_VERTEX_NUM]; // 访问标志数组(全局量)

int LocateVex(MGraph G, VertexType v)
{ 
    // 初始条件：图G存在，u和G中顶点有相同特征
    // 操作结果：若G中存在顶点u，则返回该顶点在图中位置；否则返回-1
    int i;
    for (i = 0; i < G.vexnum; ++i) {
        if (strcmp(v, G.vexs[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void CreateFUDG(MGraph &G)
{ 
    // 操作结果：采用数组(邻接矩阵)表示法，由文件构造没有相关信息的无向图G
    int i, j, k;
    char filename[13];
    VertexType va, vb;
    FILE *graphlist;
    printf("请输入数据文件名(f7-1.txt或f7-2.txt)：");
    scanf("%s", filename);
    graphlist = fopen(filename, "r"); // 打开数据文件，并以graphlist表示
    fscanf(graphlist, "%d", &G.vexnum);
    fscanf(graphlist, "%d", &G.arcnum);
    for (i = 0; i < G.vexnum; ++i) { // 构造顶点向量
        fscanf(graphlist, "%s", G.vexs[i]);
    }
    for (i = 0; i < G.vexnum; ++i) { // 初始化邻接矩阵
        for (j = 0; j < G.vexnum; ++j) {
            G.arcs[i][j].adj  = 0; // 图
            G.arcs[i][j].info = NULL; // 没有相关信息
        }
    }
    for (k = 0; k < G.arcnum; ++k) {
        fscanf(graphlist, "%s%s", va, vb);
        i = LocateVex(G, va);
        j = LocateVex(G, vb);
        G.arcs[i][j].adj = G.arcs[j][i].adj = 1; // 无向图
    }
    fclose(graphlist); // 关闭数据文件
    G.kind = UDG;
}

void CreateFUDN(MGraph &G)
{ 
    // 操作结果：采用数组(邻接矩阵)表示法，由文件构造没有相关信息的无向网G
    int i, j, k, w;
    char filename[13];
    VertexType va, vb;
    FILE *graphlist;
    printf("请输入数据文件名：");
    scanf("%s", filename);
    graphlist = fopen(filename, "r"); // 打开数据文件，并以graphlist表示
    fscanf(graphlist, "%d", &G.vexnum);
    fscanf(graphlist, "%d", &G.arcnum);
    for (i = 0; i < G.vexnum; ++i) { // 构造顶点向量
        fscanf(graphlist, "%s", G.vexs[i]);
    }
    for (i = 0; i < G.vexnum; ++i) { // 初始化邻接矩阵
        for (j = 0; j < G.vexnum; ++j) {
            G.arcs[i][j].adj  = INFINITY; // 网
            G.arcs[i][j].info = NULL; // 没有相关信息
        }
    }
    for (k = 0; k < G.arcnum; ++k) {
        fscanf(graphlist, "%s%s%d", va, vb, &w);
        i = LocateVex(G, va);
        j = LocateVex(G, vb);
        G.arcs[i][j].adj = G.arcs[j][i].adj = w; // 无向网
    }
    fclose(graphlist); // 关闭数据文件
    G.kind = UDN;
}


void CreateGraph(MGraph &G)
{ 
    // 操作结果：采用数组(邻接矩阵)表示法，构造图G
    int i, j, k, arcnum;
    VertexType va, vb;

    printf("请输入图G的类型(有向图:0,有向网:1,无向图:2,无向网:3): ");
    scanf("%d", &G.kind);
    printf("请输入图的顶点数和边数(以空格作为间隔): ");
    scanf("%d%d", &G.vexnum, &arcnum);
    if (G.vexnum >= MAX_VERTEX_NUM - 1) {
        // 若输入顶点数超过图G的最大容量则以最大容量作为顶点数
        G.vexnum = MAX_VERTEX_NUM - 1;
    }
    printf("请输入%d个顶点的值(少于%d个字符):\n", G.vexnum, MAX_NAME);
    for (i = 0; i < G.vexnum; ++i) { // 构造顶点向量
        scanf("%s", G.vexs[i]);
    }
    for (i = 0; i < G.vexnum; ++i) { // 初始化邻接矩阵
        for (j = 0; j < G.vexnum; ++j) {
            if (G.kind % 2) { // 网
                G.arcs[i][j].adj  = INFINITY; 
            } else { // 图
                G.arcs[i][j].adj  = 0; 
            }
            G.arcs[i][j].info = NULL;
        }
    }
    G.arcnum = 0;
    printf("请输入%d条弧的弧尾 弧头(以空格作为间隔): \n", arcnum);
    for (k = 0; k < arcnum; ++k) { // 依次增加弧
        scanf("%s%s", va, vb);
        InsertArc(G, va, vb);
    }
}

void DestroyGraph(MGraph &G)
{ 
    // 初始条件：图G存在
    // 操作结果：销毁图G
    int i, j, k = 0;
    if (G.kind % 2) { // 网
        k = INFINITY; // k为两顶点之间无边或弧时邻接矩阵元素的值
    }
    for (i = 0; i < G.vexnum; i++) { // 释放弧或边的相关信息(如果有的话)
        if (G.kind < 2) { // 有向
            for (j = 0; j < G.vexnum; j++) {
                if (G.arcs[i][j].adj != k) { // 有弧
                    if (G.arcs[i][j].info) { // 有相关信息
                        free(G.arcs[i][j].info);
                        G.arcs[i][j].info = NULL;
                    }
                }
            }
        } else { // 无向
            for (j = i + 1; j < G.vexnum; j++) { // 只查上三角
                if (G.arcs[i][j].adj != k) { // 有边
                    if(G.arcs[i][j].info) { // 有相关信息
                        free(G.arcs[i][j].info);
                        G.arcs[i][j].info = G.arcs[j][i].info = NULL;
                    }
                }
            }
        }
    }
    G.vexnum = 0; // 顶点数为0
    G.arcnum = 0; // 边数为0
}

VertexType& GetVex(MGraph G, int v)
{ 
    // 初始条件：图G存在，v是G中某个顶点的序号
    // 操作结果：返回v的值
    if (v >= G.vexnum || v < 0) {
        exit(ERROR);
    }
    return G.vexs[v];
}

Status PutVex(MGraph &G, VertexType v, VertexType value)
{ 
    // 初始条件：图G存在，v是G中某个顶点
    // 操作结果：对v赋新值value
    int k;
    k = LocateVex(G, v); // k为顶点v在图G中的序号
    if (k < 0) {
        return ERROR;
    }
    strcpy(G.vexs[k], value);
    return OK;
}

int FirstAdjVex(MGraph G, VertexType v)
{ 
    // 初始条件：图G存在，v是G中某个顶点
    // 操作结果：返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1
    int i, j = 0, k;
    k = LocateVex(G, v); // k为顶点v在图G中的序号
    if (k < 0) {  // 顶点不存在
        return -1; 
    }
    if (G.kind % 2) { // 网
        j = INFINITY;
    }
    for (i = 0; i < G.vexnum; i++) {
        if (G.arcs[k][i].adj != j) {
            return i;
        }
    }
    return -1;
}

int NextAdjVex(MGraph G, VertexType v, VertexType w)
{ 
    // 初始条件：图G存在，v是G中某个顶点，w是v的邻接顶点
    // 操作结果：返回v的(相对于w的)下一个邻接顶点的序号，若w是v的最后一个邻接顶点，则返回-1
    int i, j = 0, k1, k2;
    k1 = LocateVex(G, v); // k1为顶点v在图G中的序号
    k2 = LocateVex(G, w); // k2为顶点w在图G中的序号
    if (k1 < 0 || k2 < 0) {  // 顶点不存在
        return -1; 
    }
    if (G.kind % 2) { // 网
        j = INFINITY;
    }
    for (i = k2 + 1; i < G.vexnum; i++) {
        if (G.arcs[k1][i].adj != j) {
            return i;
        }
    }
    return -1;
}

void InsertVex(MGraph &G, VertexType v)
{ 
    // 初始条件：图G存在，v和图G中顶点有相同特征
    // 操作结果：在图G中增添新顶点v
    int i, j = 0;
    if (G.vexnum >= MAX_VERTEX_NUM - 1) {
        // 顶点数已达最大容量，则不插入
        return;
    }
    if (G.kind % 2) { // 网
        j = INFINITY;
    }
    strcpy(G.vexs[G.vexnum], v); // 构造新顶点向量
    for (i = 0; i <= G.vexnum; i++) {
        // 初始化新增行、新增列邻接矩阵的值(无边或弧)
        G.arcs[G.vexnum][i].adj = j;
        G.arcs[i][G.vexnum].adj = j;
        // 初始化相关信息指针
        G.arcs[G.vexnum][i].info = NULL; 
        G.arcs[i][G.vexnum].info = NULL; 
    }
    G.vexnum++; // 图G的顶点数加1
}

Status DeleteVex(MGraph &G, VertexType v)
{ 
    // 初始条件：图G存在，v是G中某个顶点
    // 操作结果：删除G中顶点v及其相关的弧
    int i, j, k;
    VRType m = 0;
    if (G.kind % 2) { // 网
        m = INFINITY;
    }
    k = LocateVex(G, v); // k为待删除顶点v的序号
    if (k < 0) { // v不是图G的顶点
        return ERROR;
    }
    for (j = 0; j < G.vexnum; j++) {
        if (G.arcs[j][k].adj != m) { // 有入弧或边
            if (G.arcs[j][k].info) { // 有相关信息
                free(G.arcs[j][k].info); // 释放相关信息
            }
            G.arcnum--; // 修改弧数
        }
    }
    if (G.kind < 2) { // 有向
        for (j = 0; j < G.vexnum; j++) {
            if (G.arcs[k][j].adj != m) { // 有出弧
                if (G.arcs[k][j].info) { // 有相关信息
                    free(G.arcs[k][j].info); // 释放相关信息
                }
                G.arcnum--; // 修改弧数
            }
        }
    }
    for (j = k + 1; j < G.vexnum; j++) { // 序号k后面的顶点向量依次前移
        strcpy(G.vexs[j - 1], G.vexs[j]);
    }
    for (i = 0; i < G.vexnum; i++) {
        for (j = k + 1; j < G.vexnum; j++) {
            G.arcs[i][j - 1] = G.arcs[i][j]; // 移动待删除顶点之右的矩阵元素
        }
    }
    for(i = 0; i < G.vexnum; i++) {
        for(j = k + 1; j < G.vexnum; j++) {
            G.arcs[j - 1][i] = G.arcs[j][i]; // 移动待删除顶点之下的矩阵元素
        }
    }
    G.vexnum--; // 更新图的顶点数
    return OK;
}

Status InsertArc(MGraph &G, VertexType v, VertexType w)
{ 
    // 初始条件：图G存在，v和w是G中两个顶点
    // 操作结果：在G中增添弧<v,w>，若G是无向的，则还增添对称弧<w,v>
    int i, l, v1, w1;
    char s[MAX_INFO];
    v1 = LocateVex(G, v); // 尾
    w1 = LocateVex(G, w); // 头
    if (v1 < 0 || w1 < 0){
        return ERROR;
    }
    G.arcnum++; // 弧或边数加1
    if (G.kind % 2) { // 网
        printf("请输入此弧或边的权值: ");
        scanf("%d", &G.arcs[v1][w1].adj);
    } else { // 图
        G.arcs[v1][w1].adj = 1;
    }
    printf("是否有该弧或边的相关信息(0:无 1:有): ");
    scanf("%d", &i);
    fflush(stdin); // 清除缓冲区中残留的回车字符
    if (i) {
        printf("请输入该弧或边的相关信息(少于%d个字符)：", MAX_INFO);
        gets(s);
        l = strlen(s);
        if (l) {
            G.arcs[v1][w1].info = (char *)malloc((l + 1) * sizeof(char));
            strcpy(G.arcs[v1][w1].info, s);
        }
    }
    if (G.kind > 1) { // 无向
        G.arcs[w1][v1].adj  = G.arcs[v1][w1].adj;
        G.arcs[w1][v1].info = G.arcs[v1][w1].info; // 指向同一个相关信息
    }
    return OK;
}

Status DeleteArc(MGraph &G, VertexType v, VertexType w)
{ 
    // 初始条件：图G存在，v和w是G中两个顶点
    // 操作结果：在G中删除弧<v,w>，若G是无向的，则还删除对称弧<w,v>
    int v1, w1, j = 0;
    if (G.kind % 2) { // 网
        j = INFINITY;
    }
    v1 = LocateVex(G, v); // 尾
    w1 = LocateVex(G, w); // 头
    if (v1 < 0 || w1 < 0) { // v1、w1的值不合法
        return ERROR;
    }
    G.arcs[v1][w1].adj = j;
    if (G.arcs[v1][w1].info) { // 有其它信息
        free(G.arcs[v1][w1].info);
        G.arcs[v1][w1].info = NULL;
    }
    if (G.kind >= 2) { // 无向，删除对称弧<w,v>
        G.arcs[w1][v1].adj  = j;
        G.arcs[w1][v1].info = NULL;
    }
    G.arcnum--; // 弧数-1
    return OK;
}

void DFS(MGraph G, int v, void (*Visit)(VertexType))
{ 
    // 操作结果：从第v个顶点出发递归地深度优先遍历图G
    int w;
    visited[v] = TRUE; // 设置访问标志为TRUE(已访问)
    Visit(G.vexs[v]); // 访问第v个顶点
    w = FirstAdjVex(G, G.vexs[v]);
    while (w >= 0) {
        if (!visited[w]) {
            DFS(G, w, Visit); // 对v的尚未访问的序号为w的邻接顶点递归调用DFS
        }
        w = NextAdjVex(G, G.vexs[v], G.vexs[w]);
    }
}

void DFSTraverse(MGraph G, void (*Visit)(VertexType))
{ 
    // 初始条件：图G存在，Visit是顶点的应用函数
    // 操作结果：从第1个顶点起，深度优先遍历图G，并对每个顶点调用函数Visit一次且仅一次
    int v;
    for (v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE; // 访问标志数组初始化(未被访问)
    }
    for (v = 0; v < G.vexnum; v++) {
        if (!visited[v]) {
            DFS(G, v, Visit); // 对尚未访问的顶点v调用DFS
        }
    }
}

void BFSTraverse(MGraph G, void (*Visit)(VertexType))
{ 
    // 初始条件：图G存在，Visit是顶点的应用函数
    // 操作结果：从第1个顶点起，按广度优先非递归遍历图G,并对每个顶点调用函数Visit一次且仅一次
    int v, u, w;
    LinkQueue Q; // 使用辅助队列Q和访问标志数组visited
    for (v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE; // 置初值
    }
    InitQueue(Q); // 置空的辅助队列Q
    for (v = 0; v < G.vexnum; v++) {
        if (!visited[v]) { // v尚未访问
            visited[v] = TRUE; // 设置访问标志为TRUE(已访问)
            Visit(G.vexs[v]);
            EnQueue(Q, v); // v入队列
            while (!QueueEmpty(Q)) { // 队列不空
                DeQueue(Q, u); // 队头元素出队并置为u
                w = FirstAdjVex(G, G.vexs[u]);
                while (w >= 0) {
                    if (!visited[w]) { // w为u的尚未访问的邻接顶点的序号
                        visited[w] = TRUE;
                        Visit(G.vexs[w]);
                        EnQueue(Q, w);
                    }
                    w = NextAdjVex(G, G.vexs[u], G.vexs[w]);
                }
            }
        }
    }
}

void Display(MGraph G)
{ 
    // 操作结果：输出邻接矩阵存储表示的图G
    int i, j;
    char s[7];
    switch (G.kind) {
        case DG: 
            strcpy(s,"有向图");
            break;
        case DN: 
            strcpy(s,"有向网");
            break;
        case UDG:
            strcpy(s,"无向图");
            break;
        case UDN:
            strcpy(s,"无向网");
    }
    printf("%d个顶点%d条边或弧的%s。顶点依次是: ", G.vexnum, G.arcnum, s);
    for (i = 0; i < G.vexnum; ++i) { // 输出G.vexs
        printf("%s ", G.vexs[i]);
    }
    printf("\nG.arcs.adj:\n"); // 输出G.arcs.adj
    for (i = 0; i < G.vexnum; i++) {
        for (j = 0; j < G.vexnum; j++) {
            printf("%11d", G.arcs[i][j].adj);
        }
        printf("\n");
    }
    printf("G.arcs.info:\n"); // 输出G.arcs.info
    printf("顶点1(弧尾) 顶点2(弧头) 该边或弧的信息：\n");
    for (i = 0; i < G.vexnum; i++) {
        if (G.kind < 2) { // 有向
            for (j = 0; j < G.vexnum; j++) {
                if (G.arcs[i][j].adj > 0 && G.arcs[i][j].adj < INFINITY) {
                    printf("%5s   %11s       %s\n", G.vexs[i], G.vexs[j], G.arcs[i][j].info);
                }
            }
        } else { // 无向,输出上三角
            for (j = i + 1; j < G.vexnum; j++) {
                if (G.arcs[i][j].adj > 0 && G.arcs[i][j].adj < INFINITY) {
                    printf("%5s   %11s      %s\n", G.vexs[i], G.vexs[j], G.arcs[i][j].info);
                }
            }
        }
    }
}

// 图相关的高级算法

typedef struct
{ 
    // 记录从顶点集U到V-U的代价最小的边的辅助数组定义
    // 用于MiniSpanTree_PRIM函数
    VertexType adjvex;
    VRType     lowcost;
} minside[MAX_VERTEX_NUM];

int minimum(minside SZ, MGraph G)
{ 
    // 操作结果：求SZ.lowcost的最小正值，并返回其在SZ中的序号
    int i = 0, j, k, min; 
    while (!SZ[i].lowcost) {
        i++; 
    }
    min = SZ[i].lowcost;  // 第一个不为0的值
    k = i; 
    for (j = i+1; j < G.vexnum; j++) {
        if (SZ[j].lowcost > 0 && min > SZ[j].lowcost) { // 找到新的大于0的最小值
            min = SZ[j].lowcost; 
            k   = j; 
        }
    }
    return k; 
}

void MiniSpanTree_PRIM(MGraph G, VertexType u)
{ 
    // 操作结果：用普里姆算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边
    int i, j, k; 
    minside closedge; 
    k = LocateVex(G, u); 
    for (j = 0; j < G.vexnum; ++j) { // 辅助数组初始化
        strcpy(closedge[j].adjvex, u); 
        closedge[j].lowcost = G.arcs[k][j].adj; 
    }
    closedge[k].lowcost = 0;  // 初始, U = {u}
    printf("最小代价生成树的各条边为:\n"); 
    for (i = 1; i < G.vexnum; ++i) {
        // 选择其余G.vexnum-1个顶点
        k = minimum(closedge, G);  // 求出T的下一个结点：第k顶点
        printf("(%s-%s)\n", closedge[k].adjvex, G.vexs[k]);  // 输出生成树的边
        closedge[k].lowcost = 0;  // 第k顶点并入U集
        for (j = 0; j < G.vexnum; ++j) {
            if (G.arcs[k][j].adj < closedge[j].lowcost) {
                // 新顶点并入U集后重新选择最小边
                strcpy(closedge[j].adjvex, G.vexs[k]); 
                closedge[j].lowcost = G.arcs[k][j].adj; 
            }
        }
    }
}


void ShortestPath_DIJ(MGraph G, int v0, PathMatrix_DIJ P, ShortPathTable D)
{ 
    // 操作结果：用Dijkstra算法求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度
    //           D[v]。若P[v][w]为TRUE，则w是从v0到v当前求得最短路径上的顶点。
    //           final[v]为TRUE当且仅当v∈S，即已经求得从v0到v的最短路径
    int v, w, i, j, min; 
    Status final[MAX_VERTEX_NUM];  // 辅助矩阵，为真表示该顶点到v0的最短距离已求出，初值为假
    for (v = 0; v < G.vexnum; ++v) {
        final[v] = FALSE;  // 设初值
        D[v] = G.arcs[v0][v].adj;  // D[]存放v0到v的最短距离，初值为v0到v的直接距离
        for (w = 0; w < G.vexnum; ++w) {
            P[v][w] = FALSE;  // 设P[][]初值为FALSE，没有路径
        }
        if (D[v] < INFINITY) { // v0到v有直接路径
            P[v][v0] = P[v][v] = TRUE;  // 一维数组p[v][]表示源点v0到v最短路径通过的顶点
        }
    }
    D[v0] = 0;  // v0到v0距离为0
    final[v0] = TRUE;  // v0顶点并入S集
    for (i = 1; i < G.vexnum; ++i) { // 其余G.vexnum-1个顶点
        // 开始主循环，每次求得v0到某个顶点v的最短路径，并将v并入S集
        min = INFINITY;  // 当前所知离v0顶点的最近距离，设初值为∞
        for (w = 0; w < G.vexnum; ++w) { // 对所有顶点检查
            if (!final[w] && D[w] < min) { //在S集之外的顶点中找离v0最近的顶点，并将其赋给v，距离赋给min
                v   = w; 
                min = D[w]; 
            }
        }
        final[v] = TRUE;  // 将v并入S集
        for (w = 0; w < G.vexnum; ++w) { // 根据新并入的顶点，更新不在S集的顶点到v0的距离和路径数组
            if (!final[w] && min < INFINITY && 
                G.arcs[v][w].adj < INFINITY && 
                (min + G.arcs[v][w].adj < D[w])) {
                // w不属于S集且v0→v→w的距离＜目前v0→w的距离
                D[w] = min + G.arcs[v][w].adj;  // 更新D[w]
                for (j = 0; j < G.vexnum; ++j)  { // 修改P[w]，v0到w经过的顶点包括v0到v经过的顶点再加上顶点w
                    P[w][j] = P[v][j]; 
                }
                P[w][w] = TRUE; 
            }
        }
    }
}


void ShortestPath_FLOYD(MGraph G, PathMatrix_FLOYD P, DistancMatrix D)
{ 
    // 操作结果：用Floyd算法求有向网G中各对顶点v和w之间的最短路径P[v][w]及其带权长度D[v][w]
    //           若P[v][w][u]为TRUE，则u是从v到w当前求得最短路径上的顶点
    int u, v, w, i; 
    for (v = 0; v < G.vexnum; v++) { // 各对结点之间初始已知路径及距离
        for (w = 0; w < G.vexnum; w++) {
            D[v][w] = G.arcs[v][w].adj;  // 顶点v到顶点w的直接距离
            for (u = 0; u < G.vexnum; u++) {
                P[v][w][u] = FALSE;  // 路径矩阵初值
            }
            if (D[v][w] < INFINITY) { // 从v到w有直接路径
                P[v][w][v] = P[v][w][w] = TRUE;  // 由v到w的路径经过v和w两点
            }
        }
    }
    for (u = 0; u < G.vexnum; u++) {
        for (v = 0; v < G.vexnum; v++) {
            for (w = 0; w < G.vexnum; w++) {
                if (D[v][u] < INFINITY && D[u][w] < INFINITY && 
                    D[v][u]+D[u][w] < D[v][w]) {
                    // 从v经u到w的一条路径更短
                    D[v][w] = D[v][u] + D[u][w];  // 更新最短距离
                    for (i = 0; i < G.vexnum; i++)
                        P[v][w][i] = P[v][u][i] || P[u][w][i];  // 从v到w的路径经过从v到u和从u到w的所有路径
                }
            }
        }
    }
}

void Kruskal(MGraph G)
{
    // 操作结果：克鲁斯卡尔算法求无向连通网的最小生成树
    int set[MAX_VERTEX_NUM], i, j; 
    int k = 0, a = 0, b = 0, min = G.arcs[a][b].adj; 
    for (i = 0; i < G.vexnum; i++) {
        set[i] = i;  // 初态，各顶点分别属于各个集合
    }
    printf("最小代价生成树的各条边为:\n"); 
    while (k < G.vexnum - 1) { // 最小生成树的边数小于顶点数-1
        // 寻找最小权值的边
        for (i = 0; i < G.vexnum; ++i) {
            for (j = i + 1; j < G.vexnum; ++j) { // 无向网，只在上三角查找
                if (G.arcs[i][j].adj < min) {
                    min = G.arcs[i][j].adj;  // 最小权值
                    a = i;  // 边的一个顶点
                    b = j;  // 边的另一个顶点
                }
            }
        }
        min = G.arcs[a][b].adj = INFINITY;  // 删除上三角中该边，下次不再查找
        if (set[a] != set[b]) { // 边的两顶点不属于同一集合
            printf("%s-%s\n", G.vexs[a], G.vexs[b]);  // 输出该边
            k++;  // 边数+1
            for (i = 0; i < G.vexnum; i++) {
                if (set[i] == set[b]) { // 将顶点b所在集合并入顶点a集合中
                    set[i] = set[a]; 
                }
            }
        }
    }
}

