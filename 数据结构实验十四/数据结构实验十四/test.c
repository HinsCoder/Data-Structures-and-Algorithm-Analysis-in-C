#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
// ˳����ң�aΪ���飬nΪҪ���ҵ����������keyΪҪ���ҵĹؼ��� 
//int Sequential_Search(int* a, int n, int key)
//{
//	int i;
//	for (i = 1; i <= n; i++)
//	{
//		if (a[i] == key)
//			return i;
//	}
//	return 0;
//}
//
//int main()
//{
//	int k = 5, i;
//	int arr[] = { 3,6,2,10,1,8,5,7,4,9 };
//	printf("ԭ��������Ϊ��");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\nԪ��5��λ��Ϊ ", *(arr + i));
//	i = Sequential_Search(arr, 10, k);
//	if (i == 0)
//		printf(" �Ҳ���!\n");
//	else
//		printf("%d\n", i + 1);
//	return 0;
//}


//���ֲ���
int binary_search(int* a, int n, int k)
{
	int left = 0;             //������ֵΪ��һ��
	int right = n - 1;		  //������ֵΪ���һ��

	while (left <= right)
	{
	    int mid = (left + right) / 2;    //�۰�
		if (a[mid] > k)                  //������ֵ����ֵС
		{
			right = mid - 1;             //�ұ߽����Ϊ��ֵ-1λ
		}
		else if (a[mid] < k)			 //������ֵ����ֵ��
		{
			left = mid + 1;				 //��߽����Ϊ��ֵ+1λ
		}
		else
		{
			return mid;					//�������˵��mid��Ϊ���ҵ���λ��
		}
	}return -1;							//������Χ
}

int main()
{
	int k = 9, i;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("ԭ��������Ϊ��");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\nԪ��9��λ��Ϊ ", *(arr + i));
	i = binary_search(arr, 10, k);
	if (i == -1)
		printf(" �Ҳ���!\n");
	else
		printf("%d\n", i + 1);
	return 0;
}