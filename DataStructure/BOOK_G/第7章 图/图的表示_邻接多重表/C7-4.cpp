// C7 - 4.cpp ����ͼ���ڽӶ��ر�Ļ�����������(16��)

#include "C7-4.h"

int LocateVex(AMLGraph G, VertexType u)
{ 
    // ��ʼ����������ͼG���ڣ�u��G�ж�������ͬ����
    // �����������G�д��ڶ���u���򷵻ظö���������ͼ��λ�ã����򷵻�-1
    int i; 
    for (i = 0; i < G.vexnum; ++i) {
        if (strcmp(u, G.adjmulist[i].data) == 0) {
            return i; 
        }
    }
    return -1; 
}

void CreateGraph(AMLGraph &G)
{ 
    // ��������������ڽӶ��ر�洢�ṹ����������ͼG
    int i, j, k, IncInfo; 
    VertexType va, vb; 
    EBox *p; 
    printf("����������ͼ�Ķ�����,����,��ͼ������(��:1, ͼ:0): "); 
    scanf("%d,%d,%d", &G.vexnum, &G.edgenum, &IncInfo); 
    printf("������%d�������ֵ(<%d���ַ�):\n", G.vexnum, MAX_NAME); 
    for (i = 0; i < G.vexnum; ++i) { // ���춥������
        scanf("%s", G.adjmulist[i].data); 
        G.adjmulist[i].firstedge = NULL; 
    }
    printf("��˳������ÿ���ߵ������˵�(�Կո���Ϊ���):\n"); 
    for (k = 0; k < G.edgenum; ++k) { // �����������
        scanf("%s%s%*c", va, vb);  // %*c�Ե��س���
        i = LocateVex(G, va);  // һ��
        j = LocateVex(G, vb);  // ��һ��
        p = (EBox*) malloc(sizeof(EBox)); 
        p->mark = unvisited;  // ���ֵ
        p->ivex = i; 
        p->ilink = G.adjmulist[i].firstedge;  // ����һ�˵ı�ͷ
        G.adjmulist[i].firstedge = p; 
        p->jvex = j; 
        p->jlink = G.adjmulist[j].firstedge;  // ������һ�˵ı�ͷ
        G.adjmulist[j].firstedge = p; 
        if (IncInfo) { // ��
            p->info = (InfoType *) malloc(sizeof(InfoType)); 
            printf("������ñߵ�Ȩֵ: "); 
            scanf("%d", p->info); 
        } else {
            p->info = NULL; 
        }
    }
}

VertexType& GetVex(AMLGraph G, int v)
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ����������
    // �������������v��ֵ
    if (v >= G.vexnum || v < 0) {
        exit(ERROR); 
    }
    return G.adjmulist[v].data; 
}

Status PutVex(AMLGraph &G, VertexType v, VertexType value)
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ������
    // �����������v����ֵvalue
    int i; 
    i = LocateVex(G, v); 
    if (i < 0) { // v����G�Ķ���
        return ERROR; 
    }
    strcpy(G.adjmulist[i].data, value); 
    return OK; 
}

int FirstAdjVex(AMLGraph G, VertexType v)
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ������
    // �������������v�ĵ�һ���ڽӶ������ţ�
    //           ��������G��û���ڽӶ��㣬�򷵻�-1
    int i; 
    i = LocateVex(G, v); 
    if (i < 0) { // G�в����ڶ���v
        return  - 1; 
    }
    if (G.adjmulist[i].firstedge) { // v���ڽӶ���
        if (G.adjmulist[i].firstedge->ivex == i) {
            return G.adjmulist[i].firstedge->jvex; 
        } else {
            return G.adjmulist[i].firstedge->ivex; 
        }
    } else {
        return -1; 
    }
}

int NextAdjVex(AMLGraph G, VertexType v, VertexType w)
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
    // �������������v��(�����w��)��һ���ڽӶ������ţ�
    //           ��w��v�����һ���ڽӵ㣬�򷵻�-1
    int i, j; 
    EBox *p; 
    i = LocateVex(G, v);  // i�Ƕ���v�����
    j = LocateVex(G, w);  // j�Ƕ���w�����
    if (i < 0 || j < 0) { // v��w����G�Ķ���
        return -1; 
    }
    p = G.adjmulist[i].firstedge;  // pָ�򶥵�v�ĵ�1����
    while (p) {
        if (p->ivex == i && p->jvex != j) { // �����ڽӶ���w(���1)
            p = p->ilink;  // ����һ���ڽӶ���
        } else if (p->jvex == i && p->ivex != j) { // �����ڽӶ���w(���2)
            p = p->jlink;  // ����һ���ڽӶ���
        } else { // ���ڽӶ���w
            break; 
        }
    }
    if (p && p->ivex == i && p->jvex == j) { // �ҵ��ڽӶ���w(���1)
        p = p->ilink; 
        if (p && p->ivex == i) {
            return p->jvex; 
        } else if (p && p->jvex == i) {
            return p->ivex; 
        }
    }
    if (p && p->ivex == j && p->jvex == i) { // �ҵ��ڽӶ���w(���2)
        p = p->jlink; 
        if (p && p->ivex == i) {
            return p->jvex; 
        } else if (p && p->jvex == i) {
            return p->ivex; 
        }
    }
    return -1; 
}

Status InsertVex(AMLGraph &G, VertexType v)
{ 
    // ��ʼ����������ͼG���ڣ�v��G�ж�������ͬ����
    // �����������G�������¶���v
    if (G.vexnum == MAX_VERTEX_NUM) { // ������������ܲ���
        return ERROR; 
    }
    if (LocateVex(G, v) >= 0) { // ����Ѵ��ڣ����ܲ���
        return ERROR; 
    }
    strcpy(G.adjmulist[G.vexnum].data, v); 
    G.adjmulist[G.vexnum++].firstedge = NULL; 
    return OK; 
}

Status DeleteArc(AMLGraph &G, VertexType v, VertexType w)
{ 
    // ��ʼ����������ͼG���ڣ�v��w��G����������
    // �����������G��ɾ���� < v, w > 
    int i, j; 
    EBox *p, *q; 
    i = LocateVex(G, v); 
    j = LocateVex(G, w); 
    if (i < 0 || j < 0 || i == j) {
        return ERROR;   // ͼ��û�иõ�򻡡�����ʹָ���ɾ���ߵĵ�1��ָ���ƹ�������
    }
    p = G.adjmulist[i].firstedge;  // pָ�򶥵�v�ĵ�1����
    if (p && p->jvex == j) { // ��1���߼�Ϊ��ɾ����(���1)
        G.adjmulist[i].firstedge = p->ilink; 
    } else if (p && p->ivex == j) { // ��1���߼�Ϊ��ɾ����(���2)
        G.adjmulist[i].firstedge = p->jlink; 
    } else { // ��1���߲��Ǵ�ɾ����
        while (p) { // �����һ� < v, w > 
            if (p->ivex == i && p->jvex != j) { // ���Ǵ�ɾ����
                q = p; 
                p = p->ilink;  // ����һ���ڽӶ���
            } else if (p->jvex == i && p->ivex != j) { // ���Ǵ�ɾ����
                q = p; 
                p = p->jlink;  // ����һ���ڽӶ���
            } else { // ���ڽӶ���w
                break;
            }
        }
        if (!p) { // û�ҵ��ñ�
            return ERROR; 
        }
        if (p->ivex == i && p->jvex == j) { // �ҵ��� < v, w > (���1)
            if (q->ivex == i) {
                q->ilink = p->ilink; 
            } else {
                q->jlink = p->ilink; 
            }
        } else if (p->ivex == j && p->jvex == i) { // �ҵ��� < v, w > (���2)
            if (q->ivex == i) {
                q->ilink = p->jlink; 
            } else {
                q->jlink = p->jlink; 
            }
        }
    } // ��������һ�������Ҵ�ɾ������ɾ��֮
    p = G.adjmulist[j].firstedge;  // pָ�򶥵�w�ĵ�1����
    if (p->jvex == i) { // ��1���߼�Ϊ��ɾ����(���1)
        G.adjmulist[j].firstedge = p->ilink; 
    } else if (p->ivex == i) { // ��1���߼�Ϊ��ɾ����(���2)
        G.adjmulist[j].firstedge = p->jlink; 
    } else { // ��1���߲��Ǵ�ɾ����
        while (p) { // �����һ� < v, w > 
            if (p->ivex == j && p->jvex != i) { // ���Ǵ�ɾ����
                q = p; 
                p = p->ilink;  // ����һ���ڽӶ���
            } else if (p->jvex == j && p->ivex != i) { // ���Ǵ�ɾ����
                q = p; 
                p = p->jlink;  // ����һ���ڽӶ���
            } else { // ���ڽӶ���v
                break;
            }
        }
        if (p->ivex == i && p->jvex == j) { // �ҵ��� < v, w > (���1)
            if (q->ivex == j) {
                q->ilink = p->jlink; 
            } else {
                q->jlink = p->jlink; 
            }
        } else if (p->ivex == j && p->jvex == i) { // �ҵ��� < v, w > (���2)
            if (q->ivex == j) {
                q->ilink = p->ilink; 
            } else {
                q->jlink = p->ilink; 
            }
        }
    }
    if (p->info) { // �������Ϣ(��Ȩֵ)
        free(p->info);  // �ͷ������Ϣ(��Ȩֵ)
    }
    free(p);  // �ͷŽ��
    G.edgenum--;  // ����-1
    return OK; 
}

Status DeleteVex(AMLGraph &G, VertexType v)
{ 
    // ��ʼ����������ͼG���ڣ�v��G��ĳ������
    // ���������ɾ��G�ж���v������صı�
    int i, j; 
    EBox *p; 
    i = LocateVex(G, v);  // iΪ��ɾ����������
    if (i < 0) {
        return ERROR; 
    }
    for (j = 0; j < G.vexnum; j++) { // ɾ���붥��v�����ı�(����еĻ�)
        DeleteArc(G, v, G.adjmulist[j].data);  // ������ڴ˻�����ɾ��
    }
    for (j = i + 1; j < G.vexnum; j++) { // ���ڶ���v����Ķ������ż�1
        G.adjmulist[j - 1] = G.adjmulist[j]; 
    }
    G.vexnum--;  // ��������1
    for (j = i; j < G.vexnum; j++) { // �޸���Ŵ���i�Ķ����ڱ����е����
        p = G.adjmulist[j].firstedge; 
        if (p) {
            if (p->ivex == j + 1) {
                p->ivex--; 
                p = p->ilink; 
            } else {
                p->jvex--; 
                p = p->jlink; 
            }
        }
    }
    return OK; 
}

void DestroyGraph(AMLGraph &G)
{ 
    // ��ʼ����������ͼG����
    // �����������������ͼG
    int i; 
    for (i = G.vexnum - 1; i >= 0; i--) { // �ɴ�С����ɾ������
        DeleteVex(G, G.adjmulist[i].data); 
    }
}

Status InsertArc(AMLGraph &G, VertexType v, VertexType w)
{ 
    // ��ʼ����������ͼG���ڣ�v��W��G����������
    // �����������G������ < v, w > 
    int i, j, IncInfo; 
    EBox *p; 
    i = LocateVex(G, v);  // һ��
    j = LocateVex(G, w);  // ��һ��
    if (i < 0 || j < 0 || i == j) {
        return ERROR; 
    }
    p = (EBox*)malloc(sizeof(EBox)); 
    p->mark = unvisited; 
    p->ivex = i; 
    p->ilink = G.adjmulist[i].firstedge;  // ���ڱ�ͷ
    G.adjmulist[i].firstedge = p; 
    p->jvex = j; 
    p->jlink = G.adjmulist[j].firstedge;  // ���ڱ�ͷ
    G.adjmulist[j].firstedge = p; 
    printf("�ñ��Ƿ���Ȩֵ(1:�� 0:��): "); 
    scanf("%d", &IncInfo); 
    if (IncInfo) { // ��Ȩֵ
        p->info = (InfoType*) malloc(sizeof(InfoType)); 
        printf("������ñߵ�Ȩֵ: "); 
        scanf("%d", p->info); 
    } else {
        p->info = NULL; 
    }
    G.edgenum++; 
    return OK; 
}

Boolean visite[MAX_VERTEX_NUM];  // ���ʱ�־����(ȫ����)
void(*VisitFunc)(VertexType v); 

void DFS(AMLGraph G, int v)
{
    int j; 
    EBox *p; 
    VisitFunc(G.adjmulist[v].data); 
    visite[v] = TRUE; 
    p = G.adjmulist[v].firstedge; 
    while (p) {
        j = p->ivex == v?p->jvex:p->ivex; 
        if (!visite[j]) {
            DFS(G, j); 
        }
        p = (p->ivex == v) ? p->ilink : p->jlink; 
    }
}

void DFSTraverse(AMLGraph G, void(*visit)(VertexType))
{ 
    // ��ʼ������ͼG���ڣ�Visit�Ƕ����Ӧ�ú���
    // ����������ӵ�1��������������ȱ���ͼG��
    //           ����ÿ��������ú���Visitһ���ҽ�һ��
    int v; 
    VisitFunc = visit; 
    for (v = 0; v < G.vexnum; v++) {
        visite[v] = FALSE; 
    }
    for (v = 0; v < G.vexnum; v++) {
        if (!visite[v]) {
            DFS(G, v); 
        }
    }
}

#include "C3-2.h" // �����еĴ洢�ṹ��BFSTraverse()��

void BFSTraverse(AMLGraph G, void(*Visit)(VertexType))
{ 
    // ��ʼ������ͼG���ڣ�Visit�Ƕ����Ӧ�ú���
    // ����������ӵ�1�������𣬰�������ȷǵݹ����ͼG������ÿ��������ú���
    //           Visitһ���ҽ�һ�Ρ�ʹ�ø�������Q�ͷ��ʱ�־����visite
    int v, u, w; 
    LinkQueue Q; 
    for (v = 0; v < G.vexnum; v++) {
        visite[v] = FALSE;  // �ó�ֵ
    }
    InitQueue(Q);  // �ÿյĸ�������Q
    for (v = 0; v < G.vexnum; v++) {
        if (!visite[v]) { // v��δ����
            visite[v] = TRUE;  // ���÷��ʱ�־ΪTRUE(�ѷ���)
            Visit(G.adjmulist[v].data); 
            EnQueue(Q, v);  // v�����
            while (!QueueEmpty(Q)) { // ���в���
                DeQueue(Q, u);  // ��ͷԪ�س��Ӳ���Ϊu
                w = FirstAdjVex(G, G.adjmulist[u].data);
                while (w >= 0) {
                    if (!visite[w]) { // wΪu����δ���ʵ��ڽӶ�������
                        visite[w] = TRUE; 
                        Visit(G.adjmulist[w].data); 
                        EnQueue(Q, w); 
                    }
                    w = NextAdjVex(G, G.adjmulist[u].data, G.adjmulist[w].data);
                }
            }
        }
    }
}

void MarkUnvizited(AMLGraph G)
{ 
    // ������������ñߵķ��ʱ��Ϊδ������
    int i; 
    EBox *p; 
    for (i = 0; i < G.vexnum; i++) {
        p = G.adjmulist[i].firstedge; 
        while (p) {
            p->mark = unvisited; 
            if (p->ivex == i) {
                p = p->ilink; 
            } else {
                p = p->jlink; 
            }
        }
    }
}

void Display(AMLGraph G)
{ 
    // ����������������ͼ���ڽӶ��ر�G
    int i; 
    EBox *p; 
    MarkUnvizited(G);  // �ñߵķ��ʱ��Ϊδ������
    printf("%d�����㣺\n", G.vexnum); 
    for (i = 0; i < G.vexnum; ++i) {
        printf("%s ", G.adjmulist[i].data); 
    }
    printf("\n%d����:\n", G.edgenum); 
    for (i = 0; i < G.vexnum; i++) {
        p = G.adjmulist[i].firstedge; 
        while (p) {
            if (p->ivex == i) { // �ߵ�i����ö����й�
                if (!p->mark) { // ֻ���һ��
                    printf("%s��%s ", G.adjmulist[i].data, G.adjmulist[p->jvex].data); 
                    p->mark = visited; 
                    if (p->info) { // ���������Ϣ
                        printf("Ȩֵ: %d ", *p->info); 
                    }
                }
                p = p->ilink; 
            } else { // �ߵ�j����ö����й�
                if (!p->mark) { // ֻ���һ��
                    printf("%s��%s ", G.adjmulist[p->ivex].data, G.adjmulist[i].data); 
                    p->mark = visited; 
                    if (p->info) { // ���������Ϣ
                        printf("Ȩֵ: %d ", *p->info); 
                    }
                }
                p = p->jlink; 
            }
        }
        printf("\n"); 
    }
}
