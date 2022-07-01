#include "SqList.h"
int main()
{
    int i = 0, j = 0;
    SqList L;
    InitList(&L);
    int arr1[] = { 5,6,7,8,10 };
    int arr2[] = { 1,2,3,4,8,9 };
    int sz1 = sizeof(arr1) / sizeof(arr1[0]);      //数组元素个数
    int sz2 = sizeof(arr2) / sizeof(arr2[0]);      //数组元素个数
    for (i = 0; i < sz1; i++)
        L.data[i] = arr1[i];
    for (i = 0, j = sz1; i < sz2; i++, j++)
        L.data[j] = arr2[i];
    L.length = sz1 + sz2;
    ListTraverse(L);
    Sort(&L, sz1, sz2);
    ListTraverse(L);

    SqList A = { {1,2,4,7,8,0,3,5,6,9 },10 };
    SqList B = { {10,64,7,84,6,17,6,44,9,64 },10 };
    SqList C = { {0 },10 };
    Intersection(&A, &B, &C);
    ListTraverse(C);

}