//#define _CRT_SECURE_NO_WARNINGS 1
//#define MAXSIZE 100          //�洢�ռ��ʼ������ 
//typedef int  ElemType;       //ElemType���͸���ʵ������������������Ϊint 
//typedef struct
//{
//    ElemType data[MAXSIZE];  //���飬�洢����Ԫ�� 
//    int length;              //���Ա�ǰ���� 
//}SqList;
//int main()
//{
//    
//        SqList data = { {1,4,5,7,10,2,6,8,8,9},10 };
//        int m = 5;//dataǰ5��Ԫ�ص�������
//        int n = 5;//data��5��Ԫ�ص�������
//
//        for (int i = m; i < m + n; i++) {
//            //elem_to_insert���浱ǰҪ�����Ԫ��
//            int elem_to_insert = SqList->data[i];
//            int j = i - 1;
//            while (j >= 0 && list.arr[j] > elem_to_insert) {
//                //Ԫ�غ���
//                list.arr[j + 1] = list.arr[j];
//                --j;
//            }
//            list.arr[j + 1] = elem_to_insert;
//        }
//}