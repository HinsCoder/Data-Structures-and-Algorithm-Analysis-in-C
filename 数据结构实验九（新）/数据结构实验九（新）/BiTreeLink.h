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
////用于构造二叉树
//
//typedef char String[24]; //  0号单元存放串的长度  
//String str;
//
//int StrAssign(String T, char* chars);
//
//typedef char TElemType;
//
//
//typedef struct BiTNode  // 结点结构 
//{
//	TElemType data;		// 结点数据 
//	struct BiTNode* lchild, * rchild; // 左右孩子指针 
//}BiTNode, * BiTree; 
//
//// 构造空二叉树T  
//void InitBiTree(BiTree* T);
//
//// 初始条件: 二叉树T存在。操作结果: 销毁二叉树T  
//void DestroyBiTree(BiTree* T);
//
//// 按前序输入二叉树中结点的值（一个字符）  
//// #表示空树，构造二叉链表表示二叉树T。  
//void CreateBiTree(BiTree* T);
//
//// 初始条件: 二叉树T存在  
//// 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE  
//int BiTreeEmpty(BiTree T);
//
//// 初始条件: 二叉树T存在。操作结果: 返回T的深度  
//int BiTreeDepth(BiTree T);
//
//// 初始条件: 二叉树T存在。操作结果: 返回T的根  
//TElemType Root(BiTree T);
//
//// 初始条件: 二叉树T存在，p指向T中某个结点  
//// 操作结果: 返回p所指结点的值  
//TElemType Value(BiTree p);
//
//// 给p所指结点赋值为value  
//void Assign(BiTree p, TElemType value);
//
//// 初始条件: 二叉树T存在  
//// 操作结果: 前序递归遍历T  
//void PreOrderTraverse(BiTree T);
//
//// 初始条件: 二叉树T存在  
//// 操作结果: 中序递归遍历T  
//void InOrderTraverse(BiTree T);
//
//// 初始条件: 二叉树T存在  
//// 操作结果: 后序递归遍历T  
//void PostOrderTraverse(BiTree T);
//

typedef char ElemType;
typedef struct node
{
	ElemType data;			//数据元素
	struct node* lchild;	//指向左孩子结点
	struct node* rchild;	//指向右孩子结点
} BTNode;

void CreateBTNode(BTNode** b, const ElemType* str);

BTNode* FindNode(BTNode* b, ElemType x);

int BTNodeHeight(BTNode* b);

int LeafNodes(BTNode* b);

void InOrderTraverse(BTNode* T);

void LevelTraverse(BTNode* T);

int InOrderNRe(BTNode* b);

void PrintBTNode(BTNode* root, int level);

