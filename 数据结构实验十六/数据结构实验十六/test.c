#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>   
#define MAXSIZE 100   //����Ҫ��������������ֵ
typedef struct
{
	int r[MAXSIZE + 1];	// ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� 
	int length;			// ���ڼ�¼˳���ĳ��� 
}SqList;

void print(SqList L)
{
	int i;
	for (i = 1; i < L.length; i++)
		printf("%d,", L.r[i]);
	printf("%d", L.r[i]);
	printf("\n");
}

void swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}  

// ������ ����ѡ������������棩

// ��֪L->r[s..m]�м�¼�Ĺؼ��ֳ�L->r[s]֮�������ѵĶ��壬 
// ����������L->r[s]�Ĺؼ���,ʹL->r[s..m]��Ϊһ���󶥶� 
void HeapAdjust(SqList* L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j *= 2) // �عؼ��ֽϴ�ĺ��ӽ������ɸѡ ���ע�͢�
	{
		if (j < m&& L->r[j] < L->r[j + 1])
			++j;					// jΪ�ؼ����нϴ�ļ�¼���±� 
		if (temp >= L->r[j])
			break;					// rcӦ������λ��s�� 
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = temp;					// ���� 
}

//  ��˳���L���ж����� 
void HeapSort(SqList* L)
{
	int i;
	for (i = L->length / 2; i > 0; i--) // ��L�е�r������һ���󶥶� ���ע�͢�
		HeapAdjust(L, i, L->length);
	printf("  �ȹ���Ϊһ���󶥶ѣ�");
	print(*L);
	for (i = L->length; i > 1; i--)
	{
		swap(L, 1, i);					// ���Ѷ���¼�͵�ǰδ�����������е����һ����¼���� 
		printf("                ������");
		print(*L);
		HeapAdjust(L, 1, i - 1);		//  ��L->r[1..i-1]���µ���Ϊ�󶥶� 
		printf("�ٴι���Ϊһ���󶥶ѣ�");
		print(*L);
	}
	printf("\n");
}

//˫��ð�������㷨�������������������෴����ð�ݡ�
void DoubleSort(SqList* L)
{
	int left = 1, right = L->length, i = 0;
	while( left < right )
	{
		for (i = left; i < right;i++)	  //����ð��
		{
			if (L->r[i] > L->r[i + 1])    //�ҵ�����������
			{
				swap(L, i, i + 1);
			}
		}
		static int k = 0;
		printf("��%d������",++k);
		print(*L);
		right--;
		for (i = right; i > left; i--)	  //����ð��
		{
			if (L->r[i] < L->r[i - 1])	  //�ҵ���������С��
			{
				swap(L, i, i - 1);
			}
		}
		left++;
		printf("��%d������", ++k);
		print(*L);
	}
	printf("����������Ϊ��");
}

//��żð������
void OddEvenSort(SqList* L)
{

	int left = 1, right = L->length, i = 0, tag = 1;   //tag=1Ϊ�����˽����ı�־
	while (tag)
	{
		tag = 0;                          //tagΪ0��ʾû�з�������
		for (i = left; i < right; i+=2)	  //ɨ������������
		{
			if (L->r[i] > L->r[i + 1])    //�ҵ�����������
			{
				swap(L, i, i + 1);
				tag = 1;				  //tagΪ1��ʾ�����˽���
			}
		}
		static int k = 0;
		printf("��%d������", ++k);
		print(*L);
		for (i = left+1; i < right; i += 2)	  //ɨ������ż����
		{
			if (L->r[i] > L->r[i + 1])    //�ҵ�����������
			{
				swap(L, i, i + 1);
				tag = 1;				  //tagΪ1��ʾ�����˽���
			}
		}
		printf("��%d������", ++k);
		print(*L);
	}
	printf("����������Ϊ��");
}


int main()
{
	int i;
	int arr[] = { 9,1,5,8,3,7,4,6,2,25,11};
	int sz = sizeof(arr) / sizeof(arr[0]);      //����Ԫ�ظ���
	SqList L0, L1, L2, L3;
	for (i = 0; i < sz; i++)
		L0.r[i + 1] = arr[i];
	L0.length = sz;
	L3 = L2 = L1 = L0;
	printf("����ǰ:\n");
	print(L0);

	printf("������:\n");
	HeapSort(&L1);
	print(L1);

	printf("ð������汾��:\n");
	DoubleSort(&L2);
	print(L2);

	printf("ð������汾��:\n");
	OddEvenSort(&L3);
	print(L3);
	return 0;
}

//ע�͢٣�һ����ȫ�����������i=1������i�Ƕ������ĸ�����˫�ף����i>1������˫���ǽ��i/2 ��
//��ô������n�����Ķ��������ԣ�����iֵ����С�ڵ��� n/2 �ˡ�
//ע�͢ڣ��ɶ����������ʿ�֪����Ϊ��ǰ��Ϊ��ȫ����������ǰ��������s�������ӵ����һ����2s��
//�Һ��ӵ����һ����2s+1��,���ǵĺ��ӵ�ȻҲ����2��λ��������ӡ�