//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <malloc.h>
//#define MaxSize 100
//typedef char ElemType;
//typedef struct node
//{
//    ElemType data;              //数据元素
//    struct node* lchild;        //指向左孩子
//    struct node* rchild;        //指向右孩子
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
//    printf("二叉树的基本运算如下:\n");
//    printf("  (1)输出二叉树:"); DispBTNode(b); printf("\n");
//    printf("  (2)H节点:");
//    p = FindNode(b, 'H');
//    if (p != NULL)
//    {
//        lp = LchildNode(p);
//        if (lp != NULL)
//            printf("左孩子为%c ", lp->data);
//        else
//            printf("无左孩子 ");
//        rp = RchildNode(p);
//        if (rp != NULL)
//            printf("右孩子为%c", rp->data);
//        else
//            printf("无右孩子 ");
//    }
//    printf("\n");
//    printf("  (3)二叉树b的深度:%d\n", BTNodeDepth(b));
//    //printf("  (4)二叉树b的宽度:%d\n",BTWidth(b));
//    //printf("  (5)二叉树b的节点个数:%d\n",Nodes(b));
//    //printf("  (6)二叉树b的叶子节点个数:%d\n",LeafNodes(b));
//    printf("  (7)释放二叉树b\n");
//    DestroyBTNode(b);
//}
//
//void CreateBTNode(BTNode*& b, char* str)     //由str串创建二叉链
//{
//    BTNode* St[MaxSize], * p = NULL;
//    int top = -1, k, j = 0;
//    char ch;
//    b = NULL;             //建立的二叉树初始时为空
//    ch = str[j];
//    while (ch != '\0')    //str未扫描完时循环
//    {
//        switch (ch)
//        {
//        case '(':top++; St[top] = p; k = 1; break;        //为左节点
//        case ')':top--; break;
//        case ',':k = 2; break;                        //为右节点
//        default:p = (BTNode*)malloc(sizeof(BTNode));
//            p->data = ch; p->lchild = p->rchild = NULL;
//            if (b == NULL)                    //p指向二叉树的根节点
//                b = p;
//            else                            //已建立二叉树根节点
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
//BTNode* FindNode(BTNode* b, ElemType x)  //返回data域为x的节点指针
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
//BTNode* LchildNode(BTNode* p)   //返回*p节点的左孩子节点指针
//{
//    return p->lchild;
//}
//BTNode* RchildNode(BTNode* p)   //返回*p节点的右孩子节点指针
//{
//    return p->rchild;
//}
//int BTNodeDepth(BTNode* b)  //求二叉树b的深度
//{
//    int lchilddep, rchilddep;
//    if (b == NULL)
//        return(0);                          //空树的高度为0
//    else
//    {
//        lchilddep = BTNodeDepth(b->lchild);   //求左子树的高度为lchilddep
//        rchilddep = BTNodeDepth(b->rchild);   //求右子树的高度为rchilddep
//        return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
//    }
//}
//void DispBTNode(BTNode* b)  //以括号表示法输出二叉树
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
//int BTWidth(BTNode *b)  //求二叉树b的宽度
//{
//    struct
//    {
//        int lno;        //节点的层次编号
//        BTNode *p;      //节点指针
//    } Qu[MaxSize];      //定义顺序非循环队列
//    int front,rear;                         //定义队首和队尾指针
//    int lnum,max,i,n;
//    front=rear=0;                           //置队列为空队
//    if (b!=NULL)
//    {
//        rear++;
//        Qu[rear].p=b;                       //根节点指针入队
//        Qu[rear].lno=1;                     //根节点的层次编号为1
//        while (rear!=front)                 //队列不为空
//        {
//            front++;
//            b=Qu[front].p;                  //队头出队
//            lnum=Qu[front].lno;
//            if (b->lchild!=NULL)            //左孩子入队
//            {
//                rear++;
//                Qu[rear].p=b->lchild;
//                Qu[rear].lno=lnum+1;
//            }
//            if (b->rchild!=NULL)            //右孩子入队
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
//int Nodes(BTNode *b)    //求二叉树b的节点个数
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
//int LeafNodes(BTNode *b)    //求二叉树b的叶子节点个数
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
//    ElemType data; // 数据元素
//    struct node* lchild; // 指向左孩子结点
//    struct node* rchild; // 指向右孩子结点
//}BTNode; // 声明二叉链结点类型
//
///*-------------由括号表示串str创建二叉链b-----------------*/
//static void create_btree(BTNode*& b, char* str) // 创建二叉树(形参b:指针的引用)
//{
//    BTNode* p{};
//    BTNode* St[MAX_SIZE]; // 定义一个顺序栈
//    int k;
//    int j = 0;
//    int top = -1; // 栈顶指针初始化
//    char ch;
//
//    b = NULL; // 建立的二叉树初始时为空
//    ch = str[j]; // 取第一个字符
//    while (ch != '\0') // str未扫描完时循环
//    {
//            switch (ch)
//            {
//            case '(': // 开始处理左子树
//                top++;
//                St[top] = p;
//                k = 1;
//                break;
//            case ')': // 子树处理完毕
//                top--;
//                break;
//            case ',': // 开始处理右子树
//                k = 2;
//                break;
//            default:
//                p = (BTNode*)malloc(sizeof(BTNode)); // 动态分配结点p的存储空间
//                p->data = ch;
//                p->lchild = p->rchild = NULL;
//                if (b == NULL) // 若b为空,p置为二叉树的根结点
//                    b = p;
//                else // 已建立二叉树根结点
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
//        // 取下一个字符
//        j++;
//        ch = str[j];
//    }
//}
//
///*--------------------------以括号表示法输出二叉树b----------------------*/
//// "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"
//static void disp_btree(BTNode* b)
//{
//        if (b != NULL)
//        {
//                printf("%c", b->data);
//            if (b->lchild != NULL || b->rchild != NULL)
//            {
//                    printf("("); // 有孩子结点时才输出(
//                disp_btree(b->lchild); // 递归处理左子树
//                if (b->rchild != NULL) // 有右孩子结点时才输出,
//                    printf(",");
//                disp_btree(b->rchild); // 递归处理右子树
//                printf(")"); // 有孩子结点时才输出)
//            }
//        }
//}
//
///*--------------------------释放二叉树b的所有结点----------------------*/
//static void destroy_btree(BTNode*& b) // 销毁二叉树(形参b:指针的引用)
//{
//        if (b != NULL)
//        {
//                destroy_btree(b->lchild);
//            destroy_btree(b->rchild);
//            free(b);
//        }
//}
//
///*--------------------------返回b结点的左孩子结点指针----------------------*/
//static BTNode* left_child_node(BTNode* b)
//{
//        return b->lchild;
//}
//
///*--------------------------返回b结点的右孩子结点指针----------------------*/
//static BTNode* right_child_node(BTNode* b)
//{
//        return b->rchild;
//}
//
///*--------------------------返回data域为x的结点指针----------------------*/
//static BTNode* find_node(BTNode* b, ElemType x) // 查找值为x的结点
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
///*--------------------------求二叉树b的高度----------------------*/
//static int btree_height(BTNode* b)
//{
//        int left_child_height, right_child_height;
//
//    if (b == NULL) // 空树的高度为0
//        return 0;
//    else
//    {
//            // 求左子树的高度
//            left_child_height = btree_height(b->lchild);
//        // 求右子树的高度
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
//    printf("二叉树的基本运算如下:\n");
//    printf("  (1)创建二叉树\n");
//    create_btree(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
//    printf("  (2)输出二叉树:");
//    disp_btree(b);
//    printf("\n");
//    printf("  (3)H结点:");
//    p = find_node(b, 'H');
//    if (p != NULL)
//    {
//            lp = left_child_node(p);
//        if (lp != NULL)
//            printf("左孩子为%c ", lp->data);
//        else
//            printf("无左孩子");
//        rp = right_child_node(p);
//        if (rp != NULL)
//            printf("右孩子为%c", rp->data);
//        else
//            printf("无右孩子");
//    }
//    printf("\n");
//    printf("  (4)二叉树b的高度:%d\n", btree_height(b));
//    printf("  (5)释放二叉树b\n");
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
//    cout << "初始化二叉树为：" << endl;
//    DispBTree(b);
//    cout << endl;
//    cout << "H结点的左结点：" << LchildNode(FindNode(b, 'H'))->data << "  右结点：" << RchildNode(FindNode(b, 'H'))->data << endl;
//    cout << "二叉树的高度为:" << endl;
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
////中序遍历 
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
//	printf("中序：");
//	InOrderTransverse(t);
//	printf("\n");
//	printf("层次：");
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
    printf("先序序列:%s\n", pre);
    printf("中序序列:%s\n", in);
    printf("构造一棵二叉树b:\n");
    printf(" 括号表示法:");
    DispBTNode(b);
    printf("\n");
    printf("中序序列:%s\n", in);
    printf("后序序列:%s\n", post);
    b = CreateBT2(post, in, 14, 14);
    printf("构造一棵二叉树b:\n");
    printf(" 括号表示法:");
    DispBTNode(b);
    printf("\n");
    DestroyBTNode(b);
}