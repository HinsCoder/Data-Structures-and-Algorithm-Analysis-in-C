//#include"LinkStack.h"
//void InitStack(LinkStack* S)
//{
//    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
//    if (!S->top)
//        printf("创建失败\n");
//    S->top = NULL;
//    S->count = 0;
//    printf("创建成功\n");
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
//    printf("置空成功\n");
//}
//
//void StackEmpty(LinkStack S)
//{
//    if (S.count == 0)
//        printf("该栈为空栈\n");
//    else
//        printf("该栈不为空栈\n");
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
//        ("该栈为空栈\n");
//    else
//        *e = S.top->data;
//    printf("该栈的栈顶元素为：%c\n", *e);
//}
//
//void Push(LinkStack* S, SElemType e)
//{
//    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
//    s->data = e;
//    s->next = S->top;	// 把当前的栈顶元素赋值给新结点的直接后继
//    S->top = s;         // 将新的结点s赋值给栈顶指针
//    S->count++;
//}
//
//void Pop(LinkStack* S, SElemType* e)
//{
//    LinkStackPtr p;
//    if (S->count == 0)
//        printf("该栈为空栈\n");
//    *e = S->top->data;
//    p = S->top;					// 将栈顶结点赋值给p，见图中③  
//    S->top = S->top->next;    // 使得栈顶指针下移一位，指向后一结点，见图中④  
//    free(p);                    // 释放结点p  
//    S->count--;
//    printf("删除成功\n");
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
