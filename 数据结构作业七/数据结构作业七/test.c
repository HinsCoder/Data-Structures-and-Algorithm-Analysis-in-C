#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct
//{
//	int key;
//}SqList;
//int SeqSearch(SqList R[], int n, int k)
//{
//	int i = 0;
//	while (i < n && R[i].key != k)i++;
//	if (i >= n)
//		return(-1);
//	else
//		return(i);
//}
//int main()
//{
//	int k = 5, i;
//	SqList R[] = { 3,6,2,10,1,8,5,7,4,9 };
//	i = SeqSearch(R, 10, k);
//	if (i == -1)
//		printf("No Found!\n");
//	else
//		printf("�ҵ��ˣ��ǵ�%d��\n", i + 1);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//typedef struct
//{
//	int key;
//}SqList;
//int BinSearch(SqList R[], int n, int k)
//{
//	int i, low = 0, high = n - 1, mid;
//	int find = 0;
//	while (low <= high && !find)
//	{
//		mid = (low + high) / 2;
//		if (k == R[mid].key)
//			find = 1;
//		else if (k < R[mid].key)
//			high = mid - 1;
//		else
//			low = mid + 1;
//	}
//	if (find == 1)
//		return mid + 1;
//	else
//		return -1;
//}
//int main()
//{
//	int k = 9, i;
//	SqList R[] = { 1,2,3,4,5,6,7,8,9,10 };
//	i = BinSearch(R, 10, k);
//	if (i == -1)
//		printf("No Found!\n");
//	else
//		printf("�ҵ��ˣ��ǵ�%d��\n", i);
//	return 0;
//}

//#include <stdio.h>
//#define MAXL 100                    //�����������¼����
//#define MAXI 20                     //�������������󳤶�
//typedef int KeyType;
//typedef char InfoType[10];
//typedef struct
//{
//    KeyType key;                    //KeyTypeΪ�ؼ��ֵ���������
//    InfoType data;                  //��������
//} NodeType;
//typedef NodeType SeqList[MAXL];     //˳�������
//typedef struct
//{
//    KeyType key;                    //KeyTypeΪ�ؼ��ֵ�����
//    int link;                       //ָ��ֿ����ʼ�±�
//} IdxType;
//typedef IdxType IDX[MAXI];          //����������
//
//int IdxSearch(IDX I, int m, SeqList R, int n, KeyType k)    //�ֿ�����㷨
//{
//    int low = 0, high = m - 1, mid, i, count1 = 0, count2 = 0;
//    int b = n / m;              //bΪÿ��ļ�¼����
//    printf("���ֲ���\n");
//    while (low <= high)       //���������н��ж��ֲ���,�ҵ���λ�ô����low��
//    {
//        mid = (low + high) / 2;
//        printf("  ��%d�αȽ�:��[%d,%d]�бȽ�Ԫ��R[%d]:%d\n", count1 + 1, low, high, mid, R[mid].key);
//        if (I[mid].key >= k)
//            high = mid - 1;
//        else
//            low = mid + 1;
//        count1++;           //�ۼ����������еıȽϴ���
//    }
//    if (low < m)              //���������в��ҳɹ���,�������Ա��н���˳�����
//    {
//        printf("�Ƚ�%d��,�ڵ�%d���в���Ԫ��%d\n", count1, low, k);
//        i = I[low].link;
//        printf("˳�����:\n    ");
//        while (i <= I[low].link + b - 1 && R[i].key != k)
//        {
//            i++; count2++;
//            printf("%d ", R[i].key);
//        }           //count2�ۼ���˳����Ӧ���еıȽϴ���
//        printf("\n");
//        printf("�Ƚ�%d��,��˳����в���Ԫ��%d\n", count2, k);
//        if (i <= I[low].link + b - 1)
//            return i;
//        else
//            return -1;
//    }
//    return -1;
//}
//int  main()
//{
//    SeqList R;
//    KeyType k = 46;
//    IDX I;
//    int a[] = { 8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87 }, i;
//    for (i = 0; i < 25; i++)              //����˳���
//        R[i].key = a[i];
//    I[0].key = 14; I[0].link = 0;
//    I[1].key = 34; I[1].link = 4;
//    I[2].key = 66; I[2].link = 10;
//    I[3].key = 85; I[3].link = 15;
//    I[4].key = 100; I[4].link = 20;
//    if ((i = IdxSearch(I, 5, R, 25, k)) != -1)
//        printf("Ԫ��%d��λ����%d\n", k, i);
//    else
//        printf("Ԫ��%d���ڱ���\n", k);
//    printf("\n");
//}


//#include<stdio.h>
//#include<stdlib.h>
//int n;
//typedef struct bstnode
//{
//	int key;
//	struct bstnode* lchild, * rchild;
//}bstnode, * bstree;
//void createtree(bstree& root, int data[])/*�������������*/
//{
//	bstree p;
//	bstree current;
//	bstree father;
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		p = (bstree)malloc(sizeof(bstnode));
//		p->key = data[i];
//		p->lchild = NULL;
//		p->rchild = NULL;
//		if (root == NULL)root = p;
//		else
//		{
//			current = root;
//			while (current != NULL)
//			{
//				father = current;
//				if (current->key >= data[i])
//					current = current->lchild;
//				else current = current->rchild;
//			}
//			if (father->key > data[i])
//				father->lchild = p;
//			else father->rchild = p;
//		}
//	}
//}
//int tree_search(bstree T, int key) /*�ҽ�㲢�������·��*/
//{
//	bstnode* pointer = T;
//	printf("��Ƚ϶������Ľ������Ϊ��");
//	while (pointer != NULL) {
//		if (pointer->key < key) {    //С��key����������������
//			printf("%d ", pointer->key);
//			pointer = pointer->rchild;
//		}
//		else if (pointer->key > key) {  //����key,��������������
//			printf("%d ", pointer->key);
//			pointer = pointer->lchild;
//		}
//		else if (pointer->key == key)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	printf("���������ݸ�����");
//	scanf("%d", &n);
//	bstree root = NULL;
//	bstree p;
//	int data[100];
//	int key;
//	printf("��������������������ݣ�");
//	for (int i = 0; i < n; i++)
//		scanf("%d", &data[i]);
//	createtree(root, data);         /*�������������*/
//	printf("�����������\n");
//	printf("������keyֵ��");
//	scanf("%d", &key);
//	tree_search(root, key);         /*�ҽ�㲢�������·��*/
//	printf("\n");
//	return 0;
//}
