#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
#define INF 32767  //�������ֵ

typedef struct
{
	char data;  // �������ַ���ʾ 
	int weight;		// Ȩֵ 
	int parent;     // ˫�� 
	int lchild;     // ���� 
	int rchild;     // �Һ��� 
}HuffNode;

typedef struct      //����������Ĵ洢�ṹ  
{
	int code[MAXNUM];	//��ű���λ�� 
	int start;				//�������ʼλ�� 
}HuffCode;


//����������� 
void HuffmanCreate(HuffNode *ht, int n);

//�������������������ʽ��
void PrintHaffman(HuffNode *ht, int X);

//��������������ƽ�����ҳ��� 
void PrintHuffCode(HuffNode *ht, HuffCode *hcd, int n);

//������������� 
void EnCoding(HuffNode *ht, HuffCode *hcd, int n);