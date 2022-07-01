#include"SqDoubleStack.h"

void InitStack(SqDoubleStack* S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    printf("构造成功\n");
}

void ClearStack(SqDoubleStack* S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    printf("置空成功\n");
}

void StackEmpty(SqDoubleStack S)
{
    if (S.top1 == -1 && S.top2 == MAXSIZE)
        printf("该栈为空栈\n");
    else
        printf("该栈不为空栈\n");
}

int StackLength(SqDoubleStack S)
{
    return (S.top1 + 1) + (MAXSIZE - S.top2);
}

void Push(SqDoubleStack* S, SElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2)	// 栈满 
        printf("该栈已满\n");
    if (stackNumber == 1)			// 栈1有元素进栈  
        S->data[++S->top1] = e; // 若是栈1则先top1+1后给数组元素赋值。  
    else if (stackNumber == 2)	// 栈2有元素进栈  
        S->data[--S->top2] = e; // 若是栈2则先top2-1后给数组元素赋值。  
}

void Pop(SqDoubleStack* S, SElemType* e, int stackNumber)
{
    if (stackNumber == 1)
    {
        if (S->top1 == -1)
            printf("栈1为空栈\n"); // 说明栈1已经是空栈，溢出  
        *e = S->data[S->top1--]; // 将栈1的栈顶元素出栈  
    }
    else if (stackNumber == 2)
    {
        if (S->top2 == MAXSIZE)
            printf("栈2为空栈\n"); // 说明栈2已经是空栈，溢出  
        *e = S->data[S->top2++]; // 将栈2的栈顶元素出栈  
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
