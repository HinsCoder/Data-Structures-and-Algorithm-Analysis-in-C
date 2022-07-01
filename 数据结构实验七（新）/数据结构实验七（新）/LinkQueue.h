#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXSIZE 20
typedef char QElemType;

typedef struct QNode	// ���ṹ  
{
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct			// ���е�����ṹ  
{
	QueuePtr front, rear; // ��ͷ����βָ��  
}LinkQueue;

// ����һ���ն���Q  
void InitQueue(LinkQueue* Q);

// ��Q��Ϊ�ն���  
void ClearQueue(LinkQueue* Q);

// ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE  
void QueueEmpty(LinkQueue Q);

// ����еĳ���  
int QueueLength(LinkQueue Q);

// �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR  
void GetHead(LinkQueue Q, QElemType* e);

// ����Ԫ��eΪQ���µĶ�βԪ��  
void EnQueue(LinkQueue* Q, QElemType e);

// �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR  
void DeQueue(LinkQueue* Q, QElemType* e);

// �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�����  
void QueueTraverse(LinkQueue Q);



