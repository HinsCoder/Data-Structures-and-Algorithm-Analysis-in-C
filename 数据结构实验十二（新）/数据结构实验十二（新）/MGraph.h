#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXEDGE 20     //���߼�����
#define INF 32767	   //�����������ֵ
#define MAXV 20        //��󶥵����

//ͼ�Ķ���  
typedef struct
{
	int edges[MAXV][MAXV];   //�ڽӾ��� 
	int n, e;				 //������������ 
	char vexs[MAXV];   //��Ŷ�����Ϣ 
}MGraph;

// �Ա߼�����Edge�ṹ�Ķ���
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   

//��������ͼ
void CreateVexs(MGraph* G);

//����ڽӾ���g
void DispMat(MGraph g);

//Prim�㷨������С������ 
void MiniSpanTree_Prim(MGraph G);

//Kruskal�㷨������С������ 
void MiniSpanTree_Kruskal(MGraph G);
