#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 20		// �洢�ռ��ʼ������ 
typedef int ElemType;  //������Ԫ�����Ͷ���Ϊ�ַ�����
typedef struct Node
{
	ElemType data;
	struct Node* next; //����ĵ�����ṹ��
}Node;				//��ʼ��һ���յĴ���ͷ���ĵ�����

typedef struct Node* LinkList;  // ����LinkList 

// ��ʼ����ʽ���Ա�  
void InitList(LinkList* L);

// ��ʼ��������ʽ���Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE  
void ListEmpty(LinkList L);

// ��ʼ��������ʽ���Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�  
void ClearList(LinkList* L);

// ��ʼ��������ʽ���Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���  
int ListLength(LinkList L);

// ��ʼ��������ʽ���Ա�L�Ѵ��ڣ�1��i��ListLength(L)  
// �����������e����L�е�i������Ԫ�ص�ֵ  
void GetElem(LinkList L, int i, ElemType* e);

// ��ʼ��������ʽ���Ա�L�Ѵ���  
// �������������L�е�1����e�����ϵ������Ԫ�ص�λ��  
// ������������Ԫ�ز����ڣ��򷵻�ֵΪ0  
void LocateElem(LinkList L, ElemType e);

// ��ʼ��������ʽ���Ա�L�Ѵ���,1��i��ListLength(L)��  
// �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1  
void ListInsert(LinkList* L, int i, ElemType e);

// ��ʼ��������ʽ���Ա�L�Ѵ��ڣ�1��i��ListLength(L)  
// ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1  
void ListDelete(LinkList* L, int i, ElemType* e);

// ��ʼ��������ʽ���Ա�L�Ѵ���  
// ������������ζ�L��ÿ������Ԫ�����  
void ListTraverse(LinkList L);

//  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨��  
void CreateListHead(LinkList* L, int n);

//  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨��  
void CreateListTail(LinkList* L, int n);

//ɾ������
void delLNode(LinkList head, int num);

//����ɾ�����
void deletes(LinkList* L, int min, int max);

void Reverse_List(LinkList L);