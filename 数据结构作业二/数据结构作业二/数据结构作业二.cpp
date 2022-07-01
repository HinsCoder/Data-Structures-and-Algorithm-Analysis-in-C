#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<malloc.h>
//typedef struct Node
//{
//    int data;
//    struct Node* next;
//}LinkList;
//void InitList(LinkList*& L)
//{
//    L = (LinkList*)malloc(sizeof(LinkList));
//    L->next = NULL;
//}
//void CreateListTail(LinkList*& L, int n)
//{
//    LinkList* p, * r;
//    int i, t;
//    L = (LinkList*)malloc(sizeof(Node));
//    r = L;
//    for (i = 0; i < n; i++)
//    {
//        p = (LinkList*)malloc(sizeof(Node));
//        scanf("%d", &t);
//        p->data = t;
//        r->next = p;
//        r = r->next;
//    }
//    r->next = NULL;
//}
//
//int x_sum(LinkList*& L)
//{
//    int n = 0, x = 0;
//    printf("请输入一个数：\n");
//    scanf("%d", &x);
//    LinkList* p = L->next;
//    while (p != NULL)
//    {
//        if (p->data == x)
//            n++;
//        p = p->next;
//    }
//    return n;
//}
//
//void main()
//{
//    int n;
//    LinkList* L;
//    printf("请输入元素个数：");
//    scanf("%d", &n);
//    InitList(L);
//    CreateListTail(L, n);
//    n = x_sum(L);
//    printf("结点个数为%d\n", n);
//}

#include<stdio.h>
int division(int a, int b)
{
	int r;       //余数
	do
	{
		r = a % b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}

int main()
{
	int x, y,result;
	printf("请输入两个整数：\n");
	scanf("%d %d", &x, &y);
	printf("%d和%d", x, y);
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	result = division(x, y);
	printf("最大公因数为：%d\n",result);
	return 0;
}