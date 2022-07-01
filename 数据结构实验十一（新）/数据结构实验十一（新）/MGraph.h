#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define INF 32767
#define MAXV 10        //��󶥵����

int visited[MAXV]; // ���ʱ�־������  

//ͼ�Ķ���  
typedef struct
{
	int edges[MAXV][MAXV];   //�ڽӾ��� 
	int n, e;				 //������������ 
	int vexs[MAXV];   //��Ŷ�����Ϣ 
}MGraph;

//��������ͼ
void CreateVexs(MGraph* G);

//����ڽӾ���g
void DispMat(MGraph g);

//�ڽӾ�������ĳ��v�����
void InDegree(MGraph g, int v);

//�ڽӾ�������ĳ��v�ĳ���
void OutDegree(MGraph g, int v);

// �ڽӾ����������ȵݹ��㷨  
void DFS(MGraph G, int i);

// �ڽӾ������ȱ�������  
void DFSTraverse(MGraph G);

// �ڽӾ���Ĺ�ȱ����㷨  
void BFSTraverse(MGraph G);
