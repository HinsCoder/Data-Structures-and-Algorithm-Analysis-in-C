#include"SqStack.h"
//#include"LinkStack.h"

//顺序栈代码
int main()
{
    SqStack s;
    char e, j;
    InitStack(&s);
    StackEmpty(s);
    for (j = 'a'; j <= 'e'; j++)
        Push(&s, j);
    printf("栈中元素依次为：");
    StackTraverse(s);
    StackEmpty(s);
    printf("该顺序栈的长度为：%d\n", StackLength(s));
    printf("从栈顶到栈底的元素依次为：");
    StackReverseTraverse(s);
    StackEmpty(s);
    ClearStack(&s);
    return 0;
}

//链栈代码
//int main()
//{
//    LinkStack s;
//    char e, j;
//    InitStack(&s);
//    for (j = 'a'; j <= 'e'; j++)
//        Push(&s, j);
//    printf("栈中元素依次为：");
//    StackTraverse(s);
//    StackEmpty(s);
//    //printf("从栈顶到栈底的元素依次为：");
//    //StackReverseTraverse(s);
//    Pop(&s, &e);
//    printf("弹出的栈顶元素 e=%c\n", e);
//    StackTraverse(s);
//    GetTop(s, &e);
//    ClearStack(&s);
//    return 0;
//}