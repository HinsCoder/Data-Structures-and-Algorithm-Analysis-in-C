#include"SqQueue.h"
//˳����д���
void InitQueue(SqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

void ClearQueue(SqQueue* Q)
{
	Q->front = Q->rear = 0;
	printf("�ÿճɹ�\n");
}

int QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear) // ���пյı�־  
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
	if (Q.front == Q.rear) // ���п�  
		printf("����Ϊ��\n");
	*e = Q.data[Q.front];
	printf("��ͷԪ��Ϊ��%c\n", *e);
}

void EnQueue(SqQueue* Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)	// ���������ж�  
		printf("��������\n");
	Q->data[Q->rear] = e;			// ��Ԫ��e��ֵ����β  
	Q->rear = (Q->rear + 1) % MAXSIZE;// rearָ�������һλ�ã�  
								// ���������ת������ͷ��  
}

char DeQueue(SqQueue* Q, QElemType* e)
{
	if (Q->front == Q->rear)			// ���пյ��ж�  
		printf("����Ϊ��\n");
	*e = Q->data[Q->front];				// ����ͷԪ�ظ�ֵ��e  
	Q->front = (Q->front + 1) % MAXSIZE;	// frontָ�������һλ�ã�  
	return *e;								// ���������ת������ͷ��  
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