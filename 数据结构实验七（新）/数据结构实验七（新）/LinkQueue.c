#include"LinkQueue.h"

void InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		printf("初始化失败\n");
	Q->front->next = NULL;
	printf("初始化成功\n");
}

void DestroyQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	printf("销毁成功\n");
}

void ClearQueue(LinkQueue* Q)
{
	QueuePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	printf("置空成功\n");
}

void QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		printf("队列为空\n");
	else
		printf("队列不为空\n");
}

int QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

void GetHead(LinkQueue Q, QElemType* e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		printf("队列为空\n");
	p = Q.front->next;
	*e = p->data;
	printf("队头元素为：%c\n", *e);
}

void EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s) // 存储分配失败  
		printf("存储分配失败\n");
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;	// 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中①  
	Q->rear = s;		// 把当前的s设置为队尾结点，rear指向s，见图中②  
}

void DeQueue(LinkQueue* Q, QElemType* e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
		printf("队列为空\n");
	p = Q->front->next;		// 将欲删除的队头结点暂存给p，见图中①  
	*e = p->data;				// 将欲删除的队头结点的值赋值给e  
	Q->front->next = p->next;// 将原队头结点的后继p->next赋值给头结点后继，见图中②  
	if (Q->rear == p)		// 若队头就是队尾，则删除后将rear指向头结点，见图中③  
		Q->rear = Q->front;
	free(p);
}

void QueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front->next;
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}