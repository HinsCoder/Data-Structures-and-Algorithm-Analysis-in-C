#include"HuffCode.h"
void HuffmanCreate(HuffNode *ht, int n)
{
	int i, k, lnode, rnode;				//lnode和rnode为寻找时权值最小的两个结点
	int min1, min2;
	for (i = 0; i < 2 * n - 1; i++)		//对数组进行初始化 
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;    //将所有结点记为-1标志未参与构造二叉树的结点
	}
	for (i = n; i < 2 * n - 1; i++)
	{
		min1 = min2 = INF;  //初始化,令min1,min2为整数最大值 
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
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;  //两结点的权值和
		ht[i].lchild = lnode;   //lnode为新结点的左孩子 
		ht[i].rchild = rnode;   //rnode为新结点的右孩子
		ht[lnode].parent = i;
		ht[rnode].parent = i; 	//lnode, rnode结点的双亲为新结点i 
	}
	printf("哈夫曼树建立成功!\n");
}

void PrintHaffman(HuffNode *ht, int n)
{
	int j = 0;
	printf("序号  权   父节点  左   右\n");
	for (int i = 0; i < n; i++)
	{
		printf("%-6c%-6d%-6d%-6d%-6d\n", ht[i].data, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
	}
	for (int i = n,j = 1; i < 2 * n - 1; i++,j++)
	{
		printf("N%-5d%-6d%-6d%-6d%-6d\n", j, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
	}
	printf("\n");
}


void PrintHuffCode(HuffNode *ht, HuffCode *hcd, int n)
{
	int i, k;
	printf("输出哈夫曼编码:\n");
	for (i = 0; i < n; i++)
	{
		printf(" %c ", ht[i].data);
		for (k = hcd[i].start; k <= n; k++)//输出哈夫曼编码 
		{
			printf(" %c", hcd[i].code[k]);
		}
		printf("\n");
	}
}

void EnCoding(HuffNode *ht, HuffCode *hcd, int n)
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
				hc.code[hc.start--] = '0';//规定左子树为代码0  
			}
			else
			{
				hc.code[hc.start--] = '1'; //规定右子树为代码1  
			}
			c = f;
			f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}