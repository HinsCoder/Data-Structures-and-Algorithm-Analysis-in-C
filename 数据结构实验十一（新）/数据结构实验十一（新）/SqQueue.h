#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXSIZE 20
typedef int QElemType;

// ѭ�����е�˳��洢�ṹ  
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    	// ͷָ��  
	int rear;		// βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��  
}SqQueue;

// ��ʼ��һ���ն���Q  
void InitQueue(SqQueue* Q);

// ��Q��Ϊ�ն���  
void ClearQueue(SqQueue* Q);

// ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE  
int QueueEmpty(SqQueue Q);

// ����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ����  
int QueueLength(SqQueue Q);

// �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR  
void GetHead(SqQueue Q, QElemType* e);

// ������δ���������Ԫ��eΪQ�µĶ�βԪ��  
void EnQueue(SqQueue* Q, QElemType e);

// �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ  
char DeQueue(SqQueue* Q, QElemType* e);

// �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�����  
void QueueTraverse(SqQueue Q);

