#include"LinkList.h"
void InitList(LinkList* L)
{
    *L = (LinkList)malloc(sizeof(Node)); // 产生头结点,并使L指向此头结点  
    if (!(*L))							 // 存储分配失败  
        printf("创建失败\n");
    (*L)->next = NULL;					 // 指针域为空  
    printf("创建成功\n");
}

void ListEmpty(LinkList L)
{
    if (L->next)
		printf("线性表不为空\n");
    else
		printf("线性表为空\n");
}

void ClearList(LinkList* L)
{
	LinkList p, q;
	p = (*L)->next;           //  p指向第一个结点  
	while (p)                //  没到表尾  
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;        // 头结点指针域为空  
	printf("清空成功\n");
}

int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next; // p指向第一个结点  
    while (p)
    {
        i++;
        p = p->next;
    }
	return i;
}

void GetElem(LinkList L, int i, ElemType* e)
{
	int j;
	LinkList p;		// 声明一结点p  
	p = L->next;		// 让p指向链表L的第一个结点  
	j = 1;		//  j为计数器  
	while (p && j < i)  // p不为空且计数器j还没有等于i时，循环继续  
	{
		p = p->next;  // 让p指向下一个结点  
		++j;
	}
	if (!p || j > i)
		printf("找不到\n");  //  第i个元素不存在  
	*e = p->data;   //  取第i个元素的数据  
	printf("第%d个元素是%c\n",i, *e);
}

void LocateElem(LinkList L, ElemType e)
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        if (p->data == e) // 找到这样的数据元素  
			printf("元素%c在第%d位\n", e, i);
        p = p->next;
    }
}

void ListInsert(LinkList* L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)     // 寻找第i个结点  
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		printf("找不到\n");   // 第i个元素不存在  
	s = (LinkList)malloc(sizeof(Node));  //  生成新结点(C语言标准函数)  
	s->data = e;
	s->next = p->next;      // 将p的后继结点赋值给s的后继   
	p->next = s;          // 将s赋值给p的后继  
}

void ListDelete(LinkList* L, int i, ElemType* e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)	// 遍历寻找第i个元素  
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		printf("找不到\n");           // 第i个元素不存在  
	q = p->next;
	p->next = q->next;			// 将q的后继赋值给p的后继  
	/*p->next = p->next->next;*/
	*e = q->data;               // 将q结点中的数据给e  
	free(q);                    // 让系统回收此结点，释放内存  
	printf("删除第%d个元素%c成功\n",i, *e);
}

void ListTraverse(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

void CreateListHead(LinkList* L, int n)
{
	LinkList p;
	int i;
	srand(time(0));                         // 初始化随机数种子  
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      //  先建立一个带头结点的单链表  
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); //  生成新结点  
		p->data = rand() % 100 + 1;             //  随机生成100以内的数字  
		p->next = (*L)->next;
		(*L)->next = p;						//  插入到表头  
	}
}

void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));                      // 初始化随机数种子  
	*L = (LinkList)malloc(sizeof(Node)); // L为整个线性表  
	r = *L;                                // r为指向尾部的结点  
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node)); //  生成新结点  
		p->data = rand() % 100 + 1;           //  随机生成100以内的数字  
		r->next = p;                        // 将表尾终端结点的指针指向新结点  
		r = p;                            // 将当前的新结点定义为表尾终端结点  
	}
	r->next = NULL;                       // 表示当前链表结束  
}