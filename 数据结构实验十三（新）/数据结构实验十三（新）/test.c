#include"MGraph.h"
int main(void)
{
	int i, j, v, w, k;
	MGraph g;
	int A[MAXV][6] = 
	{ {0,INF,5,30,INF,INF},
	  {2,0,INF,INF,8,INF},
	  {INF,15,0,INF,INF,7},
	  {INF,INF,INF,0,INF,INF},
	  {INF,INF,INF,4,0,INF},
	  {INF,INF,INF,10,18,0} };
	g.n = 6; 
	g.e = 9;
	
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j]; 

	Patharc P;
	ShortPathTable D; // 求某点到其余各点的最短路径  

	CreateVexs(&g);

	printf("有向带权图G的邻接矩阵:\n"); 
	DispMat(g);

	printf("\n请设置一个起点：");
	scanf("%d", &v);

	ShortestPath_Dijkstra(g, v, &P, &D);
	
	printf("\n");
	return 0;
}



