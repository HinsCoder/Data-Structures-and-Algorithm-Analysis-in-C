#include"LinkList.h"
int main()
{
	LinkList L;
	ElemType e;
	char j;
	int k;   //����
	InitList(&L);
	printf("��ʼ��������L\n");
	for (j = 'a',k = 1; j <= 'e'; j++,k++)
		ListInsert(&L, k, j);
	printf("β�巨���β��������Ϊ");
	ListTraverse(L);
	printf("��������Ϊ%d\n", ListLength(L));
	ListEmpty(L);
	GetElem(L, 3, &e);
	LocateElem(L,'a');
	ListInsert(&L, 4, 'f');
	ListTraverse(L);
	ListDelete(&L, 3, &e);
	ListTraverse(L);
	free(L);
}