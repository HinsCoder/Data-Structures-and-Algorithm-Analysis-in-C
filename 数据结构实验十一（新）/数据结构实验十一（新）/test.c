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
	g.n = 6;        //顶点总数
	g.e = 10;		//总边数
	
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j]; //依次存入

	CreateVexs(&g);      //读入顶点信息

	printf("有向带权图G的邻接矩阵:\n"); 
	DispMat(g);
	printf("图G中每个顶点的入度:\n");
	for (i = 0; i < g.n; i++)
		InDegree(g, i);
	printf("\n深度遍历：");
	DFSTraverse(g);
	printf("\n广度遍历：");
	BFSTraverse(g);
	printf("\n");
	return 0;
}
