//#define _CRT_SECURE_NO_WARNINGS 1
//#define MAXSIZE 100          //存储空间初始分配量 
//typedef int  ElemType;       //ElemType类型根据实际情况而定，这里假设为int 
//typedef struct
//{
//    ElemType data[MAXSIZE];  //数组，存储数据元素 
//    int length;              //线性表当前长度 
//}SqList;
//int main()
//{
//    
//        SqList data = { {1,4,5,7,10,2,6,8,8,9},10 };
//        int m = 5;//data前5个元素递增有序
//        int n = 5;//data后5个元素递增有序
//
//        for (int i = m; i < m + n; i++) {
//            //elem_to_insert保存当前要插入的元素
//            int elem_to_insert = SqList->data[i];
//            int j = i - 1;
//            while (j >= 0 && list.arr[j] > elem_to_insert) {
//                //元素后移
//                list.arr[j + 1] = list.arr[j];
//                --j;
//            }
//            list.arr[j + 1] = elem_to_insert;
//        }
//}