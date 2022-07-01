//#define _CRT_SECURE_NO_WARNINGS 
//#include<stdio.h>
//#define MAXSIZE 50
//
//typedef char SElemType;
//
////顺序栈代码
//typedef struct
//{
//    SElemType data[MAXSIZE];
//    int top; // 用于栈顶指针  
//}SqStack;
//
//// 构造一个空栈S
//void InitStack(SqStack* S);
//
//// 把S置为空栈  
//void ClearStack(SqStack* S);
//
//// 若栈S为空栈，则返回TRUE，否则返回FALSE  
//void StackEmpty(SqStack S);
//
//// 返回S的元素个数，即栈的长度  
//int StackLength(SqStack S);
//
//// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR  
//void GetTop(SqStack S, SElemType* e);
//
//// 插入元素e为新的栈顶元素  
//void Push(SqStack* S, SElemType e);
//
//// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR  
//void Pop(SqStack* S, SElemType* e);
//
//// 从栈底到栈顶依次对栈中每个元素显示  
//void StackTraverse(SqStack S);
//
//// 从栈顶到栈底依次对栈中每个元素显示 
//void StackReverseTraverse(SqStack S);
//
//// 进制转换
//void converse(SqStack* p, int num);
//
