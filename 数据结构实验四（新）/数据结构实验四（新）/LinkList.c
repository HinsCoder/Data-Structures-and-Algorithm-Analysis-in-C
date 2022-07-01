#include"LinkList.h"
void InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node)); // ����ͷ���,��ʹLָ���ͷ���  
	if (!(*L))							 // �洢����ʧ��  
		printf("����ʧ��\n");
	(*L)->next = NULL;					 // ָ����Ϊ��  
	printf("�����ɹ�\n");
}

void ListEmpty(LinkList L)
{
	if (L->next)
		printf("���Ա�Ϊ��\n");
	else
		printf("���Ա�Ϊ��\n");
}

void ClearList(LinkList* L)
{
	LinkList p, q;
	p = (*L)->next;           //  pָ���һ�����  
	while (p)                //  û����β  
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;        // ͷ���ָ����Ϊ��  
	printf("��ճɹ�\n");
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; // pָ���һ�����  
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

void GetElem(LinkList L, int i, ElemType* e)
{
	int j;
	LinkList p;		// ����һ���p  
	p = L->next;		// ��pָ������L�ĵ�һ�����  
	j = 1;		//  jΪ������  
	while (p && j < i)  // p��Ϊ���Ҽ�����j��û�е���iʱ��ѭ������  
	{
		p = p->next;  // ��pָ����һ�����  
		++j;
	}
	if (!p || j > i)
		printf("�Ҳ���\n");  //  ��i��Ԫ�ز�����  
	*e = p->data;   //  ȡ��i��Ԫ�ص�����  
	printf("��%d��Ԫ����%d\n", i, *e);
}

void LocateElem(LinkList L, ElemType e)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data == e) // �ҵ�����������Ԫ��  
			printf("Ԫ��%d�ڵ�%dλ\n", e, i);
		p = p->next;
	}
}

void ListInsert(LinkList* L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)     // Ѱ�ҵ�i�����  
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		printf("�Ҳ���\n");   // ��i��Ԫ�ز�����  
	s = (LinkList)malloc(sizeof(Node));  //  �����½��(C���Ա�׼����)  
	s->data = e;
	s->next = p->next;      // ��p�ĺ�̽�㸳ֵ��s�ĺ��   
	p->next = s;          // ��s��ֵ��p�ĺ��  
}

void ListDelete(LinkList* L, int i, ElemType* e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)	// ����Ѱ�ҵ�i��Ԫ��  
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		printf("�Ҳ���\n");           // ��i��Ԫ�ز�����  
	q = p->next;
	p->next = q->next;			// ��q�ĺ�̸�ֵ��p�ĺ��  
	/*p->next = p->next->next;*/
	*e = q->data;               // ��q����е����ݸ�e  
	free(q);                    // ��ϵͳ���մ˽�㣬�ͷ��ڴ�  
	printf("ɾ����%d��Ԫ��%d�ɹ�\n", i, *e);
}

void ListTraverse(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void CreateListHead(LinkList* L, int n)
{
	LinkList p;
	int i;
	srand(time(0));                         // ��ʼ�����������  
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      //  �Ƚ���һ����ͷ���ĵ�����  
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); //  �����½��  
		p->data = rand() % 100 + 1;             //  �������100���ڵ�����  
		p->next = (*L)->next;
		(*L)->next = p;						//  ���뵽��ͷ  
	}
}

void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));                      // ��ʼ�����������  
	*L = (LinkList)malloc(sizeof(Node)); // LΪ�������Ա�  
	r = *L;                                // rΪָ��β���Ľ��  
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node)); //  �����½��  
		p->data = rand() % 100 + 1;           //  �������100���ڵ�����  
		r->next = p;                        // ����β�ն˽���ָ��ָ���½��  
		r = p;                            // ����ǰ���½�㶨��Ϊ��β�ն˽��  
	}
	r->next = NULL;                       // ��ʾ��ǰ�������  
}

void delLNode(LinkList head, int num) {
	if (!head->next) {
		printf("������\n");
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
}

void deletes(LinkList L, int min, int max)
{
	ElemType e;
	LinkList pleft, pright;
	pright = pleft = L->next;//ָ���һ�����
	while (pright->data <= min && pright) {
		pleft = pright;
		pright = pright->next;
	}

	if (!pright) {
		printf("û�н���%g��%g֮�������\n", min, max);
	}
	while (pright->data < max && pright) {//�����ϸ�ѭ��˵��p->data > mink �����ж�һ����max�Ĺ�ϵ
		delLNode(L, pright->data);//ɾ��������֮��pright��ָ���������Ѿ���free�� ����pright��һ��Ұָ�� û�о����ָ�� 
		pright = pleft->next;//����Ҫ��������ǰһ��ָ�����¶�λָ��
	}
	printf("ɾ���ɹ�\n");
}

void Reverse_List(LinkList L)
{
	Node* r = L;
	Node* p = L->next;
	L->next = NULL;//�ǵð�ͷָ��next���ÿգ������ѭ��ָ�׽��
	while (p)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	printf("���ú�Ľ��Ϊ��");
}
