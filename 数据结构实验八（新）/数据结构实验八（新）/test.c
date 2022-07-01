#include"SqStack.h"
#include"SqQueue.h"

int  main()
{
    char c, m = 0, n = 0;
    int y = 0;
    SqStack s;
    SqQueue q;
    InitStack(&s);
    InitQueue(&q);
    printf("����һ���ַ���:\n");
    while ((c = getchar()) != '\n')
    {
        Push(&s, c);
        EnQueue(&q, c);
    }
    while (StackEmpty(s))
    {
        if (Pop(&s,&m) == DeQueue(&q,&n))
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
