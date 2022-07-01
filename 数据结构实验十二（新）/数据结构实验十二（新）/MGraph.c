#include"MGraph.h"
#include"SqQueue.h"

void CreateVexs(MGraph* G)
{
	// 读入顶点信息，建立顶点表  
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';
	G->vexs[6] = 'G';
}

void DispMat(MGraph g)
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] >= 0 && g.edges[i][j] < INF)
				printf(" %-3d ", g.edges[i][j]);
			else
				printf("%s", " INF ");
		printf("\n");
	}
}

// Prim算法生成最小生成树   
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXV];		// 保存相关顶点下标  
	int lowcost[MAXV];	// 保存相关顶点间边的权值  
	lowcost[0] = 0;// 初始化第一个权值为0，即v0加入生成树  
			// lowcost的值为0，在这里就是此下标的顶点已经加入生成树  
	adjvex[0] = 0;			// 初始化第一个顶点下标为0  
	for (i = 1; i < G.n; i++)	// 循环除下标为0外的全部顶点  
	{
		lowcost[i] = G.edges[0][i];	// 将v0顶点与之有边的权值存入数组  
		adjvex[i] = 0;					// 初始化都为v0的下标  
	}
	for (i = 1; i < G.n; i++)
	{
		min = INF;		// 初始化最小权值为∞    
		j = 1; k = 0;	// j用来做顶点下标循环的变量，k用来存储最小权值的顶点下标
		while (j < G.n)	// 循环全部顶点  
		{
			if (lowcost[j] != 0 && lowcost[j] < min)// 如果权值不为0且权值小于min  
			{
				min = lowcost[j];	// 则让当前权值成为最小值  
				k = j;			// 将当前最小值的下标存入k  
			}
			j++;
		}
		printf("边<%c, %c>权为%d\n", G.vexs[adjvex[k]], G.vexs[k], min);// 打印当前顶点边中权值最小的边  
		lowcost[k] = 0;// 将当前顶点的权值设置为0,表示此顶点已经完成任务  
		for (j = 1; j < G.n; j++)	// 循环所有顶点  
		{
			if (lowcost[j] != 0 && G.edges[k][j] < lowcost[j])
			{// 如果下标为k顶点各边权值小于此前这些顶点未被加入生成树权值  
				lowcost[j] = G.edges[k][j];// 将较小的权值存入lowcost相应位置  
				adjvex[j] = k;				// 将下标为k的顶点存入adjvex  
			}
		}
	}
}

// 交换权值 以及头和尾  
void Swap(Edge* edges, int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

// 对权值进行排序  
void sort(Edge* edges, MGraph* G)
{
	int i, j;
	for (i = 0; i < G->e; i++)
	{
		for (j = i + 1; j < G->e; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				Swap(edges, i, j);
			}
		}
	}
}

// 查找连线顶点的尾部下标  
int Find(int* circuit, int f)
{
	while (circuit[f] > 0)
	{
		f = circuit[f];
	}
	return f;
}

// 生成最小生成树  
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, n, m;
	int k = 0;
	int circuit[MAXV];// 定义一数组用来判断边与边是否形成环路  
	Edge edges[MAXEDGE];// 定义边集数组,edge的结构为begin,end,weight,均为整型  

	// 将邻接矩阵G转化为边集数组edges并按权由小到大排序
	for (i = 0; i < G.n - 1; i++)
	{
		for (j = i + 1; j < G.n; j++)
		{
			if (G.edges[i][j] < INF)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G.edges[i][j];
				k++;
			}
		}
	}
	sort(edges, &G);

	for (i = 0; i < G.n; i++)
		circuit[i] = 0;	// 初始化数组值为0  
	for (i = 0; i < G.e; i++)	// 循环每一条边  
	{
		n = Find(circuit, edges[i].begin);
		m = Find(circuit, edges[i].end);
		if (n != m) // 假如n与m不等，说明此边没有与现有的生成树形成环路  
		{
			circuit[n] = m;	// 将此边的结尾顶点放入下标为起点的circuit中。  
							// 表示此顶点已经在生成树集合中  
			printf("边<%c, %c>权为%d\n", G.vexs[edges[i].begin], G.vexs[edges[i].end], edges[i].weight);
		}
	}
}