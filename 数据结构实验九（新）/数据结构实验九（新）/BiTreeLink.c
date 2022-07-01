#include"BiTreeLink.h"
//
//int treeIndex = 1;
//
//TElemType Nil = ' '; // �ַ����Կո��Ϊ��  
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
//	printf("����ɹ�\n");
//}
//
//void DestroyBiTree(BiTree* T)
//{
//	if (*T)
//	{
//		if ((*T)->lchild) // ������  
//			DestroyBiTree(&(*T)->lchild); // ������������  
//		if ((*T)->rchild) // ���Һ���  
//			DestroyBiTree(&(*T)->rchild); // �����Һ�������  
//		free(*T); // �ͷŸ����  
//		*T = NULL; // ��ָ�븳0  
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
//			printf("����ʧ��\n");
//		(*T)->data = ch; // ���ɸ����  
//		CreateBiTree(&(*T)->lchild); // ����������  
//		CreateBiTree(&(*T)->rchild); // ����������  
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
//	printf("%c", T->data);// ��ʾ������ݣ����Ը���Ϊ�����Խ�����  
//	PreOrderTraverse(T->lchild); // ���������������  
//	PreOrderTraverse(T->rchild); // ����������������  
//}
//
//void InOrderTraverse(BiTree T)
//{
//	if (T == NULL)
//		return;
//	InOrderTraverse(T->lchild); // �������������  
//	printf("%c", T->data);// ��ʾ������ݣ����Ը���Ϊ�����Խ�����  
//	InOrderTraverse(T->rchild); // ����������������  
//}
//
//void PostOrderTraverse(BiTree T)
//{
//	if (T == NULL)
//		return;
//	PostOrderTraverse(T->lchild); // �Ⱥ������������   
//	PostOrderTraverse(T->rchild); // �ٺ������������   
//	printf("%c", T->data);// ��ʾ������ݣ����Ը���Ϊ�����Խ�����  
//}

void CreateBTNode(BTNode** b, const ElemType* str)
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	*b = NULL;				//�����Ķ�������ʼʱΪ��
	ch = str[j];
	while (ch != '\0')  	//strδɨ����ʱѭ��
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//Ϊ���ӽ��
		case ')':top--; break;
		case ',':k = 2; break;                      		//Ϊ���ӽ���ҽ��
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (*b == NULL)                    	 	///pΪ�������ĸ����
				*b = p;
			else  								//�ѽ��������������
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
		return 0;       	//�����ĸ߶�Ϊ0
	else
	{
		lchild = BTNodeHeight(b->lchild);	//���������ĸ߶�Ϊlchildh
		rchild = BTNodeHeight(b->rchild);	//���������ĸ߶�Ϊrchildh
		return(lchild > rchild) ? (lchild + 1) : (rchild + 1);
	}
}

int LeafNodes(BTNode* b)
{
	int l, r;
	if (b == NULL) return 0;//��������0
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
		InOrderTraverse(T->lchild); //�ݹ���������� 
		printf("%c", T->data);
		InOrderTraverse(T->rchild);   //�ݹ���������� 
	}
}
void LevelTraverse(BTNode* T)
{
	BTNode* p;
	BTNode* qu[MaxSize];	//���廷�ζ���,��Ž��ָ�� 
	int front, rear;	        //�����ͷ�Ͷ�βָ�� 
	front = rear = -1;	     	//�ö���Ϊ�ն��� 
	rear++;
	qu[rear] = T;		       //�����ָ�������� 
	while (front != rear)	  //���в�Ϊ�� 
	{
		front = (front + 1) % MaxSize;
		p = qu[front];	//��ͷ������ 
		printf("%c", p->data);
		if (p->lchild != NULL)	//������ʱ������� 
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)	//���Һ���ʱ������� 
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
{//������root��level��������Ԫ��ֵ�ĺ������
	if (root != NULL)
	{//�Ӷ�����root.getRight()��level+1��������Ԫ��ֵ�ĺ������
		PrintBTNode(root->rchild, level + 1);
		if (level != 0)
		{//�߹�6*(level-1)���ո�
			for (int i = 0; i < 4 * (level - 1); i++)
			{
				printf("%s", " ");
			}
			printf("%s", "---");		//�������
		}
		printf("%c", root->data); 		//�����������Ԫ��ֵ
		printf("\n");
		//�Ӷ�����root.getLeft()��level+1��������Ԫ��ֵ�ĺ������
		PrintBTNode(root->lchild, level + 1);
	}
}
