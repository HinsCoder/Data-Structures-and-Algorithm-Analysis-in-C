#include"LinkList.h"
int main()
{
	LinkList L;
	int j, k = 0;
	int min, max;
	InitList(&L);
	printf("请按照递增的顺序向链表中赋值:(输入-1认为输入终止)\n");
	scanf("%d ", &j);
	while (j!=-1)
	{
		k++;
		ListInsert(&L, k, j);
		scanf("%d", &j);
	}
	printf("尾插法依次插入后，链表为");
	ListTraverse(L);
	printf("\n想删除介于哪两者之间的数据?\n");
	scanf("%d %d", &min, &max);
	deletes(L, min, max);
	ListTraverse(L);
	Reverse_List(L);
	ListTraverse(L);
}