//#include"SqStack.h"
////˳��ջ����
//void InitStack(SqStack* S)
//{
//    /* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
//    S->top = -1;
//    printf("����ɹ�\n");
//}
//
//void ClearStack(SqStack* S)
//{
//    S->top = -1;
//    printf("�ÿճɹ�\n");
//}
//
//void StackEmpty(SqStack S)
//{
//    if (S.top == -1)
//        printf("��ջΪ��ջ\n");
//    else
//        printf("��ջ��Ϊ��ջ\n");
//}
//
//int StackLength(SqStack S)
//{
//    return S.top + 1;
//}
//
//void GetTop(SqStack S, SElemType* e)
//{
//    if (S.top == -1)
//        printf("��ջΪ��ջ\n");
//    else
//        *e = S.data[S.top];
//    printf("��ջ��ջ��Ԫ��Ϊ��%c\n",*e);
//}
//
//void Push(SqStack* S, SElemType e)
//{
//    if (S->top == MAXSIZE - 1) // ջ�� 
//    {
//        printf("��ջ����\n");
//    }
//    S->top++;				// ջ��ָ������һ 
//    S->data[S->top] = e;  // ���²���Ԫ�ظ�ֵ��ջ���ռ� 
//}
//
//void Pop(SqStack* S, SElemType* e)
//{
//    if (S->top == -1)
//        printf("��ջΪ��ջ\n");
//    *e = S->data[S->top];	// ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e 
//    printf("%d", *e);
//    S->top--;				// ջ��ָ���һ 
//}
//
//void StackTraverse(SqStack S)
//{
//    int i = 0;
//    while (i <= S.top)
//    {
//        printf("%c ", S.data[i++]);
//    }
//    printf("\n");
//}
//
//void StackReverseTraverse(SqStack S)
//{
//    int i = S.top;
//    while (i >= 0)
//    {
//        printf("%c ", S.data[i--]);
//    }
//    printf("\n");
//}
//
//void converse(SqStack* p, int num)
//{
//    int mod;//���� 
//    while (num != 0)
//    {
//        mod = num % 2;//�������
//        Push(p, mod);//������ջ 
//        num = num / 2;//��2���� 
//    }
//}
