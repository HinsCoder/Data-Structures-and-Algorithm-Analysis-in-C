#include"BiTreeLink.h"
//
//int treeIndex = 1;
//
//TElemType Nil = ' '; // 字符型以空格符为空  
//
//int StrAssign(String T, char* chars)
//{
//	int i;
//	if (strlen(chars) > MAXSIZE)
//		return ERROR;
//	else
//	{
//		T[0] = strlen(chars);
//		for (i = 1; i <= T[0]; i++)
//			T[i] = *(chars + i - 1);
//		return OK;
//	}
//}
//
//void InitBiTree(BiTree* T)
//{
//	*T = NULL;
//	printf("构造成功\n");
//}
//
//void DestroyBiTree(BiTree* T)
//{
//	if (*T)
//	{
//		if ((*T)->lchild) // 有左孩子  
//			DestroyBiTree(&(*T)->lchild); // 销毁左孩子子树  
//		if ((*T)->rchild) // 有右孩子  
//			DestroyBiTree(&(*T)->rchild); // 销毁右孩子子树  
//		free(*T); // 释放根结点  
//		*T = NULL; // 空指针赋0  
//	}
//}
//
//void CreateBiTree(BiTree* T)
//{
//	TElemType ch;
//	// scanf("%c",&ch);  
//	ch = str[treeIndex++];
//
//	if (ch == '#')
//		*T = NULL;
//	else
//	{
//		*T = (BiTree)malloc(sizeof(BiTNode));
//		if (!*T)
//			printf("构造失败\n");
//		(*T)->data = ch; // 生成根结点  
//		CreateBiTree(&(*T)->lchild); // 构造左子树  
//		CreateBiTree(&(*T)->rchild); // 构造右子树  
//	}
//}
//
//int BiTreeEmpty(BiTree T)
//{
//	if (T)
//		return FALSE;
//	else
//		return TRUE;
//}
//
//int BiTreeDepth(BiTree T)
//{
//	int i, j;
//	if (!T)
//		return 0;
//	if (T->lchild)
//		i = BiTreeDepth(T->lchild);
//	else
//		i = 0;
//	if (T->rchild)
//		j = BiTreeDepth(T->rchild);
//	else
//		j = 0;
//	return i > j ? i + 1 : j + 1;
//}
//
//TElemType Root(BiTree T)
//{
//	if (BiTreeEmpty(T))
//		return Nil;
//	else
//		return T->data;
//}
//
//TElemType Value(BiTree p)
//{
//	return p->data;
//}
//
//void Assign(BiTree p, TElemType value)
//{
//	p->data = value;
//}
//
//void PreOrderTraverse(BiTree T)
//{
//	if (T == NULL)
//		return;
//	printf("%c", T->data);// 显示结点数据，可以更改为其它对结点操作  
//	PreOrderTraverse(T->lchild); // 再先序遍历左子树  
//	PreOrderTraverse(T->rchild); // 最后先序遍历右子树  
//}
//
//void InOrderTraverse(BiTree T)
//{
//	if (T == NULL)
//		return;
//	InOrderTraverse(T->lchild); // 中序遍历左子树  
//	printf("%c", T->data);// 显示结点数据，可以更改为其它对结点操作  
//	InOrderTraverse(T->rchild); // 最后中序遍历右子树  
//}
//
//void PostOrderTraverse(BiTree T)
//{
//	if (T == NULL)
//		return;
//	PostOrderTraverse(T->lchild); // 先后序遍历左子树   
//	PostOrderTraverse(T->rchild); // 再后序遍历右子树   
//	printf("%c", T->data);// 显示结点数据，可以更改为其它对结点操作  
//}

void CreateBTNode(BTNode** b, const ElemType* str)
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	*b = NULL;				//建立的二叉树初始时为空
	ch = str[j];
	while (ch != '\0')  	//str未扫描完时循环
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//为左孩子结点
		case ')':top--; break;
		case ',':k = 2; break;                      		//为孩子结点右结点
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (*b == NULL)                    	 	///p为二叉树的根结点
				*b = p;
			else  								//已建立二叉树根结点
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
BTNode* FindNode(BTNode* b, ElemType x)
{
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}

int BTNodeHeight(BTNode* b)
{
	int lchild, rchild;
	if (b == NULL)
		return 0;       	//空树的高度为0
	else
	{
		lchild = BTNodeHeight(b->lchild);	//求左子树的高度为lchildh
		rchild = BTNodeHeight(b->rchild);	//求右子树的高度为rchildh
		return(lchild > rchild) ? (lchild + 1) : (rchild + 1);
	}
}

int LeafNodes(BTNode* b)
{
	int l, r;
	if (b == NULL) return 0;//空树返回0
	else
	{
		l = LeafNodes(b->lchild);
		r = LeafNodes(b->rchild);
		return (l + r + 1);
	}
}

void InOrderTraverse(BTNode* T)
{
	if (T != NULL)
	{
		InOrderTraverse(T->lchild); //递归访问左子树 
		printf("%c", T->data);
		InOrderTraverse(T->rchild);   //递归访问右子树 
	}
}
void LevelTraverse(BTNode* T)
{
	BTNode* p;
	BTNode* qu[MaxSize];	//定义环形队列,存放结点指针 
	int front, rear;	        //定义队头和队尾指针 
	front = rear = -1;	     	//置队列为空队列 
	rear++;
	qu[rear] = T;		       //根结点指针进入队列 
	while (front != rear)	  //队列不为空 
	{
		front = (front + 1) % MaxSize;
		p = qu[front];	//队头出队列 
		printf("%c", p->data);
		if (p->lchild != NULL)	//有左孩子时将其进队 
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)	//有右孩子时将其进队 
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
}

int InOrderNRe(BTNode* b)
{
	BTNode* St[MaxSize], * q;
	int top = -1;
	if (b == NULL) return 0;
	while (top > -1 || b != NULL)
	{
		while (b != NULL)
		{
			top++; St[top] = b;
			b = b->lchild;
		}
		q = St[top]; top--;
		printf("%c", q->data);
		if (q->rchild != NULL)
			b = q->rchild;
	}
	return 0;

}

void PrintBTNode(BTNode* root, int level)
{//二叉树root第level层结点数据元素值的横向输出
	if (root != NULL)
	{//子二叉树root.getRight()第level+1层结点数据元素值的横向输出
		PrintBTNode(root->rchild, level + 1);
		if (level != 0)
		{//走过6*(level-1)个空格
			for (int i = 0; i < 4 * (level - 1); i++)
			{
				printf("%s", " ");
			}
			printf("%s", "---");		//输出横线
		}
		printf("%c", root->data); 		//输出结点的数据元素值
		printf("\n");
		//子二叉树root.getLeft()第level+1层结点数据元素值的横向输出
		PrintBTNode(root->lchild, level + 1);
	}
}
