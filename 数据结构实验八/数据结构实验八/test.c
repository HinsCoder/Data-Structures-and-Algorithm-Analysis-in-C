#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include<stdlib.h> 
#define MAXSIZE 100 

typedef struct          //����ջ
{
    char data[MAXSIZE];
    int  top;
}SqStack;

void InitStack(SqStack* s)      //��ʼ��ջ
{
    s->top = 0;
}

int StackEMAXSIZEpty(SqStack* s)        //�ж�ջ�Ƿ�Ϊ��
{
    if (s->top == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Push(SqStack* s, char x)  //��ջ
{
    if (s->top == MAXSIZE)
    {
        printf("ջ��\n");
    }
    else
    {
        s->data[++s->top] = x;
    }
}

char Pop(SqStack* s)        //��ջ
{
    char y;
    if (s->top == 0)

    {
        printf("ջ��\n");
        return '0';
    }
    else
    {
        y = s->data[s->top];
        s->top = s->top - 1;
        return y;
    }
}

typedef struct {          //�������
    char data[MAXSIZE];
    int  front;
    int  rear;
}SqQueue;

void InitQueue(SqQueue* q)      //��ʼ������
{
    q->front = q->rear = 0;
}

void EnQueue(SqQueue* q, char e)            //���
{
    if ((q->rear + 1) % MAXSIZE == q->front)
    {
        printf("����Ϊ��\n");
    }
    else
    {
        q->data[q->rear] = e;
        q->rear = (q->rear + 1);
    }
}

char DeQueue(SqQueue* q)         //����
{
    char f;
    if (q->front == q->rear)
    {
        printf("����Ϊ��\n");
        return 0;
    }
    else
    {
        f = q->data[q->front];
        q->front = (q->front + 1);
        return f;
    }
}

int  main()
{
    char c;
    int y = 0;
    SqStack* s = (SqStack*)malloc(sizeof(SqStack));
    SqQueue* q = (SqQueue*)malloc(sizeof(SqQueue));
    InitStack(s);
    InitQueue(q);
    printf("����һ���ַ���:����#������\n");
    while ((c = getchar()) != '#')
    {
        Push(s, c);
        EnQueue(q, c);
    }
    while (StackEMAXSIZEpty(s))
    {
        if (Pop(s) == DeQueue(q))
        {
            y = 1;
            continue;
        }
        else
        {
            y = 0;
            break;
        }
    }
    if (y == 1)
        printf("���ַ���Ϊ����\n");
    else
        printf("���ַ������ǻ���\n");
    return 0;
}