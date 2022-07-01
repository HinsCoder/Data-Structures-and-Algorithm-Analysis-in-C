#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAXSIZE 20

typedef char SElemType;

// 两栈共享空间结构  
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;	// 栈1栈顶指针  
    int top2;	// 栈2栈顶指针  
}SqDoubleStack;

//  构造一个空栈S  
void InitStack(SqDoubleStack* S);

// 把S置为空栈  
void ClearStack(SqDoubleStack* S);

// 若栈S为空栈，则返回TRUE，否则返回FALSE  
void StackEmpty(SqDoubleStack S);

// 返回S的元素个数，即栈的长度  
int StackLength(SqDoubleStack S);

// 插入元素e为新的栈顶元素  
void Push(SqDoubleStack* S, SElemType e, int stackNumber);

// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR  
void Pop(SqDoubleStack* S, SElemType* e, int stackNumber);

//输出
void StackTraverse(SqDoubleStack S);

