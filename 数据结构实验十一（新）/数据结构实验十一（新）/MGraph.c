#include"MGraph.h"
#include"SqQueue.h"

void CreateVexs(MGraph* G)
{
	// ���붥����Ϣ�����������  
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

void DFS(MGraph G, int i)    //���ƶ��������������
{
	int j;
	visited[i] = 1;
	printf("%d ", G.vexs[i]);// ��ӡ����
	for (j = 0; j < G.n; j++)
		if (G.edges[i][j] != INF && !visited[j])
			DFS(G, j);// ��Ϊ���ʵ��ڽӶ���ݹ����  
}

void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.n; i++)
		visited[i] = 0; // ��ʼ���ж���״̬����δ���ʹ�״̬  
	for (i = 0; i < G.n; i++)
		if (!visited[i]) // ��δ���ʹ��Ķ������DFS
			DFS(G, i);
}

void BFSTraverse(MGraph G)    //���ƶ������Ĳ������
{
	int i, j;
	SqQueue Q;
	for (i = 0; i < G.n; i++)
		visited[i] = 0;	// ��ʼ���ж���״̬����δ���ʹ�״̬ 
	InitQueue(&Q);		// ��ʼ��һ�����õĶ���  
	for (i = 0; i < G.n; i++)  // ��ÿһ��������ѭ��  
	{
		if (!visited[i])	// ����δ���ʹ��ʹ���  
		{
			visited[i] = 1;		// ���õ�ǰ������ʹ�  
			printf("%d ", G.vexs[i]);// ��ӡ����
			EnQueue(&Q, i);		// ���˶��������  
			while (!QueueEmpty(Q))	// ����ǰ���в�Ϊ��  
			{
				DeQueue(&Q, &i);	// ���Ӷ�Ԫ�س����У���ֵ��i  
				for (j = 0; j < G.n; j++)
				{
					// �ж������������뵱ǰ������ڱ���δ���ʹ�   
					if (G.edges[i][j] != INF && !visited[j])
					{
						visited[j] = 1;			// ���ҵ��Ĵ˶�����Ϊ�ѷ���  
						printf("%d ", G.vexs[j]);	// ��ӡ����  
						EnQueue(&Q, j);				// ���ҵ��Ĵ˶��������   
					}
				}
			}
		}
	}
}