#include"MGraph.h"
#include"SqQueue.h"

void CreateVexs(MGraph* G)
{
	// ���붥����Ϣ�����������  
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

// Prim�㷨������С������   
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXV];		// ������ض����±�  
	int lowcost[MAXV];	// ������ض����ߵ�Ȩֵ  
	lowcost[0] = 0;// ��ʼ����һ��ȨֵΪ0����v0����������  
			// lowcost��ֵΪ0����������Ǵ��±�Ķ����Ѿ�����������  
	adjvex[0] = 0;			// ��ʼ����һ�������±�Ϊ0  
	for (i = 1; i < G.n; i++)	// ѭ�����±�Ϊ0���ȫ������  
	{
		lowcost[i] = G.edges[0][i];	// ��v0������֮�бߵ�Ȩֵ��������  
		adjvex[i] = 0;					// ��ʼ����Ϊv0���±�  
	}
	for (i = 1; i < G.n; i++)
	{
		min = INF;		// ��ʼ����СȨֵΪ��    
		j = 1; k = 0;	// j�����������±�ѭ���ı�����k�����洢��СȨֵ�Ķ����±�
		while (j < G.n)	// ѭ��ȫ������  
		{
			if (lowcost[j] != 0 && lowcost[j] < min)// ���Ȩֵ��Ϊ0��ȨֵС��min  
			{
				min = lowcost[j];	// ���õ�ǰȨֵ��Ϊ��Сֵ  
				k = j;			// ����ǰ��Сֵ���±����k  
			}
			j++;
		}
		printf("��<%c, %c>ȨΪ%d\n", G.vexs[adjvex[k]], G.vexs[k], min);// ��ӡ��ǰ�������Ȩֵ��С�ı�  
		lowcost[k] = 0;// ����ǰ�����Ȩֵ����Ϊ0,��ʾ�˶����Ѿ��������  
		for (j = 1; j < G.n; j++)	// ѭ�����ж���  
		{
			if (lowcost[j] != 0 && G.edges[k][j] < lowcost[j])
			{// ����±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ  
				lowcost[j] = G.edges[k][j];// ����С��Ȩֵ����lowcost��Ӧλ��  
				adjvex[j] = k;				// ���±�Ϊk�Ķ������adjvex  
			}
		}
	}
}

// ����Ȩֵ �Լ�ͷ��β  
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

// ��Ȩֵ��������  
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

// �������߶����β���±�  
int Find(int* circuit, int f)
{
	while (circuit[f] > 0)
	{
		f = circuit[f];
	}
	return f;
}

// ������С������  
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, j, n, m;
	int k = 0;
	int circuit[MAXV];// ����һ���������жϱ�����Ƿ��γɻ�·  
	Edge edges[MAXEDGE];// ����߼�����,edge�ĽṹΪbegin,end,weight,��Ϊ����  

	// ���ڽӾ���Gת��Ϊ�߼�����edges����Ȩ��С��������
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
		circuit[i] = 0;	// ��ʼ������ֵΪ0  
	for (i = 0; i < G.e; i++)	// ѭ��ÿһ����  
	{
		n = Find(circuit, edges[i].begin);
		m = Find(circuit, edges[i].end);
		if (n != m) // ����n��m���ȣ�˵���˱�û�������е��������γɻ�·  
		{
			circuit[n] = m;	// ���˱ߵĽ�β��������±�Ϊ����circuit�С�  
							// ��ʾ�˶����Ѿ���������������  
			printf("��<%c, %c>ȨΪ%d\n", G.vexs[edges[i].begin], G.vexs[edges[i].end], edges[i].weight);
		}
	}
}