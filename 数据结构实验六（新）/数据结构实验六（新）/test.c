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
//    printf("请输入需要转换的十进制正整数:");
//    scanf("%d", &num);
//    converse(&s, num); //调用转换的函数
//    printf("转换为二进制为:");
//    while (s.top != -1)//循环出栈 
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
    printf("栈中元素依次为：");
    StackTraverse(s);
    printf("当前栈中元素有%d个\n", StackLength(s));
    Pop(&s, &e, 2);
    printf("弹出的栈顶元素 e=%d\n", e);
    StackEmpty(s);
    for (j = 6; j <= MAXSIZE - 2; j++)
        Push(&s, j, 1);
    printf("栈中元素依次为：");
    StackTraverse(s);
    Push(&s, 100, 1);
    StackEmpty(s);
    ClearStack(&s);
    StackEmpty(s);
    return 0;
}
