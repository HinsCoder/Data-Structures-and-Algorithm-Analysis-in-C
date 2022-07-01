#include "SqList.h"
void InitList(SqList* L)
{
    L->length = 0;
}

void ListEmpty(SqList L)
{
	if (L.length == 0)
		printf("线性表为空\n");
	else
		printf("线性表不为空\n");
}

void ClearList(SqList* L)
{
	L->length = 0;
}

int ListLength(SqList L)
{
	return L.length;
}

int GetElem(SqList* L, int i, ElemType* e)
{
	if (L->length == 0 || i<1 || i>L->length)
		printf("找不到\n");
	*e = L->data[i - 1];
	printf("找到了，是%d\n",*e);
}

void LocateElem(SqList L, ElemType e)
{
    int i;
    if (L.length == 0)
		printf("线性表为空\n");
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            break;
    }
    if (i >= L.length)
		printf("超出范围\n");
	printf("找到了，是%d\n", i + 1);
}

void ListInsert(SqList* L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)  // 顺序线性表已经满 
		printf("线性表已满\n");
	if (i<1 || i>L->length + 1)// 当i比第一位置小或者比最后一位置后一位置还要大时 
		printf("超出范围\n");
	if (i <= L->length)        // 若插入数据位置不在表尾 
	{
		for (k = L->length - 1; k >= i - 1; k--)  // 将要插入位置之后的数据元素向后移动一位 
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;          // 将新元素插入 
	L->length++;
	printf("插入成功\n");
}

int ListDelete(SqList* L, int i, ElemType* e)
{
	int k;
	if (L->length == 0)               // 线性表为空 
		printf("线性表为空\n");
	if (i<1 || i>L->length)         // 删除位置不正确 
		printf("超出范围\n");
	*e = L->data[i - 1];
	if (i < L->length)                // 如果删除不是最后位置 
	{
		for (k = i; k < L->length; k++)// 将删除位置后继元素前移 
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	printf("删除%d成功\n", *e);
}

void ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

//其中L为顺序表指针，m为前面的有序元素个数，n为后面的有序元素个数。
//int m, n;
//void sort（SqList* L，int m，int n）
//{
//
//}

/**
 * 使得整个顺序表有序
 *
 * @param A 顺序表
 * @param m 前半部分递增有序的元素个数
 * @param n 后半部分递增有序的元素个数
 */
void Sort(SqList* L, int m, int n)
{
	int i = 0, j = 0, temp = 0;
	for (i = m; i < m + n; i++)		// 从 m 开始，需要移动 n 个数
	{
		temp = L->data[i];			// 临时保存要移动的数值
		for (j = i - 1; j > 0; j--) // 从下标为 i-1 的数开始，将前面的数向后移动一位
		{
			if (L->data[j] > temp)  // 只移动大于 temp 的数，即不能把下标为 i-1 之前的所有数（包括 i-1 所表示的数）都向后移动一位
			{
				L->data[j + 1] = L->data[j];    // 用前一位的数覆盖后一位的数
			}
			else 
			{
				break;              // 即遇到 A->data[j]<=temp 的情况时，跳出循环，停止移动
			}
		}
		L->data[j + 1] = temp;			// 移动之后，A->data[j+1]就是空出来的位置，填入temp
	}
}