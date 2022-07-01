#pragma once
#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>  

#define MAXSIZE 100        //�洢�ռ��ʼ������ 
typedef char ElemType;       //ElemType���͸���ʵ������������������Ϊint 
typedef struct L
{
    ElemType *data;  //���飬�洢����Ԫ�� 
    int length;              //���Ա�ǰ���� 
}SqList;

// ��ʼ��˳�����Ա�
void InitList_sq(SqList**  L);

// ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� 
// �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 
bool ListInsert_Sq(SqList*  L, int i, ElemType e);

// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) 
// �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ 
bool GetElem_Sq(SqList*  L, int i, ElemType e);

// ��ʼ������˳�����Ա�L�Ѵ��� 
// �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� 
// ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 
int LocateElem_Sq(SqList* L, ElemType e);

// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) 
// ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 
bool ListDelete_Sq(SqList*  L, int i, ElemType* e);

// ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE 
bool ListEmpty_Sq(SqList* L);

// ��ʼ������˳�����Ա�L�Ѵ��ڡ�����������ͷ�˳���L��ռ�õĴ洢�ռ� 
void DestroyList_Sq(SqList* L);

// ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� 
int ListLength_Sq(SqList* L);

// ��ʼ������˳�����Ա�L�Ѵ��� 
// ������������ζ�L��ÿ������Ԫ����� 
void ListTraverse_Sq(SqList* L);

