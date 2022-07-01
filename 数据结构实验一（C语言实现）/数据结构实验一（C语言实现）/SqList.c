#include "SqList.h"
//�汾1
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
    if (L->length == MAXSIZE)  // ˳�����Ա��Ѿ��� 
        return false;
    if (i<1 || i>L->length + 1)// ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ 
        return false;

    if (i <= L->length)        // ����������λ�ò��ڱ�β 
    {
        for (k = L->length - 1; k >= i - 1; k--)  // ��Ҫ����λ��֮�������Ԫ������ƶ�һλ 
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;          // ����Ԫ�ز��� 
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
    if (L->length == 0)               // ���Ա�Ϊ�� 
        return false;
    if (i<1 || i>L->length)         // ɾ��λ�ò���ȷ 
        return false;
    *e = L->data[i - 1];
    if (i < L->length)                // ���ɾ���������λ�� 
    {
        for (k = i; k < L->length; k++)// ��ɾ��λ�ú��Ԫ��ǰ�� 
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
    printf("�����Ա���Ϊ%d,��Ԫ���У�", L->length);
    for (i = 0; i < L->length; i++)
        printf("%c  ", L->data[i]);
    printf("\n");
}



