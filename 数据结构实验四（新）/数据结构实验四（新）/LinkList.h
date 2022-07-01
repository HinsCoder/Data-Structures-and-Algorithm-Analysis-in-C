#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 20		// 存储空间初始分配量 
typedef int ElemType;  //单链表元素类型定义为字符类型
typedef struct Node
{
	ElemType data;
	struct Node* next; //定义的单链表结构体
}Node;				//初始化一个空的带表头结点的单链表

typedef struct Node* LinkList;  // 定义LinkList 

// 初始化链式线性表  
void InitList(LinkList* L);

// 初始条件：链式线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE  
void ListEmpty(LinkList L);

// 初始条件：链式线性表L已存在。操作结果：将L重置为空表  
void ClearList(LinkList* L);

// 初始条件：链式线性表L已存在。操作结果：返回L中数据元素个数  
int ListLength(LinkList L);

// 初始条件：链式线性表L已存在，1≤i≤ListLength(L)  
// 操作结果：用e返回L中第i个数据元素的值  
void GetElem(LinkList L, int i, ElemType* e);

// 初始条件：链式线性表L已存在  
// 操作结果：返回L中第1个与e满足关系的数据元素的位序。  
// 若这样的数据元素不存在，则返回值为0  
void LocateElem(LinkList L, ElemType e);

// 初始条件：链式线性表L已存在,1≤i≤ListLength(L)，  
// 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1  
void ListInsert(LinkList* L, int i, ElemType e);

// 初始条件：链式线性表L已存在，1≤i≤ListLength(L)  
// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1  
void ListDelete(LinkList* L, int i, ElemType* e);

// 初始条件：链式线性表L已存在  
// 操作结果：依次对L的每个数据元素输出  
void ListTraverse(LinkList L);

//  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法）  
void CreateListHead(LinkList* L, int n);

//  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法）  
void CreateListTail(LinkList* L, int n);

//删除链表
void delLNode(LinkList head, int num);

//连续删除结点
void deletes(LinkList* L, int min, int max);

void Reverse_List(LinkList L);