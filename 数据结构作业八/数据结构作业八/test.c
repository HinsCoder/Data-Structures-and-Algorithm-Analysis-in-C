#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>   
#include <malloc.h>
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

// ����L������r���±�Ϊi��j��ֵ 
void swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

// ��˳���L��ֱ�Ӳ������� 
void InsertSort(SqList* L)
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		if (L->r[i] < L->r[i - 1]) // �轫L->r[i]���������ӱ� 
		{
			L->r[0] = L->r[i]; // �ݴ���L->r[0]  
			for (j = i - 1; L->r[j] > L->r[0]; j--)
				L->r[j + 1] = L->r[j]; // ��¼���� 
			L->r[j + 1] = L->r[0]; // ���뵽��ȷλ�� 
		}
	}
}

// ��˳���L��ð������ 
void BubbleSort(SqList* L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--)  /* ע��j�ǴӺ���ǰѭ�� */
		{
			if (L->r[j] > L->r[j + 1]) /* ��ǰ�ߴ��ں��ߣ�ע����������һ�㷨�Ĳ��죩*/
			{
				swap(L, j, j + 1);/* ����L->r[j]��L->r[j+1]��ֵ */
			}
		}
		static int i = 0;	   //��̬����
		printf("        ��%d����������", ++i);
		print(*L);
	}
}

// �������� ��ð������������棩
int Partition(SqList* L, int low, int high)
{
	int pivotkey;         //����         �������ע�͢�
	pivotkey = L->r[low]; // ���ӱ�ĵ�һ����¼�������¼ 
	while (low < high)    //  �ӱ�����˽�������м�ɨ�� 
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		swap(L, low, high);// ���������¼С�ļ�¼�������Ͷ� 
		while (low < high && L->r[low] <= pivotkey)
			low++;
		swap(L, low, high);// ���������¼��ļ�¼�������߶� 
	}
	static int i = 0;	   //��̬����
	printf("        ��%d����������", ++i);
	print(*L);
	return low; // ������������λ�� 
}

// ��˳���L�е�������L->r[low..high]����������  �е�����ֲ���
void QSort(SqList* L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high); //  ��L->r[low - high]һ��Ϊ�����������ֵpivot 
		QSort(L, low, pivot - 1);		//  �Ե��ӱ�ݹ�����  
		QSort(L, pivot + 1, high);		//  �Ը��ӱ�ݹ����� 
	}
}

// ��˳���L���������� 
void QuickSort(SqList* L)
{
	QSort(L, 1, L->length);             //1Ϊ��һ��Ԫ�أ�L->lengthΪ���һ��Ԫ��
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

//�鲢����
//�������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] 
void Merge(int SR[], int TR[], int i, int m, int n, SqList* L)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)	// ��SR�м�¼��С����ز���TR 
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[i + l];		// ��ʣ���SR[i..m]���Ƶ�TR 
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[j + l];		// ��ʣ���SR[j..n]���Ƶ�TR 
	}
	static int c = 0;	   //��̬����
	printf("        ��%d����������", ++c);
	print(*L);
}

//�ݹ鷨
//��SR[s..t]�鲢����ΪTR1[s..t] 
void MSort(int SR[], int TR1[], int s, int t,SqList* L)
{
	int m;
	int TR2[MAXSIZE + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;			// ��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t] 
		MSort(SR, TR2, s, m,L);		// �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m] 
		MSort(SR, TR2, m + 1, t,L);	// �ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����TR2[m+1..t] 
		Merge(TR2, TR1, s, m, t,L);	// ��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t] 
	}

}

// ��˳���L���鲢���� 
void MergeSort(SqList* L)
{
	MSort(L->r, L->r, 1, L->length, L);
}

////��������
//int get_num(int number, int pos) 
//{
//	int num = 0;
//	while (pos--) {
//		num = number % 10;
//		number = number / 10;
//	}
//	return num;
//}
//
//void Rsort(SqList* L, int array_length)
//{
//	int* bucket[10];
//	for (int i = 0; i < 10; ++i) 
//	{
//		bucket[i] = (int*)malloc(sizeof(int) * array_length + 1);
//		bucket[i][0] = 0;//Ͱ�ĵ�һλ����Ͱ��Ԫ�ظ���
//	}
//	for (int b = 1; b <= 31; ++b) 
//	{
//		for (int i = 0; i < array_length; ++i) 
//		{
//			int num = get_num(L->r[i], b);//����ÿ��λ�ϵ����֣���λ��ʮλ����λ...��
//			int index = ++bucket[num][0];//�����±�
//			bucket[num][index] = L->r[i];//���浽Ͱ��
//		}
//		for (int i = 0, k = 0; i < 10; i++) 
//		{
//			for (int j = 1; j <= bucket[i][0]; ++j) 
//			{
//				L->r[k++] = bucket[i][j];//��Ͱ���水˳��ȡ����
//			}
//			bucket[i][0] = 0;//�±�����
//		}
//		static int c = 0;	   //��̬����
//		printf("        ��%d����������", ++c);
//		print(*L);
//	}
//}
//
//// ��˳���L���������� 
//void RadixSort(SqList* L)
//{
//	Rsort(L, L->length);
//}

int main()
{
	int i;
	int arr[] = { 40, 27, 28, 12, 15, 50, 7 };
	int sz = sizeof(arr) / sizeof(arr[0]);      //����Ԫ�ظ���
	SqList L0, L1, L2, L3, L4, L5, L6;
	for (i = 0; i < sz; i++)
		L0.r[i + 1] = arr[i];
	L0.length = sz;
	L6 = L5 = L4 = L3 = L2 = L1 = L0;
	printf("����ǰ:\n");
	print(L0);

	printf("ֱ�Ӳ�������:\n");
	InsertSort(&L1);
	print(L1);

	printf("ð������:\n");
	BubbleSort(&L2);
	print(L2);

	printf("��������:\n");
	QuickSort(&L3);
	print(L3);

	printf("������:\n");
	HeapSort(&L4);
	print(L4);

	printf("�鲢����:\n");
	MergeSort(&L5);
	print(L5);

	//printf("��������:\n");
	//RadixSort(&L6);
	//print(L6);
	return 0;

	return 0;
}

//ע�͢٣��о�����������������Ϊdlta[k]=2��t-k+1�η�-1��0<=k<=t<=log2(n+1))ʱ��Ч�ʲ���
//ע�͢ڣ���ѡȡ�����е�һ���ؼ��֣�Ȼ���뾡�취�����ŵ�һ��λ�ã�ʹ������ߵ�ֵ������С��
//�ұߵ�ֵ�����������ǽ������Ĺؼ��ֳ�Ϊ���ᣨpivot����