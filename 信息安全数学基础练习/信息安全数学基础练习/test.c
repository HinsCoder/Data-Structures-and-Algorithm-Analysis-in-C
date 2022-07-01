#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//int main()
//{
//	unsigned long long i = 17179869184 ,result = 0;
//	int a = 302, b = 145;
//	result = pow(a, b);
//	printf("相乘结果为：%lld 模运算为：%lld\n", result , result % 667);
//	return 0;
//}
//int main()
//{
//	int i = 25*47;
//	printf("%d\n", i % 19);
//	return 0;
//}

int main()
{
	int i = 19;
	int y = 0;
	for (y = 0; y < 41; y++)
	{
		printf("%d %d\n", y, (i*y)%40);
	}
	printf("\n");
	return 0;
}