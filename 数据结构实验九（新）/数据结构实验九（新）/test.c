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
//	printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
//	e1 = Root(T);
//	printf("�������ĸ�Ϊ: %c\n", e1);
//
//	printf("\nǰ�����������:");
//	PreOrderTraverse(T);
//	printf("\n�������������:");
//	InOrderTraverse(T);
//	printf("\n�������������:");
//	PostOrderTraverse(T);
//	ClearBiTree(&T);
//	printf("\n�����������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
//	i = Root(T);
//	if (!i)
//		printf("���գ��޸�\n");
//
//	return 0;
//}

int main()
{
	BTNode* b=0;
	printf("(1)���ݶ������Ĺ�����ʾ����������������ʽ�洢�ṹ");
	CreateBTNode(&b, "1(2,3(4(6),5))");
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
