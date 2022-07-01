#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 50
typedef char DataType; 
typedef struct
{
	DataType data;  // �������ַ���ʾ 
	double weight;  // Ȩֵ 
	int parent;     /*˫��*/
	int lchild;     /*����*/
	int rchild;     /*�Һ���*/
}HuffNode;
typedef struct     /*����������Ĵ洢�ṹ */
{
	DataType cd[MAXNUM];	/*��ű���λ��*/
	int start;	/*�������ʼλ��*/
}HuffCode;
/*�����������*/
void HuffmanCreate(HuffNode ht[], int n)
{
	int i, k, lnode, rnode;
	double min1, min2;
	for (i = 0; i < 2 * n - 1; i++)		/*��������г�ʼ��*/
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	for (i = n; i < 2 * n - 1; i++)
	{
		min1 = min2 = 32767;  /*��ʼ��,��min1,min2Ϊ�������ֵ*/
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
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode;   //lnodeΪ�½������� 
		ht[i].rchild = rnode;   //lrnodeΪ�½����Һ���
		ht[lnode].parent = i;
		ht[rnode].parent = i; 	//lnode, rnode����˫��Ϊ�½��i 
	}
	printf("�������������ɹ�!\n");
}
/*��������������ƽ�����ҳ���*/
void PrintHuffCode(HuffNode ht[], HuffCode hcd[], int n)
{
	int i, k;
	int sum = 0, m = 0, j;
	printf("�������������:\n");
	for (i = 0; i < n; i ++)
	{
		j = 0;
		printf(" %c ", ht[i].data);
		for (k = hcd[i].start; k <= n; k ++)/*�������������*/
		{
			printf(" %c", hcd[i].cd[k]);
			j ++;
		}
		printf("\n");
		m += ht[i].weight;
		sum += ht[i].weight * j;
	}
	printf("\nƽ�����ҳ���=%f", 1.0 * sum / m);
}
				/*�������������*/
void EnCoding(HuffNode ht[], HuffCode hcd[],int n)
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
				hc.cd[hc.start--] = '0';/*�涨������Ϊ����0 */
			}
			else
			{
				hc.cd[hc.start--] = '1'; /*�涨������Ϊ����1 */
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


