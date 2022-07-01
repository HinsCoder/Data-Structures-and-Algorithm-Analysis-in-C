#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
// 顺序查找，a为数组，n为要查找的数组个数，key为要查找的关键字 
//int Sequential_Search(int* a, int n, int key)
//{
//	int i;
//	for (i = 1; i <= n; i++)
//	{
//		if (a[i] == key)
//			return i;
//	}
//	return 0;
//}
//
//int main()
//{
//	int k = 5, i;
//	int arr[] = { 3,6,2,10,1,8,5,7,4,9 };
//	printf("原数组序列为：");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\n元素5的位置为 ", *(arr + i));
//	i = Sequential_Search(arr, 10, k);
//	if (i == 0)
//		printf(" 找不到!\n");
//	else
//		printf("%d\n", i + 1);
//	return 0;
//}


//二分查找
int binary_search(int* a, int n, int k)
{
	int left = 0;             //定义左值为第一个
	int right = n - 1;		  //定义右值为最后一个

	while (left <= right)
	{
	    int mid = (left + right) / 2;    //折半
		if (a[mid] > k)                  //若查找值比中值小
		{
			right = mid - 1;             //右边界调整为中值-1位
		}
		else if (a[mid] < k)			 //若查找值比中值大
		{
			left = mid + 1;				 //左边界调整为中值+1位
		}
		else
		{
			return mid;					//若相等则说明mid即为查找到的位置
		}
	}return -1;							//超出范围
}

int main()
{
	int k = 9, i;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("原数组序列为：");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n元素9的位置为 ", *(arr + i));
	i = binary_search(arr, 10, k);
	if (i == -1)
		printf(" 找不到!\n");
	else
		printf("%d\n", i + 1);
	return 0;
}