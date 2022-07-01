#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MaxSize 50 
//
//#define ClearBiTree DestroyBiTree
//
////���ڹ��������
//
//typedef char String[24]; //  0�ŵ�Ԫ��Ŵ��ĳ���  
//String str;
//
//int StrAssign(String T, char* chars);
//
//typedef char TElemType;
//
//
//typedef struct BiTNode  // ���ṹ 
//{
//	TElemType data;		// ������� 
//	struct BiTNode* lchild, * rchild; // ���Һ���ָ�� 
//}BiTNode, * BiTree; 
//
//// ����ն�����T  
//void InitBiTree(BiTree* T);
//
//// ��ʼ����: ������T���ڡ��������: ���ٶ�����T  
//void DestroyBiTree(BiTree* T);
//
//// ��ǰ������������н���ֵ��һ���ַ���  
//// #��ʾ������������������ʾ������T��  
//void CreateBiTree(BiTree* T);
//
//// ��ʼ����: ������T����  
//// �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE  
//int BiTreeEmpty(BiTree T);
//
//// ��ʼ����: ������T���ڡ��������: ����T�����  
//int BiTreeDepth(BiTree T);
//
//// ��ʼ����: ������T���ڡ��������: ����T�ĸ�  
//TElemType Root(BiTree T);
//
//// ��ʼ����: ������T���ڣ�pָ��T��ĳ�����  
//// �������: ����p��ָ����ֵ  
//TElemType Value(BiTree p);
//
//// ��p��ָ��㸳ֵΪvalue  
//void Assign(BiTree p, TElemType value);
//
//// ��ʼ����: ������T����  
//// �������: ǰ��ݹ����T  
//void PreOrderTraverse(BiTree T);
//
//// ��ʼ����: ������T����  
//// �������: ����ݹ����T  
//void InOrderTraverse(BiTree T);
//
//// ��ʼ����: ������T����  
//// �������: ����ݹ����T  
//void PostOrderTraverse(BiTree T);
//

typedef char ElemType;
typedef struct node
{
	ElemType data;			//����Ԫ��
	struct node* lchild;	//ָ�����ӽ��
	struct node* rchild;	//ָ���Һ��ӽ��
} BTNode;

void CreateBTNode(BTNode** b, const ElemType* str);

BTNode* FindNode(BTNode* b, ElemType x);

int BTNodeHeight(BTNode* b);

int LeafNodes(BTNode* b);

void InOrderTraverse(BTNode* T);

void LevelTraverse(BTNode* T);

int InOrderNRe(BTNode* b);

void PrintBTNode(BTNode* root, int level);

