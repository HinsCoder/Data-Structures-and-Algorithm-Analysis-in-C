#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>   
#define MAXSIZE 100   //用于要排序数组个数最大值
typedef struct
{
	int r[MAXSIZE + 1];	// 用于存储要排序数组，r[0]用作哨兵或临时变量 
	int length;			// 用于记录顺序表的长度 
}SqList;

void print(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
		printf("%d,", L.r[i]);
	printf("%d", L.r[i]);
	printf("\n");
}

void swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}  

// 堆排序 （简单选择排序的升级版）

// 已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义， 
// 本函数调整L->r[s]的关键字,使L->r[s..m]成为一个大顶堆 
void HeapAdjust(SqList* L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j *= 2) // 沿关键字较大的孩子结点向下筛选 详见注释②
	{
		if (j < m&& L->r[j] < L->r[j + 1])
			++j;					// j为关键字中较大的记录的下标 
		if (temp >= L->r[j])
			break;					// rc应插入在位置s上 
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;					// 插入 
}

//  对顺序表L进行堆排序 
void HeapSort(SqList* L)
{
	int i;
	for (i = L->length / 2; i > 0; i--) // 把L中的r构建成一个大顶堆 详见注释①
		HeapAdjust(L, i, L->length);
	printf("  先构造为一个大顶堆：");
	print(*L);
	for (i = L->length; i > 1; i--)
	{
		swap(L, 1, i);					// 将堆顶记录和当前未经排序子序列的最后一个记录交换 
		printf("                交换：");
		print(*L);
		HeapAdjust(L, 1, i - 1);		//  将L->r[1..i-1]重新调整为大顶堆 
		printf("再次构造为一个大顶堆：");
		print(*L);
	}
	printf("\n");
}

//双向冒泡排序算法，即相邻两趟排序向相反方向冒泡。
void DoubleSort(SqList* L)
{
	int left = 1, right = L->length, i = 0;
	while( left < right )
	{
		for (i = left; i < right;i++)	  //正向冒泡
		{
			if (L->r[i] > L->r[i + 1])    //找到序列中最大的
			{
				swap(L, i, i + 1);
			}
		}
		static int k = 0;
		printf("第%d次排序：",++k);
		print(*L);
		right--;
		for (i = right; i > left; i--)	  //反向冒泡
		{
			if (L->r[i] < L->r[i - 1])	  //找到序列中最小的
			{
				swap(L, i, i - 1);
			}
		}
		left++;
		printf("第%d次排序：", ++k);
		print(*L);
	}
	printf("最终排序结果为：");
}

//奇偶冒泡排序
void OddEvenSort(SqList* L)
{

	int left = 1, right = L->length, i = 0, tag = 1;   //tag=1为发生了交换的标志
	while (tag)
	{
		tag = 0;                          //tag为0表示没有发生交换
		for (i = left; i < right; i+=2)	  //扫描所有奇数项
		{
			if (L->r[i] > L->r[i + 1])    //找到序列中最大的
			{
				swap(L, i, i + 1);
				tag = 1;				  //tag为1表示发生了交换
			}
		}
		static int k = 0;
		printf("第%d次排序：", ++k);
		print(*L);
		for (i = left+1; i < right; i += 2)	  //扫描所有偶数项
		{
			if (L->r[i] > L->r[i + 1])    //找到序列中最大的
			{
				swap(L, i, i + 1);
				tag = 1;				  //tag为1表示发生了交换
			}
		}
		printf("第%d次排序：", ++k);
		print(*L);
	}
	printf("最终排序结果为：");
}


int main()
{
	int i;
	int arr[] = { 9,1,5,8,3,7,4,6,2,25,11};
	int sz = sizeof(arr) / sizeof(arr[0]);      //数组元素个数
	SqList L0, L1, L2, L3;
	for (i = 0; i < sz; i++)
		L0.r[i + 1] = arr[i];
	L0.length = sz;
	L3 = L2 = L1 = L0;
	printf("排序前:\n");
	print(L0);

	printf("堆排序:\n");
	HeapSort(&L1);
	print(L1);

	printf("冒泡排序版本①:\n");
	DoubleSort(&L2);
	print(L2);

	printf("冒泡排序版本②:\n");
	OddEvenSort(&L3);
	print(L3);
	return 0;
}

//注释①：一棵完全二叉树，如果i=1，则结点i是二叉树的根，无双亲；如果i>1，则其双亲是结点i/2 。
//那么对于有n个结点的二叉树而言，它的i值就是小于等于 n/2 了。
//注释②：由二叉树的性质可知，因为当前树为完全二叉树，当前结点序号是s，其左孩子的序号一定是2s，
//右孩子的序号一定是2s+1，,它们的孩子当然也是以2的位数序号增加。