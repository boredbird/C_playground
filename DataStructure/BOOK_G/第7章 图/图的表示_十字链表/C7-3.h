// C7-3.h ����ͼ��ʮ������洢��ʾ(�뵥����ı������ͽ�����ϵ)
#ifndef C_7_3_H
#define C_7_3_H

#include "C1.h"

#define MAX_VERTEX_NUM  50  // ��󶥵����
#define MAX_VERTEX_NAME 5   // �����ַ�����󳤶�+1
typedef int  InfoType;      // Ȩֵ����
typedef char VertexType[MAX_VERTEX_NAME];


struct ArcBox1 // ��������hlink������
{
    int      tailvex; // β�����λ��
    int      headvex; // ͷ�����λ��
    InfoType *info;   // �����Ϣָ�룬��ָ��Ȩֵ��������Ϣ
    ArcBox1  *hlink;  // ��ͷ��ͬ�Ļ�������
    ArcBox1  *tlink;  // ��β��ͬ�Ļ�������
};

struct ElemType
{
    int      tailvex; // β�����λ��
    int      headvex; // ͷ�����λ��
    InfoType *info;   // �����Ϣָ�룬��ָ��Ȩֵ��������Ϣ
    ArcBox1  *hlink;  // ��ͷ��ͬ�Ļ�������
};

struct ArcBox
{
    ElemType data;
    ArcBox   *tlink;
};

struct VexNode // ������
{
    VertexType data;
    ArcBox1    *firstin;  // ָ��ö����һ���뻡
    ArcBox     *firstout; // ָ��ö����һ������
};

struct OLGraph
{
    VexNode xlist[MAX_VERTEX_NUM]; // ��ͷ����(����)
    int     vexnum;                // ��ǰ������
    int     arcnum;                // ��ǰ����
};

#define LNode  ArcBox     // ������Ľ������
#define next   tlink      // ���������ָ����
typedef ArcBox *LinkList; // ָ���������ָ��

// ����ͼ������ʮ������洢�Ļ�������(14��)

int LocateVex(OLGraph G, VertexType u);
// ������������ض���u������ͼG�е�λ��(���)���粻�����򷵻�-1

void CreateGraph(OLGraph &G);
// �������������ʮ������洢��ʾ����������ͼG

void DestroyGraph(OLGraph &G);
// ��ʼ����������ͼG����
// �����������������ͼG
 
VertexType& GetVex(OLGraph G, int v);
// ��ʼ����������ͼG���ڣ�v��G��ĳ����������
// �������������v��ֵ

Status PutVex(OLGraph &G, VertexType v, VertexType value);
// ��ʼ����������ͼG���ڣ�v��G��ĳ������
// �����������v����ֵvalue
 
int FirstAdjVex(OLGraph G, VertexType v);
// ��ʼ����������ͼG���ڣ�v��G��ĳ������
// �������������v�ĵ�һ���ڽӶ������ţ�
//           ��������G��û���ڽӶ��㣬�򷵻�-1

int NextAdjVex(OLGraph G, VertexType v, VertexType w);
// ��ʼ����������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
// �������������v��(�����w��)��һ���ڽӶ������ţ�
//           ��w��v�����һ���ڽӶ��㣬�򷵻�-1

void InsertVex(OLGraph &G, VertexType v);
// ��ʼ����������ͼG���ڣ�v������ͼG�ж�������ͬ����
// ���������������ͼG�������¶���v

Status DeleteVex(OLGraph &G, VertexType v);
// ��ʼ����������ͼG���ڣ�v��G��ĳ������
// ���������ɾ��G�ж���v������صĻ�

Status InsertArc(OLGraph &G, VertexType v, VertexType w);
// ��ʼ����������ͼG���ڣ�v��w��G����������
// �����������G������<v, w>

Status DeleteArc(OLGraph &G, VertexType v, VertexType w);
// ��ʼ����������ͼG���ڣ�v��w��G����������
// �����������G��ɾ����<v, w>

void DFSTraverse(OLGraph G, void(*Visit)(VertexType));
// ��ʼ����������ͼG���ڣ�v��G��ĳ�����㣬Visit�Ƕ����Ӧ�ú���
// ����������ӵ�1�������𣬰�������ȵݹ��������ͼG��
//           ����ÿ��������ú���Visitһ���ҽ�һ��

void BFSTraverse(OLGraph G, void(*Visit)(VertexType));
// ��ʼ����������ͼG���ڣ�Visit�Ƕ����Ӧ�ú���
// ����������ӵ�1�������𣬰�������ȷǵݹ��������ͼG��
//           ����ÿ��������ú���Visitһ���ҽ�һ��

void Display(OLGraph G);
// ������������ͼG
 
#endif