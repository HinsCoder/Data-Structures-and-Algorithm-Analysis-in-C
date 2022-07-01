#include"MGraph.h"

void CreateVexs(MGraph* G)
{
	// 读入顶点信息，建立顶点表  
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
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

void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D)
{

	int v, w, k, min;
	int final[MAXV];			 // final[w]=1表示求得顶点v0至vw的最短路径  
	for (v = 0; v < G.n; v++)    // 初始化数据  
	{
		final[v] = 0;			// 全部顶点初始化为未知最短路径状态  
		(*D)[v] = G.edges[v0][v];  // 将与v0点有连线的顶点加上权值  
		(*P)[v] = -1;				// 初始化路径数组P为-1  表示暂未找到最短路径
	}

	(*D)[v0] = 0;  // v0至v0路径为0  
	final[v0] = 1;    // v0至v0不需要求路径  

	// 开始主循环，每次求得v0到某个v顶点的最短路径  
	for (v = 1; v < G.n; v++)
	{
		min = INF;    // 当前所知离v0顶点的最近距离  
		for (w = 0; w < G.n; w++) // 寻找离v0最近的顶点  
		{
			if (!final[w] && (*D)[w] < min)  //如果顶点没有被访问过
			{
				k = w;         // k为所找顶点的下标
				min = (*D)[w];    // w顶点离v0顶点更近，min为最短路径的值  
			}
		}
		final[k] = 1;    // 将目前找到的最近的顶点置为1  
		for (w = 0; w < G.n; w++) // 修正当前最短路径及距离  
		{
			if (!final[w] && (min + G.edges[k][w] < (*D)[w]))
			{ //  说明找到了更短的路径，修改D[w]和P[w]  
				(*D)[w] = min + G.edges[k][w];  // 修改当前路径长度  
				(*P)[w] = k;
			}
		}
	}
	DisPath(G, D, P, final,v0);
}

void DisPath(MGraph g, int dist[], int path[], int s[], int v)
{
	int i = 0, j = 0, k = 0;
	int apath[MAXV], d = 0;//存放一条最短路径(逆向)及其顶点个数
	for (i = 0; i < g.n; i++)//循环输出从顶点v到i的路径 
	{
		if (s[i] == 1 && i != v)
		{
			printf("  从%c到%c的最短路径长度为:%d\t路径为:", g.vexs[0], g.vexs[i], dist[i]);
			d = 0;
			apath[d] = i;		//添加路径上的终点
			k = path[i];
				while (k != -1)
				{
					d++;
					apath[d] = k;
					k = path[k];
				}
				d++;
				apath[d] = v;		   //添加路径上的起点 
				printf("%c ", g.vexs[apath[d]]);//先输出起点 
				for (j = d - 1; j >= 0; j--)	//再输出其他顶点 
					printf("%c ", g.vexs[apath[j]]);
				printf("\n");
		}
	}
}
