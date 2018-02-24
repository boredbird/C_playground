// c7-1.h ͼ������(�ڽӾ���)�洢��ʾ

#ifndef C7_1_H
#define C7_1_H

#include "C1.h"
#include "C3-2.h"          // �����еĽṹ��BFSTraverse()��

#define INFINITY        INT_MAX  // ���������ֵ�����
#define MAX_VERTEX_NUM  50       // ��󶥵����
#define MAX_NAME        5        // �����ַ�������󳤶�+1
#define MAX_INFO        20       // �����Ϣ�ַ�������󳤶�+1

typedef int  VRType;   // �����ϵ����
typedef char InfoType; // �����Ϣ����
typedef char VertexType[MAX_NAME]; // ��������

enum GraphKind {DG, DN, UDG, UDN};      // ����ͼ, ������, ����ͼ, ������

typedef struct
{
    VRType adj; // �����ϵ���͡�����Ȩͼ����1(��)��0(��)��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ
    InfoType *info; // �û������Ϣ��ָ��(����)
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // ��ά����

struct MGraph
{
    VertexType vexs[MAX_VERTEX_NUM]; // ��������
    AdjMatrix  arcs;                 // �ڽӾ���
    int        vexnum;               // ͼ�ĵ�ǰ������
    int        arcnum;               // ͼ�ĵ�ǰ����
    GraphKind  kind;                 // ͼ�������־
};


// ͼ������(�ڽӾ���)�洢�Ļ�������(17��)

int LocateVex(MGraph G, VertexType v);
// ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����
// �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ�ã����򷵻�-1

void CreateFUDG(MGraph &G);
// �����������������(�ڽӾ���)��ʾ�������ļ�����û�������Ϣ������ͼG

void CreateFUDN(MGraph &G);
// �����������������(�ڽӾ���)��ʾ�������ļ�����û�������Ϣ��������G

void CreateGraph(MGraph &G);
// �����������������(�ڽӾ���)��ʾ��������ͼG

void DestroyGraph(MGraph &G);
// ��ʼ������ͼG����
// �������������ͼG

VertexType& GetVex(MGraph G, int v);
// ��ʼ������ͼG���ڣ�v��G��ĳ����������
// �������������v��ֵ

Status PutVex(MGraph &G, VertexType v, VertexType value);
// ��ʼ������ͼG���ڣ�v��G��ĳ������
// �����������v����ֵvalue

int FirstAdjVex(MGraph G, VertexType v);
// ��ʼ������ͼG���ڣ�v��G��ĳ������
// �������������v�ĵ�һ���ڽӶ������š���������G��û���ڽӶ��㣬�򷵻�-1

int NextAdjVex(MGraph G, VertexType v, VertexType w);
// ��ʼ������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
// �������������v��(�����w��)��һ���ڽӶ������ţ���w��v�����һ���ڽӶ��㣬�򷵻�-1

void InsertVex(MGraph &G, VertexType v);
// ��ʼ������ͼG���ڣ�v��ͼG�ж�������ͬ����
// �����������ͼG�������¶���v(�������붥����صĻ�������InsertArc()ȥ��)

Status DeleteVex(MGraph &G, VertexType v);
// ��ʼ������ͼG���ڣ�v��G��ĳ������
// ���������ɾ��G�ж���v������صĻ�

Status InsertArc(MGraph &G, VertexType v, VertexType w);
// ��ʼ������ͼG���ڣ�v��w��G����������
// �����������G������<v,w>����G������ģ�������Գƻ�<w,v>

Status DeleteArc(MGraph &G, VertexType v, VertexType w);
// ��ʼ������ͼG���ڣ�v��w��G����������
// �����������G��ɾ����<v,w>����G������ģ���ɾ���Գƻ�<w,v>

void DFS(MGraph G, int v, void (*Visit)(VertexType));
// ����������ӵ�v����������ݹ��������ȱ���ͼG

void DFSTraverse(MGraph G, void (*Visit)(VertexType));
// ��ʼ������ͼG���ڣ�Visit�Ƕ����Ӧ�ú���
// ����������ӵ�1��������������ȱ���ͼG������ÿ��������ú���Visitһ���ҽ�һ��

void BFSTraverse(MGraph G, void (*Visit)(VertexType));
// ��ʼ������ͼG���ڣ�Visit�Ƕ����Ӧ�ú���
// ����������ӵ�1�������𣬰�������ȷǵݹ����ͼG,����ÿ��������ú���Visitһ���ҽ�һ��

void Display(MGraph G);
// �������������ڽӾ���洢��ʾ��ͼG

// ͼ�ĸ߼��㷨

typedef int PathMatrix_DIJ[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // ·�����󣬶�ά����
typedef int ShortPathTable[MAX_VERTEX_NUM];  // ��̾����һά����
typedef int PathMatrix_FLOYD[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 3ά����
typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 2ά����

void MiniSpanTree_PRIM(MGraph G, VertexType u);
// ���������������ķ�㷨�ӵ�u���������������G����С������T�����T�ĸ�����

void ShortestPath_DIJ(MGraph G, int v0, PathMatrix_DIJ P, ShortPathTable D);
// �����������Dijkstra�㷨��������G��v0���㵽���ඥ��v�����·��P[v]����Ȩ����
//           D[v]����P[v][w]ΪTRUE����w�Ǵ�v0��v��ǰ������·���ϵĶ��㡣
//           final[v]ΪTRUE���ҽ���v��S�����Ѿ���ô�v0��v�����·��

void ShortestPath_FLOYD(MGraph G, PathMatrix_FLOYD P, DistancMatrix D);
// �����������Floyd�㷨��������G�и��Զ���v��w֮������·��P[v][w]�����Ȩ����D[v][w]
//           ��P[v][w][u]ΪTRUE����u�Ǵ�v��w��ǰ������·���ϵĶ���

void Kruskal(MGraph G);
// �����������³˹�����㷨��������ͨ������С������


#endif
