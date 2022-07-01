#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXSIZE 20

typedef char SElemType;

// ��ջ����ռ�ṹ  
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;	// ջ1ջ��ָ��  
    int top2;	// ջ2ջ��ָ��  
}SqDoubleStack;

//  ����һ����ջS  
void InitStack(SqDoubleStack* S);

// ��S��Ϊ��ջ  
void ClearStack(SqDoubleStack* S);

// ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE  
void StackEmpty(SqDoubleStack S);

// ����S��Ԫ�ظ�������ջ�ĳ���  
int StackLength(SqDoubleStack S);

// ����Ԫ��eΪ�µ�ջ��Ԫ��  
void Push(SqDoubleStack* S, SElemType e, int stackNumber);

// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR  
void Pop(SqDoubleStack* S, SElemType* e, int stackNumber);

//���
void StackTraverse(SqDoubleStack S);

