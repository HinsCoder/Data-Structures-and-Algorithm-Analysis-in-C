#define _CRT_SECURE_NO_WARNINGS
/*1.15 ��֪����x��y��z��3������ȵ�����, �����һ���㷨,
ʹ��3��������С����� ˳�����, �����Ǵ��㷨�ıȽϴ���
��Ԫ���ƶ��Ĵ�����*/
//#include<stdio.h>
//int main(void)
//{
//	int a, b, c, tmp;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a > c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b > c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//�Ƚϴ���Ϊ3��,����ƶ�9��,�����ƶ�0�Ρ�

//#include<stdio.h>
//int delete(int* a, int n, int i)
//{
//	int j, sum = 0;
//    if(i<0||i>n)
//	   return 0;
//	for (j = i + 1; j < n; j++) 
//	{ 
//	   a[j - 1] = a[j]; 
//	   sum++;
//    }
//	n--;
//	return sum; 
//}   /* delete */
//
//
//int main(void)
//{
//	int arr[10] = {0};
//	int i=0;  //ɾ���ڼ���Ԫ��
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	printf("������Ҫɾ���ڼ���Ԫ��\n");
//	scanf("%d", &i);
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int count = delete(arr, n, i-1);
//	for (i = 0; i < n - 1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	printf("��Ҫ�ƶ�%d��\n", count);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,8,11,9,7,0,2,34,99,7 };
//	int max = 0, min = 0, i;
//	max = arr[0];
//	min = arr[0];
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[i] > max)
//			max = arr[i];
//		else if (arr[i] < min)
//			min = arr[i];
//	}
//	printf("max=%d\n", max);
//	printf("min=%d\n", min);
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int solution(float a, float b, float c)
//{
//	float d, x1, x2;
//	d = b * b - 4 * a * c;
//	if (d > 0)
//	{
//		x1 = (-b + sqrt(d)) / (2 * a);
//		x2 = (-b - sqrt(d)) / (2 * a);
//		return 2;
//	}
//	else if (d == 0)
//	{
//		x1 = (-b) / (2 * a);
//		return 1;
//	}
//	else
//		return 0;
//}
//
//void myprintf(float a, float b, float c)
//{
//	float d, x1, x2;
//	d = b * b - 4 * a * c;
//	if (d > 0)
//	{
//		x1 = (-b + sqrt(d)) / (2 * a);
//		x2 = (-b - sqrt(d)) / (2 * a);
//
//		printf("���̵ĸ�Ϊ%g��%g\n", x1, x2);
//	}
//	else if (d == 0)
//	{
//		x1 = (-b) / (2 * a);
//		printf("���̵ĸ�Ϊ%g\n", x1);
//	}
//	else
//		printf("û�з��̵ĸ�\n");
//}
//
//int main()
//{
//	float m, n, p;
//	printf("�����������Ԫһ�η���ϵ����������mx2+nx+p��");
//	scanf("%f %f %f", &m, &n, &p);
//	int result = solution(m, n, p);
//	printf("һ����%d����\n", result);
//	myprintf(m, n, p);
//	return 0;
//}

//#include<stdio.h>
//void swap(int a, int b)
//{
//	int tmp;
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("%d %d", a, b);
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	swap(a, b);
//	return 0;
//}

#include<stdio.h>
int fun(int a[], int m, int i)
{
	int j, max = a[0], s = 0;
	for (j = 0;j <= i - 1; j++)
		if (a[j] > max)
			max = a[j];
	return max;
}
int main()
{
	int i, m=10;
	int a[10] = { 1,2,5,7,8,4,9,6,3,4 };
	scanf("%d",&i);
	int result=fun(a, m, i);
	printf("%d", result);
	return 0;
}