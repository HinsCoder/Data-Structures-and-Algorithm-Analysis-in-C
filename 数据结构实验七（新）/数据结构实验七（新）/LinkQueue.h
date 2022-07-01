#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXSIZE 20
typedef char QElemType;

typedef struct QNode	// 结点结构  
{
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct			// 队列的链表结构  
{
	QueuePtr front, rear; // 队头、队尾指针  
}LinkQueue;

// 构造一个空队列Q  
void InitQueue(LinkQueue* Q);

// 将Q清为空队列  
void ClearQueue(LinkQueue* Q);

// 若Q为空队列,则返回TRUE,否则返回FALSE  
void QueueEmpty(LinkQueue Q);

// 求队列的长度  
int QueueLength(LinkQueue Q);

// 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR  
void GetHead(LinkQueue Q, QElemType* e);

// 插入元素e为Q的新的队尾元素  
void EnQueue(LinkQueue* Q, QElemType e);

// 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR  
void DeQueue(LinkQueue* Q, QElemType* e);

// 从队头到队尾依次对队列Q中每个元素输出  
void QueueTraverse(LinkQueue Q);



