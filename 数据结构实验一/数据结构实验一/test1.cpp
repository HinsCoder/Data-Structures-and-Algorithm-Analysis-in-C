#include "SqList.h"
int main()
{

    SqList* L, Sq;
    L = &Sq;
    InitList_sq(L);
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'a');
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'b');
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'c');
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'd');
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'e');
    ListTraverse_Sq(L);   //判断顺序是否为空
    printf("该顺序表长度为%d\n", ListLength_Sq(L));
    ElemType e{};
    GetElem_Sq(L, 3, e);
    printf("%c\n", e);
    printf("%d\n", LocateElem_Sq(L, 'a'));
    LocateElem_Sq(L, 'a');    //判断元素a是否在顺序表中
    ListInsert_Sq(L, 4, 'f');  //在第四个元素位置上插入元素f
    ListTraverse_Sq(L);        //输出顺序表
    ListDelete_Sq(L, 3, &e);   //删除第三个元素
    ListTraverse_Sq(L);        //输出线性表
    DestroyList_Sq(L);         //释放线性表
}
