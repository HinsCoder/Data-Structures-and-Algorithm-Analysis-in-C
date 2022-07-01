#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<malloc.h>
#define INF 32767
#define MAXV 100        //��󶥵����
typedef int InfoType;

/*�ڽӾ������͵Ķ���*/
typedef struct
{
	int no;   /*������*/
	InfoType info;/*����������Ϣ*/
} VertexType;

/*ͼ�Ķ��� */
typedef struct
{
	int edges[MAXV][MAXV];   //�ڽӾ��� 
	int n, e;				 /*������������*/
	VertexType vexs[MAXV];   /*��Ŷ�����Ϣ*/
}MGraph;

//����ڽӾ���g
void DispMat(MGraph g);

//�ڽӾ�������ĳ��v�����
void InDegreeM(MGraph g, int v);

//�ڽӾ�������ĳ��v�ĳ���
void OutDegreeM(MGraph g, int v);

/* �ڽӾ������ȱ������� */
void DFSTraverse(MGraph G);

/* �ڽӾ���Ĺ�ȱ����㷨 */
void BFSTraverse(MGraph G);



