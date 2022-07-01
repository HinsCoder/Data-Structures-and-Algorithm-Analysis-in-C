#include "SqList.h"
int main()
{
    int i = 0;
    SqList L;
    InitList(&L);
    char arr[] = { 'a','b','c','d','e'};
    int sz = sizeof(arr) / sizeof(arr[0]);      //数组元素个数
    for (i = 0; i < sz; i++)
        L.data[i] = arr[i];
    L.length = sz;
    ListTraverse(L);                 //输出线性表
    printf("该顺序表长度为%d\n", ListLength(L));
    ListEmpty(L);        //判断线性表是否为空
    ElemType e = 0;
    GetElem(&L, 3, &e);     //输出顺序表的第3个元素
    LocateElem(L, 'a');     //判断元素a是否在顺序表中 
    ListInsert(&L, 4, 'f');  //在第4个元素位置上插入元素f
    ListTraverse(L);        //输出顺序表
    ListDelete(&L, 3, &e);   //删除第3个元素
    ListTraverse(L);        //输出线性表
    ClearList(&L);         //释放线性表
}
