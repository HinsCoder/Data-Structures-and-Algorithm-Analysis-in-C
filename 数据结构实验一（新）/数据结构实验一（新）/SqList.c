#include "SqList.h"
void InitList(SqList* L)
{
    L->length = 0;
}

void ListEmpty(SqList L)
{
	if (L.length == 0)
		printf("���Ա�Ϊ��\n");
	else
		printf("���Ա�Ϊ��\n");
}

void ClearList(SqList* L)
{
	L->length = 0;
}

int ListLength(SqList L)
{
	return L.length;
}

int GetElem(SqList* L, int i, ElemType* e)
{
	if (L->length == 0 || i<1 || i>L->length)
		printf("�Ҳ���\n");
	*e = L->data[i - 1];
	printf("�ҵ��ˣ���%d\n",*e);
}

void LocateElem(SqList L, ElemType e)
{
    int i;
    if (L.length == 0)
		printf("���Ա�Ϊ��\n");
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            break;
    }
    if (i >= L.length)
		printf("������Χ\n");
	printf("�ҵ��ˣ���%d\n", i + 1);
}

void ListInsert(SqList* L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)  // ˳�����Ա��Ѿ��� 
		printf("���Ա�����\n");
	if (i<1 || i>L->length + 1)// ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ 
		printf("������Χ\n");
	if (i <= L->length)        // ����������λ�ò��ڱ�β 
	{
		for (k = L->length - 1; k >= i - 1; k--)  // ��Ҫ����λ��֮�������Ԫ������ƶ�һλ 
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;          // ����Ԫ�ز��� 
	L->length++;
	printf("����ɹ�\n");
}

int ListDelete(SqList* L, int i, ElemType* e)
{
	int k;
	if (L->length == 0)               // ���Ա�Ϊ�� 
		printf("���Ա�Ϊ��\n");
	if (i<1 || i>L->length)         // ɾ��λ�ò���ȷ 
		printf("������Χ\n");
	*e = L->data[i - 1];
	if (i < L->length)                // ���ɾ���������λ�� 
	{
		for (k = i; k < L->length; k++)// ��ɾ��λ�ú��Ԫ��ǰ�� 
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	printf("ɾ��%d�ɹ�\n", *e);
}

void ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

//����LΪ˳���ָ�룬mΪǰ�������Ԫ�ظ�����nΪ���������Ԫ�ظ�����
//int m, n;
//void sort��SqList* L��int m��int n��
//{
//
//}

/**
 * ʹ������˳�������
 *
 * @param A ˳���
 * @param m ǰ�벿�ֵ��������Ԫ�ظ���
 * @param n ��벿�ֵ��������Ԫ�ظ���
 */
void Sort(SqList* L, int m, int n)
{
	int i = 0, j = 0, temp = 0;
	for (i = m; i < m + n; i++)		// �� m ��ʼ����Ҫ�ƶ� n ����
	{
		temp = L->data[i];			// ��ʱ����Ҫ�ƶ�����ֵ
		for (j = i - 1; j > 0; j--) // ���±�Ϊ i-1 ������ʼ����ǰ���������ƶ�һλ
		{
			if (L->data[j] > temp)  // ֻ�ƶ����� temp �����������ܰ��±�Ϊ i-1 ֮ǰ�������������� i-1 ����ʾ������������ƶ�һλ
			{
				L->data[j + 1] = L->data[j];    // ��ǰһλ�������Ǻ�һλ����
			}
			else 
			{
				break;              // ������ A->data[j]<=temp �����ʱ������ѭ����ֹͣ�ƶ�
			}
		}
		L->data[j + 1] = temp;			// �ƶ�֮��A->data[j+1]���ǿճ�����λ�ã�����temp
	}
}