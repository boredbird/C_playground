// C7-2.cpp ͼ���ڽӱ�洢�Ļ�������(15��)

#include "C7-2.h" 
#include "C2-3.h" 

int LocateVex(ALGraph G, VertexType u)
{ 
    // ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����
    // �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ�ã����򷵻�-1
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
    // ��������������ڽӱ�洢�ṹ������û�������Ϣͼ����G(��һ����������4��ͼ)
    int i, k, arcnum; 
    VertexType va, vb; // ���ӱ߻򻡵�2����
    printf("������ͼ������(����ͼ:0, ������:1, ����ͼ:2, ������:3): ");
    scanf("%d", &G.kind);
    printf("������ͼ�Ķ������ͱ���(�Կո���Ϊ���): ");
    scanf("%d%d", &G.vexnum, &arcnum);
    printf("������%d�������ֵ(����%d���ַ�):\n", G.vexnum, MAX_NAME);
    for (i = 0; i < G.vexnum; ++i) { // ���춥������
        scanf("%s", G.vertices[i].data);
        G.vertices[i].firstarc = NULL; // ��ʼ����ö����йصĳ�������
    }
    G.arcnum = 0;
    printf("������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n");
    for (k = 0; k < arcnum; ++k) { // �������ӻ�
        scanf("%s%s", va, vb);
        InsertArc(G, va, vb);
    }
}

void CreateGraphF(ALGraph &G)
{ 
    // ��������������ڽӱ�洢�ṹ�����ļ�����û�������Ϣͼ����G(��һ����������4��ͼ)
    int i, j, k, w; // w��Ȩֵ
    VertexType va, vb; // ���ӱ߻򻡵�2����
    ElemType e;
    char filename[13];
    FILE *graphlist;
    printf("�����������ļ���(f7-1.txt��f7-2.txt)��");
    scanf("%s",filename);
    printf("������ͼ������(����ͼ:0,������:1,����ͼ:2,������:3): ");
    scanf("%d", &G.kind);
    graphlist = fopen(filename, "r"); // �Զ��ķ�ʽ�������ļ�������graphlist��ʾ
    fscanf(graphlist, "%d", &G.vexnum);
    fscanf(graphlist, "%d", &G.arcnum);
    for (i = 0; i < G.vexnum; ++i) { // ���춥������
        fscanf(graphlist, "%s", G.vertices[i].data);
        G.vertices[i].firstarc = NULL; // ��ʼ����ö����йصĳ�������
    }
    for (k = 0; k < G.arcnum; ++k) { // ������ػ�����
        if (G.kind % 2) { // ��
            fscanf(graphlist, "%d%s%s", &w, va, vb);
        } else { // ͼ
            fscanf(graphlist, "%s%s", va, vb);
        }
        i = LocateVex(G, va); // ��β
        j = LocateVex(G, vb); // ��ͷ
        if (i < 0 || j < 0) { // ������㲻���ڣ�����������ѭ��
            continue;
        }
        e.info = NULL; // ���������e��ֵ��ͼ��Ȩ
        e.adjvex = j; // ��ͷ
        if (G.kind % 2) { // ��
            e.info = (int *)malloc(sizeof(int)); // ��̬���ɴ��Ȩֵ�Ŀռ�
            *(e.info) = w;
        }
        ListInsert(G.vertices[i].firstarc, 1, e); // ���ڵ�i��Ԫ��(����)�ı�ͷ
        if (G.kind >= 2) { // ����ͼ������������2�����㣬�����ڵ�j��Ԫ��(�뻡)�ı�ͷ
            e.adjvex = i; // e.info���䣬�����ٸ�ֵ
            ListInsert(G.vertices[j].firstarc, 1, e); // ���ڵ�j��Ԫ�صı�ͷ
        }
    }
    fclose(graphlist); // �ر������ļ�
}

void DestroyGraph(ALGraph &G)
{ 
    // ��ʼ������ͼG����
    // �������������ͼG
    int i;
    ElemType e;
    for (i = 0; i < G.vexnum; ++i) { // �������ж���
        if (G.kind % 2) { // ��
            while (G.vertices[i].firstarc) { // ��Ӧ�Ļ����������
                ListDelete(G.vertices[i].firstarc, 1, e); // ɾ������ĵ�1����㣬����ֵ����e
                if (G.kind >= 2 && e.adjvex > i) { // ��֤��������̬���ɵ�Ȩֵ�ռ�ֻ�ͷ�1��
                    free(e.info);
                }
            }
        } else { // ͼ
            DestroyList(G.vertices[i].firstarc); // ���ٻ��������
        }
    }
    G.vexnum=0; // ������Ϊ0
    G.arcnum=0; // �߻���Ϊ0
}

VertexType& GetVex(ALGraph G, int v)
{ 
    // ��ʼ������ͼG���ڣ�v��G��ĳ����������
    // �������������v��ֵ
    if (v >= G.vexnum || v < 0) {
        printf("���%d������Χ��\n", v);
        exit(ERROR);
    }
    return G.vertices[v].data;
}

Status PutVex(ALGraph &G, VertexType v, VertexType value)
{ 
    // ��ʼ������ͼG���ڣ�v��G��ĳ������
    // �����������v����ֵvalue
    int i = LocateVex(G, v);
    if (LocateVex(G, value) >= 0) { // ��������Ѵ���
        printf("����%s�Ѵ��ڣ�\n", value);
        return ERROR;
    }
    if (i < 0) {
        printf("����%s�����ڣ�\n", v);
        return ERROR;
    }
    strcpy(G.vertices[i].data, value);
    return OK;
}

int FirstAdjVex(ALGraph G, VertexType v)
{ 
    // ��ʼ������ͼG���ڣ�v��G��ĳ������
    // �������������v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ��㣬�򷵻�-1
    LinkList p;
    int v1;
    v1 = LocateVex(G, v); // v1Ϊ����v��ͼG�е����
    if (v1 < 0) { // ����v������
        printf("����%s�����ڣ�\n", v);
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
    // DeleteArc()��DeleteVex()��NextAdjVex()Ҫ���õĺ���
    if (a.adjvex == b.adjvex) {
        return OK;
    } else {
        return ERROR;
    }
}

int NextAdjVex(ALGraph G, VertexType v, VertexType w)
{ 
    // ��ʼ������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
    // �������������v��(�����w��)��һ���ڽӶ������š���w��v�����һ���ڽӵ㣬�򷵻�-1
    LinkList p, p1; // p1��Point()����������ָ��
    ElemType e;
    int v1;
    v1 = LocateVex(G, v); // v1Ϊ����v��ͼG�е����
    if (v1 < 0) { // ����v������
        printf("����%s�����ڣ�\n", v);
        return -1;
    }
    e.adjvex = LocateVex(G, w); // e.adjvexΪ����w��ͼG�е����
    p = Point(G.vertices[v1].firstarc, e, equalvex, p1); // pָ�򶥵�v���������ڽӶ���Ϊw�Ľ��
    if (!p || !p->next) { // û�ҵ�w��w�����һ���ڽӵ�
        return -1;
    } else { // p->data.adjvex==w
        return p->next->data.adjvex; // ����v��(�����w��)��һ���ڽӶ�������
    }
}

void InsertVex(ALGraph &G, VertexType v)
{ 
    // ��ʼ������ͼG���ڣ�v��ͼ�ж�������ͬ����
    // �����������ͼG�������¶���v(�������붥����صĻ�������InsertArc()ȥ��)
    if (G.vexnum == MAX_VERTEX_NUM || LocateVex(G, v) >= 0) { // ��������Ѵ���
        printf("�����Ѵ��ڣ�\n");
        return;
    }
    strcpy(G.vertices[G.vexnum].data, v); // �����¶�������
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum++; // ͼG�Ķ�������1
}

Status DeleteVex(ALGraph &G, VertexType v)
{ 
    // ��ʼ������ͼG���ڣ�v��G��ĳ������
    // ���������ɾ��G�ж���v������صĻ�
    int i, j, k;
    ElemType e;
    LinkList p, p1;
    j = LocateVex(G, v); // j�Ƕ���v�����
    if (j < 0) { // v����ͼG�Ķ���
        return ERROR;
    }
    i = ListLength(G.vertices[j].firstarc); // ��vΪ���ȵĻ������
    G.arcnum -= i; // �߻���-i
    if (G.kind % 2) { // ��
        while (G.vertices[j].firstarc) { // ��Ӧ�Ļ����������
            ListDelete(G.vertices[j].firstarc, 1, e); // ɾ������ĵ�1����㣬����ֵ����e
            free(e.info); // �ͷŶ�̬���ɵ�Ȩֵ�ռ�
        }
    } else { // ͼ
            DestroyList(G.vertices[j].firstarc); // ���ٻ��������
    }
    G.vexnum--; // ��������1
    for (i = j; i < G.vexnum; i++) { // ����v����Ķ���ǰ��
        G.vertices[i] = G.vertices[i + 1];
    }
    for (i = 0; i < G.vexnum; i++) { // ɾ����vΪ��ȵĻ�����ұ�Ҫʱ�޸ı���Ķ���λ��ֵ
        e.adjvex = j;
        p = Point(G.vertices[i].firstarc, e, equalvex, p1); 
        if (p) { // ����i���ڽӱ�����vΪ��ȵĽ��
            if (p1) { // p1ָ��p��ָ����ǰ��
                p1->next = p->next; // ��������ɾ��p��ָ���
            } else { // pָ����Ԫ���
                G.vertices[i].firstarc = p->next; // ͷָ��ָ����һ���
            }
            if (G.kind < 2) { // ����
                G.arcnum--; // �߻���-1
                if (G.kind == 1) { // ������
                    free(p->data.info); // �ͷŶ�̬���ɵ�Ȩֵ�ռ�
                }
            }
            free(p); // �ͷ�vΪ��ȵĽ��
        }
        for (k = j + 1; k <= G.vexnum; k++) { // ����adjvex��>j�Ľ�㣬�����-1
            e.adjvex = k;
            p = Point(G.vertices[i].firstarc, e, equalvex, p1); 
            if (p) {
                    p->data.adjvex--; // ���-1(��Ϊǰ��)
            }
        }
    }
    return OK;
}

Status InsertArc(ALGraph &G, VertexType v, VertexType w)
{ 
    // ��ʼ������ͼG���ڣ�v��w��G����������
    // �����������G������<v,w>����G������ģ�������Գƻ�<w,v>
    ElemType e;
    int i, j;
    i = LocateVex(G, v); // ��β��ߵ����
    j = LocateVex(G, w); // ��ͷ��ߵ����
    if (i < 0 || j < 0) {
        return ERROR;
    }
    G.arcnum++; // ͼG�Ļ���ߵ���Ŀ��1
    e.adjvex = j;
    e.info = NULL; // ��ֵ
    if (G.kind % 2) { // ��
        e.info = (int *)malloc(sizeof(int)); // ��̬���ɴ��Ȩֵ�Ŀռ�
        printf("�����뻡(��)%s��%s��Ȩֵ: ", v, w);
        scanf("%d", e.info);
    }
    ListInsert(G.vertices[i].firstarc, 1, e); // ��e���ڻ�β�ı�ͷ
    if (G.kind >= 2) { // ����������һ������
        e.adjvex = i; // e.info����
        ListInsert(G.vertices[j].firstarc, 1, e); // ��e���ڻ�ͷ�ı�ͷ
    }
    return OK;
}

Status DeleteArc(ALGraph &G, VertexType v, VertexType w)
{ 
    // ��ʼ������ͼG���ڣ�v��w��G����������
    // �����������G��ɾ����<v,w>����G������ģ���ɾ���Գƻ�<w,v>
    int i, j;
    Status k;
    ElemType e;
    i = LocateVex(G, v); // i�Ƕ���v(��β)�����
    j = LocateVex(G, w); // j�Ƕ���w(��ͷ)�����
    if (i < 0 || j < 0 || i == j) {
        return ERROR;
    }
    e.adjvex = j;
    k = DeleteElem(G.vertices[i].firstarc, e, equalvex); 
    if (k) { // ɾ���ɹ�
        G.arcnum--; // ���������1
        if (G.kind % 2) { // ��
            free(e.info);
        }
        if (G.kind >= 2) { // ����ɾ���Գƻ�<w,v>
            e.adjvex = i;
            DeleteElem(G.vertices[j].firstarc, e, equalvex);
        }
        return OK;
    } else { // û�ҵ���ɾ���Ļ�
        return ERROR;
    }
}

Boolean visited[MAX_VERTEX_NUM]; // ���ʱ�־����(ȫ����)
#include "C3-2.h"          // �����еĴ洢�ṹ����������

void BFSTraverse(ALGraph G, void (*Visit)(char*))
{
    // �����������������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited
    int v, u, w;
    LinkQueue Q;
    for (v = 0; v < G.vexnum; ++v) {
        visited[v] = FALSE; // �ó�ֵ
    }
    InitQueue(Q); // �ÿյĸ�������Q
    for (v = 0; v < G.vexnum; v++) { // �������ͨͼ��ֻv=0�ͱ���ȫͼ
        if (!visited[v]) { // v��δ����
            visited[v] = TRUE;
            Visit(G.vertices[v].data);
            EnQueue(Q, v); // v�����
            while (!QueueEmpty(Q)) { // ���в���
                DeQueue(Q, u); // ��ͷԪ�س��Ӳ���Ϊu
                w = FirstAdjVex(G, G.vertices[u].data); 
                while (w >= 0) {
                    if (!visited[w]) { // wΪu����δ���ʵ��ڽӶ���
                        visited[w] = TRUE;
                        Visit(G.vertices[w].data);
                        EnQueue(Q, w); // w���
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
    // ����������ӵ�v����������ݹ��������ȱ���ͼG�����������ڽӱ�洢�ṹ
    LinkList p; // pָ�����
    visited[v] = TRUE; // ���÷��ʱ�־ΪTRUE(�ѷ���)
    Visit(G.vertices[v].data); // ���ʸö���
    for (p = G.vertices[v].firstarc; p; p = p->next) { // p����ָ��v���ڽӶ���
        if (!visited[p->data.adjvex]) {
            DFS(G, p->data.adjvex, Visit); // ��v����δ���ʵ��ڽӵ�ݹ����DFS
        }
    }
}

void DFSTraverse(ALGraph G, void (*Visit)(char*))
{ 
    // �����������ͼG��������ȱ�����DFS1�躯��ָ�����
    int v;
    for (v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE; // ���ʱ�־�����ʼ�����ó�ֵΪδ������
    }
    for (v = 0; v < G.vexnum; v++) { // �������ͨͼ��ֻv=0�ͱ���ȫͼ
        if (!visited[v]) { // v��δ������
            DFS(G, v, Visit); // ��v����DFS
        }
    }
    printf("\n");
}

void Display(ALGraph G)
{ 
    // ������������ͼ���ڽӾ���G
    int i;
    LinkList p;
    switch(G.kind) {
        case DG: 
            printf("����ͼ\n");
            break;
        case DN: 
            printf("������\n");
            break;
        case UDG:
            printf("����ͼ\n");
            break;
        case UDN:
            printf("������\n");
    }
    printf("%d�����㣺\n", G.vexnum);
    for (i = 0; i < G.vexnum; ++i) {
        printf("%s ", G.vertices[i].data);
    }
    printf("\n%d����(��):\n", G.arcnum);
    for (i = 0; i < G.vexnum; i++) {
        p = G.vertices[i].firstarc;
        while (p) {
            if (G.kind <= 1 || i < p->data.adjvex) { // ��������������е�һ��
                printf("%s��%s ", G.vertices[i].data, G.vertices[p->data.adjvex].data);
                if (G.kind%2) { // ��
                    printf(":%d  ", *(p->data.info));
                }
            }
            p = p->next;
        }
        printf("\n");
    }
}

// ͼ�ĸ߼��㷨����


void PreOrderTraverse(CSTree T, void(*Visit)(TElemType))
{ 
    // ����������ȸ��������ӡ��ֵܶ�������ṹ����T
    if (T) {
        Visit(T->data); // �ȷ��ʸ����
        PreOrderTraverse(T->firstchild,  Visit); // ���ȸ�������������
        PreOrderTraverse(T->nextsibling, Visit); // ����ȸ�������һ���ֵ�����
    }
}


void DFSTree(ALGraph G, int v, CSTree &T)
{ 
    // ����������ӵ�v���������������ȱ���ͼG��������TΪ����������
    Boolean first = TRUE; 
    int w; 
    CSTree p, q; 
    visited[v] = TRUE; 
    w = FirstAdjVex(G, G.vertices[v].data); 
    while (w >= 0) { // w����Ϊv���ڽӶ���
        if (!visited[w]) { // w���㲻��������
            p = (CSTree) malloc(sizeof(CSNode));  // ���亢�ӽ��
            strcpy(p->data, G.vertices[w].data); 
            p->firstchild = NULL; 
            p->nextsibling = NULL; 
            if (first) {
                // w��v�ĵ�һ��δ�����ʵ��ڽӶ���
                T->firstchild = p; 
                first = FALSE;  // �Ǹ��ĵ�һ�����ӽ��
            } else { // w��v������δ�����ʵ��ڽӶ���
                q->nextsibling = p;  // ����һ�ڽӶ�����ֵܽ��ý��(��1�β�ͨ���˴����Ժ�q�Ѹ�ֵ)
            }
            q = p; 
            DFSTree(G, w, q);  // �ӵ�w���������������ȱ���ͼG��������������q
        }
        w = NextAdjVex(G, G.vertices[v].data, G.vertices[w].data);
    }
}

void DFSForest(ALGraph G, CSTree &T)
{ 
    // �����������������ͼG�������������ɭ�ֵ�(����)����(��)�ֵ�����T
    CSTree p, q; 
    int v; 
    T = NULL; 
    for (v = 0; v < G.vexnum; ++v) {
        visited[v] = FALSE;  // ����ֵ
    }
    for (v = 0; v < G.vexnum; ++v) { // �ӵ�0����������
        if (!visited[v]) { // ��v�����㲻��������
            // ��v����Ϊ�µ��������ĸ����
            p = (CSTree)malloc(sizeof(CSNode));  // ��������
            strcpy(p->data, G.vertices[v].data); 
            p->firstchild = NULL; 
            p->nextsibling = NULL; 
            if (!T) { // �ǵ�һ���������ĸ�(T�ĸ�)
                T = p;
            } else { // �������������ĸ�(ǰһ�õĸ��ģ��ֵܣ�)
                q->nextsibling = p;  // ��1�β�ͨ���˴����Ժ�q�Ѹ�ֵ
            }
            q = p;  // qָʾ��ǰ�������ĸ�
            DFSTree(G, v, p);  // ������pΪ����������
        }
    }
}


int count, lowcount = 1;  // ȫ����count�Է���˳�����, lowcount�����lowֵ��˳�����
int low[MAX_VERTEX_NUM], lowOrder[MAX_VERTEX_NUM]; 
// ȫ�����飬low[]�涥���lowֵ��lowOrder�涥�����lowֵ��˳��

void DFSArticul(ALGraph G, int v0)
{ 
    // ����������ӵ�v0���������������ȱ���ͼG�����Ҳ�����ؽڵ�
    int min, w; 
    ArcNode *p; 
    visited[v0] = min = ++count; 
    // v0�ǵ�count�����ʵĶ��㣬visited[]��ȫ�ֱ���, ��bo7-2.cpp�ж���, min�ĳ�ֵΪv0�ķ���˳��
    for (p = G.vertices[v0].firstarc; p; p = p->nextarc) { 
        // ���ζ�v0��ÿ���ڽӶ�����
        w = p->data.adjvex;  // wΪv0���ڽӶ���λ��
        if (visited[w] == 0) { // wδ�����ʣ���v0�ĺ���
            DFSArticul(G, w); 
            // �ӵ�w���������������ȱ���ͼG�����Ҳ�����ؽڵ㡣����ǰ���low[w]
            if (low[w] < min) { // ���v0�ĺ��ӽ��w��low[]С����˵�����ӽ�㻹���������(����)����
                min = low[w];  // ȡminֵΪ���ӽ���low[]����v0���ǹؽڵ�
            } else if (low[w] >= visited[v0]) { // v0�ĺ��ӽ��wֻ��v0��������v0�ǹؽڵ�
                printf("%d %s\n", v0, G.vertices[v0].data);  // ����ؽڵ�v0
            }
        } else if (visited[w] < min) { // w�ѷ��ʣ���w��v0���������ϵ����ȣ����ķ���˳���С��min
            min = visited[w];  // ��ȡminΪvisited[w]
        }
    }
    low[v0] = min;  // vo��low[]ֵΪ�����е���Сֵ
    lowOrder[v0] = lowcount++;  // ��¼v0���low[]ֵ��˳��(����), �����ڷ�����������֮ǰ���low[]
}

void FindArticul(ALGraph G)
{ 
    // �����������ͨͼG���ڽӱ����洢�ṹ�����Ҳ����G��ȫ���ؽڵ㡣ȫ����count�Է��ʼ���
    int i, v; 
    ArcNode *p; 
    count = 1;  // ����˳��
    visited[0] = count;  // �趨�ڽӱ���0�Ŷ���Ϊ�������ĸ�����1��������
    for (i = 1; i < G.vexnum; ++i) {
        visited[i] = 0;  // ���ඥ����δ���ʣ����ֵΪ0
    }
    p = G.vertices[0].firstarc;  // pָ������ĵ�1���ڽӶ���
    v = p->data.adjvex;  // v�Ǹ����ĵ�1���ڽӶ�������
    DFSArticul(G, v);  // �ӵ�v�������������Ȳ��ҹؽڵ�
    if (count < G.vexnum) { // �ɸ����ĵ�1���ڽӶ���������ȱ���G�����ʵĶ���������G�Ķ�����
        // ˵���������ĸ���������������������ǹؽڵ�
        printf("%d %s\n", 0, G.vertices[0].data);  // ���ǹؽڵ㣬�����
        while (p->nextarc) { // ������һ���ڽӵ�
            p = p->nextarc;  // pָ�������һ���ڽӵ�
            v = p->data.adjvex; 
            if (visited[v] == 0) { // ���ڽӵ�δ������
                DFSArticul(G, v);  // �Ӵ˶������������Ȳ��ҹؽڵ�
            }
        }
    }
}

void FindInDegree(ALGraph G, int indegree[])
{ 
    // ����������󶥵�����
    int i; 
    ArcNode *p; 
    for (i = 0; i < G.vexnum; i++) {
        indegree[i] = 0;  // ����ֵ
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
    // �������������ͼG�����ڽӱ�洢�ṹ����G�޻�·�������G�Ķ����һ���������в�����OK��
    //           ���򷵻�ERROR
    int i, k, count = 0;  // ���������������ֵΪ0
    int indegree[MAX_VERTEX_NUM];  // ������飬��Ÿ����㵱ǰ�����
    SqStack S; 
    ArcNode *p; 
    FindInDegree(G, indegree);  // �Ը����������indegree[]
    InitStack(S);  // ��ʼ������ȶ���ջS
    for (i = 0; i < G.vexnum; ++i) { // �����ж���i
        if (!indegree[i]) { // �������Ϊ0
            Push(S, i);  // ��i������ȶ���ջS
        }
    }
    while (!StackEmpty(S)) { // ������ȶ���ջS����
        Pop(S, i);  // ��ջ1������ȶ������ţ������丳��i
        printf("%s ", G.vertices[i].data);  // ���i�Ŷ���
        ++count;  // ����������� + 1
        for (p = G.vertices[i].firstarc; p; p = p->nextarc) {
            // ��i�Ŷ����ÿ���ڽӶ���
            k = p->data.adjvex;  // �����Ϊk
            if (!(--indegree[k])) { // k����ȼ�1������Ϊ0����k��ջS
                Push(S, k); 
            }
        }
    }
    if (count < G.vexnum) { // ����ȶ���ջS�ѿգ�ͼG���ж���δ���
        printf("������ͼ�л�·\n"); 
        return ERROR; 
    } else {
        printf("Ϊһ���������С�\n"); 
        return OK; 
    }
}


int ve[MAX_VERTEX_NUM];  // �¼����緢��ʱ�䣬ȫ�ֱ���

Status TopologicalOrder(ALGraph G, SqStack &T)
{ 
    // ���������������G�����ڽӱ�洢�ṹ����������¼������緢��ʱ��ve(ȫ�ֱ���)��TΪ��������
    //           ����ջ, SΪ����ȶ���ջ����G�޻�·������ջT����G��һ����������, �Һ���ֵΪOK, ����ΪERROR
    int i, k, count = 0;  // ����ջ����������ֵΪ0
    int indegree[MAX_VERTEX_NUM];  // ������飬��Ÿ����㵱ǰ�����
    SqStack S; 
    ArcNode *p; 
    FindInDegree(G, indegree);  // �Ը����������indegree[]����func7-1.cpp��
    InitStack(S);  // ��ʼ������ȶ���ջS
    printf("�������У�"); 
    for (i = 0; i < G.vexnum; ++i) { // �����ж���i
        if (!indegree[i]) { // �������Ϊ0
            Push(S, i);  // ��i������ȶ���ջS
        }
    }
    InitStack(T);  // ��ʼ���������ж���ջ
    for (i = 0; i < G.vexnum; ++i) { // ��ʼ��ve[] = 0(��Сֵ���ȼٶ�ÿ���¼������������¼�Լ��)
        ve[i] = 0; 
    }
    while (!StackEmpty(S)) { // ������ȶ���ջS����
        Pop(S, i);  // ��ջS������������Ķ���j����
        printf("%s ", G.vertices[i].data); 
        Push(T, i);  // j�Ŷ���������������ջT(ջ��Ԫ��Ϊ��������ĵ�1��Ԫ��)
        ++count;  // ����ջT�Ķ������
        for (p = G.vertices[i].firstarc; p; p = p->nextarc) {
            // ��i�Ŷ����ÿ���ڽӵ�
            k = p->data.adjvex;  // �����Ϊk
            if (--indegree[k] == 0) { // k����ȼ�1������Ϊ0����k��ջS
                Push(S, k); 
            }
            if (ve[i] + *(p->data.info) > ve[k]) { // *(p->data.info)��<i, k>��Ȩֵ
                // ����k�¼������緢��ʱ��Ҫ����ֱ��ǰ������i�¼���
                // ���緢��ʱ��� < i, k > ��ȨֵԼ��������i���������򣬹�ve[i]���ٸı�
                ve[k] = ve[i] + *(p->data.info);  
            }
        }                  
    }
    if (count < G.vexnum) {
        printf("���������л�·\n"); 
        return ERROR; 
    } else {
        return OK; 
    }
}

Status CriticalPath(ALGraph G)
{ 
    // ���������GΪ�����������G�ĸ���ؼ��
    int vl[MAX_VERTEX_NUM];  // �¼���ٷ���ʱ��
    SqStack T; 
    int i, j, k, ee, el, dut; 
    ArcNode *p; 
    if (!TopologicalOrder(G, T)) { // ��������
        return ERROR; 
    }
    j = ve[0];  // j�ĳ�ֵ
    for (i = 1; i < G.vexnum; i++) {
        if (ve[i] > j) {
            j = ve[i];  // j = Max(ve[]) ��ɵ�����緢��ʱ��
        }
    }
    for (i = 0; i < G.vexnum; i++) { // ��ʼ�������¼�����ٷ���ʱ��
        vl[i] = j;  // Ϊ��ɵ�����緢��ʱ��(���ֵ)
    }
    while (!StackEmpty(T)) { // ������������������vlֵ
        Pop(T, j);
        for (p = G.vertices[j].firstarc; p; p = p->nextarc) {
            // ����ջT��Ԫ��, ����j, pָ��j�ĺ���¼�k, �¼�k����ٷ���ʱ����ȷ��(��Ϊ������������)
            k = p->data.adjvex; 
            dut = *(p->data.info);  // dut=<j, k>��Ȩֵ
            if (vl[k] - dut < vl[j]) {
                // �¼�j����ٷ���ʱ��Ҫ����ֱ�Ӻ���¼�k����ٷ���ʱ��
                // �� < j, k > ��ȨֵԼ��������k�����������򣬹�vl[k]���ٸı�
                vl[j] = vl[k]-dut;  
            }
        } 
    }
    printf("\ni ve[i] vl[i]\n"); 
    for (i = 0; i < G.vexnum; i++) { // ��ʼ�������¼�����ٷ���ʱ��
        printf("%d   %d     %d", i, ve[i], vl[i]); 
        if (ve[i] == vl[i]) {
            printf(" �ؼ�·�������Ķ���"); 
        }
        printf("\n"); 
    }
    printf("j   k  Ȩֵ  ee  el\n"); 
    for (j = 0; j < G.vexnum; ++j) { // ��ee��el�͹ؼ��
        for (p = G.vertices[j].firstarc; p; p = p->nextarc) {
            k = p->data.adjvex; 
            dut = *(p->data.info);  // dut =  < j, k > ��Ȩֵ
            ee = ve[j];  // ee = � < j, k > �����翪ʼʱ��(��j��)
            el = vl[k] - dut;  // el = � < j, k > ����ٿ�ʼʱ��(��j��)
            printf("%s��%s %3d %3d %3d ", G.vertices[j].data, G.vertices[k].data, dut, ee, el); 
            // ������ߵĲ���
            if (ee == el) { // �ǹؼ��
                printf("�ؼ��"); 
            }
            printf("\n"); 
        }
    }
    return OK; 
}
