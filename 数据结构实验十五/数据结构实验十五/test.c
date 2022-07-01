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
		static int i = 0;	   //静态变量
		printf("        第%d趟排序结果：", ++i);
		print(*L);
	}
}

// 对顺序表L作希尔排序 （直接插入排序的升级版）
void ShellSort(SqList* L)
{
	int i, j, k = 0;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;// 增量序列 选取方式见注释①
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])//  需将L->r[i]插入有序增量子表 
			{
				L->r[0] = L->r[i]; //  暂存在L->r[0] 
				for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
					L->r[j + increment] = L->r[j]; //  记录后移，查找插入位置 
				L->r[j + increment] = L->r[0]; //  插入 
			}
		}
		printf("	第%d趟排序结果: ", ++k);
		print(*L);
	} while (increment > 1);     //增量为1时就停止循环
}

// 交换L中数组r的下标为i和j的值 
void swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

// 对顺序表L作简单选择排序 
void SelectSort(SqList* L)
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		min = i;						// 将当前下标定义为最小值下标  
		for (j = i + 1; j <= L->length; j++)// 循环之后的数据  
		{
			if (L->r[min] > L->r[j])	// 如果有小于当前最小值的关键字  
				min = j;				// 将此关键字的下标赋值给min  
		}
		if (i != min)						// 若min不等于i，说明找到最小值，交换  
			swap(L, i, min);				// 交换L->r[i]与L->r[min]的值  
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

int main()
{
	int i;
	int arr[] = { 9,1,5,8,3,7,4,6,2,22,15};
	int sz = sizeof(arr) / sizeof(arr[0]);      //数组元素个数
	SqList L0, L1, L2, L3, L4;
	for (i = 0; i < sz; i++)
		L0.r[i + 1] = arr[i];
	L0.length = sz;
	L4 = L3 = L2 = L1 = L0;
	printf("排序前:\n");
	print(L0);

	printf("直接插入排序:\n");
	InsertSort(&L1);
	print(L1);
	
	printf("希尔排序:\n");
	ShellSort(&L2);
	print(L2);

	printf("直接选择排序:\n");
	SelectSort(&L3);
	print(L3);

	printf("快速排序:\n");
	QuickSort(&L4);
	print(L4);
	return 0;
}

//注释①：研究表明，当增量序列为dlta[k]=2的t-k+1次方-1（0<=k<=t<=log2(n+1))时，效率不错
//注释②：先选取数组中第一个关键字，然后想尽办法将它放到一个位置，使得它左边的值都比它小，
//右边的值都比它大，我们将这样的关键字称为枢轴（pivot）。