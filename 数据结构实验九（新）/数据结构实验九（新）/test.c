#include"BiTreeLink.h"
//int main()
//{
//	int i;
//	BiTree T;
//	TElemType e1;
//	InitBiTree(&T);
//	StrAssign(str, "ABDH#K###E##CFI###G#J##");
//
//	CreateBiTree(&T);
//
//	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
//	e1 = Root(T);
//	printf("二叉树的根为: %c\n", e1);
//
//	printf("\n前序遍历二叉树:");
//	PreOrderTraverse(T);
//	printf("\n中序遍历二叉树:");
//	InOrderTraverse(T);
//	printf("\n后序遍历二叉树:");
//	PostOrderTraverse(T);
//	ClearBiTree(&T);
//	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
//	i = Root(T);
//	if (!i)
//		printf("树空，无根\n");
//
//	return 0;
//}

int main()
{
	BTNode* b=0;
	printf("(1)根据二叉树的广义表表示法创建二叉树的链式存储结构");
	CreateBTNode(&b, "1(2,3(4(6),5))");
	printf("(2)二叉树的横向输出为:\n");
	PrintBTNode(b, 0);
	BTNode* F;
	printf("\n(3)查找二叉树中的给定值的结点,例如定值点3");
	F = FindNode(b, '3');
	printf("左孩子为:%c, 右孩子为:%c", F->lchild->data, F->rchild->data);
	printf("\n(4)二叉树的高度的高度为:%d\n", BTNodeHeight(b));
	printf("(5)二叉树中的节点个数的为:%d", LeafNodes(b));
	printf("\n(6)二叉树的中序遍历为:");
	InOrderTraverse(b);
	printf("\n(7)二叉树的层序遍历为:");
	LevelTraverse(b);
	printf("\n(8)二叉树的非递归遍历(中序遍历):");
	InOrderNRe(b);
	printf("\n");

}
