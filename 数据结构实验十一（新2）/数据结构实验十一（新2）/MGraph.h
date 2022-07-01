#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<malloc.h>
#define INF 32767
#define MAXV 100        //最大顶点个数
typedef int InfoType;

/*邻接矩阵类型的定义*/
typedef struct
{
	int no;   /*顶点编号*/
	InfoType info;/*顶点其他信息*/
} VertexType;

/*图的定义 */
typedef struct
{
	int edges[MAXV][MAXV];   //邻接矩阵 
	int n, e;				 /*顶点数、弧数*/
	VertexType vexs[MAXV];   /*存放顶点信息*/
}MGraph;

//输出邻接矩阵g
void DispMat(MGraph g);

//邻接矩阵上求某点v的入度
void InDegreeM(MGraph g, int v);

//邻接矩阵上求某点v的出度
void OutDegreeM(MGraph g, int v);

/* 邻接矩阵的深度遍历操作 */
void DFSTraverse(MGraph G);

/* 邻接矩阵的广度遍历算法 */
void BFSTraverse(MGraph G);



