//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <malloc.h>
//#define MaxSize 100
//typedef char ElemType;
//typedef struct node
//{
//    ElemType data;              //����Ԫ��
//    struct node* lchild;        //ָ������
//    struct node* rchild;        //ָ���Һ���
//} BTNode;
//extern void CreateBTNode(BTNode*& b, char* str);
//extern BTNode* FindNode(BTNode* b, ElemType x);
//extern BTNode* LchildNode(BTNode* p);
//extern BTNode* RchildNode(BTNode* p);
//extern int BTNodeDepth(BTNode* b);
//extern void DispBTNode(BTNode* b);
////extern int BTWidth(BTNode *b);
////extern int Nodes(BTNode *b);
////extern int LeafNodes(BTNode *b);
//extern void DestroyBTNode(BTNode*& b);
//int main()
//{
//    BTNode* b, * p, * lp, * rp;;
//    CreateBTNode(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
//    printf("�������Ļ�����������:\n");
//    printf("  (1)���������:"); DispBTNode(b); printf("\n");
//    printf("  (2)H�ڵ�:");
//    p = FindNode(b, 'H');
//    if (p != NULL)
//    {
//        lp = LchildNode(p);
//        if (lp != NULL)
//            printf("����Ϊ%c ", lp->data);
//        else
//            printf("������ ");
//        rp = RchildNode(p);
//        if (rp != NULL)
//            printf("�Һ���Ϊ%c", rp->data);
//        else
//            printf("���Һ��� ");
//    }
//    printf("\n");
//    printf("  (3)������b�����:%d\n", BTNodeDepth(b));
//    //printf("  (4)������b�Ŀ��:%d\n",BTWidth(b));
//    //printf("  (5)������b�Ľڵ����:%d\n",Nodes(b));
//    //printf("  (6)������b��Ҷ�ӽڵ����:%d\n",LeafNodes(b));
//    printf("  (7)�ͷŶ�����b\n");
//    DestroyBTNode(b);
//}
//
//void CreateBTNode(BTNode*& b, char* str)     //��str������������
//{
//    BTNode* St[MaxSize], * p = NULL;
//    int top = -1, k, j = 0;
//    char ch;
//    b = NULL;             //�����Ķ�������ʼʱΪ��
//    ch = str[j];
//    while (ch != '\0')    //strδɨ����ʱѭ��
//    {
//        switch (ch)
//        {
//        case '(':top++; St[top] = p; k = 1; break;        //Ϊ��ڵ�
//        case ')':top--; break;
//        case ',':k = 2; break;                        //Ϊ�ҽڵ�
//        default:p = (BTNode*)malloc(sizeof(BTNode));
//            p->data = ch; p->lchild = p->rchild = NULL;
//            if (b == NULL)                    //pָ��������ĸ��ڵ�
//                b = p;
//            else                            //�ѽ������������ڵ�
//            {
//                switch (k)
//                {
//                case 1:St[top]->lchild = p; break;
//                case 2:St[top]->rchild = p; break;
//                }
//            }
//        }
//        j++;
//        ch = str[j];
//    }
//}
//BTNode* FindNode(BTNode* b, ElemType x)  //����data��Ϊx�Ľڵ�ָ��
//{
//    BTNode* p;
//    if (b == NULL)
//        return NULL;
//    else if (b->data == x)
//        return b;
//    else
//    {
//        p = FindNode(b->lchild, x);
//        if (p != NULL)
//            return p;
//        else
//            return FindNode(b->rchild, x);
//    }
//}
//BTNode* LchildNode(BTNode* p)   //����*p�ڵ�����ӽڵ�ָ��
//{
//    return p->lchild;
//}
//BTNode* RchildNode(BTNode* p)   //����*p�ڵ���Һ��ӽڵ�ָ��
//{
//    return p->rchild;
//}
//int BTNodeDepth(BTNode* b)  //�������b�����
//{
//    int lchilddep, rchilddep;
//    if (b == NULL)
//        return(0);                          //�����ĸ߶�Ϊ0
//    else
//    {
//        lchilddep = BTNodeDepth(b->lchild);   //���������ĸ߶�Ϊlchilddep
//        rchilddep = BTNodeDepth(b->rchild);   //���������ĸ߶�Ϊrchilddep
//        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
//    }
//}
//void DispBTNode(BTNode* b)  //�����ű�ʾ�����������
//{
//    if (b != NULL)
//    {
//        printf("%c", b->data);
//        if (b->lchild != NULL || b->rchild != NULL)
//        {
//            printf("(");
//            DispBTNode(b->lchild);
//            if (b->rchild != NULL) printf(",");
//            DispBTNode(b->rchild);
//            printf(")");
//        }
//    }
//}
///*
//int BTWidth(BTNode *b)  //�������b�Ŀ��
//{
//    struct
//    {
//        int lno;        //�ڵ�Ĳ�α��
//        BTNode *p;      //�ڵ�ָ��
//    } Qu[MaxSize];      //����˳���ѭ������
//    int front,rear;                         //������׺Ͷ�βָ��
//    int lnum,max,i,n;
//    front=rear=0;                           //�ö���Ϊ�ն�
//    if (b!=NULL)
//    {
//        rear++;
//        Qu[rear].p=b;                       //���ڵ�ָ�����
//        Qu[rear].lno=1;                     //���ڵ�Ĳ�α��Ϊ1
//        while (rear!=front)                 //���в�Ϊ��
//        {
//            front++;
//            b=Qu[front].p;                  //��ͷ����
//            lnum=Qu[front].lno;
//            if (b->lchild!=NULL)            //�������
//            {
//                rear++;
//                Qu[rear].p=b->lchild;
//                Qu[rear].lno=lnum+1;
//            }
//            if (b->rchild!=NULL)            //�Һ������
//            {
//                rear++;
//                Qu[rear].p=b->rchild;
//                Qu[rear].lno=lnum+1;
//            }
//        }
//        max=0;lnum=1;i=1;
//        while (i<=rear)
//        {
//            n=0;
//            while (i<=rear && Qu[i].lno==lnum)
//            {
//                n++;i++;
//            }
//            lnum=Qu[i].lno;
//            if (n>max) max=n;
//        }
//        return max;
//    }
//    else
//        return 0;
//}
//
//int Nodes(BTNode *b)    //�������b�Ľڵ����
//{
//    int num1,num2;
//    if (b==NULL)
//        return 0;
//    else if (b->lchild==NULL && b->rchild==NULL)
//        return 1;
//    else
//    {
//        num1=Nodes(b->lchild);
//        num2=Nodes(b->rchild);
//        return (num1+num2+1);
//    }
//}
//int LeafNodes(BTNode *b)    //�������b��Ҷ�ӽڵ����
//{
//    int num1,num2;
//    if (b==NULL)
//        return 0;
//    else if (b->lchild==NULL && b->rchild==NULL)
//        return 1;
//    else
//    {
//        num1=LeafNodes(b->lchild);
//        num2=LeafNodes(b->rchild);
//        return (num1+num2);
//    }
//}
//*/
//void DestroyBTNode(BTNode*& b)
//{
//    if (b != NULL)
//    {
//        DestroyBTNode(b->lchild);
//        DestroyBTNode(b->rchild);
//        free(b);
//    }
//}


//#include <stdio.h>
//#include <malloc.h>
//
//#define MAX_SIZE 100
//
//typedef char ElemType;
//typedef struct node
//{
//    ElemType data; // ����Ԫ��
//    struct node* lchild; // ָ�����ӽ��
//    struct node* rchild; // ָ���Һ��ӽ��
//}BTNode; // �����������������
//
///*-------------�����ű�ʾ��str����������b-----------------*/
//static void create_btree(BTNode*& b, char* str) // ����������(�β�b:ָ�������)
//{
//    BTNode* p{};
//    BTNode* St[MAX_SIZE]; // ����һ��˳��ջ
//    int k;
//    int j = 0;
//    int top = -1; // ջ��ָ���ʼ��
//    char ch;
//
//    b = NULL; // �����Ķ�������ʼʱΪ��
//    ch = str[j]; // ȡ��һ���ַ�
//    while (ch != '\0') // strδɨ����ʱѭ��
//    {
//            switch (ch)
//            {
//            case '(': // ��ʼ����������
//                top++;
//                St[top] = p;
//                k = 1;
//                break;
//            case ')': // �����������
//                top--;
//                break;
//            case ',': // ��ʼ����������
//                k = 2;
//                break;
//            default:
//                p = (BTNode*)malloc(sizeof(BTNode)); // ��̬������p�Ĵ洢�ռ�
//                p->data = ch;
//                p->lchild = p->rchild = NULL;
//                if (b == NULL) // ��bΪ��,p��Ϊ�������ĸ����
//                    b = p;
//                else // �ѽ��������������
//                {
//                        switch (k)
//                        {
//                        case 1:
//                            St[top]->lchild = p;
//                            break;
//                        case 2:
//                            St[top]->rchild = p;
//                            break;
//                        }
//                }
//                break;
//            }
//        // ȡ��һ���ַ�
//        j++;
//        ch = str[j];
//    }
//}
//
///*--------------------------�����ű�ʾ�����������b----------------------*/
//// "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"
//static void disp_btree(BTNode* b)
//{
//        if (b != NULL)
//        {
//                printf("%c", b->data);
//            if (b->lchild != NULL || b->rchild != NULL)
//            {
//                    printf("("); // �к��ӽ��ʱ�����(
//                disp_btree(b->lchild); // �ݹ鴦��������
//                if (b->rchild != NULL) // ���Һ��ӽ��ʱ�����,
//                    printf(",");
//                disp_btree(b->rchild); // �ݹ鴦��������
//                printf(")"); // �к��ӽ��ʱ�����)
//            }
//        }
//}
//
///*--------------------------�ͷŶ�����b�����н��----------------------*/
//static void destroy_btree(BTNode*& b) // ���ٶ�����(�β�b:ָ�������)
//{
//        if (b != NULL)
//        {
//                destroy_btree(b->lchild);
//            destroy_btree(b->rchild);
//            free(b);
//        }
//}
//
///*--------------------------����b�������ӽ��ָ��----------------------*/
//static BTNode* left_child_node(BTNode* b)
//{
//        return b->lchild;
//}
//
///*--------------------------����b�����Һ��ӽ��ָ��----------------------*/
//static BTNode* right_child_node(BTNode* b)
//{
//        return b->rchild;
//}
//
///*--------------------------����data��Ϊx�Ľ��ָ��----------------------*/
//static BTNode* find_node(BTNode* b, ElemType x) // ����ֵΪx�Ľ��
//{
//        BTNode* p;
//
//    if (b == NULL)
//        return NULL;
//    else if (b->data == x)
//        return b;
//    else
//    {
//            p = find_node(b->lchild, x);
//        if (p != NULL)
//            return p;
//        else
//            return find_node(b->rchild, x);
//    }
//}
//
///*--------------------------�������b�ĸ߶�----------------------*/
//static int btree_height(BTNode* b)
//{
//        int left_child_height, right_child_height;
//
//    if (b == NULL) // �����ĸ߶�Ϊ0
//        return 0;
//    else
//    {
//            // ���������ĸ߶�
//            left_child_height = btree_height(b->lchild);
//        // ���������ĸ߶�
//        right_child_height = btree_height(b->rchild);
//
//        return (left_child_height > right_child_height) ? (left_child_height + 1) : (right_child_height + 1);
//    }
//}
//
//int main(int argc, char* argv[])
//{
//        BTNode* b, * p, * lp, * rp;
//
//    printf("�������Ļ�����������:\n");
//    printf("  (1)����������\n");
//    create_btree(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
//    printf("  (2)���������:");
//    disp_btree(b);
//    printf("\n");
//    printf("  (3)H���:");
//    p = find_node(b, 'H');
//    if (p != NULL)
//    {
//            lp = left_child_node(p);
//        if (lp != NULL)
//            printf("����Ϊ%c ", lp->data);
//        else
//            printf("������");
//        rp = right_child_node(p);
//        if (rp != NULL)
//            printf("�Һ���Ϊ%c", rp->data);
//        else
//            printf("���Һ���");
//    }
//    printf("\n");
//    printf("  (4)������b�ĸ߶�:%d\n", btree_height(b));
//    printf("  (5)�ͷŶ�����b\n");
//    destroy_btree(b);
//
//    return 0;
//}

//#include "iostream"
//#define Maxsize 100
//using namespace std;
//typedef char ElemType;
//
//typedef struct node
//{
//    ElemType data;
//    struct node* lchild;
//    struct node* rchild;
//}BTNode;
//
//
//
//void CreateBTree(BTNode*& b, char* str) 
//{
//    BTNode* St[Maxsize], * p = NULL;
//    int top = -1, k, j = 0;
//    char ch;
//    b = NULL;
//    ch = str[j];
//    while (ch != '\0')
//    {
//        switch (ch)
//        {
//        case '(':top++; St[top] = p; k = 1; break;
//        case ')':top--;              break;
//        case ',':k = 2;                break;
//        default:
//            p = (BTNode*)malloc(sizeof(BTNode));
//            p->data = ch;
//            p->lchild = p->rchild = NULL;
//            if (b == NULL)
//                b = p;
//            else
//            {
//                switch (k)
//                {
//                case 1:St[top]->lchild = p; break;
//                case 2:St[top]->rchild = p; break;
//                }
//            }
//        }
//        j++;
//        ch = str[j];
//    }
//}
//
//void DestroyBtree(BTNode*& b) 
//{
//    if (b != NULL)
//    {
//        DestroyBtree(b->lchild);
//        DestroyBtree(b->rchild);
//        free(b);
//    }
//}
//
//BTNode* FindNode(BTNode* b, ElemType x)
//{
//    BTNode* p;
//    if (b == NULL)
//    {
//        return NULL;
//    }
//    else if (b->data == x)
//    {
//        return b;
//    }
//    else
//    {
//        p = FindNode(b->lchild, x);
//        if (p != NULL)
//        {
//            return p;
//        }
//        else
//        {
//            return FindNode(b->rchild, x);
//        }
//    }
//}
//
//BTNode* LchildNode(BTNode* p)
//{
//    return p->lchild;
//}
//
//BTNode* RchildNode(BTNode* p)
//{
//    return p->rchild;
//}
//
//int BTHeight(BTNode* b)
//{
//    int lchildh, rchildh;
//    if (b == NULL) return 0;
//    else
//    {
//        lchildh = BTHeight(b->lchild);
//        rchildh = BTHeight(b->rchild);
//        return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
//    }
//}
//
//void DispBTree(BTNode* b)
//{
//    if (b != NULL)
//    {
//        cout << b->data;
//        if (b->lchild != NULL || b->rchild != NULL)
//        {
//            cout << "(";
//            DispBTree(b->lchild);
//            if (b->rchild != NULL) cout << ",";
//            DispBTree(b->rchild);
//            cout << ")";
//        }
//    }
//}
//int main()
//{
//    BTNode* b;
//    char str[] = "A(B(D,E(H(J,K))),C(,G))";
//    CreateBTree(b, str);
//    cout << "��ʼ��������Ϊ��" << endl;
//    DispBTree(b);
//    cout << endl;
//    cout << "H�������㣺" << LchildNode(FindNode(b, 'H'))->data << "  �ҽ�㣺" << RchildNode(FindNode(b, 'H'))->data << endl;
//    cout << "�������ĸ߶�Ϊ:" << endl;
//    cout << BTHeight(b) << endl;
//    DestroyBtree(b);
//    return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//#define MAXSIZE 100
//typedef struct BinaryTreeNode {
//	char data;
//	struct BinaryTreeNode* lchild, * rchild;
//}BinaryTreeNode, * BinTree;
//
//void PreCreateBT(BinTree* t) {
//	char ch;
//	ch = getchar();
//
//	if (ch == '#')
//		*t = NULL;
//	else {
//		*t = (BinTree)malloc(sizeof(BinaryTreeNode));
//		(*t)->data = ch;
//		PreCreateBT(&(*t)->lchild);
//		PreCreateBT(&(*t)->rchild);
//	}
//}
////������� 
//void InOrderTransverse(BinTree t)
//{
//	if (t == NULL)
//		return;
//	InOrderTransverse(t->lchild);
//	printf("%c", t->data);
//	InOrderTransverse(t->rchild);
//}
//
//void PrintLevel(BinTree T)
//{
//	BinTree Queue[MAXSIZE];
//	int front, rear;
//	if (T == NULL)
//	{
//		return;
//	}
//	front = -1;
//	rear = 0;
//	Queue[rear] = T;
//	while (front != rear)
//	{
//		front++;
//		printf("%c", Queue[front]->data);
//		if (Queue[front]->lchild != NULL)
//		{
//			rear++;
//			Queue[rear] = Queue[front]->lchild;
//		}
//		if (Queue[front]->rchild != NULL)
//		{
//			rear++;
//			Queue[rear] = Queue[front]->rchild;
//
//		}
//
//	}
//
//}
//int main()
//{
//	BinTree t;
//	PreCreateBT(&t);
//	printf("����");
//	InOrderTransverse(t);
//	printf("\n");
//	printf("��Σ�");
//	PrintLevel(t);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int ans;
//typedef struct biTnode
//{
//
//	char data;
//	struct biTnode* lc, * rc;
//}biTnode, * bitree;
//void cr_bitree(bitree& T)
//{
//	char ch;
//	cin >> ch;
//	if (ch == '#')  T = NULL;
//	else {
//		T = new biTnode;
//		T->data = ch;
//		cr_bitree(T->lc);
//		cr_bitree(T->rc);
//	}
//}
//void find(bitree T)
//{
//	if (T == NULL) return;
//	if (T->lc == NULL && T->rc == NULL)
//		ans++;
//	else
//	{
//		find(T->lc);
//		find(T->rc);
//	}
//}
//int main()
//{
//	ans = 0;
//	bitree T;
//	cr_bitree(T);
//	find(T);
//	cout << ans << endl;
//	delete T;
//	return 0;
//}

#include<iomanip>
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define MaxWidth 40
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node* lchild;
    struct node* rchild;
}BTNode;

void DispBTNode(BTNode* b)
{
    if (b != NULL)
    {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");
            DispBTNode(b->lchild);
            if (b->rchild != NULL)
                printf(",");
            DispBTNode(b->rchild);
            printf(")");
        }
    }
}

void DestroyBTNode(BTNode*& b)
{
    if (b != NULL)
    {
        DestroyBTNode(b->lchild);
        DestroyBTNode(b->rchild);
        free(b);
    }
}
BTNode* CreateBT1(char* pre, char* in, int n)
{
    BTNode* s;
    char* p;
    int k;
    if (n <= 0) return NULL;
    s = (BTNode*)malloc(sizeof(BTNode));
    s->data = *pre;
    for (p = in; p < in + n; p++)
        if (*p == *pre) break;
    k = p - in;
    s->lchild = CreateBT1(pre + 1, in, k);
    s->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);
    return s;
}
BTNode* CreateBT2(char* post, char* in, int n, int m)
{
    BTNode* s;
    char* p, * q, * maxp{};
    int maxpost, maxin, k;
    if (n <= 0) return NULL;
    maxpost = -1;
    for (p = in; p < in + n; p++)
        for (q = post; q < post + m; q++)
            if (*p == *q)
            {
                k = q - post;
                if (k > maxpost)
                {
                    maxpost = k;
                    maxp = p;
                    maxin = p - in;
                }
            }
    s = (BTNode*)malloc(sizeof(BTNode));
    s->data = post[maxpost];
    s->lchild = CreateBT2(post, in, maxin, m);
    s->rchild = CreateBT2(post, maxp + 1, n - maxin - 1, m);
    return s;
}
int main()
{
    BTNode* b;
    ElemType pre[] = "ABDEHJKLMNCFGI";
    ElemType in[] = "DBJHLKMNEAFCGI";
    ElemType post[] = "DJLNMKHEBFIGCA";
    b = CreateBT1(pre, in, 14);
    printf("��������:%s\n", pre);
    printf("��������:%s\n", in);
    printf("����һ�ö�����b:\n");
    printf(" ���ű�ʾ��:");
    DispBTNode(b);
    printf("\n");
    printf("��������:%s\n", in);
    printf("��������:%s\n", post);
    b = CreateBT2(post, in, 14, 14);
    printf("����һ�ö�����b:\n");
    printf(" ���ű�ʾ��:");
    DispBTNode(b);
    printf("\n");
    DestroyBTNode(b);
}