//#define _CRT_SECURE_NO_WARNINGS 
//#include<stdio.h>
//#define MAXSIZE 20
//
//typedef char SElemType;
//// ��ջ�ṹ 
//typedef struct StackNode
//{
//    SElemType data;
//    struct StackNode* next;
//}StackNode, * LinkStackPtr;
//
//typedef struct
//{
//    LinkStackPtr top;
//    int count;
//}LinkStack;
////typedef struct StackNode
////{ 
////    SElemType data;           //������
////    struct StackNode* next;   //ָ����
////}LinkStack;
//
//// ����һ����ջS  
//void InitStack(LinkStack* S);
//
//// ��S��Ϊ��ջ  
//void ClearStack(LinkStack* S);
//
//// ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE  
//void StackEmpty(LinkStack S);
//
//// ����S��Ԫ�ظ�������ջ�ĳ���  
//int StackLength(LinkStack S);
//
//// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR  
//void GetTop(LinkStack S, SElemType* e);
//
//// ����Ԫ��eΪ�µ�ջ��Ԫ��  
//void Push(LinkStack* S, SElemType e);
//
//// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR  
//void Pop(LinkStack* S, SElemType* e);
//
////���
//void StackTraverse(LinkStack S);
//
////�������
//void StackReverseTraverse(LinkStackPtr S);
//
////�ͷ�ջ
//void DestroyStack(LinkStack* S);