#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//int adjust(int n)
//{
//	int j=0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	} 
//	return 1;
//}
//
//int main(void)
//{
//	//0-200判断素数
//	int i = 0;
//	for (i = 0; i < 200; i++)
//	{
//		//判断i是否为素数
//		if (adjust(i) == 1)
//		{
//			printf("%d是素数\n", i);
//		}
//		else
//		{
//			printf("%d不是素数\n", i);
//		}
//	}
//	
//	return 0;
//}

//int is_leap_year(int n)
//{
//	int j;
//	if ((n % 4 == 0) && (n % 100 != 0)||(n%400==0))
//	{
//		return 1;
//	} 
//	else
//	return 0;
//}
//
//#include<stdio.h>
//int main() 
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (is_leap_year(y) == 1)
//		{
//			printf("%d ", y);
//		}
//	}
//	return 0;
//}

/*写一个函数，实现一个整形有序数组的二分查找。*/
//#include<stdio.h>
//int binary_search(int a[], int k, int s)
//{
//	int left = 0;
//	int right = s - 1;
//
//	while (left <= right)
//	{
//	    int mid = (left + right) / 2;
//		if (a[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (a[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 }; 
//	int key = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, key, sz);
//	if (ret >= 0)
//	{
//		printf("找到了，是%d", ret);
//	}
//	else
//	{
//		printf("没找到");
//	}
//	return 0;
//}

//#include<stdio.h>
//int max(int x, int y)
//{
//	if (x > y) 
//		return x;
//	else 
//	    return y;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int result = max(a, b);
//	printf("%d\n", result);
//	return 0;
//}

//写代码将三个整数数按从大到小输出。
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	int tmp;
//	scanf("%d %d %d", &a, &b ,&c);
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	else if(a<c)
//	{
//		tmp = c;
//		c = a;
//		a = tmp;
//	}
//	else if (b < c)
//	{
//		tmp = c;
//		c = b;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

//写一个代码打印1 - 100之间所有3的倍数的数字
//#include<stdio.h>
//int main()
//{
//	int i;
//	for (i = 1; i < 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//给定两个数，求这两个数的最大公约数（版本1）
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = a < b ? a : b;
//	int i;
//	for (i = a; i > 0; i--)
//	{
//		if (a % i ^ b % i == 0)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}

//给定两个数，求这两个数的最大公约数（版本2）
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = (a < b) ? a : b;
//	int m = min;
//	while (1)
//	{
//		if (a % m == 0 && b % m == 0)
//		{
//			break;
//		}
//		m--;
//	}
//	printf("%d\n", m);
//	return 0;
//}

//给定两个数，求这两个数的最大公约数（辗转相除法）
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = (a < b) ? a : b;
//	int m = min;
//	while (a%b)
//	{
//		int c = a % b;
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//打印闰年
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (((i % 4 ==0)&& (i % 100 != 0)) || ((i % 400) == 0))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//打印闰年（函数版）
//int is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || ((y % 400) == 0))
//		return 1;
//	else
//		return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if(is_leap_year(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//打印100~200之间的素数
//#include<stdio.h>
//int main()
//{
//	int i = 0, j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//打印100~200之间的素数（函数版）
//#include<stdio.h>
//#include<math.h>
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 101; i <= 200; i += 2)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int ret = 1, sum = 0;
//	int i = 0;
//	for (i = 1; i < 11; i++)
//	{
//		ret = ret * i;
//		sum = sum + ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//数一下1到 100 的所有整数中出现多少个数字9
//#include<stdio.h>
//int main()
//{
//	int i = 0, count = 0;
//	for (i = 1; i < 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("一共有%d个数字9\n",count);
//	return 0;
//}

//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	float sum_plus = 0.0f;
//	float sum_minus = 0.0f;
//	float total = 0.0f;
//	for (i = 1; i < 100; i = i + 2)
//	{
//		sum_plus = sum_plus + 1.000000/ i;
//	}
//	for (i = 2; i < 101; i = i + 2)
//	{
//		sum_minus = sum_minus - 1.000000 / i;
//	}
//	total = sum_plus + sum_minus;
//	printf("结果为%f", total);
//	return 0;
//}

//求10 个整数中最大值
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[i];
//	for (i = 0; i < 10; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("最大值为%d", max);
//	return 0;
//}

//在屏幕上输出9*9乘法口诀表
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//猜数字
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 }; 
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标是%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到");
//	}
//	return 0;
//}

//演示多个字符从两端移动，向中间汇聚。
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "welcome to bit!!!!";
//	char arr2[] = "##################";
//
//	int left = 0;
//	int right = strlen(arr2) - 1;
//
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		//清空屏幕
//		system("cls");
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//}

//模拟密码登录
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：>");
//		scanf("%s", password);
//		if (strcmp(password,"abcdef")==0)
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码均输入错误，退出程序\n");
//	}
//
//	return 0;
//}

//电脑产生一个随机数（1-100）
//猜数字  猜大了  猜小了  猜对了就结束
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("*******************************\n");
//	printf("*********  1.play  ************\n");
//	printf("*********  0.exit  ************\n");
//	printf("*******************************\n");
//}
//
//void game()
//{
//	int guess = 0;
//	int ret = rand()%100+1;
//
//	while (1)
//	{
//		printf("请猜数字：>");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜对了\n");
//			break;
//		}
//	}
//
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do 
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，重新选择！\n");
//			break;
//		}	
//	} while (input);
//	return 0;
//}


//关机程序
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<time.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("你的电脑将在60秒内关机，如果输入：我是猪，就取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//交换整数
//#include<stdio.h>
//void swap(int *a, int *b)
//{
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main()
//{
//	int x=10, y=20;
//	printf("交换前为：%d %d\n", x, y);
//	swap(&x, &y);
//	printf("交换后为：%d %d\n", x, y);
//	return 0;
//}

//在屏幕上输出乘法口诀表(自定义)
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int k = 0;
//	scanf("%d", &k);
//	for (i = 1; i <= k; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//递归方式实现打印一个整数的每一位
//#include<stdio.h>
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	print(i);
//	return 0;
//}

//模拟实现strlen（非递归）
//#include<stdio.h>
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//模拟实现strlen（递归法）
//#include<stdio.h>
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str+1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//字符串逆序（非递归）
//#include<stdio.h>
//#include<string.h>
//void reverse_string(char* str)
//{
//	int left = 0, right = strlen(str)-1;
//	int tmp = 0;
//	for (left=0;left<right;left++,right--)
//	{
//		tmp = str[right];
//		str[right] = str[left];
//		str[left] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//字符串逆序（递归实现）
//#include<stdio.h>
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//void reverse_string(char* str)
//{
//	int len = my_strlen(str);
//	char tmp = *str;
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str+1)>=2)
//	{
//		reverse_string(str + 1);
//	}
//	
//	*(str + len - 1) = tmp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//求阶乘（非递归）
//#include<stdio.h>
//int fac(int n)
//{
//	int k = 0, sum = 1;
//	for (k = 1; k <= n; k++)
//	{
//		sum = sum * k;
//	}
//	return sum;
//}
//
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int ret = fac(i);
//	printf("%d\n", ret);
//	return 0;
//}

//求阶乘（递归法）
//#include<stdio.h>
//int fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
//
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int ret = fac(i);
//	printf("%d\n", ret);
//	return 0;
//}

//求第n个斐波那契数列（递归法）
//#include<stdio.h>
//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//求第n个斐波那契数列（递归法升级版）
//#include<stdio.h>
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//#include<stdio.h>
//int DigitSum(int n)
//{
//	if (n > 9)
//	{
//		return DigitSum(n / 10 )+ n % 10;
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int result = DigitSum(i);
//	printf("%d\n", result);
//	return 0;
//}

//递归实现n的k次方
//#include<stdio.h>
//double Pow(int n,int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if (k > 0)
//	{
//		return n * Pow(n, k - 1);
//	}
//	else
//	{
//		return 1.0 / (Pow(n, -k));
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = Pow(n, k);
//	printf("%g\n", ret);
//	return 0;
//}

//信息安全数学临时代码
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int tmp = 0, yushu = 0;
//	for (i = 1; i < 25; i++)
//	{
//		tmp = 93 * i;
//		yushu = tmp % 37;
//		printf("%d %d\n", i, yushu);
//	}
//	return 0;
//}

//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
//#include<stdio.h>
//void Swap(int* arr1, int* arr2,int sz)
//{
//	int i = 0;
//	int tmp = 0;
//	for (i = 0; i < sz; i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//}
//int main()
//{
//	int arr1[] = { 0,5,10,2,6,7 };
//	int arr2[] = { 4,1,9,8,3,22 };
//	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//	Swap(arr1, arr2, sz1);
//	int i = 0;
//
//	for (i = 0; i < sz1; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
//	for (i = 0; i < sz2; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}

//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。

//#include<stdio.h>
//void print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void reverse(int* arr, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (left < right)
//	{
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//void init(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//int main()
//{
//	int arr[] = { 0,5,10,2,6,7,3,4,1,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	init(arr, sz);
//	print(arr, sz);
//	return 0;
//}

//冒泡排序
//#include<stdio.h>
//void bubble_sort(int* arr,int sz)
//{
//	//趟数
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		//一趟冒泡排序
//		int j = 0;
//		for (j=0; j<sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				//交换
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
 

//int main()
//{
//	//数组
//	//把数组的数据排成升序
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	//0 1 2 3 4 5 6 7 8 9
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//冒泡排序的算法，对数组进行排序
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int i, j;
//    for (i = 10000; i < 99999; i++)
//    {
//        int sum = 0;
//        for (j = 10; j <= 10000; j = 10 * j)
//        {
//            sum += (i / j) * (i % j);
//        }
//        if (sum == i)
//            printf("%d ", i);
//    }
//    return 0;
//}

//求两个数二进制中不同位的个数
//#include<stdio.h>
//int main()
//{
//	int m = 0, n = 0, c = 0, count = 0;
//	scanf("%d %d", &m, &n);
//	c = m ^ n;
//	while (c)
//	{
//		if (c % 2)
//		{
//			count++;
//		}
//		c = c >> 1;
//	}
//	printf("%d\n", count);
//	return 0;
//}

//打印整数二进制的奇数位和偶数位
//#include<stdio.h>
//int main()
//{
//	int i = 0, num = 0;
//	scanf("%d", &num);
//	printf("奇数序列为：");
//	for (i = 31; i > 0; i = i - 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("偶数序列为：");
//	for (i = 30; i >= 0; i = i - 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	return 0;
//}

//统计二进制中1的个数
//#include<stdio.h>
//int main()
//{
//	int num = 0, i = 0, result = 0;
//	scanf("%d", &num);
//	for (i = 31; i >= 0; i--)
//	{
//		if (num >> i & 1)
//		{
//			result++;
//		}
//	}
//	printf("一共有%d个1\n", result);
//	return 0;
//}

//交换两个变量（不创建临时变量）
//#include<stdio.h>
//int main()
//{
//	int a = 5, b = 3;
//	printf("交换前：a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后：a=%d b=%d\n", a, b);
//	return 0;
//}

//#include <stdio.h>
//int i;
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int a = 0x11223344;
//    char* pc = (char*)&a;
//    *pc = 0;
//    printf("%x\n", a);
//    return 0;
//}

//使用指针打印数组内容
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0;
//}

//字符串逆序
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char ch[10001];
//	gets_s(ch);
//	int len = strlen(ch);
//	char* p = ch, * q = ch + len - 1, tmp;
//	while (p < q)
//	{
//		tmp = *p;
//		*p = *q;
//		*q = tmp;
//		++p;
//		--q;
//	}
//	printf("%s", ch);
//	return 0;
//}

//计算求和
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d\n", 5 * a + 40 * a + 300 * a + 2000 * a + 10000 * a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int i = 0;
//	int sum = 0;
//	int k = 0;
//	for (i = 0; i < n; i++)
//	{
//		k = k * 10 + a;
//		sum += k;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//求水仙花数
//#include<stdio.h>
//#include<math.h>
//int sum(int i,int n)
//{
//	int k = 0;
//	k = i % 10;
//	if (i == 0)
//	{
//		return 0;
//	}
//	return sum(i / 10, n) + pow(k, n);//递归算出每一位的n次方和
//}
//
//int is_hua(int a)
//{
//	int i = a;
//	int c = 0;
//	while (i)
//	{
//		c++;
//		i = i / 10;
//	}
//	if (sum(a, c) == a)//判断是否为水仙花数
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int a = 0;
//	while (a < 100000)
//	{
//		if (is_hua(a) == 1)
//		{
//			printf("%d ", a);
//		}
//		a++;
//	}
//	printf("\n");
//	return 0;
//}

//打印菱形
//#include<stdio.h>
//int main()
//{
//	int line = 0;
//	int i = 0;
//	scanf("%d", &line);//7
//	//打印上半部分
//	for (i = 0; i < line; i++)
//	{
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2*i+1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < line - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
#include<stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	total = money;
	empty = money;
	while (empty > 1)
	{
		total = total + empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("total = %d\n", total);
	printf("total = %d\n", total);
	return 0;
}

//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}

//模拟实现strlen（非递归）
//#include<stdio.h>
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	//断言
//	assert(src != NULL);
//	assert(dest != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "XXXXXXXXXXXX";
//	char arr2[] = "hello bit";
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}


//#include <stdio.h>
//void Adjust(int arr[], int len)
//{
//	int i, j;
//	for (i = 0; i < len; i++)
//	{
//		if ((arr[i] % 2) == 0)
//			for (j = i + 1; j < len; j++)
//			{
//				int temp;
//				if ((arr[j] % 2) == 1)
//				{
//					temp = arr[i];
//					arr[i] = arr[j];
//					arr[j] = temp;
//					break;
//				}
//			}
//	}
//}
//int main()
//{
//	int i;
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	printf("原数组为：");
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%3d", arr[i]);
//	}
//	printf("\n");
//	Adjust(arr, sizeof(arr) / sizeof(arr[0]));
//	printf("改变后：");
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%3d", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//#include<stdio.h>
//int change(long long n)
//{
//    int b = n % 10;
//    int c = b % 2;
//    n = n / 10;
//    if (n)
//    {
//
//            return 10 * change(n) + c;
//    }
//
//    return c;
//}
//
//int main()
//{
//    long long n = 0;
//    scanf("%lld", &n);
//    int a = change(n);
//    printf("%d", a);
//    return 0;
//}

//输出图形
//#include<stdio.h>
//int main()
//{
//	int i = 0, j = 0, k = 0, num = 0;
//	while (scanf("%d", &num) != EOF)
//	{
//		for (i = 0; i < num; i++)
//			{
//				for (j = 0; j < (num-i-1); j++)
//				{
//					printf("  ");
//				}
//				for (j = 0; j <= i; j++)
//				{
//					printf("* ");
//				}
//				printf("\n");
//			}
//	}
//	return 0;
//}

//网购
//#include<stdio.h>
//int main()
//{
//    float a = 0;
//    int b, c, d;
//    scanf("%f %d %d %d", &a, &b, &c, &d);
//
//    if (b == 11 && c == 11)
//    {
//        a *= 0.7;
//        if (d == 1)
//        {
//            a -= 50;
//            if (a <= 0)
//            {
//                a = 0.00;
//                printf("%.2f", a);
//            }
//            else
//            {
//                printf("%.2f", a);
//            }
//
//
//        }
//        else
//        {
//            printf("%.2f", a);
//        }
//
//    }
//
//    else if (b == 12 && c == 12)
//    {
//        a *= 0.8;
//        if (d == 1)
//        {
//            a -= 50;
//            if (a <= 0)
//            {
//                a = 0.00;
//                printf("%.2f", a);
//            }
//            else
//            {
//                printf("%.2f", a);
//            }
//        }
//        else
//        {
//            printf("%.2f", a);
//        }
//    }
//    else
//    {
//        printf("输入错误\n");
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	if (*(char*)&a == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//#include<string.h>
//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}


//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；B选手说：我第二，E第四；
//C选手说：我第一，D第二；D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//#include<stdio.h>
//int main()
//{
//    int a = 0, b = 0, c = 0, d = 0, e = 0;
//    for (a = 1; a <= 5; a++)
//    {
//        for (b = 1; b <= 5; b++)
//        {
//            for (c = 1; c <= 5; c++)
//            {
//                for (d = 1; d <= 5; d++)
//                {
//                    for (e = 1; e <= 5; e++)
//                    {
//
//                        if ((2 == b && 3 != a) || (2 != b && 3 == a) == 1)
//                        {
//                            if ((2 == b && 4 != e) || (2 != b && 4 == e) == 1)
//                            {
//                                if ((1 == c && 2 != d) || (1 != c && 2 == d) == 1)
//                                {
//                                    if ((5 == c && 3 != d) || (5 != c && 3 == d) == 1)
//                                    {
//                                        if ((4 == e && 1 != a) || (4 != e && 1 == a) == 1)
//                                        {//对五个值均不相同的判断
//                                            if (((a != b) && (a != c) && (a != d) && (a != e))
//                                                && ((b != c) && (b != d) && (b != e))
//                                                && ((c != d) && (c != e))
//                                                && ((d != e)))
//                                            {
//                                                printf("a= %d, b= %d,c= %d,d= %d,e= %d\n", a, b, c, d, e);
//                                            }
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:   A说：不是我。 B说：是C。
//C说：是D。        D说：C在胡说
//已知3个人说了真话，1个人说的是假话。现在请根据这些信息，写一个程序来确定到底谁是凶手。
//#include<stdio.h>
//int main()
//{
//    char k; //代表凶手
//    for (k = 'A'; k <= 'D'; k++)//让凶手四人分别去验证if条件，满足条件者就是凶手
//    {
//        if (3 == ((k != 'A') + (k == 'C') + (k == 'D') + (k != 'D')))//只有满足三个人说真话，一个假话，他们之和为3这个条件，就能确定此人是凶手
//        {
//            printf("凶手是：%c\n", k);
//        }
//    }
//    return 0;
//}


//杨辉三角
//#include <stdio.h>
//int main()
//{
//	int i, j, k, arr[10][10] = { 0 };//arr[11][11]必须初始化，初始化为{0}
//	printf("打印出杨辉三角：\n");
//	//第一列和对角线的数，均为1，此时第一二行已赋值完
//	for (i = 0; i < 10; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//	//分析出杨辉三角排列的规律
//	for (i = 2; i < 10; i++)
//	{
//		for (j = 1; j < 10; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	//打印空格和数字；
//	for (i = 0; i < 10; i++)
//	{
//		for (k = 0; k < 10 - 1 - i; k++)//行数与空格的关系
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)//打印数字
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



//#include<stdio.h>
//void find_k(int arr[3][3], int k, int r, int c)
//{
//	int x = 0;
//	int y = c - 1;
//	while (x < r && y >= 0) {
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			printf("找到了，下标是：%d %d\n", x, y);
//			return;
//		}
//	}
//	printf("找不到\n");
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 3;
//	find_k(arr, k, 3, 3);
//	return 0;
//}