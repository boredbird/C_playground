// C8-1.h �߽��ʶ�������ÿռ��Ľ��ṹ
// head��foot�ֱ��ǿ����ÿռ���н��ĵ�һ���ֺ����һ����(WORD)

#ifndef C_8_1_H
#define C_8_1_H

typedef struct WORD // ������
{
    union
    {
        WORD *llink;  // ͷ����ָ��ǰ�����
        WORD *uplink;  // �ײ���ָ�򱾽��ͷ��
    }; 
    int  tag;     // ���־��0�����У�1��ռ�ã�ͷ����β������
    int  size;    // ͷ���򣬿��С
    WORD *rlink;  // ͷ����ָ���̽��
}WORD, head, foot, *Space;  // *Space�������ÿռ�ָ������

#define FootLoc(p) ((p)+((p)->size-1)) // �������ĺ궨�壬ָ��p��ָ���ĵײ�(���һ����)
#define MAX 1000 // �����ÿռ�Ĵ�С(��WORD���ֽ���Ϊ��λ)
#define e   10   // �����С�ߴ� - 1(��WORD���ֽ���Ϊ��λ)



Space AllocBoundTag(Space &pav, int n); 
// �������ÿռ��pav���в�С��n�Ŀ��п飬�������Ӧ�Ĵ洢�飬���������׵�ַ�����򷵻�NULL
// �����������ÿռ���գ���pavָ����иշ�����Ľ��ĺ�̽��

void Reclaim(Space &pav, Space &p);
// �߽��ʶ���Ļ����㷨����p��ָ���ͷſ���յ������ÿռ��pav��

void Print(Space p);
// ���p��ָ�Ŀ����ÿռ��

void PrintUser(Space p[]);
// ���p������ָ���ѷ���ռ�


#endif