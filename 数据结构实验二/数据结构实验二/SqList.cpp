#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>    
#include <stdlib.h>  
#define MAXSIZE 20           //存储空间初始分配量 
typedef int  ElemType;       //ElemType类型根据实际情况而定，这里假设为int 
typedef struct
{
    ElemType data[MAXSIZE];  //数组，存储数据元素 
    int length;              //线性表当前长度 
}SqList;


// 初始化顺序线性表
void InitList_sq(SqList*& L)
{
    L = (SqList*)malloc(sizeof(SqList));
    L->length = 0;
}

// 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， 
// 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 
void ListInsert_Sq(SqList& L, int i, ElemType e)
{
    for (int j = L.length - 1; j >= i; j--)
        L.data[j + 1] = L.data[j];
    ++L.length;
    L.data[i] = e;
}

// 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) 
// 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 
bool GetElem_Sq(SqList*& L, int i, ElemType e)
{
    if (i<1 || i>L->length)
        return false;
    e = L->data[i - 1];
    return true;
}

// 初始条件：顺序线性表L已存在 
// 操作结果：返回L中第1个与e满足关系的数据元素的位序。 
// 若这样的数据元素不存在，则返回值为0 
int LocateElem_Sq(SqList* L, ElemType e)
{
    int i = 0;
    if (L->length == 0)
        return 0;
    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
            break;
    }
    if (i >= L->length)
        return 0;
    return i + 1;
}

// 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) 
// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 
void ListDelete_Sq(SqList& L, int i)
{
    for (int j = i; j <= L.length; j++)
        L.data[j] = L.data[j + 1];
        --L.length;
}

// 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE 
bool ListEmpty_Sq(SqList* L)
{
    if (L->length == 0)
        return true;
    else
        return false;
}

// 初始条件：顺序线性表L已存在。操作结果：释放顺序表L所占用的存储空间 
void DestroyList_Sq(SqList* L)
{
    free(L);
}

// 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 
int ListLength_Sq(SqList* L)
{
    return L->length;
}


// 初始条件：顺序线性表L已存在 
// 操作结果：依次对L的每个数据元素输出 
void ListTraverse_Sq(SqList* L)
{
    int i;
    printf("该线性表长度为%d,且元素有：", L->length);
    for (i = 0; i < L->length; i++)
        printf("%c  ", L->data[i]);
    printf("\n");
}


//打印线性表
void print_Sq(SqList& L)
{
    printf("顺序表的交集为：\n");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}


//其中L为顺序表指针，m为前面的有序元素个数，n为后面的有序元素个数。
//int m, n;
//void sort（SqList* L，int m，int n）
//{
//
//}

/**
 * 使得整个顺序表有序
 *
 * @param A 顺序表
 * @param m 前半部分递增有序的元素个数
 * @param n 后半部分递增有序的元素个数
 */
void Sort(SqList* A, int m, int n)
{
    // 从 m 开始，需要移动 n 个数
    for (int i = m; i < m + n; i++) {
        // 临时保存要移动的数值
        int temp = A->data[i];

        int j;
        // 从下标为 i-1 的数开始，将前面的数向后移动一位
        for (j = i - 1; j > 0; j--) {
            // 只移动大于 temp 的数，即不能把下标为 i-1 之前的所有数（包括 i-1 所表示的数）都向后移动一位
            if (A[j] > temp) {
                // 用前一位的数覆盖后一位的数
                A[j + 1] = A[j];
            }
            else {
                // 即遇到 A[j]<=temp 的情况时，跳出循环，停止移动
                break;
            }
        }

        // 移动之后，A[j+1]就是空出来的位置，填入temp
        A[j + 1] = temp;
    }
}

//分类
//void Sort(SqList& L)
//{
//    
//    int flag = 0;
//    for (int i = 0; i < 4; i++)
//    {
//        int Lb2 = L.data[6 + i];
//        //printf("输出得到的Lb2 的值：%d\n", Lb2);
//        for (int j = flag; j < L.length; j++)
//        {
//            if (Lb2 < L.data[j])
//            {
//                ListInsert_Sq(L, j, Lb2);
//                break;
//            }
//            flag = j;
//            //printf("输出flag的值：%d\n", flag);
//            continue;
//        }
//        //printf("删除的是：%d\n", La.data[7 + i]);
//        ListDelete_Sq(*&L, 7 + i);
//        //PrintList(La);
//        printf("\n");
//    }
//    print_Sq(L);
//}

//整体有序化，找到一个数的插入位置并插入后然后再删除
//void SortAll(SqList& L)
//{
//    int flag = 0;
//    int Lb1 = L.data[5];
//    if (Lb1 < L.data[0])
//    {
//        ListInsert_Sq(L, 0, Lb1);
//        ListDelete_Sq(L, 6);
//        //PrintList(La);
//        //printf("\n");
//        Sort(L);
//    }
//}

//求A∩B
void Intersection(SqList& A, SqList& B, SqList& C)
{
    int i, j, k = 0;
    for (i = 0; i < A.length; i++)
    {
        j = 0;
        while (j < B.length && B.data[j] != A.data[i])
            j++;
        if (j < B.length) //表⽰A->data[i]在B中，将其放到C中  
        {
            C.data[k++] = A.data[i];
        }
    }
    C.length = k;
    print_Sq(C);
}

int main()
{
    SqList A = { {1,2,4,7,8,0,3,5,6,9 },10 };
    SqList B = { {10,64,7,84,6,17,6,44,9,64 },10 };
    SqList C = { {0 },10 };
    Intersection(A, B, C);
    return 0;
}


//int main()
//{
//    SqList L = { {1,2,4,7,8,0,3,5,6,9 },10 };
//    SortAll(L);
//    return 0;
//}


