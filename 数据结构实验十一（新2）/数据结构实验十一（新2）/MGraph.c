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
		visited[i] = FALSE; /* ��ʼ���ж���״̬����δ���ʹ�״̬ */
	for (i = 0; i < G.numVertexes; i++)
		if (!visited[i]) /* ��δ���ʹ��Ķ������DFS��������ͨͼ��ֻ��ִ��һ�� */
			DFS(G, i);
}

void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);		/* ��ʼ��һ�����õĶ��� */
	for (i = 0; i < G.numVertexes; i++)  /* ��ÿһ��������ѭ�� */
	{
		if (!visited[i])	/* ����δ���ʹ��ʹ��� */
		{
			visited[i] = TRUE;		/* ���õ�ǰ������ʹ� */
			printf("%c ", G.vexs[i]);/* ��ӡ���㣬Ҳ������������ */
			EnQueue(&Q, i);		/* ���˶�������� */
			while (!QueueEmpty(Q))	/* ����ǰ���в�Ϊ�� */
			{
				DeQueue(&Q, &i);	/* ���Ӷ�Ԫ�س����У���ֵ��i */
				for (j = 0; j < G.numVertexes; j++)
				{
					/* �ж������������뵱ǰ������ڱ���δ���ʹ�  */
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;			/* ���ҵ��Ĵ˶�����Ϊ�ѷ��� */
						printf("%c ", G.vexs[j]);	/* ��ӡ���� */
						EnQueue(&Q, j);				/* ���ҵ��Ĵ˶��������  */
					}
				}
			}
		}
	}
}