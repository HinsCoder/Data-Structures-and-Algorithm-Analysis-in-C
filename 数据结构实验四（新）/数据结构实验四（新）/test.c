#include"LinkList.h"
int main()
{
	LinkList L;
	int j, k = 0;
	int min, max;
	InitList(&L);
	printf("�밴�յ�����˳���������и�ֵ:(����-1��Ϊ������ֹ)\n");
	scanf("%d ", &j);
	while (j!=-1)
	{
		k++;
		ListInsert(&L, k, j);
		scanf("%d", &j);
	}
	printf("β�巨���β��������Ϊ");
	ListTraverse(L);
	printf("\n��ɾ������������֮�������?\n");
	scanf("%d %d", &min, &max);
	deletes(L, min, max);
	ListTraverse(L);
	Reverse_List(L);
	ListTraverse(L);
}