#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define LEN sizeof(struct LNode) 

struct LNode {
	int data;//������
	struct LNode* next;
};
typedef struct LNode LNode, * LinkList;
//��ʼ��һ������ 
LinkList InitLNode(void) {
	LinkList head;
	head = (LinkList)malloc(LEN);//������һ���ṹ���С�Ķ�̬�洢�ռ�
	if (!head) {
		printf("�ڴ�ռ�����ʧ�ܣ�\n");
		exit(ERROR);
	}
	head->data = 0;//ͷ�����������������ʵ�ʱ�
	head->next = NULL;
	return head;
}
//����һ������
int CreatList(LinkList head) {
	LinkList pleft, pright;
	pleft = head;
	pright = (LinkList)malloc(LEN);//ָ���¿��ٵ�һ���ڴ�ռ� Ҫ��֤pleft��prightһǰһ�� 
	printf("�밴�յ�����˳���������и�ֵ:(����-1��Ϊ������ֹ)\n");
	scanf("%d", &pright->data);
	while (pright->data != -1) {
		head->data++;//����1 
		pleft->next = pright;//pleft��Զָ��ǰ��������һ����� prightָ��ǰ�����ɵ�һ����� 
		pleft = pright;
		pright = (LinkList)malloc(LEN);
		scanf("%d", &pright->data);
	}
	pleft->next = NULL;
	free(pright);//pright����������-1ָ����û�и�ֵ Ҳ����˵pright��ָ��㲢δ���뵽������ û������
	return OK;
}
//�������
int PrintLNode(LinkList head) {
	if (!head->next) {
		printf("������\n");
		return ERROR;
	}
	LinkList p;//ָ�����λ�õĽ�� 
	p = head->next;//����ָ���һ����� p = head�ǳ�ʼָ����ͷ���
	printf("�������:\n");
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	return OK;
}
//ɾ������
int delLNode(LinkList head, int num) {
	if (!head->next) {
		printf("������\n");
		return ERROR;
	}
	LinkList pleft, pright;
	pleft = head;//ָ��ͷ��� 
	pright = head->next;//ָ���һ�����
	while (pright->data != num && pright != NULL) {
		pleft = pright;
		pright = pright->next;
	}
	if (pright->data == num) {
		pleft->next = pright->next;//pleft = head�������������ɾ����λ���ڵ�һ��������� 
		free(pright);
		head->data--;//����1 
	}
	else {
		printf("\nû���ҵ�������!\n");
	}
	return OK;
}
//ɾ����������֮���Ԫ��
int delLink(LinkList head, float mink, float maxk) {
	LinkList pleft, pright;
	pright = pleft = head->next;//ָ���һ�����
	while (pright->data <= mink && pright) {
		pleft = pright;
		pright = pright->next;
	}

	if (!pright) {
		printf("û�н���%g��%g֮�������\n", mink, maxk);
		return ERROR;
	}
	while (pright->data < maxk && pright) {//�����ϸ�ѭ��˵��p->data > mink �����ж�һ����max�Ĺ�ϵ
		delLNode(head, pright->data);//ɾ��������֮��pright��ָ���������Ѿ���free�� ����pright��һ��Ұָ�� û�о����ָ�� 
		pright = pleft->next;//����Ҫ��������ǰһ��ָ�����¶�λָ��
	}
	return OK;
}

//ͷ�巨ԭ�����õ�����
void Reverse_List(LinkList L)
{
	LNode* r = L;
	LNode* p = L->next;
	L->next = NULL;//�ǵð�ͷָ��next���ÿգ������ѭ��ָ�׽��
	while (p)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
}


int main() {
	LinkList head;
	float mink, maxk;
	head = InitLNode();
	CreatList(head);
	PrintLNode(head);
	printf("\n��ɾ������������֮�������?\n");
	scanf("%f%f", &mink, &maxk);
	delLink(head, mink, maxk);
	printf("\n");
	PrintLNode(head);
	Reverse_List(head);
	printf("\n");
	printf("���ú��");
	PrintLNode(head);



}