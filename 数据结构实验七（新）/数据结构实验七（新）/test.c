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
	printf("进队后，现在队列中的元素为: \n");
	QueueTraverse(Q);
	DeQueue(&Q, &j);
	printf("出队的元素为：%c\n", j);
	printf("队列长度为: %d\n", QueueLength(Q));
	for (j = 'd'; j <= 'f'; j++)
		EnQueue(&Q, j);
	printf("进队后，队列长度为: %d\n", QueueLength(Q));
	printf("此时队列中的元素为: \n");
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
	printf("进队后，现在队列中的元素为: \n");
	QueueTraverse(Q);
	DeQueue(&Q, &j);
	printf("出队的元素为：%c\n", j);
	printf("队列长度为: %d\n", QueueLength(Q));
	for (j = 'd'; j <= 'f'; j++)
		EnQueue(&Q, j);
	printf("进队后，队列长度为: %d\n", QueueLength(Q));
	printf("此时队列中的元素为: \n");
	QueueTraverse(Q);
	DestroyQueue(&Q);
	return 0;
}
