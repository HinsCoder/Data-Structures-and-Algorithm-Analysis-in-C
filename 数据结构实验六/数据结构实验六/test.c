#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#define MAXSIZE 20
//typedef struct
//{
//	int arr[MAXSIZE];
//	int top;
//}Stack;//创建栈 
//void push(Stack* p, int e)//入栈 
//{
//	if (p->top == MAXSIZE - 1)
//	{
//		printf("无法入栈\n");
//	}
//	else
//	{
//		p->arr[++p->top] = e;//入栈，先加后压 
//	}
//}
//void pop(Stack* p)//出栈 
//{
//	int e;
//	if (p->top == -1)//栈空判断 
//	{
//		printf("栈空\n");
//	}
//	else
//	{
//		e = p->arr[p->top--];
//		printf("%d", e);
//	}
//}
//void converse(Stack* p, int num)
//{
//	int mod;//余数 
//	while (num != 0)
//	{
//		mod = num % 2;//求出余数
//		push(p, mod);//余数入栈 
//		num = num / 2;//除2继续 
//	}
//}
//int main() //程序入口，主函数，从这里开始执行
//{
//	Stack s;
//	s.top = -1;
//	int num;
//	printf("请输入需要转换的十进制正整数:");
//	scanf("%d", &num);
//	converse(&s, num); //调用转换的函数
//	printf("转换为二进制为:");
//	while (s.top != -1)//循环出栈 
//	{
//		pop(&s);
//	}
//	printf("\n");
//}



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
typedef int EleType;
typedef int Status;
//2栈共享存储空间 数据结构
typedef struct SeqDoubleStack
{
	EleType data[MAXSIZE];
	int top1;
	int top2;

}SeqDoubleStack;
/*
弹栈
*/
Status pop(SeqDoubleStack* stack, EleType* e, int stackNum)
{
	if (!stack || !e)//空指针
	{
		return ERROR;
	}

	//栈不为空的情况，根据栈编号，pop相应的栈的元素。
	//栈1空栈判断stack->top1!=-1 栈2空栈判断stack->top2 != MAXSIZE
	if (stackNum == 1 && stack->top1 != -1)
	{
		*e = stack->data[stack->top1];
		stack->top1--;
		return OK;
	}
	if (stackNum == 2 && stack->top2 != MAXSIZE)
	{
		*e = stack->data[stack->top2];
		stack->top2++;
		return OK;
	}
	//栈为空或者编号不对
	return ERROR;
}
/*
压栈操作
*/
Status push(SeqDoubleStack* stack, EleType e, int stackNum)
{
	if (!stack)//空指针
	{
		return ERROR;
	}

	//栈没有满的情况，根据栈编号，push相应的栈的元素。
	//栈未满的条件都是stack->top1+1 < stack->top2
	if (stackNum == 1 && stack->top1 + 1 < stack->top2)
	{
		stack->top1++;
		stack->data[stack->top1] = e;
		return OK;
	}
	if (stackNum == 2 && stack->top1 + 1 < stack->top2)
	{
		stack->top2--;
		stack->data[stack->top2] = e;
		return OK;
	}
	//栈已满或者编号不对
	return ERROR;
}

/*
展示2个栈的元素
*/
void showStack(SeqDoubleStack* stack)
{
	for (int i = 0; i <= stack->top1; i++)
	{
		printf("%d,", stack->data[i]);
	}
	for (int i = stack->top2; i <= MAXSIZE - 1; i++)
	{
		printf("%d,", stack->data[i]);
	}
	printf("\n");
}
/*
清空栈元素
*/
Status clearSeqDoubleStack(SeqDoubleStack* stack)
{
	if (!stack)
	{
		return ERROR;
	}
	stack->top1 = -1;
	stack->top2 = MAXSIZE;
	return OK;
}
/*
初始化栈
*/
Status initSeqDoubleStack(SeqDoubleStack* stack)
{
	if (!stack)
	{
		return ERROR;
	}
	stack->top1 = -1;
	stack->top2 = MAXSIZE;
	return OK;
}
/*
栈元素个数
*/
int getLengthSeqDoubleStack(SeqDoubleStack* stack)
{
	if (!stack)
	{
		return ERROR;
	}
	//stack->top1+1;//栈1元素个数
	//MAXSIZE - stack->top2;//栈2元素个数
	return stack->top1 + 1 + MAXSIZE - stack->top2;
}
int main(int argc, char* argv[])
{
	SeqDoubleStack stack;
	//初始化
	initSeqDoubleStack(&stack);
	//压栈
	push(&stack, 1, 1);
	push(&stack, 2, 1);
	push(&stack, 3, 1);
	push(&stack, 4, 1);
	push(&stack, 5, 1);
	push(&stack, 9, 2);
	push(&stack, 8, 2);
	push(&stack, 7, 2);
	push(&stack, 6, 2);
	puts("展示元素:");
	//显示元素
	showStack(&stack);
	printf("元素个数：%d\n", getLengthSeqDoubleStack(&stack));
	EleType e1;
	EleType e2;
	//弹栈
	pop(&stack, &e1, 1);
	printf("pop:%d,", e1);
	pop(&stack, &e2, 2);
	printf("pop:%d\n", e2);
	puts("展示元素:");
	showStack(&stack);
	//清空
	clearSeqDoubleStack(&stack);
	printf("\n");
	return 0;
}
