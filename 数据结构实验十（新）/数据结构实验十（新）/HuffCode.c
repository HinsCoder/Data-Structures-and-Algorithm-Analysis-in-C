#include"HuffCode.h"
void HuffmanCreate(HuffNode *ht, int n)
{
	int i, k, lnode, rnode;				//lnode��rnodeΪѰ��ʱȨֵ��С���������
	int min1, min2;
	for (i = 0; i < 2 * n - 1; i++)		//��������г�ʼ�� 
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;    //�����н���Ϊ-1��־δ���빹��������Ľ��
	}
	for (i = n; i < 2 * n - 1; i++)
	{
		min1 = min2 = INF;  //��ʼ��,��min1,min2Ϊ�������ֵ 
		lnode = rnode = -1;
		for (k = 0; k <= i - 1; k++)	//������ht[]����Ȩֵ��С���������
		{
			if (ht[k].parent == -1)	// ֻ����δ���빹��Ķ������Ľ���в��� 
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
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;  //������Ȩֵ��
		ht[i].lchild = lnode;   //lnodeΪ�½������� 
		ht[i].rchild = rnode;   //rnodeΪ�½����Һ���
		ht[lnode].parent = i;
		ht[rnode].parent = i; 	//lnode, rnode����˫��Ϊ�½��i 
	}
	printf("�������������ɹ�!\n");
}

void PrintHaffman(HuffNode *ht, int n)
{
	int j = 0;
	printf("���  Ȩ   ���ڵ�  ��   ��\n");
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
	printf("�������������:\n");
	for (i = 0; i < n; i++)
	{
		printf(" %c ", ht[i].data);
		for (k = hcd[i].start; k <= n; k++)//������������� 
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
		hc.start = n; 	//��ʼλ�� 
		c = i;       	//��Ҷ�ӽ�㿪ʼ���� 
		f = ht[i].parent;
		while (f != -1)  	//ֱ������Ϊֹ 
		{
			if (ht[f].lchild == c)
			{
				hc.code[hc.start--] = '0';//�涨������Ϊ����0  
			}
			else
			{
				hc.code[hc.start--] = '1'; //�涨������Ϊ����1  
			}
			c = f;
			f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}