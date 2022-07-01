#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h> 
typedef char ElemType; /*单链表元素类型定义为字符类型*/
typedef struct LNode
{
	ElemType data;
	struct LNode* next; /*定义的单链表结构体*/
}LinkList; /*初始化一个空的带表头结点的单链表*/
void InitList_L(LinkList*& L) /*分配头结点的空间*/
{
	L = (LinkList*)malloc(sizeof(LinkList)); /*令单链表L为空表*/
	L->next = NULL; /*在单链表指定的位序插入一个元素*/
}

bool ListInsert_L(LinkList*& L, int i, ElemType e)
{
	LinkList* s, * p = L; int j = 0; /*在单链表L中寻找第i-1个结点*/
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		++j; /*1<i<L->length+1,p为空表示i大于length+1,j>i-1表示i小于1*/
	}
	if (p == NULL|| j> i - 1) /*若i值不合法则返回false,表示插入失败*/
	return false;
	else
	{
		s = (LinkList*)malloc(sizeof(LinkList)); /*生成新结点*/
		s->data = e;							  /*使新结点数据域的值为e*/
		s->next = p->next;                       /*将新结点插入单链表L中*/
		p->next = s;
		return true;
	}
}

/*获得指定位序的单链表元素*/ 
bool GetElem_L(LinkList* L, int i, ElemType &e)
{
	LinkList* p = L->next;             /*设置指针p,初始时指向单链表L的第一个结点*/
	int j = 1;                         /*设置计数器j,初始时为1*/
	while (p != NULL & j < i)            /*指针向后查找,直到P指向第1个元素或为空*/
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i)
		return false;
	else
	{
		e = p->data;/*取第1个元素*/
		return true;
	}
}

/*指定值的元素是否在单链表中,如果在则返回位序,否则返回0*/ 
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

/*删除指定位序的元素*/ 
bool ListDelete_L(LinkList*& L, int i, ElemType& e)
{
	LinkList* q, * p = L;
	int j = 0;
	while (p != NULL & j < i - 1)/*在单链表L中寻找第1-1个结点*/
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i - 1)
		return false; /*没有找到,若;值不合法则返回0*/
	else
	{
		q = p->next; /*用指针q指向被删除结点*/
		if (q == NULL)
			return 0;
		p->next = q->next; /*删除单链表L中的第1个结点*/
		e = q->data; /*取出第1个结点的数据域值*/
		free(q); /*释放第1个结点的空间*/
		return true; 
	}
}

/*判断单链表是否为空*/
bool ListEmpty_L(LinkList* L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

/*释放单链表*/ 
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

/*获得当前单链表的元素个数*/
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

/*顺序输出单链表的所有元素,并用空格隔开元素*/ 
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
	printf("the length of list is %d\n", ListLength_L(L)); /*使用ListEmpty_L函数判断单链表是否为空*/
	if (ListEmpty_L(L))
		printf("List Empty!");
	else
		printf("List not Empty!"); /*使用GetElem_L函数输出第三元素值*/
	GetElem_L(L, 3, e); 
	printf("%c\n", e);
	/*使用LocateElem_L函数判断元素a是否在单链表中 */ 
	printf("a是否在单链表中:%d", LocateElem_L(L, 'a'));
	/*使用ListInsert_L函数在第四个元素位置上插人元素f */
	ListInsert_L(L, 4, 'f');
	/*使用ListTraverse_L函数输出单链表*/
	ListTraverse_L(L);
	/*使用ListDelete_L函数删除第三个元素 */ 
	ListDelete_L(L, 3, e);
	/*使用ListTraverse_L函数输出单链表 */ 
	ListTraverse_L(L);
	/*使用DestroyList_L函数销毁单链表 */
	DestroyList_L(L);
}

