//#include"SqStack.h"
#include"SqDoubleStack.h"
//int main()
//{
//    SqStack s;
//    char e, j;
//    InitStack(&s);
//    StackEmpty(s);
//    s.top = -1;
//    int num;
//    printf("��������Ҫת����ʮ����������:");
//    scanf("%d", &num);
//    converse(&s, num); //����ת���ĺ���
//    printf("ת��Ϊ������Ϊ:");
//    while (s.top != -1)//ѭ����ջ 
//    {
//    	Pop(&s,&e);
//    }
//    printf("\n");
//    return 0;
//}

int main()
{
    SqDoubleStack s;
    int e = 0, j;
    InitStack(&s);
    StackEmpty(s);
    for (j = 1; j <= 5; j++)
        Push(&s, j, 1);
    for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
        Push(&s, j, 2);
    printf("ջ��Ԫ������Ϊ��");
    StackTraverse(s);
    printf("��ǰջ��Ԫ����%d��\n", StackLength(s));
    Pop(&s, &e, 2);
    printf("������ջ��Ԫ�� e=%d\n", e);
    StackEmpty(s);
    for (j = 6; j <= MAXSIZE - 2; j++)
        Push(&s, j, 1);
    printf("ջ��Ԫ������Ϊ��");
    StackTraverse(s);
    Push(&s, 100, 1);
    StackEmpty(s);
    ClearStack(&s);
    StackEmpty(s);
    return 0;
}
