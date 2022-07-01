#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define INF 32767
#define MAXV 10        //最大顶点个数

int visited[MAXV]; // 访问标志的数组  

//图的定义  
typedef struct
{
	int edges[MAXV][MAXV];   //邻接矩阵 
	int n, e;				 //顶点数、弧数 
	int vexs[MAXV];   //存放顶点信息 
}MGraph;

//创建顶点图
void CreateVexs(MGraph* G);

//输出邻接矩阵g
void DispMat(MGraph g);

//邻接矩阵上求某点v的入度
void InDegree(MGraph g, int v);

//邻接矩阵上求某点v的出度
void OutDegree(MGraph g, int v);

// 邻接矩阵的深度优先递归算法  
void DFS(MGraph G, int i);

// 邻接矩阵的深度遍历操作  
void DFSTraverse(MGraph G);

// 邻接矩阵的广度遍历算法  
void BFSTraverse(MGraph G);
