#define _CRT_SECURE_NO_WARNINGS 

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
//	bstree father=0;
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


//#include<stdio.h>
//#include<stdlib.h>
//typedef struct
//{
//	int key;
//}htable, * htype;
//int Hash(int key, int mod)
//{
//	return key % 11;
//}
//void createhash(htype& hashtable, htype st, int n, int m)
//{
//	int i, j;
//	hashtable = (htype)malloc(m * sizeof(htable));
//	for (i = 0; i < m; i++)
//		hashtable[i].key = NULL;
//	for (i = 0; i < n; i++)
//	{
//		j = Hash(st[i].key, m);
//		while (hashtable[j].key != NULL)
//			j = (j + 1) % m;
//		hashtable[j].key = st[i].key;
//	}
//}
//int search(htype hashtable, int key, int m)
//{
//	int i;
//	i = Hash(key, m);
//	while (hashtable[i].key != 0 && hashtable[i].key != key)
//	{
//		i++;
//	}
//	if (hashtable[i].key == 0)return -1;
//	else return i;
//}
//void out(htype hash, int m)
//{
//	int i;
//	printf("��ϣ��ַ��");
//	for (i = 0; i < m; i++)printf("%5d", i);
//	printf("\n");
//	printf("�ؼ���ֵ��");
//	for (i = 0; i < m; i++)printf("%5d", hash[i].key);
//}
//int main()
//{
//	htype st, hash;
//	hash = NULL;
//	int key, i, n, m;
//	printf("���������ݳ��ȣ�");
//	scanf("%d", &n);
//	printf("�������ϣ��ĳ��ȣ�");
//	scanf("%d", &m);
//	printf("���������ݣ�");
//	st = (htype)malloc(n * sizeof(htable)); /*��������*/
//	for (i = 0; i < n; i++)scanf("%d", &st[i].key);
//	createhash(hash, st, n, m);             /*��ʼ����ϣ��*/
//	out(hash, m);                           /*�����ϣ��*/
//	printf("\n");
//	printf("������������ҵ�Ԫ�أ�");
//	scanf("%d", &key);
//	i = search(hash, key, m);
//	if (i != -1)
//	{
//		printf("%d�Ĺ�ϣ��ַΪ��%d\n", key, i);
//	}
//	else
//	{
//		printf("��Ԫ�ز�����\n");
//	}
//	printf("��������ɾ����Ԫ�أ�");
//	scanf("%d", &key);
//	printf("ɾ����\n");
//	i = search(hash, key, m);
//	hash[i].key = 0;                      /*ɾ��Ԫ��*/
//	out(hash, m);
//	int j;
//	j = Hash(key, m);
//	while (hash[j].key != NULL)
//		j = (j + 1) % m;
//	hash[j].key = key;                    /*����Ԫ��*/
//	printf("\n�����\n");
//	out(hash, m);
//	printf("\n");
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//#define MAX_LENGTH 255
//
//typedef struct BSTreeNode {
//	char ch;
//	int count;
//	struct BSTreeNode* lchild;
//	struct BSTreeNode* rchild;
//}BSTNode;
//
//void CreateBSTree(BSTreeNode*& BT, char ch) {
//	if (BT == NULL) {
//		BT = (BSTNode*)malloc(sizeof(BSTNode));
//		BT->ch = ch;
//		BT->count = 1;
//		BT->lchild = BT->rchild = NULL;
//	}
//	else if (ch == BT->ch)
//		BT->count++;
//	else if (ch < BT->ch)
//		CreateBSTree(BT->lchild, ch);
//	else
//		CreateBSTree(BT->rchild, ch);
//}
//
//void InOrderTraverse(BSTNode* BT) {
//	if (BT != NULL) {
//		InOrderTraverse(BT->lchild);
//		printf("%c->[%d]\n", BT->ch, BT->count);
//		InOrderTraverse(BT->rchild);
//	}
//}
//
//void DestroyBSTree(BSTNode* BT) {
//	if (BT != NULL) {
//		DestroyBSTree(BT->lchild);
//		DestroyBSTree(BT->rchild);
//		free(BT);
//	}
//}
//
//int main() {
//	BSTNode* BT = NULL;
//	int i = 0;
//	char str[MAX_LENGTH];
//	printf("�������ַ���:\n");
//	gets_s(str);
//	while (str[i] != '\0') {
//		CreateBSTree(BT, str[i]);
//		i++;
//	}
//	printf("ÿ���ַ����ֵĴ���:\n");
//	InOrderTraverse(BT);
//	printf("\n");
//	DestroyBSTree(BT);
//	return 0;
//}

#include<stdio.h>
#include<math.h>
int main()
{
	long long i = pow(25, 12);
	printf("%lld\n", i%36);
	return 0;
}