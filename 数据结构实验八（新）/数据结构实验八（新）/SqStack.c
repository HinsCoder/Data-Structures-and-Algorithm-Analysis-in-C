#include"SqStack.h"
//顺序栈代码
void InitStack(SqStack* S)
{
    // S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); 
    S->top = -1;
    printf("栈构造成功\n");
}

void ClearStack(SqStack* S)
{
    S->top = -1;
    printf("置空成功\n");
}

int StackEmpty(SqStack S)
{
    if (S.top == -1)
        return 0;
    else
        return 1;
}

int StackLength(SqStack S)
{
    return S.top + 1;
}

void GetTop(SqStack S, SElemType* e)
{
    if (S.top == -1)
        printf("该栈为空栈\n");
    else
        *e = S.data[S.top];
    printf("该栈的栈顶元素为：%c\n",*e);
}

void Push(SqStack* S, SElemType e)
{
    if (S->top == MAXSIZE - 1) // 栈满 
    {
        printf("该栈已满\n");
    }
    S->top++;				// 栈顶指针增加一 
    S->data[S->top] = e;  // 将新插入元素赋值给栈顶空间 
}

char Pop(SqStack* S, SElemType* e)
{
    if (S->top == -1)
        printf("该栈为空栈\n");
    *e = S->data[S->top];	// 将要删除的栈顶元素赋值给e 
    S->top--;				// 栈顶指针减一 
    return *e;
}

void StackTraverse(SqStack S)
{
    int i = 0;
    while (i <= S.top)
    {
        printf("%c ", S.data[i++]);
    }
    printf("\n");
}

void StackReverseTraverse(SqStack S)
{
    int i = S.top;
    while (i >= 0)
    {
        printf("%c ", S.data[i--]);
    }
    printf("\n");
}