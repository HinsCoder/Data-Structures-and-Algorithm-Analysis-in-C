#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXEDGE 20
#define INF 32767
#define MAXV 20        //最大顶点个数

//图的定义  
typedef struct
{
	int edges[MAXV][MAXV];   //邻接矩阵 
	int n, e;				 //顶点数、弧数 
	char vexs[MAXV];   //存放顶点信息 
}MGraph;

typedef int Patharc[MAXV];        //用于存储最短路径下标的数组
typedef int ShortPathTable[MAXV]; //用于存储到各点最短路径的权值和

//创建顶点图
void CreateVexs(MGraph* G);

//输出邻接矩阵g
void DispMat(MGraph g);

//  Dijkstra算法，求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v] 
//  P[v]的值为前驱顶点下标,D[v]表示v0到v的最短路径长度和 
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D);

//输出
void DisPath(MGraph g, int dist[], int path[], int s[], int v);
