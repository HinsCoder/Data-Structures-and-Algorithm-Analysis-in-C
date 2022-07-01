#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>   
#include <malloc.h>
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

// 交换L中数组r的下标为i和j的值 
void swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

// 对顺序表L作直接插入排序 
void InsertSort(SqList* L)
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->r[i] < L->r[i - 1]) // 需将L->r[i]插入有序子表 
		{
			L->r[0] = L->r[i]; // 暂存在L->r[0]  
			for (j = i - 1; L->r[j] > L->r[0]; j--)
				L->r[j + 1] = L->r[j]; // 记录后移 
			L->r[j + 1] = L->r[0]; // 插入到正确位置 
		}
	}
}

// 对顺序表L作冒泡排序 
void BubbleSort(SqList* L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--)  /* 注意j是从后往前循环 */
		{
			if (L->r[j] > L->r[j + 1]) /* 若前者大于后者（注意这里与上一算法的差异）*/
			{
				swap(L, j, j + 1);/* 交换L->r[j]与L->r[j+1]的值 */
			}
		}
		static int i = 0;	   //静态变量
		printf("        第%d趟排序结果：", ++i);
		print(*L);
	}
}

// 快速排序 （冒泡排序的升级版）
int Partition(SqList* L, int low, int high)
{
	int pivotkey;         //枢轴         定义详见注释②
	pivotkey = L->r[low]; // 用子表的第一个记录作枢轴记录 
	while (low < high)    //  从表的两端交替地向中间扫描 
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		swap(L, low, high);// 将比枢轴记录小的记录交换到低端 
		while (low < high && L->r[low] <= pivotkey)
			low++;
		swap(L, low, high);// 将比枢轴记录大的记录交换到高端 
	}
	static int i = 0;	   //静态变量
	printf("        第%d趟排序结果：", ++i);
	print(*L);
	return low; // 返回枢轴所在位置 
}

// 对顺序表L中的子序列L->r[low..high]作快速排序  有点像二分查找
void QSort(SqList* L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high); //  将L->r[low - high]一分为二，算出枢轴值pivot 
		QSort(L, low, pivot - 1);		//  对低子表递归排序  
		QSort(L, pivot + 1, high);		//  对高子表递归排序 
	}
}

// 对顺序表L作快速排序 
void QuickSort(SqList* L)
{
	QSort(L, 1, L->length);             //1为第一个元素，L->length为最后一个元素
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

//归并排序
//将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] 
void Merge(int SR[], int TR[], int i, int m, int n, SqList* L)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)	// 将SR中记录由小到大地并入TR 
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];		// 将剩余的SR[i..m]复制到TR 
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];		// 将剩余的SR[j..n]复制到TR 
	}
	static int c = 0;	   //静态变量
	printf("        第%d趟排序结果：", ++c);
	print(*L);
}

//递归法
//将SR[s..t]归并排序为TR1[s..t] 
void MSort(int SR[], int TR1[], int s, int t,SqList* L)
{
	int m;
	int TR2[MAXSIZE + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;			// 将SR[s..t]平分为SR[s..m]和SR[m+1..t] 
		MSort(SR, TR2, s, m,L);		// 递归地将SR[s..m]归并为有序的TR2[s..m] 
		MSort(SR, TR2, m + 1, t,L);	// 递归地将SR[m+1..t]归并为有序的TR2[m+1..t] 
		Merge(TR2, TR1, s, m, t,L);	// 将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t] 
	}

}

// 对顺序表L作归并排序 
void MergeSort(SqList* L)
{
	MSort(L->r, L->r, 1, L->length, L);
}

////基数排序
//int get_num(int number, int pos) 
//{
//	int num = 0;
//	while (pos--) {
//		num = number % 10;
//		number = number / 10;
//	}
//	return num;
//}
//
//void Rsort(SqList* L, int array_length)
//{
//	int* bucket[10];
//	for (int i = 0; i < 10; ++i) 
//	{
//		bucket[i] = (int*)malloc(sizeof(int) * array_length + 1);
//		bucket[i][0] = 0;//桶的第一位保存桶中元素个数
//	}
//	for (int b = 1; b <= 31; ++b) 
//	{
//		for (int i = 0; i < array_length; ++i) 
//		{
//			int num = get_num(L->r[i], b);//计算每个位上的数字（个位、十位、百位...）
//			int index = ++bucket[num][0];//计算下标
//			bucket[num][index] = L->r[i];//保存到桶中
//		}
//		for (int i = 0, k = 0; i < 10; i++) 
//		{
//			for (int j = 1; j <= bucket[i][0]; ++j) 
//			{
//				L->r[k++] = bucket[i][j];//从桶里面按顺序取出来
//			}
//			bucket[i][0] = 0;//下标清零
//		}
//		static int c = 0;	   //静态变量
//		printf("        第%d趟排序结果：", ++c);
//		print(*L);
//	}
//}
//
//// 对顺序表L作基数排序 
//void RadixSort(SqList* L)
//{
//	Rsort(L, L->length);
//}

int main()
{
	int i;
	int arr[] = { 40, 27, 28, 12, 15, 50, 7 };
	int sz = sizeof(arr) / sizeof(arr[0]);      //数组元素个数
	SqList L0, L1, L2, L3, L4, L5, L6;
	for (i = 0; i < sz; i++)
		L0.r[i + 1] = arr[i];
	L0.length = sz;
	L6 = L5 = L4 = L3 = L2 = L1 = L0;
	printf("排序前:\n");
	print(L0);

	printf("直接插入排序:\n");
	InsertSort(&L1);
	print(L1);

	printf("冒泡排序:\n");
	BubbleSort(&L2);
	print(L2);

	printf("快速排序:\n");
	QuickSort(&L3);
	print(L3);

	printf("堆排序:\n");
	HeapSort(&L4);
	print(L4);

	printf("归并排序:\n");
	MergeSort(&L5);
	print(L5);

	//printf("基数排序:\n");
	//RadixSort(&L6);
	//print(L6);
	return 0;

	return 0;
}

//注释①：研究表明，当增量序列为dlta[k]=2的t-k+1次方-1（0<=k<=t<=log2(n+1))时，效率不错
//注释②：先选取数组中第一个关键字，然后想尽办法将它放到一个位置，使得它左边的值都比它小，
//右边的值都比它大，我们将这样的关键字称为枢轴（pivot）。