#include"MGraph.h"
int main(void)
{
	int i, j;
	MGraph g;
	int A[MAXV][7] = 
	{ {0,50,60,INF,INF,INF,INF},
	  {50,0,INF,65,40,INF,INF},
	  {60,INF,0,52,INF,INF,45},
	  {INF,65,52,0,50,30,42},
	  {INF,40,INF,50,0,70,INF},
	  {INF,INF,INF,30,70,0,INF},
	  {INF,INF,45,42,INF,INF,0} };
	g.n = 7; 
	g.e = 10;
	
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j]; 

	CreateVexs(&g);

	printf("无向带权图G的邻接矩阵:\n"); 
	DispMat(g);
	printf("\n普里姆算法的最小生成树：\n");
	MiniSpanTree_Prim(g);
	printf("\n克鲁斯卡尔算法的最小生成树：\n");
	MiniSpanTree_Kruskal(g);
	printf("\n");
	return 0;
}
