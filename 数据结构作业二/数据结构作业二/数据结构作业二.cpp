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
//    printf("������һ������\n");
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
//    printf("������Ԫ�ظ�����");
//    scanf("%d", &n);
//    InitList(L);
//    CreateListTail(L, n);
//    n = x_sum(L);
//    printf("������Ϊ%d\n", n);
//}

#include<stdio.h>
int division(int a, int b)
{
	int r;       //����
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
	printf("����������������\n");
	scanf("%d %d", &x, &y);
	printf("%d��%d", x, y);
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	result = division(x, y);
	printf("�������Ϊ��%d\n",result);
	return 0;
}