// C7-3.cpp ����ͼ������ʮ������洢�Ļ�������(14��)

#include "C7-3.h" 
#include "C2-3.h" // ����ͷ���ĵ������������

int LocateVex(OLGraph G, VertexType u)
{ 
    // ������������ض���u������ͼG�е�λ��(���)���粻�����򷵻�-1
    int i;
    for (i = 0; i < G.vexnum; ++i) { // ��ѭ�����Ҹý��
        if (!strcmp(G.xlist[i].data, u)) {
            return i;
        }
    }
    return -1;
}

void CreateGraph(OLGraph &G)
{ 
    // �������������ʮ������洢��ʾ����������ͼG
    int i, j, k;
    int IncInfo;
    ArcBox *p;
    VertexType v1, v2;
    printf("����������ͼ�Ķ�����,����,��ͼ������(��:1, ͼ:0):");
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &IncInfo);
    printf("������%d�������ֵ(<%d���ַ�):\n", G.vexnum, MAX_VERTEX_NAME);
    for (i = 0; i < G.vexnum; ++i) { // �����ͷ����
        scanf("%s", &G.xlist[i].data); // ���붥��ֵ
        G.xlist[i].firstin  = NULL; // ��ʼ���뻡������ͷָ��
        G.xlist[i].firstout = NULL; // ��ʼ������������ͷָ��
    }
    printf("������%d�����Ļ�β�ͻ�ͷ(�ո�Ϊ���):\n", G.arcnum);
    for (k = 0; k < G.arcnum; ++k) { // �������������ʮ������
        scanf("%s%s", &v1, &v2);
        i = LocateVex(G, v1); // ȷ��v1��v2��G�е�λ��
        j = LocateVex(G, v2);
        if (i < 0 || j < 0) { // v1��v2����G�Ķ���
            continue;
        }
        p = (ArcBox *) malloc(sizeof(ArcBox)); // ���������(�ٶ����㹻�ռ�)
        p->data.tailvex = i; // �Ի���㸳ֵ
        p->data.headvex = j;
        p->data.hlink = G.xlist[j].firstin; // ������뻡�ͳ��������ͷ�Ĳ���
        p->tlink = G.xlist[i].firstout;
        G.xlist[j].firstin = (ArcBox1 *) p; // ǿ������ת��
        G.xlist[i].firstout = p;
        if (IncInfo) { // ��
            p->data.info = (InfoType *) malloc(sizeof(InfoType));
            printf("������û���Ȩֵ: ");
            scanf("%d", p->data.info);
        } else { // ͼ
            p->data.info = NULL;
        }
    }
}

void DestroyGraph(OLGraph &G)
{ 
    // ��ʼ����������ͼG����
    // �����������������ͼG
    int i;
    ElemType e;
    for (i = 0; i < G.vexnum; i++) { // �����ж���
        while (G.xlist[i].firstout) { // ����������
            ListDelete(G.xlist[i].firstout, 1, e); // ɾ�����1����㣬��ֵ����e
            if (e.info) { // ��Ȩ
                free(e.info); // �ͷŶ�̬���ɵ�Ȩֵ�ռ�
            }
        }
    }
    G.arcnum = 0;
    G.vexnum = 0;
}

VertexType& GetVex(OLGraph G, int v)
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ����������
    // �������������v��ֵ
    if (v >= G.vexnum || v < 0) {
        exit(ERROR);
    }
    return G.xlist[v].data;
}

Status PutVex(OLGraph &G, VertexType v, VertexType value)
{   
    // ��ʼ����������ͼG���ڣ�v��G��ĳ������
    // �����������v����ֵvalue
    int i;
    i = LocateVex(G, v);
    if (i < 0) { // v����G�Ķ���
        return ERROR;
    }
    strcpy(G.xlist[i].data, value);
    return OK;
}

int FirstAdjVex(OLGraph G, VertexType v)
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ������
    // �������������v�ĵ�һ���ڽӶ������ţ�
    //           ��������G��û���ڽӶ��㣬�򷵻�-1
    int i;
    ArcBox *p;
    i = LocateVex(G, v);
    p = G.xlist[i].firstout; // pָ�򶥵�v�ĵ�1������
    if (p) {
        return p->data.headvex;
    } else {
        return -1;
    }
}

int NextAdjVex(OLGraph G, VertexType v, VertexType w)
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
    // �������������v��(�����w��)��һ���ڽӶ������ţ�
    //           ��w��v�����һ���ڽӶ��㣬�򷵻�-1
    int i, j;
    ArcBox *p;
    i = LocateVex(G, v); // i�Ƕ���v�����
    j = LocateVex(G, w); // j�Ƕ���w�����
    p = G.xlist[i].firstout; // pָ�򶥵�v�ĵ�1������
    while (p && p->data.headvex != j) {
        p = p->tlink;
    }
    if (p) { // w����v�����һ���ڽӶ���
        p = p->tlink; // pָ�������w����һ���ڽӶ���
    }
    if (p) { // ����һ���ڽӶ���
        return p->data.headvex;
    } else {
        return -1;
    }
}

void InsertVex(OLGraph &G, VertexType v)
{ 
    // ��ʼ����������ͼG���ڣ�v������ͼG�ж�������ͬ����
    // ���������������ͼG�������¶���v
    strcpy(G.xlist[G.vexnum].data, v); // ������������
    G.xlist[G.vexnum].firstin  = NULL; // ��ʼ���뻡����
    G.xlist[G.vexnum].firstout = NULL; // ��ʼ����������
    G.vexnum++; // ������+1
}

Status equal(ElemType c1, ElemType c2)
{
    if (c1.headvex == c2.headvex) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Status DeleteVex(OLGraph &G, VertexType v)
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ������
    // ���������ɾ��G�ж���v������صĻ�
    int i, j, k;
    ElemType e1, e2;
    ArcBox *p;
    ArcBox1 *p1, *p2;
    k = LocateVex(G, v); // k�Ƕ���v�����
    if (k < 0) { // v����ͼG�Ķ���
        return ERROR; // ����ɾ������v���뻡
    }
    e1.headvex = k; // e1��ΪLocateElem()�ıȽ�Ԫ��
    for (j = 0; j < G.vexnum; j++) { // ����v���뻡����������ĳ���
        i = LocateElem(G.xlist[j].firstout, e1, equal);
        if (i) { // ����v�Ƕ���j�ĳ���
            ListDelete(G.xlist[j].firstout, i, e2); // ɾ���û���㣬��ֵ����e2
            G.arcnum--; // ����-1
            if (e2.info) {// ��Ȩ
                free(e2.info); // �ͷŶ�̬���ɵ�Ȩֵ�ռ�
            }
        }
    } // ����ɾ������v�ĳ���
    for (j = 0; j < G.vexnum; j++) { // ����v�ĳ���������������뻡
        p1 = G.xlist[j].firstin;
        while (p1&&p1->tailvex != k) {
            p2 = p1;
            p1 = p1->hlink;
        }
        if (p1) { // �ҵ�����v�ĳ���
            if (p1 == G.xlist[j].firstin) { // ���׽��
                G.xlist[j].firstin = p1->hlink; // �뻡ָ��ָ����һ�����
            } else { // �����׽��
                p2->hlink = p1->hlink; // ����������ȥp1��ָ���
            }
            if (p1->info) { // ��Ȩ
                free(p1->info); // �ͷŶ�̬���ɵ�Ȩֵ�ռ�
            }
            free(p1); // �ͷ�p1��ָ���
            G.arcnum--; // ����-1
        }
    }
    for (j = k + 1; j < G.vexnum; j++) { // ���>k�Ķ���������ǰ��
        G.xlist[j-1] = G.xlist[j];
    }
    G.vexnum--; // ��������1
    for (j = 0; j < G.vexnum; j++) { // ������>k��Ҫ��1
        p = G.xlist[j].firstout; // �������
        while (p) {
            if (p->data.tailvex > k) {
                p->data.tailvex--; // ���-1
            }
            if (p->data.headvex > k) {
                p->data.headvex--; // ���-1
            }
            p = p->tlink;
        }
    }
    return OK;
}

Status InsertArc(OLGraph &G, VertexType v, VertexType w)
{ 
    // ��ʼ����������ͼG���ڣ�v��w��G����������
    // �����������G������<v, w>
    int i, j;
    int IncInfo;
    ArcBox *p;
    i = LocateVex(G, v); // ��β�����
    j = LocateVex(G, w); // ��ͷ�����
    if (i < 0 || j < 0) {
        return ERROR;
    }
    p = (ArcBox *) malloc(sizeof(ArcBox)); // �����½��
    p->data.tailvex = i; // ���½�㸳ֵ
    p->data.headvex = j;
    p->data.hlink = G.xlist[j].firstin; // �����뻡�ͳ�������ͷ
    p->tlink = G.xlist[i].firstout;
    G.xlist[j].firstin = (ArcBox1 *) p;
    G.xlist[i].firstout = p;
    G.arcnum++; // ������1
    printf("Ҫ����Ļ��Ƿ��Ȩ(��: 1, ��: 0): ");
    scanf("%d", &IncInfo);
    if (IncInfo) { // ��Ȩ
        p->data.info = (InfoType *) malloc(sizeof(InfoType)); // ��̬����Ȩֵ�ռ�
        printf("������û���Ȩֵ: ");
        scanf("%d", p->data.info);
    } else {
        p->data.info = NULL;
    }
    return OK;
}

Status DeleteArc(OLGraph &G, VertexType v, VertexType w)
{ 
    // ��ʼ����������ͼG���ڣ�v��w��G����������
    // �����������G��ɾ����<v, w>
    int i, j, k;
    ElemType e;
    ArcBox1 *p1, *p2;
    i=LocateVex(G, v); // ��β�����
    j=LocateVex(G, w); // ��ͷ�����
    if (i < 0 || j < 0 || i == j) {
        return ERROR;
    }
    p1 = G.xlist[j].firstin; // p1ָ��w���뻡����
    while (p1 && p1->tailvex != i) { // ʹp1ָ���ɾ���
        p2 = p1;
        p1 = p1->hlink;
    }
    if (p1 == G.xlist[j].firstin) { // �׽���Ǵ�ɾ���
        G.xlist[j].firstin = p1->hlink; // �뻡ָ��ָ����һ�����
    } else { // �׽�㲻�Ǵ�ɾ���
        p2->hlink = p1->hlink; // ����������ȥp1��ָ���(�ý�����ڳ���������)
    }
    e.headvex = j; // ��ɾ�����Ļ�ͷ�������Ϊj��e��ΪLocateElem()�ıȽ�Ԫ��
    k = LocateElem(G.xlist[i].firstout, e, equal); // �ڳ��������е�λ��
    ListDelete(G.xlist[i].firstout, k, e); // �ڳ���������ɾ���ý�㣬��ֵ����e
    if (e.info) { // ��Ȩ
        free(e.info); // �ͷŶ�̬���ɵ�Ȩֵ�ռ�
    }
    G.arcnum--; // ����-1
    return OK;
}

Boolean visited[MAX_VERTEX_NUM]; // ���ʱ�־����
void(*VisitFunc)(VertexType); // ��������

void DFS(OLGraph G, int i) 
{
    ArcBox *p;
    visited[i] = TRUE; // ���ʱ�־������1(�ѱ�����)
    VisitFunc(G.xlist[i].data); // ������i������
    p = G.xlist[i].firstout; // pָ���i������ĳ���
    while (p && visited[p->data.headvex]) { // pû����β�Ҹû���ͷ�����ѱ�����
        p = p->tlink; // ������һ�����
    }
    if (p && !visited[p->data.headvex]) { // �û���ͷ����δ������
        DFS(G, p->data.headvex); // �ݹ����DFS()
    }
}

void DFSTraverse(OLGraph G, void(*Visit)(VertexType))
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ�����㣬Visit�Ƕ����Ӧ�ú���
    // ����������ӵ�1�������𣬰�������ȵݹ��������ͼG��
    //           ����ÿ��������ú���Visitһ���ҽ�һ��
    int v;
    VisitFunc = Visit;
    for (v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE; // ���ʱ�־�����ó�ֵ(δ������)
    }
    for (v = 0; v < G.vexnum; v++) { // �����0��ʼ����������δ�����ʹ��Ķ���
        if (!visited[v]) {
            DFS(G, v);
        }
    }
}

#include "C3-2.h" // �����еĴ洢�ṹ

void BFSTraverse(OLGraph G, void(*Visit)(VertexType))
{ 
    // ��ʼ����������ͼG���ڣ�Visit�Ƕ����Ӧ�ú������㷨7.6
    // ����������ӵ�1�������𣬰�������ȷǵݹ��������ͼG��
    //           ����ÿ��������ú���Visitһ���ҽ�һ��
    int v, u, w;
    LinkQueue Q;
    for (v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE;
    }
    InitQueue(Q);
    for (v = 0; v < G.vexnum; v++) {
        if (!visited[v]) {
            visited[v] = TRUE;
            Visit(G.xlist[v].data);
            EnQueue(Q, v);
            while (!QueueEmpty(Q)) {
                DeQueue(Q, u);
                w = FirstAdjVex(G, G.xlist[u].data);
                while (w>=0) {
                    if (!visited[w]) { // wΪu����δ���ʵ��ڽӶ�������
                        visited[w] = TRUE;
                        Visit(G.xlist[w].data);
                        EnQueue(Q, w);
                    }
                    w = NextAdjVex(G, G.xlist[u].data, G.xlist[w].data);
                }
            }
        }
    }
}

void Display(OLGraph G)
{ 
    // ������������ͼG
    int i;
    ArcBox *p;
    printf("��%d������: ", G.vexnum);
    for (i = 0; i < G.vexnum; i++) { // �������
        printf("%s ", G.xlist[i].data);
    }
    printf("\n%d����:\n", G.arcnum);
    for (i = 0; i < G.vexnum; i++) { // ˳�����������
        p = G.xlist[i].firstout;
        while (p) {
            printf("%s��%s ", G.xlist[i].data, G.xlist[p->data.headvex].data);
            if (p->data.info) { // �û��������Ϣ(Ȩֵ)
                printf("Ȩֵ: %d ", *p->data.info);
            }
            p = p->tlink;
        }
        printf("\n");
    }
}
