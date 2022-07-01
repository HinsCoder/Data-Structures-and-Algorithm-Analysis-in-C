#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h> 
typedef char ElemType; /*������Ԫ�����Ͷ���Ϊ�ַ�����*/
typedef struct LNode
{
	ElemType data;
	struct LNode* next; /*����ĵ�����ṹ��*/
}LinkList; /*��ʼ��һ���յĴ���ͷ���ĵ�����*/
void InitList_L(LinkList*& L) /*����ͷ���Ŀռ�*/
{
	L = (LinkList*)malloc(sizeof(LinkList)); /*�����LΪ�ձ�*/
	L->next = NULL; /*�ڵ�����ָ����λ�����һ��Ԫ��*/
}

bool ListInsert_L(LinkList*& L, int i, ElemType e)
{
	LinkList* s, * p = L; int j = 0; /*�ڵ�����L��Ѱ�ҵ�i-1�����*/
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		++j; /*1<i<L->length+1,pΪ�ձ�ʾi����length+1,j>i-1��ʾiС��1*/
	}
	if (p == NULL|| j> i - 1) /*��iֵ���Ϸ��򷵻�false,��ʾ����ʧ��*/
	return false;
	else
	{
		s = (LinkList*)malloc(sizeof(LinkList)); /*�����½��*/
		s->data = e;							  /*ʹ�½���������ֵΪe*/
		s->next = p->next;                       /*���½����뵥����L��*/
		p->next = s;
		return true;
	}
}

/*���ָ��λ��ĵ�����Ԫ��*/ 
bool GetElem_L(LinkList* L, int i, ElemType &e)
{
	LinkList* p = L->next;             /*����ָ��p,��ʼʱָ������L�ĵ�һ�����*/
	int j = 1;                         /*���ü�����j,��ʼʱΪ1*/
	while (p != NULL & j < i)            /*ָ��������,ֱ��Pָ���1��Ԫ�ػ�Ϊ��*/
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i)
		return false;
	else
	{
		e = p->data;/*ȡ��1��Ԫ��*/
		return true;
	}
}

/*ָ��ֵ��Ԫ���Ƿ��ڵ�������,������򷵻�λ��,���򷵻�0*/ 
int LocateElem_L(LinkList* L, ElemType e)
{
	int i = 1;
	LinkList* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i;
}

/*ɾ��ָ��λ���Ԫ��*/ 
bool ListDelete_L(LinkList*& L, int i, ElemType& e)
{
	LinkList* q, * p = L;
	int j = 0;
	while (p != NULL & j < i - 1)/*�ڵ�����L��Ѱ�ҵ�1-1�����*/
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i - 1)
		return false; /*û���ҵ�,��;ֵ���Ϸ��򷵻�0*/
	else
	{
		q = p->next; /*��ָ��qָ��ɾ�����*/
		if (q == NULL)
			return 0;
		p->next = q->next; /*ɾ��������L�еĵ�1�����*/
		e = q->data; /*ȡ����1������������ֵ*/
		free(q); /*�ͷŵ�1�����Ŀռ�*/
		return true; 
	}
}

/*�жϵ������Ƿ�Ϊ��*/
bool ListEmpty_L(LinkList* L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

/*�ͷŵ�����*/ 
void DestroyList_L(LinkList*& L)
{
	LinkList* pre = L, * p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre); 
}

/*��õ�ǰ�������Ԫ�ظ���*/
int ListLength_L(LinkList* L)
{
	LinkList* p = L;
	int count = 0;
	while (p->next != NULL)
	{
		p = p->next;
		count++;
	}
	return(count);
}

/*˳����������������Ԫ��,���ÿո����Ԫ��*/ 
void ListTraverse_L(LinkList* L)
{
	LinkList* p = L->next;
	int i = 1;
	printf("This Linklist Traverse:\n");
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
		i++;
	}
	printf("\n");
}

int main(void)
{
	LinkList* L;
	ElemType e;
	InitList_L(L);
	ListInsert_L(L, ListLength_L(L) + 1, 'a');
	ListInsert_L(L, ListLength_L(L) + 1, 'b');
	ListInsert_L(L, ListLength_L(L) + 1, 'd');
	ListInsert_L(L, ListLength_L(L) + 1, 'd');
	ListInsert_L(L, ListLength_L(L) + 1, 'e');
	ListTraverse_L(L);
	printf("the length of list is %d\n", ListLength_L(L)); /*ʹ��ListEmpty_L�����жϵ������Ƿ�Ϊ��*/
	if (ListEmpty_L(L))
		printf("List Empty!");
	else
		printf("List not Empty!"); /*ʹ��GetElem_L�����������Ԫ��ֵ*/
	GetElem_L(L, 3, e); 
	printf("%c\n", e);
	/*ʹ��LocateElem_L�����ж�Ԫ��a�Ƿ��ڵ������� */ 
	printf("a�Ƿ��ڵ�������:%d", LocateElem_L(L, 'a'));
	/*ʹ��ListInsert_L�����ڵ��ĸ�Ԫ��λ���ϲ���Ԫ��f */
	ListInsert_L(L, 4, 'f');
	/*ʹ��ListTraverse_L�������������*/
	ListTraverse_L(L);
	/*ʹ��ListDelete_L����ɾ��������Ԫ�� */ 
	ListDelete_L(L, 3, e);
	/*ʹ��ListTraverse_L������������� */ 
	ListTraverse_L(L);
	/*ʹ��DestroyList_L�������ٵ����� */
	DestroyList_L(L);
}

