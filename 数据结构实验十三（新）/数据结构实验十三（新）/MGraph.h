#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXEDGE 20
#define INF 32767
#define MAXV 20        //��󶥵����

//ͼ�Ķ���  
typedef struct
{
	int edges[MAXV][MAXV];   //�ڽӾ��� 
	int n, e;				 //������������ 
	char vexs[MAXV];   //��Ŷ�����Ϣ 
}MGraph;

typedef int Patharc[MAXV];        //���ڴ洢���·���±������
typedef int ShortPathTable[MAXV]; //���ڴ洢���������·����Ȩֵ��

//��������ͼ
void CreateVexs(MGraph* G);

//����ڽӾ���g
void DispMat(MGraph g);

//  Dijkstra�㷨����������G��v0���㵽���ඥ��v�����·��P[v]����Ȩ����D[v] 
//  P[v]��ֵΪǰ�������±�,D[v]��ʾv0��v�����·�����Ⱥ� 
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D);

//���
void DisPath(MGraph g, int dist[], int path[], int s[], int v);
