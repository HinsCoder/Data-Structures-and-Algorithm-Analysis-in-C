#define _CRT_SECURE_NO_WARNINGS 1
void Prim(MGraph g, int v)
{
	int lowcost[MAXV], closest[MAXV], i, min, j, k;
	for (i = 0; i < g.n; i++)
	{
		closest[i] = v;
		lowcost[i] = g.edges[v][i];
	}
	for (i = 1; i < g.n; i++)
	{
		min = INF;
		for (j = 0; j < g.n; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		printf("边(%c,%c)权为:%d\n", closest[k] + 65, k + 65, min);
		lowcost[k] = 0;
		for (j = 0; j < g.n; j++)
		{
			if (g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
		}
	}
}

void Kruskal(MGraph g)
{
	int i, j, u1, v1, sn1, sn2, k;
	int vset[MAX];
	Edge E[MaxSize];
	k = 0;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.edges[i][j];
				k++;
			}
	InsertSort(E, g.e);
	for (i = 0; i < g.n; i++)
		vset[i] = i;
	k = 1;
	j = 0;
	while (k < g.n)
	{
		u1 = E[j].u;
		v1 = E[j].v;
		sn1 = vset[u1];
		sn2 = vset[v1];
		if (sn1 != sn2)
		{
			printf("边(%c,%c)权为:%d\n", u1 + 65, v1 + 65, E[j].w);
			k++;
			for (i = 0; i < g.n; i++)
			{
				if (vset[i] == sn2)
					vset[i] = sn1;
			}
		}
		j++;
	}
}

int main()
{
	MGraph g;
	VertexType node[7] = { {0,'A'},{1,'B'},{2,'C'},{3,'D'},{4,'E'},{5,'F'},{6,'G'} };
	int A[7][7] = {
	{0,50,60,INF,INF,INF,INF},
	{50,0,INF,65,40,INF,INF},
	{60,INF,0,52,INF,INF,45},
	{INF,65,52,0,50,30,42},
	{INF,40,INF,50,0,70,INF},
	{INF,INF,INF,30,70,0,INF},
	{INF,INF,45,42,INF,INF,0} };
	int j, n, a, b;
	int* p[7];
	for (int i = 0; i < 7; i++)
		p[i] = A[i];
	CreateGraph(g, node, 7, p, 7);
	printf(" 有向图G的邻接矩阵:\n");
	DispMat(g);
	printf("最小生成树：\n");
	Prim(g, 0);
	printf("\n");
	printf("最小生成树：\n");
	Kruskal(g);
}