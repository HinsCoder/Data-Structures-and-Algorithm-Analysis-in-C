#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXSIZE 20
typedef char QElemType;

// 循环队列的顺序存储结构  
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	// 头指针  
	int rear;		// 尾指针，若队列不空，指向队列尾元素的下一个位置  
}SqQueue;

// 初始化一个空队列Q  
void InitQueue(SqQueue* Q);

// 将Q清为空队列  
void ClearQueue(SqQueue* Q);

// 若队列Q为空队列,则返回TRUE,否则返回FALSE  
void QueueEmpty(SqQueue Q);

// 返回Q的元素个数，也就是队列的当前长度  
int QueueLength(SqQueue Q);

// 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR  
void GetHead(SqQueue Q, QElemType* e);

// 若队列未满，则插入元素e为Q新的队尾元素  
void EnQueue(SqQueue* Q, QElemType e);

// 若队列不空，则删除Q中队头元素，用e返回其值  
char DeQueue(SqQueue* Q, QElemType* e);

// 从队头到队尾依次对队列Q中每个元素输出  
void QueueTraverse(SqQueue Q);

