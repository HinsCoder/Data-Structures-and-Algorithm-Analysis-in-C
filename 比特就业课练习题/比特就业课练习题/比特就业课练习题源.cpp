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
//	//0-200�ж�����
//	int i = 0;
//	for (i = 0; i < 200; i++)
//	{
//		//�ж�i�Ƿ�Ϊ����
//		if (adjust(i) == 1)
//		{
//			printf("%d������\n", i);
//		}
//		else
//		{
//			printf("%d��������\n", i);
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

/*дһ��������ʵ��һ��������������Ķ��ֲ��ҡ�*/
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
//		printf("�ҵ��ˣ���%d", ret);
//	}
//	else
//	{
//		printf("û�ҵ�");
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

//д���뽫�������������Ӵ�С�����
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

//дһ�������ӡ1 - 100֮������3�ı���������
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

//���������������������������Լ�����汾1��
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

//���������������������������Լ�����汾2��
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

//���������������������������Լ����շת�������
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

//��ӡ����
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

//��ӡ���꣨�����棩
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

//��ӡ100~200֮�������
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

//��ӡ100~200֮��������������棩
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

//��һ��1�� 100 �����������г��ֶ��ٸ�����9
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
//	printf("һ����%d������9\n",count);
//	return 0;
//}

//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ
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
//	printf("���Ϊ%f", total);
//	return 0;
//}

//��10 �����������ֵ
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
//	printf("���ֵΪ%d", max);
//	return 0;
//}

//����Ļ�����9*9�˷��ھ���
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

//������
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
//			printf("�ҵ��ˣ��±���%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���");
//	}
//	return 0;
//}

//��ʾ����ַ��������ƶ������м��ۡ�
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
//		//�����Ļ
//		system("cls");
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//}

//ģ�������¼
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("���������룺>");
//		scanf("%s", password);
//		if (strcmp(password,"abcdef")==0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("�����������������˳�����\n");
//	}
//
//	return 0;
//}

//���Բ���һ���������1-100��
//������  �´���  ��С��  �¶��˾ͽ���
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
//		printf("������֣�>");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("��С��\n");
//		}
//		else if (guess > ret)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("�¶���\n");
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
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ���������ѡ��\n");
//			break;
//		}	
//	} while (input);
//	return 0;
//}


//�ػ�����
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<time.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("��ĵ��Խ���60���ڹػ���������룺��������ȡ���ػ�\n");
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//��������
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
//	printf("����ǰΪ��%d %d\n", x, y);
//	swap(&x, &y);
//	printf("������Ϊ��%d %d\n", x, y);
//	return 0;
//}

//����Ļ������˷��ھ���(�Զ���)
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

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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

//ģ��ʵ��strlen���ǵݹ飩
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

//ģ��ʵ��strlen���ݹ鷨��
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

//�ַ������򣨷ǵݹ飩
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

//�ַ������򣨵ݹ�ʵ�֣�
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

//��׳ˣ��ǵݹ飩
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

//��׳ˣ��ݹ鷨��
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

//���n��쳲��������У��ݹ鷨��
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

//���n��쳲��������У��ݹ鷨�����棩
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

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
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

//�ݹ�ʵ��n��k�η�
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

//��Ϣ��ȫ��ѧ��ʱ����
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

//������A�е����ݺ�����B�е����ݽ��н�����������һ����
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

//����һ���������飬��ɶ�����Ĳ���
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�

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

//ð������
//#include<stdio.h>
//void bubble_sort(int* arr,int sz)
//{
//	//����
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		//һ��ð������
//		int j = 0;
//		for (j=0; j<sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				//����
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
 

//int main()
//{
//	//����
//	//������������ų�����
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	//0 1 2 3 4 5 6 7 8 9
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	//ð��������㷨���������������
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

//���������������в�ͬλ�ĸ���
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

//��ӡ���������Ƶ�����λ��ż��λ
//#include<stdio.h>
//int main()
//{
//	int i = 0, num = 0;
//	scanf("%d", &num);
//	printf("��������Ϊ��");
//	for (i = 31; i > 0; i = i - 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("ż������Ϊ��");
//	for (i = 30; i >= 0; i = i - 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	return 0;
//}

//ͳ�ƶ�������1�ĸ���
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
//	printf("һ����%d��1\n", result);
//	return 0;
//}

//����������������������ʱ������
//#include<stdio.h>
//int main()
//{
//	int a = 5, b = 3;
//	printf("����ǰ��a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("������a=%d b=%d\n", a, b);
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

//ʹ��ָ���ӡ��������
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

//�ַ�������
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

//�������
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


//��ˮ�ɻ���
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
//	return sum(i / 10, n) + pow(k, n);//�ݹ����ÿһλ��n�η���
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
//	if (sum(a, c) == a)//�ж��Ƿ�Ϊˮ�ɻ���
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

//��ӡ����
//#include<stdio.h>
//int main()
//{
//	int line = 0;
//	int i = 0;
//	scanf("%d", &line);//7
//	//��ӡ�ϰ벿��
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

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
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

//ģ��ʵ��strlen���ǵݹ飩
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
//	//����
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
//	printf("ԭ����Ϊ��");
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%3d", arr[i]);
//	}
//	printf("\n");
//	Adjust(arr, sizeof(arr) / sizeof(arr[0]));
//	printf("�ı��");
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

//���ͼ��
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

//����
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
//        printf("�������\n");
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	if (*(char*)&a == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
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


//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ�����Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
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
//                                        {//�����ֵ������ͬ���ж�
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

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:   A˵�������ҡ� B˵����C��
//C˵����D��        D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ��������������Щ��Ϣ��дһ��������ȷ������˭�����֡�
//#include<stdio.h>
//int main()
//{
//    char k; //��������
//    for (k = 'A'; k <= 'D'; k++)//���������˷ֱ�ȥ��֤if���������������߾�������
//    {
//        if (3 == ((k != 'A') + (k == 'C') + (k == 'D') + (k != 'D')))//ֻ������������˵�滰��һ���ٻ�������֮��Ϊ3�������������ȷ������������
//        {
//            printf("�����ǣ�%c\n", k);
//        }
//    }
//    return 0;
//}


//�������
//#include <stdio.h>
//int main()
//{
//	int i, j, k, arr[10][10] = { 0 };//arr[11][11]�����ʼ������ʼ��Ϊ{0}
//	printf("��ӡ��������ǣ�\n");
//	//��һ�кͶԽ��ߵ�������Ϊ1����ʱ��һ�����Ѹ�ֵ��
//	for (i = 0; i < 10; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//	//����������������еĹ���
//	for (i = 2; i < 10; i++)
//	{
//		for (j = 1; j < 10; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	//��ӡ�ո�����֣�
//	for (i = 0; i < 10; i++)
//	{
//		for (k = 0; k < 10 - 1 - i; k++)//������ո�Ĺ�ϵ
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)//��ӡ����
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
//			printf("�ҵ��ˣ��±��ǣ�%d %d\n", x, y);
//			return;
//		}
//	}
//	printf("�Ҳ���\n");
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 3;
//	find_k(arr, k, 3, 3);
//	return 0;
//}