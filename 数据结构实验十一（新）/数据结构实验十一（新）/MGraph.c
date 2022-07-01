#include"MGraph.h"
#include"SqQueue.h"

void CreateVexs(MGraph* G)
{
	// 读入顶点信息，建立顶点表  
	G->vexs[0] = 0;
	G->vexs[1] = 1;
	G->vexs[2] = 2;
	G->vexs[3] = 3;
	G->vexs[4] = 4;
	G->vexs[5] = 5;
}

void DispMat(MGraph g)
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] >= 0 && g.edges[i][j] < INF)
				printf("  %-3d", g.edges[i][j]);
			else
				printf("%s", " INF ");
		printf("\n");
	}
}

void InDegree(MGraph g, int v)
{
	int i, num = 0;
	for (i = 0; i < g.n; i++)
	{
		if (g.edges[i][v] != 0 && g.edges[i][v] != INF)
			num++;
	}
	printf("%3d: %2d\n", v, num);
}

void outDegree(MGraph g, int v)
{
	int i, num = 0;
	for (i = 0; i < g.n; i++)
	{
		if (g.edges[v][i] != 0 && g.edges[v][i] != INF)
			num++;
	}
	printf("%3d: %2d\n", v, num);
}

void DFS(MGraph G, int i)    //类似二叉树的先序遍历
{
	int j;
	visited[i] = 1;
	printf("%d ", G.vexs[i]);// 打印顶点
	for (j = 0; j < G.n; j++)
		if (G.edges[i][j] != INF && !visited[j])
			DFS(G, j);// 对为访问的邻接顶点递归调用  
}

void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.n; i++)
		visited[i] = 0; // 初始所有顶点状态都是未访问过状态  
	for (i = 0; i < G.n; i++)
		if (!visited[i]) // 对未访问过的顶点调用DFS
			DFS(G, i);
}

void BFSTraverse(MGraph G)    //类似二叉树的层序遍历
{
	int i, j;
	SqQueue Q;
	for (i = 0; i < G.n; i++)
		visited[i] = 0;	// 初始所有顶点状态都是未访问过状态 
	InitQueue(&Q);		// 初始化一辅助用的队列  
	for (i = 0; i < G.n; i++)  // 对每一个顶点做循环  
	{
		if (!visited[i])	// 若是未访问过就处理  
		{
			visited[i] = 1;		// 设置当前顶点访问过  
			printf("%d ", G.vexs[i]);// 打印顶点
			EnQueue(&Q, i);		// 将此顶点入队列  
			while (!QueueEmpty(Q))	// 若当前队列不为空  
			{
				DeQueue(&Q, &i);	// 将队对元素出队列，赋值给i  
				for (j = 0; j < G.n; j++)
				{
					// 判断其它顶点若与当前顶点存在边且未访问过   
					if (G.edges[i][j] != INF && !visited[j])
					{
						visited[j] = 1;			// 将找到的此顶点标记为已访问  
						printf("%d ", G.vexs[j]);	// 打印顶点  
						EnQueue(&Q, j);				// 将找到的此顶点入队列   
					}
				}
			}
		}
	}
}