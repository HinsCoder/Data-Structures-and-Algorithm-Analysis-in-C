#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 50
typedef char DataType; 
typedef struct
{
	DataType data;  // 数据用字符表示 
	double weight;  // 权值 
	int parent;     /*双亲*/
	int lchild;     /*左孩子*/
	int rchild;     /*右孩子*/
}HuffNode;
typedef struct     /*哈夫曼编码的存储结构 */
{
	DataType cd[MAXNUM];	/*存放编码位串*/
	int start;	/*编码的起始位置*/
}HuffCode;
/*构造哈夫曼树*/
void HuffmanCreate(HuffNode ht[], int n)
{
	int i, k, lnode, rnode;
	double min1, min2;
	for (i = 0; i < 2 * n - 1; i++)		/*对数组进行初始化*/
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	for (i = n; i < 2 * n - 1; i++)
	{
		min1 = min2 = 32767;  /*初始化,令min1,min2为整数最大值*/
		lnode = rnode = -1;
		for (k = 0; k <= i - 1; k++)	//从数组ht[]中找权值最小的两个结点
		{
			if (ht[k].parent == -1)	// 只在尚未参与构造的二叉树的结点中查找 
			{
				if (ht[k].weight < min1)
				{
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2)
				{
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		}
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode;   //lnode为新结点的左孩子 
		ht[i].rchild = rnode;   //lrnode为新结点的右孩子
		ht[lnode].parent = i;
		ht[rnode].parent = i; 	//lnode, rnode结点的双亲为新结点i 
	}
	printf("哈夫曼树建立成功!\n");
}
/*输出哈夫曼编码和平均查找长度*/
void PrintHuffCode(HuffNode ht[], HuffCode hcd[], int n)
{
	int i, k;
	int sum = 0, m = 0, j;
	printf("输出哈夫曼编码:\n");
	for (i = 0; i < n; i ++)
	{
		j = 0;
		printf(" %c ", ht[i].data);
		for (k = hcd[i].start; k <= n; k ++)/*输出哈夫曼编码*/
		{
			printf(" %c", hcd[i].cd[k]);
			j ++;
		}
		printf("\n");
		m += ht[i].weight;
		sum += ht[i].weight * j;
	}
	printf("\n平均查找长度=%f", 1.0 * sum / m);
}
				/*构造哈夫曼编码*/
void EnCoding(HuffNode ht[], HuffCode hcd[],int n)
{
	int i, f, c;
	HuffCode hc;
	for (i = 0; i < n; i++)
	{
		hc.start = n; 	//起始位置 
		c = i;       	//从叶子结点开始向上 
		f = ht[i].parent;
		while (f != -1)  	//直到树根为止 
		{
			if (ht[f].lchild == c)
			{
				hc.cd[hc.start--] = '0';/*规定左子树为代码0 */
			}
			else
			{
				hc.cd[hc.start--] = '1'; /*规定右子树为代码1 */
			}
			c = f;
			f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}
			
	
int main()
{
	int n = 8, i;
	char str[] = { 'A','B','C', 'D', 'E','F','G' , 'H'};
	int fnum[] = { 9,5,3,7,6,2,1,1 };
	HuffNode ht[2 * MAXNUM];
	HuffCode hcd[MAXNUM];
	for (i = 0; i < n; i ++)
	{
		ht[i].data = str[i];
		ht[i].weight = fnum[i];
	}
	HuffmanCreate(ht,n);
	EnCoding(ht,hcd,n);
	PrintHuffCode(ht, hcd, n);
	return 0;
}


