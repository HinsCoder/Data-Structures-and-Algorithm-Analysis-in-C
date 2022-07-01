#include"LinkList.h"
int main()
{
	LinkList L;
	ElemType e;
	char j;
	int k;   //计数
	InitList(&L);
	printf("初始化单链表L\n");
	for (j = 'a',k = 1; j <= 'e'; j++,k++)
		ListInsert(&L, k, j);
	printf("尾插法依次插入后，链表为");
	ListTraverse(L);
	printf("单链表长度为%d\n", ListLength(L));
	ListEmpty(L);
	GetElem(L, 3, &e);
	LocateElem(L,'a');
	ListInsert(&L, 4, 'f');
	ListTraverse(L);
	ListDelete(&L, 3, &e);
	ListTraverse(L);
	free(L);
}