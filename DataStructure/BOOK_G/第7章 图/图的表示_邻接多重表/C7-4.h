// C7-4.h ����ͼ���ڽӶ��ر�洢��ʾ

#ifndef C_7_4_H
#define C_7_4_H

#include "C1.h"

#define MAX_VERTEX_NUM 50 // ��󶥵���
#define MAX_NAME       5  // �����ַ�������󳤶�+1
typedef int  InfoType;             // Ȩֵ����
typedef char VertexType[MAX_NAME]; // �ַ�������

enum VisitIf{unvisited, visited};

struct EBox
{
    VisitIf  mark;   // ���ʱ��
    int      ivex;   // �ñ������ĵ�һ�������λ��
    int      jvex;   // �ñ������ĵڶ��������λ��
    EBox     *ilink; // ָ����������i����һ����
    EBox     *jlink; // ָ����������j����һ����
    InfoType *info;  // �ñ���Ϣָ�룬��ָ��Ȩֵ��������Ϣ
};

struct VexBox
{
    VertexType data;       // ����ֵ
    EBox       *firstedge; // ָ���һ�������ö���ı�
};

struct AMLGraph
{
    VexBox adjmulist[MAX_VERTEX_NUM];
    int    vexnum;  // ��ǰ������
    int    edgenum; // ��ǰ����
};


// ����ͼ���ڽӶ��ر�Ļ�����������

int LocateVex(AMLGraph G, VertexType u);
// ��ʼ����������ͼG���ڣ�u��G�ж�������ͬ����
// �����������G�д��ڶ���u���򷵻ظö���������ͼ��λ�ã����򷵻�-1

void CreateGraph(AMLGraph &G);
// ��������������ڽӶ��ر�洢�ṹ����������ͼG

VertexType& GetVex(AMLGraph G, int v);
// ��ʼ����������ͼG���ڣ�v��G��ĳ����������
// �������������v��ֵ

Status PutVex(AMLGraph &G, VertexType v, VertexType value);
// ��ʼ����������ͼG���ڣ�v��G��ĳ������
// �����������v����ֵvalue

int FirstAdjVex(AMLGraph G, VertexType v);
// ��ʼ����������ͼG���ڣ�v��G��ĳ������
// �������������v�ĵ�һ���ڽӶ������ţ�
//           ��������G��û���ڽӶ��㣬�򷵻�-1

int NextAdjVex(AMLGraph G, VertexType v, VertexType w);
// ��ʼ����������ͼG���ڣ�v��G��ĳ�����㣬w��v���ڽӶ���
// �������������v��(�����w��)��һ���ڽӶ������ţ�
//           ��w��v�����һ���ڽӵ㣬�򷵻�-1

Status InsertVex(AMLGraph &G, VertexType v);
// ��ʼ����������ͼG���ڣ�v��G�ж�������ͬ����
// �����������G�������¶���v

Status DeleteArc(AMLGraph &G, VertexType v, VertexType w);
// ��ʼ����������ͼG���ڣ�v��w��G����������
// �����������G��ɾ���� <v, w> 

Status DeleteVex(AMLGraph &G, VertexType v);
// ��ʼ����������ͼG���ڣ�v��G��ĳ������
// ���������ɾ��G�ж���v������صı�

void DestroyGraph(AMLGraph &G);
// ��ʼ����������ͼG����
// �����������������ͼG

Status InsertArc(AMLGraph &G, VertexType v, VertexType w);
// ��ʼ����������ͼG���ڣ�v��W��G����������
// �����������G������ <v, w> 

void DFSTraverse(AMLGraph G, void(*visit)(VertexType));
// ��ʼ������ͼG���ڣ�Visit�Ƕ����Ӧ�ú���
// ����������ӵ�1��������������ȱ���ͼG��
//           ����ÿ��������ú���Visitһ���ҽ�һ��
 
void BFSTraverse(AMLGraph G, void(*Visit)(VertexType));
// ��ʼ������ͼG���ڣ�Visit�Ƕ����Ӧ�ú���
// ����������ӵ�1�������𣬰�������ȷǵݹ����ͼG������ÿ��������ú���
//           Visitһ���ҽ�һ�Ρ�ʹ�ø�������Q�ͷ��ʱ�־����visite

void Display(AMLGraph G);
// ����������������ͼ���ڽӶ��ر�G

#endif