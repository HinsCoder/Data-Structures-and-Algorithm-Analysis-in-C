#include"SqQueue.h"
//顺序队列代码
void InitQueue(SqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

void ClearQueue(SqQueue* Q)
{
	Q->front = Q->rear = 0;
	printf("置空成功\n");
}

int QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear) // 队列空的标志  
		return 1;
	else
		return 0;
}

int QueueLength(SqQueue Q)
{
	return  (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

void GetHead(SqQueue Q, QElemType* e)
{
	if (Q.front == Q.rear) // 队列空  
		printf("队列为空\n");
	*e = Q.data[Q.front];
	printf("队头元素为：%c\n", *e);
}

void EnQueue(SqQueue* Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)	// 队列满的判断  
		printf("队列已满\n");
	Q->data[Q->rear] = e;			// 将元素e赋值给队尾  
	Q->rear = (Q->rear + 1) % MAXSIZE;// rear指针向后移一位置，  
								// 若到最后则转到数组头部  
}

char DeQueue(SqQueue* Q, QElemType* e)
{
	if (Q->front == Q->rear)			// 队列空的判断  
		printf("队列为空\n");
	*e = Q->data[Q->front];				// 将队头元素赋值给e  
	Q->front = (Q->front + 1) % MAXSIZE;	// front指针向后移一位置，  
	return *e;								// 若到最后则转到数组头部  
}

void QueueTraverse(SqQueue Q)
{
	int i = Q.front;
	while ((i + Q.front) <= Q.rear)
	{
		printf("%c ", Q.data[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
}