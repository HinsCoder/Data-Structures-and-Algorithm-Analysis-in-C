#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    while(n)
//    {
//    printf("%d", n % 10);
//    n = n / 10;
//    }
//    return 0;
//}

#include<stdio.h>
int max3(int i, int j, int k)
{
    int max = i;
    if (max < j)
    {
        max = j;
    }
    if (max < k)
    {
        max = k;
    }
    return max;
}
int main()
{
    int a, b, c;
    float m=0.0;
    scanf("%d %d %d", &a, &b, &c);
    int ret1 = max3(a + b, b, c);
    int ret2 = max3(a, b + c, c);
    int ret3 = max3(a, b, b + c);
    m = ret1 *1.0/ (ret2 + ret3);
    printf("%.2f", m);
    return 0;
}