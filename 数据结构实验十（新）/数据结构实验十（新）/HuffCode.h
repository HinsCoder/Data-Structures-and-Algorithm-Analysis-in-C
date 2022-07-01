#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
#define INF 32767  //整数最大值

typedef struct
{
	char data;  // 数据用字符表示 
	int weight;		// 权值 
	int parent;     // 双亲 
	int lchild;     // 左孩子 
	int rchild;     // 右孩子 
}HuffNode;

typedef struct      //哈夫曼编码的存储结构  
{
	int code[MAXNUM];	//存放编码位串 
	int start;				//编码的起始位置 
}HuffCode;


//构造哈夫曼树 
void HuffmanCreate(HuffNode *ht, int n);

//输出哈夫曼树（数组形式）
void PrintHaffman(HuffNode *ht, int X);

//输出哈夫曼编码和平均查找长度 
void PrintHuffCode(HuffNode *ht, HuffCode *hcd, int n);

//构造哈夫曼编码 
void EnCoding(HuffNode *ht, HuffCode *hcd, int n);