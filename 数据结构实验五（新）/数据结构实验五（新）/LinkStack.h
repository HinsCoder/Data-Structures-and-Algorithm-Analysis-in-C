//#define _CRT_SECURE_NO_WARNINGS 
//#include<stdio.h>
//#define MAXSIZE 20
//
//typedef char SElemType;
//// 链栈结构 
//typedef struct StackNode
//{
//    SElemType data;
//    struct StackNode* next;
//}StackNode, * LinkStackPtr;
//
//typedef struct
//{
//    LinkStackPtr top;
//    int count;
//}LinkStack;
////typedef struct StackNode
////{ 
////    SElemType data;           //数据域
////    struct StackNode* next;   //指针域
////}LinkStack;
//
//// 构造一个空栈S  
//void InitStack(LinkStack* S);
//
//// 把S置为空栈  
//void ClearStack(LinkStack* S);
//
//// 若栈S为空栈，则返回TRUE，否则返回FALSE  
//void StackEmpty(LinkStack S);
//
//// 返回S的元素个数，即栈的长度  
//int StackLength(LinkStack S);
//
//// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR  
//void GetTop(LinkStack S, SElemType* e);
//
//// 插入元素e为新的栈顶元素  
//void Push(LinkStack* S, SElemType e);
//
//// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR  
//void Pop(LinkStack* S, SElemType* e);
//
////输出
//void StackTraverse(LinkStack S);
//
////逆序输出
//void StackReverseTraverse(LinkStackPtr S);
//
////释放栈
//void DestroyStack(LinkStack* S);