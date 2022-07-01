#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>    
#include <stdlib.h>
#include <stdbool.h>  

#define MAXSIZE 100        //存储空间初始分配量 
typedef char ElemType;       //ElemType类型根据实际情况而定，这里假设为int 
typedef struct 
{
    ElemType data[MAXSIZE];  //数组，存储数据元素 
    int length;              //线性表当前长度 
}SqList;

// 初始化顺序线性表
void InitList(SqList* L);

// 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE 
void ListEmpty(SqList L);

// 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 
void ClearList(SqList* L);

// 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 
int ListLength(SqList L);

// 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) 
// 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 
int GetElem(SqList* L, int i, ElemType *e);

// 初始条件：顺序线性表L已存在 
// 操作结果：返回L中第1个与e满足关系的数据元素的位序。 
// 若这样的数据元素不存在，则返回值为0 
void LocateElem(SqList L, ElemType e);

// 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， 
// 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 
void ListInsert(SqList* L, int i, ElemType e);

// 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) 
// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 
int ListDelete(SqList* L, int i, ElemType* e);

// 初始条件：顺序线性表L已存在 
// 操作结果：依次对L的每个数据元素输出 
void ListTraverse(SqList L);

// 初始条件：顺序线性表L已存在。操作结果：释放顺序表L所占用的存储空间 
void DestroyList(SqList* L);





