#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;			//����Ԫ��
	struct node* lchild;	//ָ�����ӽ��
	struct node* rchild;	//ָ���Һ��ӽ��
} BTNode;

void CreateBTNode(BTNode*& b, const ElemType* str)
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//�����Ķ�������ʼʱΪ��
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
			if (b == NULL)                    	 	//*pΪ�������ĸ����
				b = p;
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
		InOrderTraverse(T->lchild); /*�ݹ����������*/
		printf("%c", T->data);
		InOrderTraverse(T->rchild);   /*�ݹ����������*/
	}
}
void LevelTraverse(BTNode* T)
{
	BTNode* p;
	BTNode* qu[MaxSize];	/*���廷�ζ���,��Ž��ָ��*/
	int front, rear;	        /*�����ͷ�Ͷ�βָ��*/
	front = rear = -1;	     	/*�ö���Ϊ�ն���*/
	rear++;
	qu[rear] = T;		       /*�����ָ��������*/
	while (front != rear)	  /*���в�Ϊ��*/
	{
		front = (front + 1) % MaxSize;
		p = qu[front];	/*��ͷ������*/
		printf("%c", p->data);
		if (p->lchild != NULL)	/*������ʱ�������*/
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)	/*���Һ���ʱ�������*/
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

int main()
{
	BTNode* b;
	printf("(1)���ݶ������Ĺ�����ʾ����������������ʽ�洢�ṹ");
	CreateBTNode(b, "1(2,3(4(6),5))");
	printf("(2)�������ĺ������Ϊ:\n");
	PrintBTNode(b, 0);
	BTNode* F;
	printf("\n(3)���Ҷ������еĸ���ֵ�Ľ��,���綨ֵ��3");
	F = FindNode(b, '3');
	printf("����Ϊ:%c, �Һ���Ϊ:%c", F->lchild->data, F->rchild->data);
	printf("\n(4)�������ĸ߶ȵĸ߶�Ϊ:%d\n", BTNodeHeight(b));
	printf("(5)�������еĽڵ������Ϊ:%d", LeafNodes(b));
	printf("\n(6)���������������Ϊ:");
	InOrderTraverse(b);
	printf("\n(7)�������Ĳ������Ϊ:");
	LevelTraverse(b);
	printf("\n(8)�������ķǵݹ����(�������):");
	InOrderNRe(b);
	printf("\n");

}