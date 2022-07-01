#include"MGraph.h"
int main(void)
{
	int i, j;
	MGraph g;
	int A[MAXV][6] = 
	{ {0,5,INF,7,INF,INF},
	  {INF,0,4,INF,INF,INF},
	  {8,INF,0,INF,INF,9},
	  {INF,INF,5,0,INF,6},
	  {INF,INF,INF,5,0,INF},
	  {3,INF,INF,INF,1,0} };
	g.n = 6;        //��������
	g.e = 10;		//�ܱ���
	
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j]; //���δ���

	CreateVexs(&g);      //���붥����Ϣ

	printf("�����ȨͼG���ڽӾ���:\n"); 
	DispMat(g);
	printf("ͼG��ÿ����������:\n");
	for (i = 0; i < g.n; i++)
		InDegree(g, i);
	printf("\n��ȱ�����");
	DFSTraverse(g);
	printf("\n��ȱ�����");
	BFSTraverse(g);
	printf("\n");
	return 0;
}
