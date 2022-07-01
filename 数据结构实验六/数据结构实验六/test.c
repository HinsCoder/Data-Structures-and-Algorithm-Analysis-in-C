#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#define MAXSIZE 20
//typedef struct
//{
//	int arr[MAXSIZE];
//	int top;
//}Stack;//����ջ 
//void push(Stack* p, int e)//��ջ 
//{
//	if (p->top == MAXSIZE - 1)
//	{
//		printf("�޷���ջ\n");
//	}
//	else
//	{
//		p->arr[++p->top] = e;//��ջ���ȼӺ�ѹ 
//	}
//}
//void pop(Stack* p)//��ջ 
//{
//	int e;
//	if (p->top == -1)//ջ���ж� 
//	{
//		printf("ջ��\n");
//	}
//	else
//	{
//		e = p->arr[p->top--];
//		printf("%d", e);
//	}
//}
//void converse(Stack* p, int num)
//{
//	int mod;//���� 
//	while (num != 0)
//	{
//		mod = num % 2;//�������
//		push(p, mod);//������ջ 
//		num = num / 2;//��2���� 
//	}
//}
//int main() //������ڣ��������������￪ʼִ��
//{
//	Stack s;
//	s.top = -1;
//	int num;
//	printf("��������Ҫת����ʮ����������:");
//	scanf("%d", &num);
//	converse(&s, num); //����ת���ĺ���
//	printf("ת��Ϊ������Ϊ:");
//	while (s.top != -1)//ѭ����ջ 
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
//2ջ����洢�ռ� ���ݽṹ
typedef struct SeqDoubleStack
{
	EleType data[MAXSIZE];
	int top1;
	int top2;

}SeqDoubleStack;
/*
��ջ
*/
Status pop(SeqDoubleStack* stack, EleType* e, int stackNum)
{
	if (!stack || !e)//��ָ��
	{
		return ERROR;
	}

	//ջ��Ϊ�յ����������ջ��ţ�pop��Ӧ��ջ��Ԫ�ء�
	//ջ1��ջ�ж�stack->top1!=-1 ջ2��ջ�ж�stack->top2 != MAXSIZE
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
	//ջΪ�ջ��߱�Ų���
	return ERROR;
}
/*
ѹջ����
*/
Status push(SeqDoubleStack* stack, EleType e, int stackNum)
{
	if (!stack)//��ָ��
	{
		return ERROR;
	}

	//ջû���������������ջ��ţ�push��Ӧ��ջ��Ԫ�ء�
	//ջδ������������stack->top1+1 < stack->top2
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
	//ջ�������߱�Ų���
	return ERROR;
}

/*
չʾ2��ջ��Ԫ��
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
���ջԪ��
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
��ʼ��ջ
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
ջԪ�ظ���
*/
int getLengthSeqDoubleStack(SeqDoubleStack* stack)
{
	if (!stack)
	{
		return ERROR;
	}
	//stack->top1+1;//ջ1Ԫ�ظ���
	//MAXSIZE - stack->top2;//ջ2Ԫ�ظ���
	return stack->top1 + 1 + MAXSIZE - stack->top2;
}
int main(int argc, char* argv[])
{
	SeqDoubleStack stack;
	//��ʼ��
	initSeqDoubleStack(&stack);
	//ѹջ
	push(&stack, 1, 1);
	push(&stack, 2, 1);
	push(&stack, 3, 1);
	push(&stack, 4, 1);
	push(&stack, 5, 1);
	push(&stack, 9, 2);
	push(&stack, 8, 2);
	push(&stack, 7, 2);
	push(&stack, 6, 2);
	puts("չʾԪ��:");
	//��ʾԪ��
	showStack(&stack);
	printf("Ԫ�ظ�����%d\n", getLengthSeqDoubleStack(&stack));
	EleType e1;
	EleType e2;
	//��ջ
	pop(&stack, &e1, 1);
	printf("pop:%d,", e1);
	pop(&stack, &e2, 2);
	printf("pop:%d\n", e2);
	puts("չʾԪ��:");
	showStack(&stack);
	//���
	clearSeqDoubleStack(&stack);
	printf("\n");
	return 0;
}
