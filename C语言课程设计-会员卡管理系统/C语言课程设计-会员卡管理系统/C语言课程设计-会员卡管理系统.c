//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>                  //����Ԥ����ָ�����ͷ�ļ�
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#define MAX 10                      //�Զ�����ų���
//#define MENU_MAIN_COUNT 7 		    //���˵���ѡ�����
//typedef struct member               //����ṹ������member��������ʽ�洢�ṹ 
//{
//	char name[MAX];	                 //���� 
//	char id[MAX];                    //���� 
//	char sex[2];		             //�Ա� 
//	int age;		             	//���� 
//	float money;	            	 //��� 
//	char tel[12]; 	                //�绰 
//	struct member* next;             //����һ��ָ��ָ����һ����Ա��Ϣ 
//	float cost;		            	//���ѽ�� 
//}mem;                                //����ṹ�����mem
//										/*��������*/
//void menu();                          /*���������������˵�����*/
//void save(mem* p);                     //�������溯��
//
//mem* head = NULL;	                         //ͷָ��ΪNULL 
//mem* get_last(mem* p)                   //ȡ���������һ��Ԫ�صĽڵ�ָ�벢���ظ�ָ��
//{
//	if (p->next == NULL)
//	{
//		return p;
//	}
//	else
//	{
//		get_last(p->next);
//	}
//}
//
//
//
//void creat_member(mem* pNew)                                      //������Ϣ��������Ա�ǼǺ���
//{		                                                          //����һ���µĻ�Ա 
//	char s;
//	printf("����:");					scanf("%s", pNew->id);     //����ָ�����뿨��
//	printf("����������: ");				scanf("%s", pNew->name);   //����ָ����������
//a:
//	printf("�������Ա�(f--Ům--��): ");	getchar();                //������Ů
//	s = getchar();
//	if (s == 'f' || s == 'm')                                            //�ж��� �� �� Ů
//	{
//		if (s == 'f' || s == 'F') strcpy(pNew->sex, "Ů");
//		if (s == 'M' || s == 'm') strcpy(pNew->sex, "��");
//	}
//	else                                                           //����������
//	{
//		printf("�����������������...\n");
//		goto a;                                                    //��ת��a����������
//	}
//	printf("����������: ");				scanf("%d", &(pNew->age));   //����ָ����������
//	printf("������ɷѽ��: ");			scanf("%f", &(pNew->money));  //����ָ���������
//	printf("������绰: ");				scanf("%s", pNew->tel);       //����ָ������绰
//	pNew->cost = 0;                                                    //����ָ���ʼ�����Ѷ�Ϊ0
//	printf("\n�������!\n");
//}
//
//
//void newMember()                                                    //��Ա�ǼǺ���
//{	                                               	                //��ӻ�Ա��Ϣ 
//	char con = 'N';
//	mem* pLast = NULL;
//	mem* pNew = (mem*)malloc(sizeof(mem));                           //�� mem ��̬�����ڴ�
//	pNew->next = NULL;
//	creat_member(pNew);                                             //���û�Ա�ǼǺ���
//	if (head == NULL)
//	{
//		head = pNew;
//	}
//	else
//	{
//		pLast = get_last(head);
//		pLast->next = pNew;
//	}
//	printf("���������Ա��Ϣ��(Y ������ N ���ز˵�)");              //�ж��Ƿ�����Ǽ�
//	getchar();
//	con = getchar();
//	if (con == 'n' || con == 'N')
//	{
//		save(pNew);
//		menu();
//	}
//	else {
//		save(pNew);
//		newMember();
//	}
//}
//
//
////��ʾ��Ϣ����
//
//void table_head()
//{	                                                             	//�����ͷ 
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//	printf("|   ����   | ���� | �Ա� | ���� |  ���  |�ۼ�����|   �绰    |\n");
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//}
//void table_buttom()
//{                                                               	//������� 
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//}
//void table_row(mem* p)
//{	                                                                // �����м䲿��
//	printf("|%10s|%6s|%6s|%6d|%8.2f|%8.2f|%11s|\n",
//		p->id, p->name, p->sex, p->age, p->money, p->cost, p->tel);
//}
//
//
//
//
//void display(mem* p)
//{	                                        //��ʾ������Ϣ 
//	p = head;
//	table_head();                            //���ñ�ͷ
//	while (p != NULL)
//	{
//		table_row(p);                       //�����м䲿��
//		p = p->next;
//	}
//	table_buttom();                          //���õ���
//}
//
//
//void display_one(mem* p)
//{	                                        //ֻ��ʾһ����Ϣ 
//	table_head();
//	table_row(p);
//	table_buttom();
//}
//
//
//void table_sum()
//{                                //�����ܼ�
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//	printf("|          |      |      |      |  �ܼ�  |  �ܼ�  |           |\n");
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//}
//void table_r(float money, float cost)
//{                              //�����ܼ�2
//	printf("|          |      |      |      |%8.2f|%8.2f|           |\n", money, cost);
//}
//
//
//
//
//void display_statistics(mem* p, float money, float cost)
//{                                                                  //��ʾͳ����Ϣ����
//	p = head;
//	table_head();                                                 //���ñ�ͷ
//	while (p != NULL)
//	{
//		table_row(p);                                             //�����м䲿��
//		p = p->next;
//	}
//	p = head;
//	table_sum();                                                  //�����ܼ�
//	table_r(money, cost);                                          //�����ܼ�2
//	table_buttom();                                               //�����β
//}                                                                 //�ļ���ز���
//
//
//
//void save(mem* p)
//{	                                            	                 //���溯��
//	FILE* fp;                                                        //����һ��ָ���ļ���ָ�����
//	fp = fopen("member.dat", "a");                                     //��fopen�����ķ���ֵ����ָ�����fp
//	while (p != NULL)
//	{
//		fprintf(fp, "%s %s %s %d %f %s %d\n", p->id, p->name, p->sex, p->age, p->money, p->tel, p->cost);
//		p = p->next;
//	}
//	fclose(fp);                                                       //�ر�ָ��
//	getchar();
//}
//
//
//
//void modify_file(mem* p)
//{	                                                                //�����޸Ļ�Ա��Ϣ����
//	FILE* fp;
//	p = head;
//	if ((fp = fopen("member.dat", "w")) == NULL)
//	{                                                               //�����ļ��Ĳ����Ƿ��д�
//		printf("�ļ�������");
//		getchar();
//		menu();                                                     //���ò˵�����
//	}
//	while (p != NULL)
//	{
//		fprintf(fp, "%s %s %s %d %f %s %f\n", p->id, p->name, p->sex, p->age, p->money, p->tel, p->cost);
//		p = p->next;
//	}
//	fclose(fp);
//	getchar();
//}
//
//
//
//void load(mem* p)
//{	                                                          //���ļ�������Ϣ 
//	FILE* fp;
//	mem* pLast = NULL;
//	head = NULL;
//	if ((fp = fopen("member.dat", "r")) == NULL)
//	{                                                         //�����ļ��Ĳ����Ƿ��д�
//		printf("û�л�Ա��Ϣ����¼�룡");
//		getchar();
//		menu();                                               //���ò˵�����
//	}
//	while (!feof(fp))
//	{                                                         //�ļ�ָ���Ƿ񵽴�ĩβ
//		mem* pNew = (mem*)malloc(sizeof(mem));               //�� mem ��̬�����ڴ�
//		pNew->next = NULL;
//		fscanf(fp, "%s %s %s %d %f %s %f\n",
//			pNew->id, pNew->name, pNew->sex, &(pNew->age), &(pNew->money), pNew->tel, &(pNew->cost));
//		if (head == NULL)
//		{
//			head = pNew;
//		}
//		else
//		{
//			pLast = get_last(head);
//			pLast->next = pNew;
//		}
//	}
//	p = head;
//	fclose(fp);
//}
////ͨ������������Ϣ���� 
//
//
//mem* search_id(mem* p)
//{ 	                                                      //ͨ������������Ϣ 
//	char id[MAX];
//	int i = 0;
//	p = head;
//	scanf("%s", id);
//	while (p && (strcmp(id, "n") != 0))
//	{                                                       //�ж�id�Ƿ�Ϊn
//		if (strcmp(p->id, id) == 0)
//		{                                                   //�ҵ�
//			i = 1;
//			break;
//		}
//		else
//			p = p->next;
//	}
//	if (strcmp(id, "n") == 0)	                                //����nʱ���ز˵� 
//		menu();
//	if (p == NULL)
//	{			                                           //������������ 
//		printf("�����ҵĿ��Ų����ڣ����������룺\n");
//		p = search_id(p);                                    //����Ѱ�Һ���
//	}
//	else
//		return p;                                          //����p
//}
///*�޸Ļ�Ա��Ϣ����*/
//
//
//
//void modify_m()
//{	                                                       //�޸Ļ�Ա����Ϣ 
//
//	char s, fun = 'y';
//	char pro[] =
//		"|\n"
//		"| 1 ����\n"
//		"| 2 �Ա�\n"
//		"| 3 ����\n"
//		"| 4 �绰\n"
//		"| 5 ����\n"
//		"|\n";
//	mem* p;{};
//	load(p);
//	display(p);                                    //������ʾ����
//	printf("��������Ҫ�޸���Ϣ�Ļ�Ա���ţ�n���ز˵�����");
//	p = search_id(p);                                //���ð���Ѱ�Һ���
//	while (fun == 'y' || fun == 'Y')
//	{                                              //������Ѱ��ʱ
//		system("cls");                            //����
//		display_one(p);                            //������ʾһ������
//		printf("��ѡ���޸ĵ���Ŀ��\n");
//		printf(pro);                               //���pro
//		getchar();
//		scanf("%c", &fun);
//		switch (fun)
//		{                                           //��switch���ѡ���޸�����
//		case '1':	printf("����������: ");				scanf("%s", p->name); break;
//		case '2':	a:
//			printf("�������Ա�(f--Ům--��): ");	getchar();
//			s = getchar();
//			if (s == 'f' || s == 'm')
//			{
//				if (s == 'f' || s == 'F') strcpy(p->sex, "Ů");
//				if (s == 'M' || s == 'm') strcpy(p->sex, "��");
//			}
//			else
//			{
//				printf(">�����������������...\n");
//				goto a;
//			}
//			break;
//		case '3':	printf("����������: ");				scanf("%d", &(p->age)); break;
//		case '4': 	printf("������绰: ");				scanf("%s", p->tel);	break;
//		default:	break;
//		}
//		printf("�Ƿ�����޸�Y/N?");                     //�ж��Ƿ����Ѱ��
//		getchar();
//		fun = getchar();
//	}
//	modify_file(p);                                    //���ñ����޸Ļ�Ա��Ϣ����                                      
//	system("cls");                                     //����
//	display_one(p);                                    //������ʾһ������
//	printf("\n�޸ĳɹ�,�����������!");
//	getchar();
//	menu();                                            //���ò˵�����
//}
////��Ա���Ѻ���
//
//
//void add()
//{			                                           //��Ա���� 
//	float money;
//	mem* p;{}
//	load(p);
//	display(p);                                        //�����������
//	printf("\n");
//	printf("��������Ҫ���ѵĻ�Ա���ţ�n���ز˵�����");
//	p = search_id(p);                                      //���ð���Ѱ�Һ���
//	system("cls");                                       //����
//	display_one(p);                                      //������ʾһ������
//	printf("���������ѽ�");
//	scanf("%f", &money);
//	p->money += money;                                      //����
//	modify_file(p);                                        //���ñ����޸Ļ�Ա��Ϣ���� 
//	system("cls");                                         //����
//	display_one(p);                                        //������ʾһ������
//	printf("���ѳɹ������������!");
//	getchar();
//	menu();                                                  //���ò˵�����
//}
////��Ա���㺯��
//
//
//
//void consume()
//{	                                                     	//��Ա���� 
//	mem* p;
//	float cost;
//	load(p);
//	display(p);                                                /* �����������*/
//	printf("\n");
//	printf("��������Ҫ����Ļ�Ա���ţ�n���ز˵�����");
//	p = search_id(p);                                          //���ð���Ѱ�Һ���    
//	system("cls");                                           //����
//	display_one(p);                                          //������ʾһ������
//	printf("�����뻨�ѽ�");
//	scanf("%f", &cost);
//	if (p->cost >= 1000)
//	{                                                         //�ж��Ƿ�����Ϊvip
//		printf("��ϲ���Ѿ�����ΪVIP����������9���Żݡ�\n");
//		printf("����ʵ������%.2fԪ��", cost * 0.9);              //����Ϊvip�����Ѵ�9��
//		cost *= 0.9;
//		if ((p->money - cost) < 0)
//		{                                                     //�ж�����Ƿ����
//			printf("�Բ������㣬�뼰ʱ��ֵ��");
//			getchar();
//			menu();
//		}
//		p->cost += cost;
//		p->money -= cost;                                       //����
//		getchar();
//	}
//	else
//	{
//		if ((p->money - cost) < 0)
//		{                                 //ͬ��
//			printf("�Բ������㣬�뼰ʱ��ֵ��");
//			getchar();
//			menu();
//		}
//		p->cost += cost;
//		p->money -= cost;
//	}
//	modify_file(p);                                       //���ñ����޸Ļ�Ա��Ϣ���� 
//	system("cls");                                         //����
//	display_one(p);                                       //������ʾһ������
//	printf("����ɹ������������!");
//	getchar();
//	menu();                                               //���ò˵�����
//}
///*��Ա�˳�����*/
//
//
//
//void delete_m()
//{	                                                      //ɾ����Ա��Ϣ 
//	mem* p, * q = head, * thelast;
//	float money;
//	load(p);
//	display(p);                                           /* �����������*/
//	printf("\n");
//	printf("��������Ҫɾ���Ļ�Ա���ţ�n���ز˵�����");
//	p = search_id(p);                                        //���ð���Ѱ�Һ���
//	thelast = head;
//	if (p == head)
//	{                                                     //�ж�ָ��
//		head = p->next;
//		money = p->money;
//		free(p);
//	}
//	else
//	{
//		while (thelast)
//		{
//			if (thelast->next == p)
//				break;
//			else
//				thelast = thelast->next;
//		}
//		thelast->next = p->next;
//		money = p->money;
//		free(p);
//	}
//	modify_file(q);                                           //���ñ��溯��
//	printf("�˻����%.2fԪ��\n", money);
//	printf("ɾ���ɹ����������������");                         //��ʾ�˻ص����
//	getchar();
//	menu();                                                    //���ò˵�����
//}                                                                /*ͳ�ƺ���*/
//
//
//mem* sort_m()
//{                                                             //���ɷ��ܶ�����
//	mem* q, * tail, * p = (mem*)malloc(sizeof(mem));
//	p->next = head;
//	head = p;
//	tail = NULL;                                                  //���� tail
//	while (tail != head->next)
//	{
//		p = head;
//		q = p->next;
//		while (q->next != tail)
//		{                                                        //�ж� q�Ƿ�Ϊ��
//			if (p->next->money > q->next->money)
//			{
//				p->next = q->next;                                 //�Ƚϴ�С������
//				q->next = q->next->next;
//				p->next->next = q;
//			}
//			p = p->next;
//			q = p->next;
//		}
//		tail = q;
//	}
//	head = head->next;
//	free(p);
//	return head;                                                  //����ֵ
//}
//
//
//mem* sort_c()
//{                                                                //�����ѽ������ 
//	mem* q, * tail, * p = (mem*)malloc(sizeof(mem));
//	p->next = head;
//	head = p;
//	tail = NULL;                                                     //���� tail                             
//	while (tail != head->next)
//	{
//		p = head;
//		q = p->next;
//		while (q->next != tail)
//		{
//			if (p->next->cost > q->next->cost)
//			{                                                    //�Ƚϴ�С������
//				p->next = q->next;
//				q->next = q->next->next;
//				p->next->next = q;
//			}
//			p = p->next;
//			q = p->next;
//		}
//		tail = q;
//	}
//	head = head->next;
//	free(p);
//	return head;                                        //����ֵ
//}
//
//
//float summ(mem* p)
//{	                                   //����ɷ��ܶ� 
//	float summ = 0;
//	p = head;
//	while (p)
//	{                                         //ѭ����ʵ�����ܶ�
//		summ += p->money;
//		p = p->next;
//	}
//	return summ;                                      //�����ܶ�
//}
//
//
//
//float sumc(mem* p)
//{	                              //���������ܶ� 
//	float sumc = 0;
//	p = head;
//	while (p)
//	{                                          //ѭ����ʵ�����ܶ�
//		sumc += p->cost;
//		p = p->next;
//	}
//	return sumc;                                       //�����ܶ�
//}
//
//
//void statistics()
//{		                          //ͳ�ƻ�Ա��Ϣ����
//	int f = 0;
//	mem* p;{};
//	load(p);
//
//	system("cls");
//	printf("\t\t=======================================\n"
//		"\t\t|\n"
//		"\t\t|1 ���ɷ��ܶ�����\n"
//		"\t\t|2 �������ܶ�����\n"
//		"\t\t|3 ���ز˵�\n"
//		"\t\t|\n"
//		"\t\t=======================================\n"
//	);
//	printf("��ѡ���ܣ�");
//	scanf("%d", &f);
//	switch (f)
//	{                                          //��switch���ѡ����
//	case 1:	p = sort_m(p);                              //���ð��ɷ��ܶ�����
//		display_statistics(p, summ(p), sumc(p));    //���ú���
//		getchar();
//		menu();
//		break;
//	case 2: p = sort_c(p);                             //���ð������ܶ�����
//		display_statistics(p, summ(p), sumc(p));   //���ú���
//		getchar();
//		menu(); break;
//	default: menu(); break;
//	}
//}
///*�˳�ϵͳ����*/
//
//
//
//void clear(mem* p)
//{		                                     //�ͷ�����ռ� 
//	if (p == NULL)
//	{
//		return;
//	}
//	if (p->next == NULL)
//	{
//		free(p);
//	}
//	else
//	{
//		clear(p->next);
//		free(p);
//		p = NULL;
//	}
//}
//
//
//
//void quit()
//{                                               //�˳�����
//	clear(head);
//	exit(0);
//}
///*�˵���Ϣ*/
//
//
//void menu_tile(char* title)
//{                                              //�˵���ͷ  
//	printf("\t\t=======================================\n");
//	printf("\t\t| %s\n", title);
//	printf("\t\t---------------------------------------\n");
//}
//
//
//void (*menu_main_func[])() =                                    /*����ָ������ menu_main_func[] �洢�������˵�����7�����ܺ����ĵ�ַ��
//																�ֱ��Ӧ1-7�˵�������û�ѡ��1ʱ����������ĵ�0��Ԫ�أ�������
//																newMember()�������Դ����ơ�*/
//{
//	newMember,
//	modify_m,
//	add,
//	consume,
//	delete_m,
//	statistics,
//	quit,
//};
//char menu_main[] =                                              //�˵�������
//"\t\t\n"
//"\t\t| 1 �»�Ա�Ǽ�\n"
//"\t\t| 2 ��Ա��Ϣ�޸�\n"
//"\t\t| 3 ��Ա����\n"
//"\t\t| 4 ��Ա���ѽ���\n"
//"\t\t| 5 ��Ա�˿�\n"
//"\t\t| 6 ͳ�ƹ���\n"
//"\t\t| 7 �˳�ϵͳ\n"
//"\t\t|\n";
//void menu()
//{                                                               //�˵�����
//	int selected = 0;                                           //��ʼ������
//	system("cls");                                              //����
//
//	printf("                 ��Ա���Ʒ�ϵͳ");
//	printf(menu_main);                                          //����˵�������
//	printf("\t\t=======================================\n");
//
//	while (!(selected >= 1 && selected <= MENU_MAIN_COUNT))
//	{                                                          //�жϳ�ʼֵ
//		printf("��ѡ��");
//		scanf("%d", &selected);
//		if (selected >= 1 && selected <= MENU_MAIN_COUNT)
//		{    //�ж�����ֵ�Ƿ���Ч
//			break;
//		}
//		printf("\n>������󣡣�ע����ѡ�� 1 - %d)\n", MENU_MAIN_COUNT);
//	}
//	menu_main_func[selected - 1]();                             //������Ӧ�ĺ���ָ�������еĺ�����ִ�в���
//
//}
//int main()                                                  /*������*/
//{
//	menu();                                                   //���ò˵�����
//	return 0;                                                //����ֵ
//}




//#include "stdio.h"
//#pragma warning(disable:4996)
//struct School {
//    char name;
//    int totalScore;
//    struct Item* next;
//};
//
//struct School* sch[5];
//struct Item {
//    char id;
//    int score;
//    struct Item* next;
//};
//
//int atoi(char c)
//{
//    return c - '0';
//}
//
//int DataValidation(char* str)
//{
//    int tmpItem[10], tmpScore[100], a, b, c, i;
//    for (i = 0; i < 10; i++)
//    {
//        tmpItem[i] = tmpScore[i] = 0;
//    }
//    for (i = 0; i < 27; i += 3)
//    {
//        a = atoi(str[i]);
//        b = atoi(str[i + 1]);
//        c = atoi(str[i + 2]);
//        if ((a < 1 || a>3) || (b < 1 || b>5) || (c != 5 && c != 3 && c != 1 && c != 0))
//        {
//            return 0;
//        }
//        else
//        {
//            tmpItem[a]++;
//            tmpScore[a] += c;
//        }
//    }
//    for (i = 1; i <= 3; i++)
//    {
//        if (tmpItem[i] != 3)
//        {
//            return 0;
//        }
//    }
//    for (i = 1; i <= 3; i++)
//    {
//        if (tmpScore[i] != 9)
//            return 0;
//    }
//    return 1;
//}
//
//void insert(char itemId, char schoolId, int score)
//{
//    int i;
//    for (i = 0; i < 5; i++)
//    {
//        if (sch[i]->name == schoolId)
//        {
//            struct Item* item = (struct Item*)malloc(sizeof(struct Item));
//            item->id = itemId;
//            item->score = score;
//            item->next = sch[i]->next;
//            sch[i]->next = item;
//        }
//    }
//}
//
//void updateTotalScore()
//{
//    int i = 0;
//    struct Item* tmp;
//    for (i = 0; i < 5; i++)
//    {
//        tmp = sch[i]->next;
//        while (tmp != NULL)
//        {
//            sch[i]->totalScore += tmp->score;
//            tmp = tmp->next;
//        }
//    }
//}
//
//void sort()
//{
//    int i, j;
//    struct School* tmp;
//    for (i = 0; i < 5; i++)
//    {
//        for (j = 0; j < i; j++)
//        {
//            if (sch[i]->totalScore > sch[j]->totalScore)
//            {
//                tmp = sch[i];
//                sch[i] = sch[j];
//                sch[j] = tmp;
//            }
//        }
//    }
//}
//
//
//void print()
//{
//    int i;
//    struct Item* tmp;
//    for (i = 0; i < 5; i++)
//    {
//        printf("college%d : %2d  ", sch[i]->name, sch[i]->totalScore);
//        tmp = sch[i]->next;
//        while (tmp != NULL)
//        {
//            printf("item%c(%d)  ", tmp->id, tmp->score);
//            tmp = tmp->next;
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//    int i;
//    char str[50], tmp1, tmp2;
//    for (i = 0; i < 5; i++)
//    {
//        sch[i] = (struct School*)malloc(sizeof(struct School));
//        sch[i]->name = i + 1 + '0';
//        sch[i]->next = NULL;
//        sch[i]->totalScore = 0;
//    }
//    for (i = 0; i < 27; i++)
//    {
//        scanf("%c", &str[i]);
//    }
//    str[27] = '\0';
//    while (DataValidation(str) == 0)
//    {
//        printf("��������ݲ��Ϸ�����ȫ����������\n");
//        for (i = 0; i < 27; i++)
//        {
//            scanf("%c", &str[i]);
//        }
//    }
//    for (i = 1; i <= 25; i = i + 3)
//    {
//        int convert = atoi(str[i + 1]);
//        insert(str[i - 1], str[i], convert);
//    }
//    updateTotalScore();
//    sort();
//    print();
//    while (1);
//    return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define n 20
#define m 20
#define w 20
FILE* fp;//�ļ�ָ��
int num4;//��¼������Ŀ������
int num5;//��¼Ů����Ŀ������
char str[50];//��¼�洢·��
typedef struct School
{
    int id;//ѧУ���
    int score[1][2];//�洢��ѧУ���Ӻ�Ů����Ŀ���ܵ÷ֺ�����,score[0][0]�洢�÷�����,score[0][1]�洢�÷�;
    int score1[m + w][2];//�洢��ѧУ������Ů�Ӹ�����Ŀ�����κ͵÷�,score1[n][0]�洢����,score1[n][1]�洢�÷�
    int Mscore[1][2];//�洢�����ֵܷ����κ͵÷֣�Mscore[0][0]�洢�����ܵ÷ֵ����Σ�Mscore[0][1]�洢�����ܵ÷�
    int Wscore[1][2];//�洢�����ֵܷ����κ͵÷֣�Mscore[0][0]�洢Ů���ܵ÷ֵ����Σ�Mscore[0][1]�洢Ů���ܵ÷�

}School;
typedef struct Num
{
    int num1;//��¼ѧУ�ĸ���
    int num2;//��¼������Ŀ����
    int num3;//��¼Ů����Ŀ����

}Num;
typedef struct Str
{
    char str1[10];//�����ַ��Ա�����ֽڶ������
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[12];
    char str6[12];
    char str7[10];

}Str;
void Initial(School school[], Num* data)//�����ݽ��г�ʼ��
{
    for (int i = 0; i < data->num1; i++)
    {
        school[i].score[0][1] = 0;
        school[i].Mscore[0][1] = 0;
        school[i].Wscore[0][1] = 0;
    }
}
void AddUp(School school[], Num* data)
{
    for (int i = 0; i < data->num1; i++)
    {
        for (int j = 0; j < data->num2; j++)
            school[i].Mscore[0][1] = school[i].Mscore[0][1] + school[i].score1[j][1];//����������Ŀ�ֵܷ�ͳ��
        for (int k = data->num2; k < (data->num2 + data->num3); k++)
            school[i].Wscore[0][1] = school[i].Wscore[0][1] + school[i].score1[k][1];//����Ů����Ŀ�ֵܷ�ͳ��
        school[i].score[0][1] = school[i].Mscore[0][1] + school[i].Wscore[0][1];//�����ֵܷ�ͳ��

    }
}

void Input(School school[], Num* data)
{
    char key1, key2;
    char str1[] = ".txt";
    printf("\n**************************************************************************************");
    printf("��������Ϣ����¼��");
    printf("*************************************************************************************");
    printf("������Ҫ¼����Ϣ�Ĵ洢�ļ�������:");
    scanf("%s", str);
    strcat(str, str1);//���ĵ���txt��ʽ����
    fp = fopen(str, "w");
    if (fp == NULL)
    {
        printf("�洢���ļ���ʧ�ܣ���������˳�");
        getchar();
        getchar();
        exit(1);
    }
    else
    {
    start1:printf("������Ҫ��Ҫ¼��ѧУ�ĸ���:");
        scanf("%d", &(data->num1));
        if (data->num1 > n || data->num1 < 1)//�����ݵ���������жϣ���������������������
        {
            printf("�������ݳ�����Χ������,����������\n");
            goto start1;

        }
    start2:printf("������Ҫ¼��������Ŀ�ĸ���:");
        scanf("%d", &(data->num2));
        if (data->num2 > m || data->num2 < 0)
        {
            printf("�������ݳ�����Χ������,����������\n");
            goto start2;

        }
    start3:printf("������Ҫ¼��Ů����Ŀ�ĸ���:");
        scanf("%d", &(data->num3));
        if (data->num3 < 0 || data->num3>w)
        {
            printf("�������ݳ�����Χ������,����������\n");
            goto start3;

        }
        fflush(stdin);//ˢ�¼���

        fwrite(data, sizeof(Num), 1, fp);
        for (int i = 0; i < data->num1; i++)
        {
        start5:printf("�����%d��ѧУ�ı��:", i + 1);
            scanf("%d", &(school[i].id));
            if (i >= 1)
            {
                for (int g = 0; g < i; g++)
                {
                    if (school[g].id == school[i].id)
                    {
                        printf("��ѧУ�ı�ź�����ѧУ�Ĵ����ظ�������������\n");
                        goto start5;

                    }
                }

            }
            for (int j = 0; j < (data->num2 + data->num3); j++)
            {
                if (j < data->num2)
                {
                start4:printf("�����У��Ŀ���Ϊ%d��������Ŀ������:", j + 1);
                }
                else
                {
                    printf("�����У��Ŀ���Ϊ%d��Ů����Ŀ������:", j + 1);

                }
                scanf("%d", &num4);
                school[i].score1[j][0] = num4;//����Ŀ���˳��Ϊ��Ŀ���θ�ֵ
                if ((j + 1) % 2 == 0)//����������Ŀ����Ů����Ŀ�����Ϊż���Ŀ�������ǰ������������ֻ������ǰ����
                {
                    switch (num4)//�����ν��л��ֻ���
                    {
                    case 0:school[i].score1[j][1] = 0; break;
                    case 1:school[i].score1[j][1] = 7; break;
                    case 2:school[i].score1[j][1] = 5; break;
                    case 3:school[i].score1[j][1] = 3; break;
                    case 4:school[i].score1[j][1] = 2; break;
                    case 5:school[i].score1[j][1] = 1; break;
                    default:printf("���������볬����Χ�����ٴ�����\n"); goto start4;
                    }
                }
                else
                {
                    switch (num4)
                    {
                    case 0:school[i].score1[j][1] = 0; break;
                    case 1:school[i].score1[j][1] = 5; break;
                    case 2:school[i].score1[j][1] = 3; break;
                    case 3:school[i].score1[j][1] = 2; break;
                    default:printf("���������볬����Χ�����ٴ�����\n"); goto start4;
                    }
                }
            }
            fflush(stdin);
        }
        Initial(school, data);
        AddUp(school, data);
        fwrite(school, sizeof(School), data->num1, fp);//�ڴ�����д�����ݿ�
    }
    fclose(fp);
    printf("����ִ���밴1���˳������밴�����:");
    key1 = _getch();//��ȡ�����
    printf("%c", key1);//��ӡ�������
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }

}
void IdSort(School  school[], Num* data)//��ѧУ��Ž�������
{
    int i;
    int j;
    int t;
    School temp;
    int count = 1;
    for (i = 0; i < data->num1 - 1; i++)
    {
        t = i;
        for (j = i + 1; j < data->num1; j++)
            if (school[t].id > school[j].id)
                t = j;
        if (t != i)
        {
            temp = school[t];
            school[t] = school[i];
            school[i] = temp;

        }
    }
}

void ScoreSort(School school[], Num* data)//�����ֵܷ�����
{
    int i;
    int j;
    int t;
    School temp;
    int count = 1;
    for (i = 0; i < data->num1 - 1; i++)
    {
        t = i;
        for (j = i + 1; j < data->num1; j++)
            if (school[t].score[0][1] < school[j].score[0][1])
                t = j;
        if (t != i)
        {
            temp = school[t];
            school[t] = school[i];
            school[i] = temp;
        }
    }
    for (int k = 0; k < data->num1; k++)//������֮�󣬽�������ͬ�ĸ�ֵΪһ��������
    {
        if (k == 0)
        {
            school[k].score[0][0] = count;
            count++;

        }
        else
        {
            if (school[k].score[0][1] == school[k - 1].score[0][1])
            {
                school[k].score[0][0] = school[k - 1].score[0][0];

            }
            else
            {
                school[k].score[0][0] = count;
                count++;

            }
        }
    }
}
void MscoreSort(School school[], Num* data)//�������������ֵܷ�����
{
    int i;
    int j;
    int t;
    School temp;
    int count = 1;
    for (i = 0; i < data->num1 - 1; i++)
    {
        t = i;
        for (j = i + 1; j < data->num1; j++)
            if (school[t].Mscore[0][1] < school[j].Mscore[0][1])
                t = j;
        if (t != i)
        {
            temp = school[t];
            school[t] = school[i];
            school[i] = temp;

        }
    }
    for (int k = 0; k < data->num1; k++)//������֮�󣬽�������ͬ�ĸ�ֵΪһ��������
    {
        if (k == 0)
        {
            school[k].Mscore[0][0] = count;
            count++;

        }
        else
        {
            if (school[k].Mscore[0][1] == school[k - 1].Mscore[0][1])
            {
                school[k].Mscore[0][0] = school[k - 1].Mscore[0][0];

            }
            else
            {
                school[k].Mscore[0][0] = count;
                count++;
            }
        }
    }
}
void WscoreSort(School school[], Num* data)//����Ů�������ֵܷ�����
{
    int i;
    int j;
    int t;
    School temp;
    int count = 1;
    for (i = 0; i < data->num1 - 1; i++)
    {
        t = i;
        for (j = i + 1; j < data->num1; j++)
            if (school[t].Wscore[0][1] < school[j].Wscore[0][1])
                t = j;
        if (t != i)
        {
            temp = school[t];
            school[t] = school[i];
            school[i] = temp;
        }
    }
    for (int k = 0; k < data->num1; k++)
    {
        if (k == 0)
        {
            school[k].Wscore[0][0] = count;
            count++;
        }
        else
        {
            if (school[k].Wscore[0][1] == school[k - 1].Wscore[0][1])//������֮�󣬽�������ͬ�ĸ�ֵΪһ��������
            {
                school[k].Wscore[0][0] = school[k - 1].Wscore[0][0];

            }
            else
            {
                school[k].Wscore[0][0] = count;
                count++;
            }
        }
    }
}
void OutputId(School school[], Num* data, Str& name)//��ѧУ��Ž����������
{
    char key1;
    char key2;
    printf("\n************************************************************************************");
    printf("ѧУ��������������:");
    printf("************************************************************************************\n");
    printf("%15s", name.str1);
    for (int i = 0; i < data->num2 + data->num3; i++)
    {
        if (i < data->num2)//�ж���������Ŀ����Ů����Ŀ�������ַ�����ķ�ʽ�������
            printf("%14s%d", name.str3, i + 1);
        else
            printf("%14s%d", name.str4, i + 1);
    }
    printf("%15s", name.str5);
    printf("%15s", name.str6);
    printf("%15s", name.str7);
    printf("\n");
    for (int i = 0; i < data->num1; i++)
    {
        printf("%15d", school[i].id);
        for (int j = 0; j < data->num2 + data->num3; j++)
            printf("%15d", school[i].score1[j][1]);
        printf("%15d", school[i].Mscore[0][1]);
        printf("%15d", school[i].Wscore[0][1]);
        printf("%15d", school[i].score[0][1]);
        printf("\n");


    }
    printf("����ִ���밴1���˳������밴�����:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void OutputScore(School school[], Num* data, Str& name)//���ֽܷ����������
{
    char key1;
    char key2;
    printf("\n**************************************************************************************");
    printf("�ܷ������������:");
    printf("**************************************************************************************\n");
    printf("%15s", name.str1);
    printf("%15s", name.str2);
    for (int i = 0; i < data->num2 + data->num3; i++)
    {
        if (i < data->num2)
        {
            printf("%14s%d ", name.str3, i + 1);
        }
        else
        {
            printf("%14s%d ", name.str4, i + 1);
        }
    }
    printf("%15s", name.str5);
    printf("%15s", name.str6);
    printf("%15s", name.str7);
    printf("\n");
    for (int i = 0; i < data->num1; i++)
    {
        printf("%15d", school[i].id);
        printf("%15d", school[i].score[0][0]);
        for (int j = 0; j < data->num2 + data->num3; j++)
            printf("%15d", school[i].score1[j][1]);
        printf("%15d", school[i].Mscore[0][1]);
        printf("%15d", school[i].Wscore[0][1]);
        printf("%15d", school[i].score[0][1]);
        printf("\n");
    }
    printf("����ִ���밴1���˳������밴�����:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void OutputMscore(School school[], Num* data, Str& name)//���������ֽܷ����������
{
    char key1;
    char key2;
    printf("\n***********************************************************************************");
    printf("�������ܷ������������:");
    printf("***********************************************************************************\n");
    printf("%15s", name.str1);
    printf("%15s", name.str2);
    for (int i = 0; i < data->num2 + data->num3; i++)
    {
        if (i < data->num2)
            printf("%14s%d ", name.str3, i + 1);
        else
            printf("%14s%d ", name.str4, i + 1);
    }
    printf("%15s", name.str5);
    printf("%15s", name.str6);
    printf("%15s", name.str7);
    printf("\n");
    for (int i = 0; i < data->num1; i++)
    {
        printf("%15d", school[i].id);
        printf("%15d", school[i].Mscore[0][0]);
        for (int j = 0; j < data->num2 + data->num3; j++)
            printf("%15d", school[i].score1[j][1]);
        printf("%15d", school[i].Mscore[0][1]);
        printf("%15d", school[i].Wscore[0][1]);
        printf("%15d", school[i].score[0][1]);
        printf("\n");

    }
    printf("����ִ���밴1���˳������밴�����:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void OutputWscore(School school[], Num* data, Str& name)//��Ů�����ֽܷ����������
{
    char key1;
    char key2;
    printf("\n***********************************************************************************");
    printf("Ů�����ܷ������������:");
    printf("***********************************************************************************\n");
    printf("%15s", name.str1);
    printf("%15s", name.str2);
    for (int i = 0; i < data->num2 + data->num3; i++)
    {
        if (i < data->num2)
            printf("%14s%d ", name.str3, i + 1);
        else
            printf("%14s%d ", name.str4, i + 1);
    }
    printf("%15s", name.str6);
    printf("%15s", name.str5);
    printf("%15s", name.str7);
    printf("\n");
    for (int i = 0; i < data->num1; i++)
    {
        printf("%15d", school[i].id);
        printf("%15d", school[i].Wscore[0][0]);
        for (int j = 0; j < data->num2 + data->num3; j++)
            printf("%15d", school[i].score1[j][1]);
        printf("%15d", school[i].Wscore[0][1]);
        printf("%15d", school[i].Mscore[0][1]);
        printf("%15d", school[i].score[0][1]);
        printf("\n");
    }
    printf("����ִ���밴1���˳������밴�����:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void SearchItem(School school[], Num* data)//��ѧУ��Ų�ѯѧУĳ����Ŀ�����
{
    char key1;
    char key2;
    int num6;//ѧУ���
    int num7;//��Ŀ���
    int flag = 0;
    printf("\n*****************************************************************************");
    printf("��ѧУ��Ų�ѯѧУĳ����Ŀ�����");
    printf("*******************************************************************************\n");
start1:printf("������Ҫ��ѯ��ѧУ�ı��:");
    scanf("%d", &num6);
    if (num6 > data->num1 || num6 < 1)
    {
        printf("�����������������������ѧУ���\n");
        goto start1;
    }
    for (int k = 0; k < data->num1; k++)
    {
        if (school[k].id == num6)//�����ж��Ƿ���ڸ�У�ı��
        {
            flag = 1;
            break;
        }
    }
    if (flag != 1)
    {
        printf("û�и�ѧУ�ı��,����������");
        goto start1;

    }
start2:printf("������Ҫ��ѯ����Ŀ���:");
    scanf("%d", &num7);
    if (num7 > (data->num2 + data->num3) || num7 < 1)
    {
        printf("�������������������������Ŀ���\n");
        goto start2;

    }
    for (int i = 0; i < data->num1; i++)
    {
        if (school[i].id == num6)
        {
            if (num7 > data->num2)
            {
                printf("\t\t\t\t\t\t\t\t\tŮ����Ŀ");
                printf("  ����:%d  ����:%d\n", school[i].score1[num7 - 1][0], school[i].score1[num7 - 1][1]);

            }
            else
            {
                printf("\t\t\t\t\t\t\t\t\t������Ŀ");
                printf("  ����:%d  ����:%d\n", school[i].score1[num7 - 1][0], school[i].score1[num7 - 1][1]);


            }

        }
    }
    printf("����ִ���밴1���˳������밴�����:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void SearchSchool(School school[], Num* data)//����Ŀ��Ų�ѯȡ��ǰ����ǰ������ѧУ
{
    char key1;
    char key2;
    printf("\n***************************************************************************");
    printf("����Ŀ��Ų�ѯȡ��ǰ����ǰ������ѧУ");
    printf("******************************************************************************");
    int num8;//��¼�˶�����Ŀ���
    int i, j, t, k, z;
    School temp;
    int count = 1;
    char str1[] = "����";
    char str2[] = "ѧУ���";
    int* p;
    p = (int*)malloc(sizeof(int) * data->num1);//��̬�����ڴ�
start:printf("������Ҫ��ѯ����Ŀ���:");
    scanf("%d", &num8);
    if (num8 >= 1 && num8 <= data->num2 + data->num3)//ѡ������
    {
        for (i = 0; i < data->num1 - 1; i++)
        {
            t = i;
            for (j = i + 1; j < data->num1; j++)
                if (school[t].score1[num8 - 1][1] < school[j].score1[num8 - 1][1])
                    t = j;
            if (t != i)
            {
                temp = school[t];
                school[t] = school[i];
                school[i] = temp;
            }
        }
    }
    else
    {
        printf("������Ŀ�ı�Ŵ��ڴ���,����������\n");
        goto start;//������������
    }
    for (k = 0; k < data->num1; k++)//������֮��,�Ը�����Ŀ�����������ν��и�ֵ
    {
        if (k == 0)
        {
            p[k] = count;
            count++;
        }
        else
        {
            if (school[k].score1[num8 - 1][1] == school[k - 1].score1[num8 - 1][1])//����÷���ͬ�������θ�ֵΪ��ͬ
            {
                p[k] = p[k - 1];
            }
            else
            {
                p[k] = count;
                count++;
            }
        }
    }
    printf("\t\t\t\t\t\t\t\t\t");
    printf("%12s", str1);
    printf("%12s", str2);

    printf("\n");
    if (num8 % 2 == 0)//�ж������ǰ�����ɼ�����ǰ�����ɼ�
    {
        if (data->num1 < 5)
            for (z = 0; z < data->num1; z++)
            {
                printf("\t\t\t\t\t\t\t\t\t");
                printf("%12d", p[z]);
                printf("%12d\n", school[z].id);
            }
        else
        {
            for (z = 0; z < 5; z++)
            {
                printf("\t\t\t\t\t\t\t\t\t");
                printf("%12d", p[z]);
                printf("%12d\n", school[z].id);
            }
        }
    }
    else
    {
        if (data->num1 < 3)
        {
            for (z = 0; z < data->num1; z++)
            {
                printf("\t\t\t\t\t\t\t\t\t");
                printf("%12d", p[z]);
                printf("%12d\n", school[z].id);
            }
        }
        else
        {
            for (z = 0; z < 3; z++)
            {
                printf("\t\t\t\t\t\t\t\t\t");
                printf("%12d", p[z]);
                printf("%12d\n", school[z].id);
            }
        }
    }
    free(p);//�ͷ��ڴ�
    printf("����ִ���밴1���˳������밴�����:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void Revise(School school[], Num* data)//�޸�ĳ��ѧУĳ���˶���Ŀ������
{
    printf("\n******************************************************************************");
    printf("�޸�ĳ��ѧУĳ���˶���Ŀ������");
    printf("*********************************************************************************\n");
    int id1;//��¼ѧУ�ı��
    int id2;//��¼��Ŀ�ı��
    int rank;//�޸ĵ�����
    int i;
    int flag = 0;
    School tmp;
    char key1;
    char key2;
start:printf("������Ҫ�޸���ĿѧУ�ı��:");
    scanf("%d", &id1);
    for (i = 0; i < data->num1; i++)
    {
        if (school[i].id == id1)//��ѯ�Ƿ��������ѧУ�ı��
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
    start1:printf("������Ҫ�޸���Ŀ�ı��:");
        scanf("%d", &id2);
        if (id2 > (data->num2 + data->num3) || id2 < 1)//�Ա�Ž����ж�
        {
            printf("�����ѧУ�����������������\n");
            goto start1;
        }
    start2:printf("�������Ŀ�޸ĺ������:");
        scanf("%d", &rank);
        fflush(stdin);
        if (id2 % 2 == 0)//����������Ŀ����Ů����Ŀ�����Ϊż���Ŀ�������ǰ������������ֻ������ǰ����
        {
            switch (rank)//�����ν��л��ֻ���
            {
            case 0:school[i].score1[id2 - 1][1] = 0; break;
            case 1:school[i].score1[id2 - 1][1] = 7; break;
            case 2:school[i].score1[id2 - 1][1] = 5; break;
            case 3:school[i].score1[id2 - 1][1] = 3; break;
            case 4:school[i].score1[id2 - 1][1] = 2; break;
            case 5:school[i].score1[id2 - 1][1] = 1; break;
            default:printf("���������볬����Χ�����ٴ�����\n"); goto start2;
            }
        }
        else
        {
            switch (rank)
            {
            case 0:school[i].score1[id2 - 1][1] = 0; break;
            case 1:school[i].score1[id2 - 1][1] = 5; break;
            case 2:school[i].score1[id2 - 1][1] = 3; break;
            case 3:school[i].score1[id2 - 1][1] = 2; break;
            default:printf("���������볬����Χ�����ٴ�����\n"); goto start2;
            }
        }
    }
    else
    {
        printf("�����ѧУ���û�У����Ĳ������ݣ�����������\n");
        goto start;//���ѧУ����������,�������¿�ʼ����

    }
    Initial(school, data);
    AddUp(school, data);//���޸ĺ�����ݽ�������ͳ��
    fflush(stdin);
    school[i].score1[id2 - 1][0] = rank;
    char str1[] = "��ʱ�ĵ�.txt";//����һ����ʱ�ļ������������
    FILE* p = fopen(str1, "w");
    FILE* fp = fopen(str, "r");
    if (p == NULL || fp == NULL)
    {
        printf("�ļ���ʧ�ܣ���������˳�");
        getchar();
        getchar();
        exit(1);
    }
    else
    {
        fread(data, sizeof(Num), 1, fp);
        fwrite(data, sizeof(Num), 1, p);
        fread(&tmp, sizeof(School), 1, fp);
        while (!feof(fp))
        {
            if (tmp.id != id1)//д��û���޸ĵ�ѧУ������
            {
                fwrite(&tmp, sizeof(School), 1, p);
                fread(&tmp, sizeof(School), 1, fp);
            }
            else
            {
                fwrite(&school[i], sizeof(School), 1, p);//д���޸ĵ�ѧУ������
                fread(&tmp, sizeof(School), 1, fp);
            }
        }
        fclose(fp);
        fclose(p);
        remove(str);//��ԭ�ļ�����
        rename(str1, str);//����ʱ�ļ�����Ϊԭ�ļ���
    }
    printf("����ִ���밴1���˳������밴�����:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void Fread(School school[], Num* data)//�ڴ����ļ��ж�ȡ���ݿ�
{
    printf("\n**************************************************************************************");
    printf("���ļ����ж�ȡ");
    printf("*****************************************************************************************");
    int k = 0;
    int key1, key2;
    School s;
    char str1[] = ".txt";
    printf("������Ҫ��ȡ�ļ�������:");
    scanf("%s", str);
    strcat(str, str1);
    fp = fopen(str, "r");
    if (fp == NULL)//�ļ���ʧ��
    {
        printf("�ļ���ʧ�ܣ��밴������˳�����:");
        getchar();
        getchar();
        exit(1);
    }
    else
    {
        fread(data, sizeof(Num), 1, fp);//��ȡ�ļ��е�����
        fread(&s, sizeof(School), 1, fp);
        while (!feof(fp))
        {
            school[k] = s;
            k++;
            fread(&s, sizeof(School), 1, fp);
        }
    }
    fclose(fp);
    printf("ȷ�϶�ȡ�밴1���˳������밴�����:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }

}
void PrintfItem(School school[], Num* data, Str& name)
{

    char key1;
    char key2;
    int id1;
    int i;
    int flag = 0;
    char str[] = "����";
    char str1[] = "�÷�";
    printf("\n***************************************************************************");
    printf("��ѧУ��Ų�ѯ��У������Ŀ�����κͳɼ�");
    printf("****************************************************************************");
start1:printf("������Ҫ�鿴��ѧУ�ı��:");
    scanf("%d", &id1);
    fflush(stdin);
    for (i = 0; i < data->num1; i++)
    {
        if (school[i].id == id1)//��ѯ�Ƿ��������ѧУ�ı��
        {
            flag = 1;
            break;
        }
    }

    if (flag != 1)
    {
        printf("�����ѧУ��ű����������������:\n");
        goto start1;
    }
    printf("\t");
    MscoreSort(school, data);
    WscoreSort(school, data);
    ScoreSort(school, data);
    for (int k = 0; k < data->num2 + data->num3; k++)
    {
        if (k < data->num2)
            printf("%14s%d", name.str3, k + 1);
        else
            printf("%14s%d", name.str4, k + 1);


    }
    printf("%15s", name.str5);
    printf("%15s", name.str6);
    printf("%15s", name.str7);
    printf("\n");
    printf("%-6s", str);
    for (int j = 0; j < data->num2 + data->num3; j++)
    {
        printf("%15d", school[i].score1[j][0]);

    }
    printf("%15d", school[i].Mscore[0][0]);
    printf("%15d", school[i].Wscore[0][0]);
    printf("%15d", school[i].score1[0][0]);
    printf("\n");
    printf("%-6s", str1);
    for (int s = 0; s < data->num2 + data->num3; s++)
    {
        printf("%15d", school[i].score1[s][1]);


    }
    printf("%15d", school[i].Mscore[0][1]);
    printf("%15d", school[i].Wscore[0][1]);
    printf("%15d", school[i].score[0][1]);
    printf("\n");

    printf("\nȷ���밴1���˳������밴�����:");

    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }



}

void Tnterface()//��ӡ�˵�����
{
    char ch;
    int j;
    ch = '*';
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t�˶������ͳ��ϵͳ\n");
    for (int i = 0; i < 52; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < 40; i++)
    {
        printf(" ");
        printf("%c", ch);
    }
    printf("\n");
    printf("\t\t\t\t\t\t     * �����0�˳�����");
    printf("                                                             *\n");
    printf("\t\t\t\t\t\t     * �����1������Ŀ�ɼ���¼��");
    printf("                                                   *\n");
    printf("\t\t\t\t\t\t     * �����2����ѧУ����������");
    printf("                                                 *\n");
    printf("\t\t\t\t\t\t     * �����3����ѧУ�ܷ��������");
    printf("                                                 *\n");
    printf("\t\t\t\t\t\t     * �����4�������������ܷ��������");
    printf("                                             *\n");
    printf("\t\t\t\t\t\t     * �����5����Ů�������ܷ��������");
    printf("                                             *\n");
    printf("\t\t\t\t\t\t     * �����6���а�ѧУ��Ų�ѯѧУĳ����Ŀ�����");
    printf("                                 *\n");
    printf("\t\t\t\t\t\t     * �����7���а���Ŀ��Ų�ѯȡ��ǰ����ǰ���ѧУ");
    printf("                               *\n");
    printf("\t\t\t\t\t\t     * �����8�����޸�ĳ��ѧУĳ����Ŀ������");
    printf("                                       *\n");
    printf("\t\t\t\t\t\t     * �����9���дӴ����ж�ȡ�ļ�");
    printf("                                                 *\n");
    printf("\t\t\t\t\t\t     * �����a����ͨ��ѧУ���������е���Ŀ�ɼ�������");
    printf("                             *\n");
    for (int i = 0; i < 53; i++)
    {
        printf(" ");
    }
    printf("*");
    for (int i = 0; i < 39; i++)
    {
        printf(" ");
        printf("%c", ch);
    }
    printf("\n");
    printf("\t\t\t\t\t\t");
    printf("!ע��ѧУ��Ŀ��������Ŀ������Ů����Ŀ���������ܳ���20�����洢�ļ��Ͷ�ȡ�ļ�����.txt������\n");
    printf("\t\t\t\t\t\t");
    printf("�����Ŀû����������0���������������ݻ��ȡ�ļ�����ܽ��������Ĳ���,��Ŀ���Ϊ����ֻ����\n");
    printf("\t\t\t\t\t\t");
    printf("��ǰ�����ɼ�����Ŀ���Ϊż��������ǰ�����ɼ�.");


}
void main()
{
    School school[n];//���ֻ�ܱ����ѧУ������
    Str name = { "ѧУ���", "ѧУ����", "������Ŀ","Ů����Ŀ" ,"�������ܷ�","Ů�����ܷ�", "ѧУ�ܷ�" };
    Num data;
    char ch1;
    char ch2;

    for (;;)//��������ѭ��
    {
        Tnterface();
    start1:    printf("\n������ִ�������:");
        ch1 = _getch();//��ȡ�����
        printf("%c", ch1);
        ch2 = _getch();
        switch (ch1)
        {
        case '0':exit(1); break;
        case '1':Input(school, &data); break;//���ݵ�����
        case '2':IdSort(school, &data); OutputId(school, &data, name); break;//����Ž����������
        case '3':ScoreSort(school, &data); OutputScore(school, &data, name); break;//���ֽܷ����������
        case '4': MscoreSort(school, &data); OutputMscore(school, &data, name); break;//���������ֽܷ����������
        case '5':WscoreSort(school, &data); OutputWscore(school, &data, name); break;//��Ů��������������
        case '6':SearchItem(school, &data); break;//��ѧУ��Ų�ѯĳ��Ŀ�����
        case '7':SearchSchool(school, &data); break;//����Ŀ��Ų�ѯĳȡ��ǰ������ǰ������ѧУ
        case '8':Revise(school, &data); break;//�޸�ĳ����Ŀ������
        case '9':Fread(school, &data); break;//�Ӵ����ж�ȡ�ļ�����
        case 'a':PrintfItem(school, &data, name); break;//��ӡѧУ��ȫ����Ŀ���;
        default: printf("������������������\n"); goto start1;//�����������򷵻�ȥ��������
        }

    }
}