#include"SqStack.h"
//#include"LinkStack.h"

//˳��ջ����
int main()
{
    SqStack s;
    char e, j;
    InitStack(&s);
    StackEmpty(s);
    for (j = 'a'; j <= 'e'; j++)
        Push(&s, j);
    printf("ջ��Ԫ������Ϊ��");
    StackTraverse(s);
    StackEmpty(s);
    printf("��˳��ջ�ĳ���Ϊ��%d\n", StackLength(s));
    printf("��ջ����ջ�׵�Ԫ������Ϊ��");
    StackReverseTraverse(s);
    StackEmpty(s);
    ClearStack(&s);
    return 0;
}

//��ջ����
//int main()
//{
//    LinkStack s;
//    char e, j;
//    InitStack(&s);
//    for (j = 'a'; j <= 'e'; j++)
//        Push(&s, j);
//    printf("ջ��Ԫ������Ϊ��");
//    StackTraverse(s);
//    StackEmpty(s);
//    //printf("��ջ����ջ�׵�Ԫ������Ϊ��");
//    //StackReverseTraverse(s);
//    Pop(&s, &e);
//    printf("������ջ��Ԫ�� e=%c\n", e);
//    StackTraverse(s);
//    GetTop(s, &e);
//    ClearStack(&s);
//    return 0;
//}