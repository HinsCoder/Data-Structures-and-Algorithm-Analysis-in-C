#include "SqList.h"
int main()
{

    SqList* L=0, Sq;
    /*L = &Sq;*/
    InitList_sq(&L);
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'a');
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'b');
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'c');
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'd');
    ListInsert_Sq(L, ListLength_Sq(L) + 1, 'e');
    ListTraverse_Sq(L);   //�ж�˳���Ƿ�Ϊ��
    printf("��˳�����Ϊ%d\n", ListLength_Sq(L));
    ElemType e;
    GetElem_Sq(L, 3, &e);
    printf("%c\n", e);
    printf("%d\n", LocateElem_Sq(L, 'a'));
    LocateElem_Sq(L, 'a');    //�ж�Ԫ��a�Ƿ���˳�����
    ListInsert_Sq(L, 4, 'f');  //�ڵ��ĸ�Ԫ��λ���ϲ���Ԫ��f
    ListTraverse_Sq(L);        //���˳���
    ListDelete_Sq(L, 3, &e);   //ɾ��������Ԫ��
    ListTraverse_Sq(L);        //������Ա�
    DestroyList_Sq(L);         //�ͷ����Ա�
}

//С�᣺ʹ��C�����������Ա�ʱ��*��Ӧ->��&��Ӧ.������&Ҫ��*������
//���㴫��һ��������������ʱ��,��������᲻���ں����ڱ��Ķ�������ʹ��ʲô������ʽ�� 
//�����Ҫ���Ķ�,����Ҫ����ָ�����������ָ�룬����ֱ�Ӵ����������