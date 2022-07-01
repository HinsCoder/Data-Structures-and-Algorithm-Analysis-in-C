#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include<stdlib.h> 
#define MAXSIZE 100 

typedef struct          //定义栈
{
    char data[MAXSIZE];
    int  top;
}SqStack;

void InitStack(SqStack* s)      //初始化栈
{
    s->top = 0;
}

int StackEMAXSIZEpty(SqStack* s)        //判断栈是否为空
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

void Push(SqStack* s, char x)  //入栈
{
    if (s->top == MAXSIZE)
    {
        printf("栈空\n");
    }
    else
    {
        s->data[++s->top] = x;
    }
}

char Pop(SqStack* s)        //出栈
{
    char y;
    if (s->top == 0)

    {
        printf("栈空\n");
        return '0';
    }
    else
    {
        y = s->data[s->top];
        s->top = s->top - 1;
        return y;
    }
}

typedef struct {          //定义队列
    char data[MAXSIZE];
    int  front;
    int  rear;
}SqQueue;

void InitQueue(SqQueue* q)      //初始化队列
{
    q->front = q->rear = 0;
}

void EnQueue(SqQueue* q, char e)            //入队
{
    if ((q->rear + 1) % MAXSIZE == q->front)
    {
        printf("队列为空\n");
    }
    else
    {
        q->data[q->rear] = e;
        q->rear = (q->rear + 1);
    }
}

char DeQueue(SqQueue* q)         //出队
{
    char f;
    if (q->front == q->rear)
    {
        printf("队列为空\n");
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
    printf("输入一个字符串:（以#结束）\n");
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
        printf("此字符串为回文\n");
    else
        printf("此字符串不是回文\n");
    return 0;
}