#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXEDGE 20     //最大边集个数
#define INF 32767	   //定义整数最大值
#define MAXV 20        //最大顶点个数

//图的定义  
typedef struct
{
	int edges[MAXV][MAXV];   //邻接矩阵 
	int n, e;				 //顶点数、弧数 
	char vexs[MAXV];   //存放顶点信息 
}MGraph;

// 对边集数组Edge结构的定义
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;   

//创建顶点图
void CreateVexs(MGraph* G);

//输出邻接矩阵g
void DispMat(MGraph g);

//Prim算法生成最小生成树 
void MiniSpanTree_Prim(MGraph G);

//Kruskal算法生成最小生成树 
void MiniSpanTree_Kruskal(MGraph G);
