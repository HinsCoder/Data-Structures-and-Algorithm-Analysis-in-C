#include "SqList.h"
int main()
{
    int i = 0;
    SqList L;
    InitList(&L);
    char arr[] = { 'a','b','c','d','e'};
    int sz = sizeof(arr) / sizeof(arr[0]);      //����Ԫ�ظ���
    for (i = 0; i < sz; i++)
        L.data[i] = arr[i];
    L.length = sz;
    ListTraverse(L);                 //������Ա�
    printf("��˳�����Ϊ%d\n", ListLength(L));
    ListEmpty(L);        //�ж����Ա��Ƿ�Ϊ��
    ElemType e = 0;
    GetElem(&L, 3, &e);     //���˳���ĵ�3��Ԫ��
    LocateElem(L, 'a');     //�ж�Ԫ��a�Ƿ���˳����� 
    ListInsert(&L, 4, 'f');  //�ڵ�4��Ԫ��λ���ϲ���Ԫ��f
    ListTraverse(L);        //���˳���
    ListDelete(&L, 3, &e);   //ɾ����3��Ԫ��
    ListTraverse(L);        //������Ա�
    ClearList(&L);         //�ͷ����Ա�
}
