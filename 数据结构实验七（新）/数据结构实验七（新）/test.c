//#include"SqQueue.h"
#include"LinkQueue.h"

int main()
{
	char j, e=0;
	SqQueue Q;
	InitQueue(&Q);
	QueueEmpty(Q);
	for (j = 'a'; j <= 'c'; j++)
		EnQueue(&Q, j);
	printf("���Ӻ����ڶ����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	DeQueue(&Q, &j);
	printf("���ӵ�Ԫ��Ϊ��%c\n", j);
	printf("���г���Ϊ: %d\n", QueueLength(Q));
	for (j = 'd'; j <= 'f'; j++)
		EnQueue(&Q, j);
	printf("���Ӻ󣬶��г���Ϊ: %d\n", QueueLength(Q));
	printf("��ʱ�����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	ClearQueue(&Q);
	return 0;
}


int main()
{
	char j, e = 0;
	LinkQueue Q;
	InitQueue(&Q);
	QueueEmpty(Q);
	for (j = 'a'; j <= 'c'; j++)
		EnQueue(&Q, j);
	printf("���Ӻ����ڶ����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	DeQueue(&Q, &j);
	printf("���ӵ�Ԫ��Ϊ��%c\n", j);
	printf("���г���Ϊ: %d\n", QueueLength(Q));
	for (j = 'd'; j <= 'f'; j++)
		EnQueue(&Q, j);
	printf("���Ӻ󣬶��г���Ϊ: %d\n", QueueLength(Q));
	printf("��ʱ�����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	DestroyQueue(&Q);
	return 0;
}
