#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>  

#define MAXSIZE 100        //�洢�ռ��ʼ������ 
typedef char ElemType;       //ElemType���͸���ʵ������������������Ϊint 
typedef struct 
{
    ElemType data[MAXSIZE];  //���飬�洢����Ԫ�� 
    int length;              //���Ա�ǰ���� 
}SqList;

// ��ʼ��˳�����Ա�
void InitList(SqList* L);

// ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE 
void ListEmpty(SqList L);

// ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� 
void ClearList(SqList* L);

// ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� 
int ListLength(SqList L);

// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) 
// �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ 
int GetElem(SqList* L, int i, ElemType *e);

// ��ʼ������˳�����Ա�L�Ѵ��� 
// �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� 
// ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 
void LocateElem(SqList L, ElemType e);

// ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� 
// �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 
void ListInsert(SqList* L, int i, ElemType e);

// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) 
// ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 
int ListDelete(SqList* L, int i, ElemType* e);

// ��ʼ������˳�����Ա�L�Ѵ��� 
// ������������ζ�L��ÿ������Ԫ����� 
void ListTraverse(SqList L);

// ��ʼ������˳�����Ա�L�Ѵ��ڡ�����������ͷ�˳���L��ռ�õĴ洢�ռ� 
void DestroyList(SqList* L);





