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
//		printf("找到了：是第%d个\n", i + 1);
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
//		printf("找到了：是第%d个\n", i);
//	return 0;
//}

//#include <stdio.h>
//#define MAXL 100                    //定义表中最多记录个数
//#define MAXI 20                     //定义索引表的最大长度
//typedef int KeyType;
//typedef char InfoType[10];
//typedef struct
//{
//    KeyType key;                    //KeyType为关键字的数据类型
//    InfoType data;                  //其他数据
//} NodeType;
//typedef NodeType SeqList[MAXL];     //顺序表类型
//typedef struct
//{
//    KeyType key;                    //KeyType为关键字的类型
//    int link;                       //指向分块的起始下标
//} IdxType;
//typedef IdxType IDX[MAXI];          //索引表类型
//
//int IdxSearch(IDX I, int m, SeqList R, int n, KeyType k)    //分块查找算法
//{
//    int low = 0, high = m - 1, mid, i, count1 = 0, count2 = 0;
//    int b = n / m;              //b为每块的记录个数
//    printf("二分查找\n");
//    while (low <= high)       //在索引表中进行二分查找,找到的位置存放在low中
//    {
//        mid = (low + high) / 2;
//        printf("  第%d次比较:在[%d,%d]中比较元素R[%d]:%d\n", count1 + 1, low, high, mid, R[mid].key);
//        if (I[mid].key >= k)
//            high = mid - 1;
//        else
//            low = mid + 1;
//        count1++;           //累计在索引表中的比较次数
//    }
//    if (low < m)              //在索引表中查找成功后,再在线性表中进行顺序查找
//    {
//        printf("比较%d次,在第%d块中查找元素%d\n", count1, low, k);
//        i = I[low].link;
//        printf("顺序查找:\n    ");
//        while (i <= I[low].link + b - 1 && R[i].key != k)
//        {
//            i++; count2++;
//            printf("%d ", R[i].key);
//        }           //count2累计在顺序表对应块中的比较次数
//        printf("\n");
//        printf("比较%d次,在顺序表中查找元素%d\n", count2, k);
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
//    for (i = 0; i < 25; i++)              //建立顺序表
//        R[i].key = a[i];
//    I[0].key = 14; I[0].link = 0;
//    I[1].key = 34; I[1].link = 4;
//    I[2].key = 66; I[2].link = 10;
//    I[3].key = 85; I[3].link = 15;
//    I[4].key = 100; I[4].link = 20;
//    if ((i = IdxSearch(I, 5, R, 25, k)) != -1)
//        printf("元素%d的位置是%d\n", k, i);
//    else
//        printf("元素%d不在表中\n", k);
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
//void createtree(bstree& root, int data[])/*构建排序二叉树*/
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
//int tree_search(bstree T, int key) /*找结点并输出查找路径*/
//{
//	bstnode* pointer = T;
//	printf("因比较而经过的结点依次为：");
//	while (pointer != NULL) {
//		if (pointer->key < key) {    //小于key，往树的右子树找
//			printf("%d ", pointer->key);
//			pointer = pointer->rchild;
//		}
//		else if (pointer->key > key) {  //大于key,往树的左子树找
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
//	printf("请输入数据个数：");
//	scanf("%d", &n);
//	bstree root = NULL;
//	bstree p;
//	int data[100];
//	int key;
//	printf("请输入二叉排序树的数据：");
//	for (int i = 0; i < n; i++)
//		scanf("%d", &data[i]);
//	createtree(root, data);         /*构建排序二叉树*/
//	printf("是排序二叉树\n");
//	printf("请输入key值：");
//	scanf("%d", &key);
//	tree_search(root, key);         /*找结点并输出查找路径*/
//	printf("\n");
//	return 0;
//}
