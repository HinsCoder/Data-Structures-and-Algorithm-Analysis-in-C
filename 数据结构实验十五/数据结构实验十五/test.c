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
		static int i = 0;	   //��̬����
		printf("        ��%d����������", ++i);
		print(*L);
	}
}

// ��˳���L��ϣ������ ��ֱ�Ӳ�������������棩
void ShellSort(SqList* L)
{
	int i, j, k = 0;
	int increment = L->length;
	do
	{
		increment = increment / 3 + 1;// �������� ѡȡ��ʽ��ע�͢�
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])//  �轫L->r[i]�������������ӱ� 
			{
				L->r[0] = L->r[i]; //  �ݴ���L->r[0] 
				for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
					L->r[j + increment] = L->r[j]; //  ��¼���ƣ����Ҳ���λ�� 
				L->r[j + increment] = L->r[0]; //  ���� 
			}
		}
		printf("	��%d��������: ", ++k);
		print(*L);
	} while (increment > 1);     //����Ϊ1ʱ��ֹͣѭ��
}

// ����L������r���±�Ϊi��j��ֵ 
void swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

// ��˳���L����ѡ������ 
void SelectSort(SqList* L)
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		min = i;						// ����ǰ�±궨��Ϊ��Сֵ�±�  
		for (j = i + 1; j <= L->length; j++)// ѭ��֮�������  
		{
			if (L->r[min] > L->r[j])	// �����С�ڵ�ǰ��Сֵ�Ĺؼ���  
				min = j;				// ���˹ؼ��ֵ��±긳ֵ��min  
		}
		if (i != min)						// ��min������i��˵���ҵ���Сֵ������  
			swap(L, i, min);				// ����L->r[i]��L->r[min]��ֵ  
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

int main()
{
	int i;
	int arr[] = { 9,1,5,8,3,7,4,6,2,22,15};
	int sz = sizeof(arr) / sizeof(arr[0]);      //����Ԫ�ظ���
	SqList L0, L1, L2, L3, L4;
	for (i = 0; i < sz; i++)
		L0.r[i + 1] = arr[i];
	L0.length = sz;
	L4 = L3 = L2 = L1 = L0;
	printf("����ǰ:\n");
	print(L0);

	printf("ֱ�Ӳ�������:\n");
	InsertSort(&L1);
	print(L1);
	
	printf("ϣ������:\n");
	ShellSort(&L2);
	print(L2);

	printf("ֱ��ѡ������:\n");
	SelectSort(&L3);
	print(L3);

	printf("��������:\n");
	QuickSort(&L4);
	print(L4);
	return 0;
}

//ע�͢٣��о�����������������Ϊdlta[k]=2��t-k+1�η�-1��0<=k<=t<=log2(n+1))ʱ��Ч�ʲ���
//ע�͢ڣ���ѡȡ�����е�һ���ؼ��֣�Ȼ���뾡�취�����ŵ�һ��λ�ã�ʹ������ߵ�ֵ������С��
//�ұߵ�ֵ�����������ǽ������Ĺؼ��ֳ�Ϊ���ᣨpivot����