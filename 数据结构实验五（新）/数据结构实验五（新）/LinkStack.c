//#include"LinkStack.h"
//void InitStack(LinkStack* S)
//{
//    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
//    if (!S->top)
//        printf("����ʧ��\n");
//    S->top = NULL;
//    S->count = 0;
//    printf("�����ɹ�\n");
//}
//
//void ClearStack(LinkStack* S)
//{
//    LinkStackPtr p, q;
//    p = S->top;
//    while (p)
//    {
//        q = p;
//        p = p->next;
//        free(q);
//    }
//    S->count = 0;
//    printf("�ÿճɹ�\n");
//}
//
//void StackEmpty(LinkStack S)
//{
//    if (S.count == 0)
//        printf("��ջΪ��ջ\n");
//    else
//        printf("��ջ��Ϊ��ջ\n");
//}
//
//int StackLength(LinkStack S)
//{
//    return S.count;
//}
//
//void GetTop(LinkStack S, SElemType* e)
//{
//    if (S.top == NULL)
//        ("��ջΪ��ջ\n");
//    else
//        *e = S.top->data;
//    printf("��ջ��ջ��Ԫ��Ϊ��%c\n", *e);
//}
//
//void Push(LinkStack* S, SElemType e)
//{
//    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
//    s->data = e;
//    s->next = S->top;	// �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��
//    S->top = s;         // ���µĽ��s��ֵ��ջ��ָ��
//    S->count++;
//}
//
//void Pop(LinkStack* S, SElemType* e)
//{
//    LinkStackPtr p;
//    if (S->count == 0)
//        printf("��ջΪ��ջ\n");
//    *e = S->top->data;
//    p = S->top;					// ��ջ����㸳ֵ��p����ͼ�Т�  
//    S->top = S->top->next;    // ʹ��ջ��ָ������һλ��ָ���һ��㣬��ͼ�Т�  
//    free(p);                    // �ͷŽ��p  
//    S->count--;
//    printf("ɾ���ɹ�\n");
//}
//
//void StackTraverse(LinkStack S)
//{
//    LinkStackPtr p;
//    p = S.top;
//    while (p)
//    {
//        printf("%c ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//
////void StackReverseTraverse(LinkStack S)
////{
////    LinkStackPtr p;
////    while (p->next != NULL)
////    {
////        p = p->next;
////        printf("%c ", p->data);
////    }
////    printf("\n");
////}
//
