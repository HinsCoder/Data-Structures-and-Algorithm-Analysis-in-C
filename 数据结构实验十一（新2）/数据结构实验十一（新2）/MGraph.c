#include"MGraph.h"

void DispMat(MGraph g) 
{
	int i, j;
	for (i = 0; i < g.n;i++) 
	{
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j >= 0 && g.edges[i][j] < INF)
				printf("%5d", g.edges[i][j);
			else
				printf("%s", " INF");
		printf("\n");
	}
}

void InDegreeM(MGraph g, int v) 
{
	int i, num = 0; 
	for (i = 0; i < g.n; i++)
	{
		if (g.edges[i][v] != 0 && g.edges[i][v] != INF)
			num++;
	}	
	printf("%3d: %2d\n", v, num);
}

void outDegreeM(MGraph g, int v)
{
	int i, num = 0;
	for (i = 0; i < g.n; i++)
	{
		if (g.edges[v][i] != 0 && g.edges[v][i] != INF)
			num++;
	}
	printf("%3d: %2d\n", v, num);
}

void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE; /* 初始所有顶点状态都是未访问过状态 */
	for (i = 0; i < G.numVertexes; i++)
		if (!visited[i]) /* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
			DFS(G, i);
}

void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);		/* 初始化一辅助用的队列 */
	for (i = 0; i < G.numVertexes; i++)  /* 对每一个顶点做循环 */
	{
		if (!visited[i])	/* 若是未访问过就处理 */
		{
			visited[i] = TRUE;		/* 设置当前顶点访问过 */
			printf("%c ", G.vexs[i]);/* 打印顶点，也可以其它操作 */
			EnQueue(&Q, i);		/* 将此顶点入队列 */
			while (!QueueEmpty(Q))	/* 若当前队列不为空 */
			{
				DeQueue(&Q, &i);	/* 将队对元素出队列，赋值给i */
				for (j = 0; j < G.numVertexes; j++)
				{
					/* 判断其它顶点若与当前顶点存在边且未访问过  */
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;			/* 将找到的此顶点标记为已访问 */
						printf("%c ", G.vexs[j]);	/* 打印顶点 */
						EnQueue(&Q, j);				/* 将找到的此顶点入队列  */
					}
				}
			}
		}
	}
}