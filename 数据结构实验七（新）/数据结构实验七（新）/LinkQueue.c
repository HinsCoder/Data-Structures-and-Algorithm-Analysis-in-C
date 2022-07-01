#include"LinkQueue.h"

void InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		printf("��ʼ��ʧ��\n");
	Q->front->next = NULL;
	printf("��ʼ���ɹ�\n");
}

void DestroyQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	printf("���ٳɹ�\n");
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
	printf("�ÿճɹ�\n");
}

void QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		printf("����Ϊ��\n");
	else
		printf("���в�Ϊ��\n");
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
		printf("����Ϊ��\n");
	p = Q.front->next;
	*e = p->data;
	printf("��ͷԪ��Ϊ��%c\n", *e);
}

void EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s) // �洢����ʧ��  
		printf("�洢����ʧ��\n");
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;	// ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�̣���ͼ�Т�  
	Q->rear = s;		// �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s����ͼ�Т�  
}

void DeQueue(LinkQueue* Q, QElemType* e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
		printf("����Ϊ��\n");
	p = Q->front->next;		// ����ɾ���Ķ�ͷ����ݴ��p����ͼ�Т�  
	*e = p->data;				// ����ɾ���Ķ�ͷ����ֵ��ֵ��e  
	Q->front->next = p->next;// ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т�  
	if (Q->rear == p)		// ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��㣬��ͼ�Т�  
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