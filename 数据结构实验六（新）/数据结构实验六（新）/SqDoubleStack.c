#include"SqDoubleStack.h"

void InitStack(SqDoubleStack* S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    printf("����ɹ�\n");
}

void ClearStack(SqDoubleStack* S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    printf("�ÿճɹ�\n");
}

void StackEmpty(SqDoubleStack S)
{
    if (S.top1 == -1 && S.top2 == MAXSIZE)
        printf("��ջΪ��ջ\n");
    else
        printf("��ջ��Ϊ��ջ\n");
}

int StackLength(SqDoubleStack S)
{
    return (S.top1 + 1) + (MAXSIZE - S.top2);
}

void Push(SqDoubleStack* S, SElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2)	// ջ�� 
        printf("��ջ����\n");
    if (stackNumber == 1)			// ջ1��Ԫ�ؽ�ջ  
        S->data[++S->top1] = e; // ����ջ1����top1+1�������Ԫ�ظ�ֵ��  
    else if (stackNumber == 2)	// ջ2��Ԫ�ؽ�ջ  
        S->data[--S->top2] = e; // ����ջ2����top2-1�������Ԫ�ظ�ֵ��  
}

void Pop(SqDoubleStack* S, SElemType* e, int stackNumber)
{
    if (stackNumber == 1)
    {
        if (S->top1 == -1)
            printf("ջ1Ϊ��ջ\n"); // ˵��ջ1�Ѿ��ǿ�ջ�����  
        *e = S->data[S->top1--]; // ��ջ1��ջ��Ԫ�س�ջ  
    }
    else if (stackNumber == 2)
    {
        if (S->top2 == MAXSIZE)
            printf("ջ2Ϊ��ջ\n"); // ˵��ջ2�Ѿ��ǿ�ջ�����  
        *e = S->data[S->top2++]; // ��ջ2��ջ��Ԫ�س�ջ  
    }
}

void StackTraverse(SqDoubleStack S)
{
    int i;
    i = 0;
    while (i <= S.top1)
    {
        printf("%d ", S.data[i++]);
    }
    i = S.top2;
    while (i < MAXSIZE)
    {
        printf("%d ", S.data[i++]);
    }
    printf("\n");
}
