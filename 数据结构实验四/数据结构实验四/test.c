#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define LEN sizeof(struct LNode) 

struct LNode {
	int data;//数据域
	struct LNode* next;
};
typedef struct LNode LNode, * LinkList;
//初始化一个链表 
LinkList InitLNode(void) {
	LinkList head;
	head = (LinkList)malloc(LEN);//生成有一个结构体大小的动态存储空间
	if (!head) {
		printf("内存空间申请失败！\n");
		exit(ERROR);
	}
	head->data = 0;//头结点的数据域用来存放实际表长
	head->next = NULL;
	return head;
}
//创建一个链表
int CreatList(LinkList head) {
	LinkList pleft, pright;
	pleft = head;
	pright = (LinkList)malloc(LEN);//指向新开辟的一段内存空间 要保证pleft和pright一前一后 
	printf("请按照递增的顺序向链表中赋值:(输入-1认为输入终止)\n");
	scanf("%d", &pright->data);
	while (pright->data != -1) {
		head->data++;//表长加1 
		pleft->next = pright;//pleft永远指向当前链表的最后一个结点 pright指向当前新生成的一个结点 
		pleft = pright;
		pright = (LinkList)malloc(LEN);
		scanf("%d", &pright->data);
	}
	pleft->next = NULL;
	free(pright);//pright的数据域是-1指针域没有赋值 也就是说pright所指结点并未链入到链表中 没有用了
	return OK;
}
//输出链表
int PrintLNode(LinkList head) {
	if (!head->next) {
		printf("空链表！\n");
		return ERROR;
	}
	LinkList p;//指向输出位置的结点 
	p = head->next;//首先指向第一个结点 p = head是初始指向了头结点
	printf("结果如下:\n");
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	return OK;
}
//删除链表
int delLNode(LinkList head, int num) {
	if (!head->next) {
		printf("空链表！\n");
		return ERROR;
	}
	LinkList pleft, pright;
	pleft = head;//指向头结点 
	pright = head->next;//指向第一个结点
	while (pright->data != num && pright != NULL) {
		pleft = pright;
		pright = pright->next;
	}
	if (pright->data == num) {
		pleft->next = pright->next;//pleft = head避免了讨论如果删除的位置在第一个结点的情况 
		free(pright);
		head->data--;//表长减1 
	}
	else {
		printf("\n没有找到该数据!\n");
	}
	return OK;
}
//删除介于两数之间的元素
int delLink(LinkList head, float mink, float maxk) {
	LinkList pleft, pright;
	pright = pleft = head->next;//指向第一个结点
	while (pright->data <= mink && pright) {
		pleft = pright;
		pright = pright->next;
	}

	if (!pright) {
		printf("没有介于%g和%g之间的数据\n", mink, maxk);
		return ERROR;
	}
	while (pright->data < maxk && pright) {//跳出上个循环说明p->data > mink 再来判断一下与max的关系
		delLNode(head, pright->data);//删除这个结点之后pright所指的这个结点已经被free了 所以pright是一个野指针 没有具体的指向 
		pright = pleft->next;//所以要根据它的前一个指针重新定位指向
	}
	return OK;
}

//头插法原地逆置单链表
void Reverse_List(LinkList L)
{
	LNode* r = L;
	LNode* p = L->next;
	L->next = NULL;//记得把头指针next域置空，否则会循环指首结点
	while (p)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
}


int main() {
	LinkList head;
	float mink, maxk;
	head = InitLNode();
	CreatList(head);
	PrintLNode(head);
	printf("\n想删除介于哪两者之间的数据?\n");
	scanf("%f%f", &mink, &maxk);
	delLink(head, mink, maxk);
	printf("\n");
	PrintLNode(head);
	Reverse_List(head);
	printf("\n");
	printf("逆置后的");
	PrintLNode(head);



}