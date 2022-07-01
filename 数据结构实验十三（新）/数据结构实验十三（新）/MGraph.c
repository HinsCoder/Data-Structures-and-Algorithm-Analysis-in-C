#include"MGraph.h"

void CreateVexs(MGraph* G)
{
	// ���붥����Ϣ�����������  
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
	int final[MAXV];			 // final[w]=1��ʾ��ö���v0��vw�����·��  
	for (v = 0; v < G.n; v++)    // ��ʼ������  
	{
		final[v] = 0;			// ȫ�������ʼ��Ϊδ֪���·��״̬  
		(*D)[v] = G.edges[v0][v];  // ����v0�������ߵĶ������Ȩֵ  
		(*P)[v] = -1;				// ��ʼ��·������PΪ-1  ��ʾ��δ�ҵ����·��
	}

	(*D)[v0] = 0;  // v0��v0·��Ϊ0  
	final[v0] = 1;    // v0��v0����Ҫ��·��  

	// ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��  
	for (v = 1; v < G.n; v++)
	{
		min = INF;    // ��ǰ��֪��v0������������  
		for (w = 0; w < G.n; w++) // Ѱ����v0����Ķ���  
		{
			if (!final[w] && (*D)[w] < min)  //�������û�б����ʹ�
			{
				k = w;         // kΪ���Ҷ�����±�
				min = (*D)[w];    // w������v0���������minΪ���·����ֵ  
			}
		}
		final[k] = 1;    // ��Ŀǰ�ҵ�������Ķ�����Ϊ1  
		for (w = 0; w < G.n; w++) // ������ǰ���·��������  
		{
			if (!final[w] && (min + G.edges[k][w] < (*D)[w]))
			{ //  ˵���ҵ��˸��̵�·�����޸�D[w]��P[w]  
				(*D)[w] = min + G.edges[k][w];  // �޸ĵ�ǰ·������  
				(*P)[w] = k;
			}
		}
	}
	DisPath(G, D, P, final,v0);
}

void DisPath(MGraph g, int dist[], int path[], int s[], int v)
{
	int i = 0, j = 0, k = 0;
	int apath[MAXV], d = 0;//���һ�����·��(����)���䶥�����
	for (i = 0; i < g.n; i++)//ѭ������Ӷ���v��i��·�� 
	{
		if (s[i] == 1 && i != v)
		{
			printf("  ��%c��%c�����·������Ϊ:%d\t·��Ϊ:", g.vexs[0], g.vexs[i], dist[i]);
			d = 0;
			apath[d] = i;		//���·���ϵ��յ�
			k = path[i];
				while (k != -1)
				{
					d++;
					apath[d] = k;
					k = path[k];
				}
				d++;
				apath[d] = v;		   //���·���ϵ���� 
				printf("%c ", g.vexs[apath[d]]);//�������� 
				for (j = d - 1; j >= 0; j--)	//������������� 
					printf("%c ", g.vexs[apath[j]]);
				printf("\n");
		}
	}
}
