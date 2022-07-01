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
	printf("找到了，是%c\n",*e);
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
	printf("删除%c成功\n", *e);
}

void ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("%c ", L.data[i]);
	}
	printf("\n");
}

void DestroyList(SqList* L)
{
	free(L);
}