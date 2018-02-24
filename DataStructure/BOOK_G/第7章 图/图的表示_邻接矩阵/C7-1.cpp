// C7-1.cpp ͼ������(�ڽӾ���)�洢�Ļ�������(17��)

#include "C7-1.h"

Boolean visited[MAX_VERTEX_NUM]; // ���ʱ�־����(ȫ����)

int LocateVex(MGraph G, VertexType v)
{ 
    // ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����
    // �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ�ã����򷵻�-1
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
    // �����������������(�ڽӾ���)��ʾ�������ļ�����û�������Ϣ������ͼG
    int i, j, k;
    char filename[13];
    VertexType va, vb;
    FILE *graphlist;
    printf("�����������ļ���(f7-1.txt��f7-2.txt)��");
    scanf("%s", filename);
    graphlist = fopen(filename, "r"); // �������ļ�������graphlist��ʾ
    fscanf(graphlist, "%d", &G.vexnum);
    fscanf(graphlist, "%d", &G.arcnum);
    for (i = 0; i < G.vexnum; ++i) { // ���춥������
        fscanf(graphlist, "%s", G.vexs[i]);
    }
    for (i = 0; i < G.vexnum; ++i) { // ��ʼ���ڽӾ���
        for (j = 0; j < G.vexnum; ++j) {
            G.arcs[i][j].adj  = 0; // ͼ
            G.arcs[i][j].info = NULL; // û�������Ϣ
        }
    }
    for (k = 0; k < G.arcnum; ++k) {
        fscanf(graphlist, "%s%s", va, vb);
        i = LocateVex(G, va);
        j = LocateVex(G, vb);
        G.arcs[i][j].adj = G.arcs[j][i].adj = 1; // ����ͼ
    }
    fclose(graphlist); // �ر������ļ�
    G.kind = UDG;
}

void CreateFUDN(MGraph &G)
{ 
    // �����������������(�ڽӾ���)��ʾ�������ļ�����û�������Ϣ��������G
    int i, j, k, w;
    char filename[13];
    VertexType va, vb;
    FILE *graphlist;
    printf("�����������ļ�����");
    scanf("%s", filename);
    graphlist = fopen(filename, "r"); // �������ļ�������graphlist��ʾ
    fscanf(graphlist, "%d", &G.vexnum);
    fscanf(graphlist, "%d", &G.arcnum);
    for (i = 0; i < G.vexnum; ++i) { // ���춥������
        fscanf(graphlist, "%s", G.vexs[i]);
    }
    for (i = 0; i < G.vexnum; ++i) { // ��ʼ���ڽӾ���
        for (j = 0; j < G.vexnum; ++j) {
            G.arcs[i][j].adj  = INFINITY; // ��
            G.arcs[i][j].info = NULL; // û�������Ϣ
        }
    }
    for (k = 0; k < G.arcnum; ++k) {
        fscanf(graphlist, "%s%s%d", va, vb, &w);
        i = LocateVex(G, va);
        j = LocateVex(G, vb);
        G.arcs[i][j].adj = G.arcs[j][i].adj = w; // ������
    }
    fclose(graphlist); // �ر������ļ�
    G.kind = UDN;
}


void CreateGraph(MGraph &G)
{ 
    // �����������������(�ڽӾ���)��ʾ��������ͼG
    int i, j, k, arcnum;
    VertexType va, vb;

    printf("������ͼG������(����ͼ:0,������:1,����ͼ:2,������:3): ");
    scanf("%d", &G.kind);
    printf("������ͼ�Ķ������ͱ���(�Կո���Ϊ���): ");
    scanf("%d%d", &G.vexnum, &arcnum);
    if (G.vexnum >= MAX_VERTEX_NUM - 1) {
        // �����붥��������ͼG����������������������Ϊ������
        G.vexnum = MAX_VERTEX_NUM - 1;
    }
    printf("������%d�������ֵ(����%d���ַ�):\n", G.vexnum, MAX_NAME);
    for (i = 0; i < G.vexnum; ++i) { // ���춥������
        scanf("%s", G.vexs[i]);
    }
    for (i = 0; i < G.vexnum; ++i) { // ��ʼ���ڽӾ���
        for (j = 0; j < G.vexnum; ++j) {
            if (G.kind % 2) { // ��
                G.arcs[i][j].adj  = INFINITY; 
            } else { // ͼ
                G.arcs[i][j].adj  = 0; 
            }
            G.arcs[i][j].info = NULL;
        }
    }
    G.arcnum = 0;
    printf("������%d�����Ļ�β ��ͷ(�Կո���Ϊ���): \n", arcnum);
    for (k = 0; k < arcnum; ++k) { // �������ӻ�
        scanf("%s%s", va, vb);
        InsertArc(G, va, vb);
    }
}

void DestroyGraph(MGraph &G)
{ 
    // ��ʼ������ͼG����
    // �������������ͼG
    int i, j, k = 0;
    if (G.kind % 2) { // ��
        k = INFINITY; // kΪ������֮���ޱ߻�ʱ�ڽӾ���Ԫ�ص�ֵ
    }
    for (i = 0; i < G.vexnum; i++) { // �ͷŻ���ߵ������Ϣ(����еĻ�)
        if (G.kind < 2) { // ����
            for (j = 0; j < G.vexnum; j++) {
                if (G.arcs[i][j].adj != k) { // �л�
                    if (G.arcs[i][j].info) { // �������Ϣ
                        free(G.arcs[i][j].info);
                        G.arcs[i][j].info = NULL;
                    }
                }
            }
        } else { // ����
            for (j = i + 1; j < G.vexnum; j++) { // ֻ��������
                if (G.arcs[i][j].adj != k) { // �б�
                    if(G.arcs[i][j].info) { // �������Ϣ
                        free(G.arcs[i][j].info);
                        G.arcs[i][j].info = G.arcs[j][i].info = NULL;
                    }
                }
            }
        }
    }
    G.vexnum = 0; // ������Ϊ0
    G.arcnum = 0; // ����Ϊ0
}

VertexType& GetVex(MGraph G, int v)
{ 
    // ��ʼ������ͼG���ڣ�v��G��ĳ����������
    // �������������v��ֵ
    if (v >= G.vexnum || v < 0) {
        exit(ERROR);
    }
    return G.vexs[v];
}

Status PutVex(MGraph &G, VertexType v, VertexType value)
{ 
    // ��ʼ������ͼG���ڣ�v��G��ĳ������
    // �����������v����ֵvalue
    int k;
    k = LocateVex(G, v); // kΪ����v��ͼG�е����
    if (k < 0) {
        return ERROR;
    }
    strcpy(G.vexs[k], value);
    return OK;
}

int FirstAdjVex(MGraph G, VertexType v)
{ 
    // ��ʼ������ͼG���ڣ�v��G��ĳ������
    // �������������v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ��㣬�򷵻�-1
    int i, j = 0, k;
    k = LocateVex(G, v); // kΪ����v��ͼG�е����
    if (k < 0) {  // ���㲻����
        return -1; 
    }
    if (G.kind % 2) { // ��
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
    // ��ʼ������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
    // �������������v��(�����w��)��һ���ڽӶ������ţ���w��v�����һ���ڽӶ��㣬�򷵻�-1
    int i, j = 0, k1, k2;
    k1 = LocateVex(G, v); // k1Ϊ����v��ͼG�е����
    k2 = LocateVex(G, w); // k2Ϊ����w��ͼG�е����
    if (k1 < 0 || k2 < 0) {  // ���㲻����
        return -1; 
    }
    if (G.kind % 2) { // ��
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
    // ��ʼ������ͼG���ڣ�v��ͼG�ж�������ͬ����
    // �����������ͼG�������¶���v
    int i, j = 0;
    if (G.vexnum >= MAX_VERTEX_NUM - 1) {
        // �������Ѵ�����������򲻲���
        return;
    }
    if (G.kind % 2) { // ��
        j = INFINITY;
    }
    strcpy(G.vexs[G.vexnum], v); // �����¶�������
    for (i = 0; i <= G.vexnum; i++) {
        // ��ʼ�������С��������ڽӾ����ֵ(�ޱ߻�)
        G.arcs[G.vexnum][i].adj = j;
        G.arcs[i][G.vexnum].adj = j;
        // ��ʼ�������Ϣָ��
        G.arcs[G.vexnum][i].info = NULL; 
        G.arcs[i][G.vexnum].info = NULL; 
    }
    G.vexnum++; // ͼG�Ķ�������1
}

Status DeleteVex(MGraph &G, VertexType v)
{ 
    // ��ʼ������ͼG���ڣ�v��G��ĳ������
    // ���������ɾ��G�ж���v������صĻ�
    int i, j, k;
    VRType m = 0;
    if (G.kind % 2) { // ��
        m = INFINITY;
    }
    k = LocateVex(G, v); // kΪ��ɾ������v�����
    if (k < 0) { // v����ͼG�Ķ���
        return ERROR;
    }
    for (j = 0; j < G.vexnum; j++) {
        if (G.arcs[j][k].adj != m) { // ���뻡���
            if (G.arcs[j][k].info) { // �������Ϣ
                free(G.arcs[j][k].info); // �ͷ������Ϣ
            }
            G.arcnum--; // �޸Ļ���
        }
    }
    if (G.kind < 2) { // ����
        for (j = 0; j < G.vexnum; j++) {
            if (G.arcs[k][j].adj != m) { // �г���
                if (G.arcs[k][j].info) { // �������Ϣ
                    free(G.arcs[k][j].info); // �ͷ������Ϣ
                }
                G.arcnum--; // �޸Ļ���
            }
        }
    }
    for (j = k + 1; j < G.vexnum; j++) { // ���k����Ķ�����������ǰ��
        strcpy(G.vexs[j - 1], G.vexs[j]);
    }
    for (i = 0; i < G.vexnum; i++) {
        for (j = k + 1; j < G.vexnum; j++) {
            G.arcs[i][j - 1] = G.arcs[i][j]; // �ƶ���ɾ������֮�ҵľ���Ԫ��
        }
    }
    for(i = 0; i < G.vexnum; i++) {
        for(j = k + 1; j < G.vexnum; j++) {
            G.arcs[j - 1][i] = G.arcs[j][i]; // �ƶ���ɾ������֮�µľ���Ԫ��
        }
    }
    G.vexnum--; // ����ͼ�Ķ�����
    return OK;
}

Status InsertArc(MGraph &G, VertexType v, VertexType w)
{ 
    // ��ʼ������ͼG���ڣ�v��w��G����������
    // �����������G������<v,w>����G������ģ�������Գƻ�<w,v>
    int i, l, v1, w1;
    char s[MAX_INFO];
    v1 = LocateVex(G, v); // β
    w1 = LocateVex(G, w); // ͷ
    if (v1 < 0 || w1 < 0){
        return ERROR;
    }
    G.arcnum++; // ���������1
    if (G.kind % 2) { // ��
        printf("������˻���ߵ�Ȩֵ: ");
        scanf("%d", &G.arcs[v1][w1].adj);
    } else { // ͼ
        G.arcs[v1][w1].adj = 1;
    }
    printf("�Ƿ��иû���ߵ������Ϣ(0:�� 1:��): ");
    scanf("%d", &i);
    fflush(stdin); // ����������в����Ļس��ַ�
    if (i) {
        printf("������û���ߵ������Ϣ(����%d���ַ�)��", MAX_INFO);
        gets(s);
        l = strlen(s);
        if (l) {
            G.arcs[v1][w1].info = (char *)malloc((l + 1) * sizeof(char));
            strcpy(G.arcs[v1][w1].info, s);
        }
    }
    if (G.kind > 1) { // ����
        G.arcs[w1][v1].adj  = G.arcs[v1][w1].adj;
        G.arcs[w1][v1].info = G.arcs[v1][w1].info; // ָ��ͬһ�������Ϣ
    }
    return OK;
}

Status DeleteArc(MGraph &G, VertexType v, VertexType w)
{ 
    // ��ʼ������ͼG���ڣ�v��w��G����������
    // �����������G��ɾ����<v,w>����G������ģ���ɾ���Գƻ�<w,v>
    int v1, w1, j = 0;
    if (G.kind % 2) { // ��
        j = INFINITY;
    }
    v1 = LocateVex(G, v); // β
    w1 = LocateVex(G, w); // ͷ
    if (v1 < 0 || w1 < 0) { // v1��w1��ֵ���Ϸ�
        return ERROR;
    }
    G.arcs[v1][w1].adj = j;
    if (G.arcs[v1][w1].info) { // ��������Ϣ
        free(G.arcs[v1][w1].info);
        G.arcs[v1][w1].info = NULL;
    }
    if (G.kind >= 2) { // ����ɾ���Գƻ�<w,v>
        G.arcs[w1][v1].adj  = j;
        G.arcs[w1][v1].info = NULL;
    }
    G.arcnum--; // ����-1
    return OK;
}

void DFS(MGraph G, int v, void (*Visit)(VertexType))
{ 
    // ����������ӵ�v����������ݹ��������ȱ���ͼG
    int w;
    visited[v] = TRUE; // ���÷��ʱ�־ΪTRUE(�ѷ���)
    Visit(G.vexs[v]); // ���ʵ�v������
    w = FirstAdjVex(G, G.vexs[v]);
    while (w >= 0) {
        if (!visited[w]) {
            DFS(G, w, Visit); // ��v����δ���ʵ����Ϊw���ڽӶ���ݹ����DFS
        }
        w = NextAdjVex(G, G.vexs[v], G.vexs[w]);
    }
}

void DFSTraverse(MGraph G, void (*Visit)(VertexType))
{ 
    // ��ʼ������ͼG���ڣ�Visit�Ƕ����Ӧ�ú���
    // ����������ӵ�1��������������ȱ���ͼG������ÿ��������ú���Visitһ���ҽ�һ��
    int v;
    for (v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE; // ���ʱ�־�����ʼ��(δ������)
    }
    for (v = 0; v < G.vexnum; v++) {
        if (!visited[v]) {
            DFS(G, v, Visit); // ����δ���ʵĶ���v����DFS
        }
    }
}

void BFSTraverse(MGraph G, void (*Visit)(VertexType))
{ 
    // ��ʼ������ͼG���ڣ�Visit�Ƕ����Ӧ�ú���
    // ����������ӵ�1�������𣬰�������ȷǵݹ����ͼG,����ÿ��������ú���Visitһ���ҽ�һ��
    int v, u, w;
    LinkQueue Q; // ʹ�ø�������Q�ͷ��ʱ�־����visited
    for (v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE; // �ó�ֵ
    }
    InitQueue(Q); // �ÿյĸ�������Q
    for (v = 0; v < G.vexnum; v++) {
        if (!visited[v]) { // v��δ����
            visited[v] = TRUE; // ���÷��ʱ�־ΪTRUE(�ѷ���)
            Visit(G.vexs[v]);
            EnQueue(Q, v); // v�����
            while (!QueueEmpty(Q)) { // ���в���
                DeQueue(Q, u); // ��ͷԪ�س��Ӳ���Ϊu
                w = FirstAdjVex(G, G.vexs[u]);
                while (w >= 0) {
                    if (!visited[w]) { // wΪu����δ���ʵ��ڽӶ�������
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
    // �������������ڽӾ���洢��ʾ��ͼG
    int i, j;
    char s[7];
    switch (G.kind) {
        case DG: 
            strcpy(s,"����ͼ");
            break;
        case DN: 
            strcpy(s,"������");
            break;
        case UDG:
            strcpy(s,"����ͼ");
            break;
        case UDN:
            strcpy(s,"������");
    }
    printf("%d������%d���߻򻡵�%s������������: ", G.vexnum, G.arcnum, s);
    for (i = 0; i < G.vexnum; ++i) { // ���G.vexs
        printf("%s ", G.vexs[i]);
    }
    printf("\nG.arcs.adj:\n"); // ���G.arcs.adj
    for (i = 0; i < G.vexnum; i++) {
        for (j = 0; j < G.vexnum; j++) {
            printf("%11d", G.arcs[i][j].adj);
        }
        printf("\n");
    }
    printf("G.arcs.info:\n"); // ���G.arcs.info
    printf("����1(��β) ����2(��ͷ) �ñ߻򻡵���Ϣ��\n");
    for (i = 0; i < G.vexnum; i++) {
        if (G.kind < 2) { // ����
            for (j = 0; j < G.vexnum; j++) {
                if (G.arcs[i][j].adj > 0 && G.arcs[i][j].adj < INFINITY) {
                    printf("%5s   %11s       %s\n", G.vexs[i], G.vexs[j], G.arcs[i][j].info);
                }
            }
        } else { // ����,���������
            for (j = i + 1; j < G.vexnum; j++) {
                if (G.arcs[i][j].adj > 0 && G.arcs[i][j].adj < INFINITY) {
                    printf("%5s   %11s      %s\n", G.vexs[i], G.vexs[j], G.arcs[i][j].info);
                }
            }
        }
    }
}

// ͼ��صĸ߼��㷨

typedef struct
{ 
    // ��¼�Ӷ��㼯U��V-U�Ĵ�����С�ıߵĸ������鶨��
    // ����MiniSpanTree_PRIM����
    VertexType adjvex;
    VRType     lowcost;
} minside[MAX_VERTEX_NUM];

int minimum(minside SZ, MGraph G)
{ 
    // �����������SZ.lowcost����С��ֵ������������SZ�е����
    int i = 0, j, k, min; 
    while (!SZ[i].lowcost) {
        i++; 
    }
    min = SZ[i].lowcost;  // ��һ����Ϊ0��ֵ
    k = i; 
    for (j = i+1; j < G.vexnum; j++) {
        if (SZ[j].lowcost > 0 && min > SZ[j].lowcost) { // �ҵ��µĴ���0����Сֵ
            min = SZ[j].lowcost; 
            k   = j; 
        }
    }
    return k; 
}

void MiniSpanTree_PRIM(MGraph G, VertexType u)
{ 
    // ���������������ķ�㷨�ӵ�u���������������G����С������T�����T�ĸ�����
    int i, j, k; 
    minside closedge; 
    k = LocateVex(G, u); 
    for (j = 0; j < G.vexnum; ++j) { // ���������ʼ��
        strcpy(closedge[j].adjvex, u); 
        closedge[j].lowcost = G.arcs[k][j].adj; 
    }
    closedge[k].lowcost = 0;  // ��ʼ, U = {u}
    printf("��С�����������ĸ�����Ϊ:\n"); 
    for (i = 1; i < G.vexnum; ++i) {
        // ѡ������G.vexnum-1������
        k = minimum(closedge, G);  // ���T����һ����㣺��k����
        printf("(%s-%s)\n", closedge[k].adjvex, G.vexs[k]);  // ����������ı�
        closedge[k].lowcost = 0;  // ��k���㲢��U��
        for (j = 0; j < G.vexnum; ++j) {
            if (G.arcs[k][j].adj < closedge[j].lowcost) {
                // �¶��㲢��U��������ѡ����С��
                strcpy(closedge[j].adjvex, G.vexs[k]); 
                closedge[j].lowcost = G.arcs[k][j].adj; 
            }
        }
    }
}


void ShortestPath_DIJ(MGraph G, int v0, PathMatrix_DIJ P, ShortPathTable D)
{ 
    // �����������Dijkstra�㷨��������G��v0���㵽���ඥ��v�����·��P[v]����Ȩ����
    //           D[v]����P[v][w]ΪTRUE����w�Ǵ�v0��v��ǰ������·���ϵĶ��㡣
    //           final[v]ΪTRUE���ҽ���v��S�����Ѿ���ô�v0��v�����·��
    int v, w, i, j, min; 
    Status final[MAX_VERTEX_NUM];  // ��������Ϊ���ʾ�ö��㵽v0����̾������������ֵΪ��
    for (v = 0; v < G.vexnum; ++v) {
        final[v] = FALSE;  // ���ֵ
        D[v] = G.arcs[v0][v].adj;  // D[]���v0��v����̾��룬��ֵΪv0��v��ֱ�Ӿ���
        for (w = 0; w < G.vexnum; ++w) {
            P[v][w] = FALSE;  // ��P[][]��ֵΪFALSE��û��·��
        }
        if (D[v] < INFINITY) { // v0��v��ֱ��·��
            P[v][v0] = P[v][v] = TRUE;  // һά����p[v][]��ʾԴ��v0��v���·��ͨ���Ķ���
        }
    }
    D[v0] = 0;  // v0��v0����Ϊ0
    final[v0] = TRUE;  // v0���㲢��S��
    for (i = 1; i < G.vexnum; ++i) { // ����G.vexnum-1������
        // ��ʼ��ѭ����ÿ�����v0��ĳ������v�����·��������v����S��
        min = INFINITY;  // ��ǰ��֪��v0�����������룬���ֵΪ��
        for (w = 0; w < G.vexnum; ++w) { // �����ж�����
            if (!final[w] && D[w] < min) { //��S��֮��Ķ���������v0����Ķ��㣬�����丳��v�����븳��min
                v   = w; 
                min = D[w]; 
            }
        }
        final[v] = TRUE;  // ��v����S��
        for (w = 0; w < G.vexnum; ++w) { // �����²���Ķ��㣬���²���S���Ķ��㵽v0�ľ����·������
            if (!final[w] && min < INFINITY && 
                G.arcs[v][w].adj < INFINITY && 
                (min + G.arcs[v][w].adj < D[w])) {
                // w������S����v0��v��w�ľ��룼Ŀǰv0��w�ľ���
                D[w] = min + G.arcs[v][w].adj;  // ����D[w]
                for (j = 0; j < G.vexnum; ++j)  { // �޸�P[w]��v0��w�����Ķ������v0��v�����Ķ����ټ��϶���w
                    P[w][j] = P[v][j]; 
                }
                P[w][w] = TRUE; 
            }
        }
    }
}


void ShortestPath_FLOYD(MGraph G, PathMatrix_FLOYD P, DistancMatrix D)
{ 
    // �����������Floyd�㷨��������G�и��Զ���v��w֮������·��P[v][w]�����Ȩ����D[v][w]
    //           ��P[v][w][u]ΪTRUE����u�Ǵ�v��w��ǰ������·���ϵĶ���
    int u, v, w, i; 
    for (v = 0; v < G.vexnum; v++) { // ���Խ��֮���ʼ��֪·��������
        for (w = 0; w < G.vexnum; w++) {
            D[v][w] = G.arcs[v][w].adj;  // ����v������w��ֱ�Ӿ���
            for (u = 0; u < G.vexnum; u++) {
                P[v][w][u] = FALSE;  // ·�������ֵ
            }
            if (D[v][w] < INFINITY) { // ��v��w��ֱ��·��
                P[v][w][v] = P[v][w][w] = TRUE;  // ��v��w��·������v��w����
            }
        }
    }
    for (u = 0; u < G.vexnum; u++) {
        for (v = 0; v < G.vexnum; v++) {
            for (w = 0; w < G.vexnum; w++) {
                if (D[v][u] < INFINITY && D[u][w] < INFINITY && 
                    D[v][u]+D[u][w] < D[v][w]) {
                    // ��v��u��w��һ��·������
                    D[v][w] = D[v][u] + D[u][w];  // ������̾���
                    for (i = 0; i < G.vexnum; i++)
                        P[v][w][i] = P[v][u][i] || P[u][w][i];  // ��v��w��·��������v��u�ʹ�u��w������·��
                }
            }
        }
    }
}

void Kruskal(MGraph G)
{
    // �����������³˹�����㷨��������ͨ������С������
    int set[MAX_VERTEX_NUM], i, j; 
    int k = 0, a = 0, b = 0, min = G.arcs[a][b].adj; 
    for (i = 0; i < G.vexnum; i++) {
        set[i] = i;  // ��̬��������ֱ����ڸ�������
    }
    printf("��С�����������ĸ�����Ϊ:\n"); 
    while (k < G.vexnum - 1) { // ��С�������ı���С�ڶ�����-1
        // Ѱ����СȨֵ�ı�
        for (i = 0; i < G.vexnum; ++i) {
            for (j = i + 1; j < G.vexnum; ++j) { // ��������ֻ�������ǲ���
                if (G.arcs[i][j].adj < min) {
                    min = G.arcs[i][j].adj;  // ��СȨֵ
                    a = i;  // �ߵ�һ������
                    b = j;  // �ߵ���һ������
                }
            }
        }
        min = G.arcs[a][b].adj = INFINITY;  // ɾ���������иñߣ��´β��ٲ���
        if (set[a] != set[b]) { // �ߵ������㲻����ͬһ����
            printf("%s-%s\n", G.vexs[a], G.vexs[b]);  // ����ñ�
            k++;  // ����+1
            for (i = 0; i < G.vexnum; i++) {
                if (set[i] == set[b]) { // ������b���ڼ��ϲ��붥��a������
                    set[i] = set[a]; 
                }
            }
        }
    }
}

