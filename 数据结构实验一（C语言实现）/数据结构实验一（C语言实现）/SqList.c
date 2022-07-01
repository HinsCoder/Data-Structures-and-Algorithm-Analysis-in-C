#include "SqList.h"
//版本1
//void InitList_sq(SqList* L)
//{
//    L = (SqList*)malloc(sizeof(SqList));
//    L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//    L->length = 0;
//    return L;
//}

void InitList_sq(SqList**  L)
{
    *L = (SqList*)malloc(sizeof(SqList));
    (*L)->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    (*L)->length = 0;
    /*return L;*/
}

bool ListInsert_Sq(SqList*  L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE)  // 顺序线性表已经满 
        return false;
    if (i<1 || i>L->length + 1)// 当i比第一位置小或者比最后一位置后一位置还要大时 
        return false;

    if (i <= L->length)        // 若插入数据位置不在表尾 
    {
        for (k = L->length - 1; k >= i - 1; k--)  // 将要插入位置之后的数据元素向后移动一位 
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;          // 将新元素插入 
    L->length++;

    return true;
}

bool GetElem_Sq(SqList*  L, int i, ElemType *e)
{
    if (i<1 || i>L->length)
        return false;
    *e = L->data[i - 1];
    return true;
}

int LocateElem_Sq(SqList* L, ElemType e)
{
    int i = 0;
    if (L->length == 0)
        return 0;
    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
            break;
    }
    if (i >= L->length)
        return 0;
    return i + 1;
}

bool ListDelete_Sq(SqList*  L, int i, ElemType* e)
{
    int k;
    if (L->length == 0)               // 线性表为空 
        return false;
    if (i<1 || i>L->length)         // 删除位置不正确 
        return false;
    *e = L->data[i - 1];
    if (i < L->length)                // 如果删除不是最后位置 
    {
        for (k = i; k < L->length; k++)// 将删除位置后继元素前移 
            L->data[k - 1] = L->data[k];
    }
    L->length--;
    return true;
}

bool ListEmpty_Sq(SqList* L)
{
    if (L->length == 0)
        return true;
    else
        return false;
}

void DestroyList_Sq(SqList* L)
{
    free(L);
}

int ListLength_Sq(SqList* L)
{
    return L->length;
}

void ListTraverse_Sq(SqList* L)
{
    int i;
    printf("该线性表长度为%d,且元素有：", L->length);
    for (i = 0; i < L->length; i++)
        printf("%c  ", L->data[i]);
    printf("\n");
}



