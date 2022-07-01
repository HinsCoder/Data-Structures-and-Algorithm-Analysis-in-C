//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>                  //编译预处理指令，引入头文件
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#define MAX 10                      //自定义符号常量
//#define MENU_MAIN_COUNT 7 		    //主菜单的选项个数
//typedef struct member               //定义结构体类型member，采用链式存储结构 
//{
//	char name[MAX];	                 //姓名 
//	char id[MAX];                    //卡号 
//	char sex[2];		             //性别 
//	int age;		             	//年龄 
//	float money;	            	 //余额 
//	char tel[12]; 	                //电话 
//	struct member* next;             //定义一个指针指向下一个会员信息 
//	float cost;		            	//消费金额 
//}mem;                                //定义结构体变量mem
//										/*声明函数*/
//void menu();                          /*声明函数，声明菜单函数*/
//void save(mem* p);                     //声明保存函数
//
//mem* head = NULL;	                         //头指针为NULL 
//mem* get_last(mem* p)                   //取得链表最后一个元素的节点指针并返回该指针
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
//void creat_member(mem* pNew)                                      //输入信息操作，会员登记函数
//{		                                                          //创建一个新的会员 
//	char s;
//	printf("卡号:");					scanf("%s", pNew->id);     //运用指针输入卡号
//	printf("请输入姓名: ");				scanf("%s", pNew->name);   //运用指针输入姓名
//a:
//	printf("请输入性别(f--女m--男): ");	getchar();                //输入男女
//	s = getchar();
//	if (s == 'f' || s == 'm')                                            //判断是 男 是 女
//	{
//		if (s == 'f' || s == 'F') strcpy(pNew->sex, "女");
//		if (s == 'M' || s == 'm') strcpy(pNew->sex, "男");
//	}
//	else                                                           //如果输入错误
//	{
//		printf("输入错误，请重新输入...\n");
//		goto a;                                                    //跳转至a，重新输入
//	}
//	printf("请输入年龄: ");				scanf("%d", &(pNew->age));   //运用指针输入年龄
//	printf("请输入缴费金额: ");			scanf("%f", &(pNew->money));  //运用指针输入余额
//	printf("请输入电话: ");				scanf("%s", pNew->tel);       //运用指针输入电话
//	pNew->cost = 0;                                                    //运用指针初始化消费额为0
//	printf("\n创建完毕!\n");
//}
//
//
//void newMember()                                                    //会员登记函数
//{	                                               	                //添加会员信息 
//	char con = 'N';
//	mem* pLast = NULL;
//	mem* pNew = (mem*)malloc(sizeof(mem));                           //按 mem 动态分配内存
//	pNew->next = NULL;
//	creat_member(pNew);                                             //调用会员登记函数
//	if (head == NULL)
//	{
//		head = pNew;
//	}
//	else
//	{
//		pLast = get_last(head);
//		pLast->next = pNew;
//	}
//	printf("继续输入会员信息？(Y 继续， N 返回菜单)");              //判断是否继续登记
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
////显示信息操作
//
//void table_head()
//{	                                                             	//定义表头 
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//	printf("|   卡号   | 姓名 | 性别 | 年龄 |  余额  |累计消费|   电话    |\n");
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//}
//void table_buttom()
//{                                                               	//定义底线 
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//}
//void table_row(mem* p)
//{	                                                                // 定义中间部分
//	printf("|%10s|%6s|%6s|%6d|%8.2f|%8.2f|%11s|\n",
//		p->id, p->name, p->sex, p->age, p->money, p->cost, p->tel);
//}
//
//
//
//
//void display(mem* p)
//{	                                        //显示所有信息 
//	p = head;
//	table_head();                            //调用表头
//	while (p != NULL)
//	{
//		table_row(p);                       //调用中间部分
//		p = p->next;
//	}
//	table_buttom();                          //调用底线
//}
//
//
//void display_one(mem* p)
//{	                                        //只显示一条信息 
//	table_head();
//	table_row(p);
//	table_buttom();
//}
//
//
//void table_sum()
//{                                //定义总计
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//	printf("|          |      |      |      |  总计  |  总计  |           |\n");
//	printf("+----------+------+------+------+--------+--------+-----------+\n");
//}
//void table_r(float money, float cost)
//{                              //定义总计2
//	printf("|          |      |      |      |%8.2f|%8.2f|           |\n", money, cost);
//}
//
//
//
//
//void display_statistics(mem* p, float money, float cost)
//{                                                                  //显示统计信息函数
//	p = head;
//	table_head();                                                 //调用表头
//	while (p != NULL)
//	{
//		table_row(p);                                             //定义中间部分
//		p = p->next;
//	}
//	p = head;
//	table_sum();                                                  //定义总计
//	table_r(money, cost);                                          //定义总计2
//	table_buttom();                                               //定义表尾
//}                                                                 //文件相关操作
//
//
//
//void save(mem* p)
//{	                                            	                 //保存函数
//	FILE* fp;                                                        //定义一个指向文件的指针变量
//	fp = fopen("member.dat", "a");                                     //将fopen函数的返回值赋给指针变量fp
//	while (p != NULL)
//	{
//		fprintf(fp, "%s %s %s %d %f %s %d\n", p->id, p->name, p->sex, p->age, p->money, p->tel, p->cost);
//		p = p->next;
//	}
//	fclose(fp);                                                       //关闭指针
//	getchar();
//}
//
//
//
//void modify_file(mem* p)
//{	                                                                //保存修改会员信息函数
//	FILE* fp;
//	p = head;
//	if ((fp = fopen("member.dat", "w")) == NULL)
//	{                                                               //检查打开文件的操作是否有错
//		printf("文件不存在");
//		getchar();
//		menu();                                                     //调用菜单函数
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
//{	                                                          //从文件加载信息 
//	FILE* fp;
//	mem* pLast = NULL;
//	head = NULL;
//	if ((fp = fopen("member.dat", "r")) == NULL)
//	{                                                         //检查打开文件的操作是否有错
//		printf("没有会员信息，请录入！");
//		getchar();
//		menu();                                               //调用菜单函数
//	}
//	while (!feof(fp))
//	{                                                         //文件指针是否到达末尾
//		mem* pNew = (mem*)malloc(sizeof(mem));               //按 mem 动态分配内存
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
////通过卡号搜索信息函数 
//
//
//mem* search_id(mem* p)
//{ 	                                                      //通过卡号搜索信息 
//	char id[MAX];
//	int i = 0;
//	p = head;
//	scanf("%s", id);
//	while (p && (strcmp(id, "n") != 0))
//	{                                                       //判断id是否不为n
//		if (strcmp(p->id, id) == 0)
//		{                                                   //找到
//			i = 1;
//			break;
//		}
//		else
//			p = p->next;
//	}
//	if (strcmp(id, "n") == 0)	                                //输入n时返回菜单 
//		menu();
//	if (p == NULL)
//	{			                                           //重新搜索卡号 
//		printf("您查找的卡号不存在，请重新输入：\n");
//		p = search_id(p);                                    //调用寻找函数
//	}
//	else
//		return p;                                          //返回p
//}
///*修改会员信息操作*/
//
//
//
//void modify_m()
//{	                                                       //修改会员的信息 
//
//	char s, fun = 'y';
//	char pro[] =
//		"|\n"
//		"| 1 姓名\n"
//		"| 2 性别\n"
//		"| 3 年龄\n"
//		"| 4 电话\n"
//		"| 5 返回\n"
//		"|\n";
//	mem* p;{};
//	load(p);
//	display(p);                                    //调用显示函数
//	printf("请输入需要修改信息的会员卡号（n返回菜单）：");
//	p = search_id(p);                                //调用按号寻找函数
//	while (fun == 'y' || fun == 'Y')
//	{                                              //当继续寻找时
//		system("cls");                            //清屏
//		display_one(p);                            //调用显示一条函数
//		printf("请选择修改的项目：\n");
//		printf(pro);                               //输出pro
//		getchar();
//		scanf("%c", &fun);
//		switch (fun)
//		{                                           //用switch语句选择修改内容
//		case '1':	printf("请输入姓名: ");				scanf("%s", p->name); break;
//		case '2':	a:
//			printf("请输入性别(f--女m--男): ");	getchar();
//			s = getchar();
//			if (s == 'f' || s == 'm')
//			{
//				if (s == 'f' || s == 'F') strcpy(p->sex, "女");
//				if (s == 'M' || s == 'm') strcpy(p->sex, "男");
//			}
//			else
//			{
//				printf(">输入错误，请重新输入...\n");
//				goto a;
//			}
//			break;
//		case '3':	printf("请输入年龄: ");				scanf("%d", &(p->age)); break;
//		case '4': 	printf("请输入电话: ");				scanf("%s", p->tel);	break;
//		default:	break;
//		}
//		printf("是否继续修改Y/N?");                     //判断是否继续寻找
//		getchar();
//		fun = getchar();
//	}
//	modify_file(p);                                    //调用保存修改会员信息函数                                      
//	system("cls");                                     //清屏
//	display_one(p);                                    //调用显示一条函数
//	printf("\n修改成功,按任意键继续!");
//	getchar();
//	menu();                                            //调用菜单函数
//}
////会员续费函数
//
//
//void add()
//{			                                           //会员续费 
//	float money;
//	mem* p;{}
//	load(p);
//	display(p);                                        //调用浏览函数
//	printf("\n");
//	printf("请输入需要续费的会员卡号（n返回菜单）：");
//	p = search_id(p);                                      //调用按号寻找函数
//	system("cls");                                       //清屏
//	display_one(p);                                      //调用显示一条函数
//	printf("请输入续费金额：");
//	scanf("%f", &money);
//	p->money += money;                                      //续费
//	modify_file(p);                                        //调用保存修改会员信息函数 
//	system("cls");                                         //清屏
//	display_one(p);                                        //调用显示一条函数
//	printf("续费成功，任意键继续!");
//	getchar();
//	menu();                                                  //调用菜单函数
//}
////会员结算函数
//
//
//
//void consume()
//{	                                                     	//会员结算 
//	mem* p;
//	float cost;
//	load(p);
//	display(p);                                                /* 调用浏览函数*/
//	printf("\n");
//	printf("请输入需要结算的会员卡号（n返回菜单）：");
//	p = search_id(p);                                          //调用按号寻找函数    
//	system("cls");                                           //清屏
//	display_one(p);                                          //调用显示一条函数
//	printf("请输入花费金额：");
//	scanf("%f", &cost);
//	if (p->cost >= 1000)
//	{                                                         //判断是否升级为vip
//		printf("恭喜您已经升级为VIP，本次消费9折优惠。\n");
//		printf("本次实际消费%.2f元！", cost * 0.9);              //升级为vip，消费打9折
//		cost *= 0.9;
//		if ((p->money - cost) < 0)
//		{                                                     //判断余额是否充足
//			printf("对不起，余额不足，请及时充值！");
//			getchar();
//			menu();
//		}
//		p->cost += cost;
//		p->money -= cost;                                       //消费
//		getchar();
//	}
//	else
//	{
//		if ((p->money - cost) < 0)
//		{                                 //同上
//			printf("对不起，余额不足，请及时充值！");
//			getchar();
//			menu();
//		}
//		p->cost += cost;
//		p->money -= cost;
//	}
//	modify_file(p);                                       //调用保存修改会员信息函数 
//	system("cls");                                         //清屏
//	display_one(p);                                       //调用显示一条函数
//	printf("结算成功，任意键继续!");
//	getchar();
//	menu();                                               //调用菜单函数
//}
///*会员退出函数*/
//
//
//
//void delete_m()
//{	                                                      //删除会员信息 
//	mem* p, * q = head, * thelast;
//	float money;
//	load(p);
//	display(p);                                           /* 调用浏览函数*/
//	printf("\n");
//	printf("请输入需要删除的会员卡号（n返回菜单）：");
//	p = search_id(p);                                        //调用按号寻找函数
//	thelast = head;
//	if (p == head)
//	{                                                     //判断指针
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
//	modify_file(q);                                           //调用保存函数
//	printf("退回余额%.2f元！\n", money);
//	printf("删除成功，按任意键继续！");                         //显示退回的余额
//	getchar();
//	menu();                                                    //调用菜单函数
//}                                                                /*统计函数*/
//
//
//mem* sort_m()
//{                                                             //按缴费总额排序
//	mem* q, * tail, * p = (mem*)malloc(sizeof(mem));
//	p->next = head;
//	head = p;
//	tail = NULL;                                                  //定义 tail
//	while (tail != head->next)
//	{
//		p = head;
//		q = p->next;
//		while (q->next != tail)
//		{                                                        //判断 q是否为空
//			if (p->next->money > q->next->money)
//			{
//				p->next = q->next;                                 //比较大小，排序
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
//	return head;                                                  //返回值
//}
//
//
//mem* sort_c()
//{                                                                //按消费金额排序 
//	mem* q, * tail, * p = (mem*)malloc(sizeof(mem));
//	p->next = head;
//	head = p;
//	tail = NULL;                                                     //定义 tail                             
//	while (tail != head->next)
//	{
//		p = head;
//		q = p->next;
//		while (q->next != tail)
//		{
//			if (p->next->cost > q->next->cost)
//			{                                                    //比较大小，排序
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
//	return head;                                        //返回值
//}
//
//
//float summ(mem* p)
//{	                                   //计算缴费总额 
//	float summ = 0;
//	p = head;
//	while (p)
//	{                                         //循环，实现求总额
//		summ += p->money;
//		p = p->next;
//	}
//	return summ;                                      //返回总额
//}
//
//
//
//float sumc(mem* p)
//{	                              //计算消费总额 
//	float sumc = 0;
//	p = head;
//	while (p)
//	{                                          //循环，实现求总额
//		sumc += p->cost;
//		p = p->next;
//	}
//	return sumc;                                       //返回总额
//}
//
//
//void statistics()
//{		                          //统计会员信息函数
//	int f = 0;
//	mem* p;{};
//	load(p);
//
//	system("cls");
//	printf("\t\t=======================================\n"
//		"\t\t|\n"
//		"\t\t|1 按缴费总额排序\n"
//		"\t\t|2 按消费总额排序\n"
//		"\t\t|3 返回菜单\n"
//		"\t\t|\n"
//		"\t\t=======================================\n"
//	);
//	printf("请选择功能：");
//	scanf("%d", &f);
//	switch (f)
//	{                                          //用switch语句选择功能
//	case 1:	p = sort_m(p);                              //调用按缴费总额排序
//		display_statistics(p, summ(p), sumc(p));    //调用函数
//		getchar();
//		menu();
//		break;
//	case 2: p = sort_c(p);                             //调用按消费总额排序
//		display_statistics(p, summ(p), sumc(p));   //调用函数
//		getchar();
//		menu(); break;
//	default: menu(); break;
//	}
//}
///*退出系统操作*/
//
//
//
//void clear(mem* p)
//{		                                     //释放链表空间 
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
//{                                               //退出函数
//	clear(head);
//	exit(0);
//}
///*菜单信息*/
//
//
//void menu_tile(char* title)
//{                                              //菜单表头  
//	printf("\t\t=======================================\n");
//	printf("\t\t| %s\n", title);
//	printf("\t\t---------------------------------------\n");
//}
//
//
//void (*menu_main_func[])() =                                    /*函数指针数组 menu_main_func[] 存储的是主菜单项中7个功能函数的地址，
//																分别对应1-7菜单项。例如用户选择1时，调用数组的第0个元素，即调用
//																newMember()函数，以此类推。*/
//{
//	newMember,
//	modify_m,
//	add,
//	consume,
//	delete_m,
//	statistics,
//	quit,
//};
//char menu_main[] =                                              //菜单主函数
//"\t\t\n"
//"\t\t| 1 新会员登记\n"
//"\t\t| 2 会员信息修改\n"
//"\t\t| 3 会员续费\n"
//"\t\t| 4 会员消费结算\n"
//"\t\t| 5 会员退卡\n"
//"\t\t| 6 统计功能\n"
//"\t\t| 7 退出系统\n"
//"\t\t|\n";
//void menu()
//{                                                               //菜单函数
//	int selected = 0;                                           //初始化变量
//	system("cls");                                              //清屏
//
//	printf("                 会员卡计费系统");
//	printf(menu_main);                                          //输出菜单主函数
//	printf("\t\t=======================================\n");
//
//	while (!(selected >= 1 && selected <= MENU_MAIN_COUNT))
//	{                                                          //判断初始值
//		printf("请选择：");
//		scanf("%d", &selected);
//		if (selected >= 1 && selected <= MENU_MAIN_COUNT)
//		{    //判断输入值是否有效
//			break;
//		}
//		printf("\n>输入错误！（注：请选择 1 - %d)\n", MENU_MAIN_COUNT);
//	}
//	menu_main_func[selected - 1]();                             //调用相应的函数指针数组中的函数，执行操作
//
//}
//int main()                                                  /*主函数*/
//{
//	menu();                                                   //调用菜单函数
//	return 0;                                                //返回值
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
//        printf("输入的数据不合法，请全部重新输入\n");
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
FILE* fp;//文件指针
int num4;//记录男子项目的名次
int num5;//记录女子项目的名次
char str[50];//记录存储路径
typedef struct School
{
    int id;//学校编号
    int score[1][2];//存储该学校男子和女子项目的总得分和名次,score[0][0]存储得分名次,score[0][1]存储得分;
    int score1[m + w][2];//存储该学校男子与女子各个项目的名次和得分,score1[n][0]存储名次,score1[n][1]存储得分
    int Mscore[1][2];//存储男子总分的名次和得分，Mscore[0][0]存储男子总得分的名次，Mscore[0][1]存储男子总得分
    int Wscore[1][2];//存储男子总分的名次和得分，Mscore[0][0]存储女子总得分的名次，Mscore[0][1]存储女子总得分

}School;
typedef struct Num
{
    int num1;//记录学校的个数
    int num2;//记录男子项目个数
    int num3;//记录女子项目个数

}Num;
typedef struct Str
{
    char str1[10];//中文字符以便进行字节对齐输出
    char str2[10];
    char str3[10];
    char str4[10];
    char str5[12];
    char str6[12];
    char str7[10];

}Str;
void Initial(School school[], Num* data)//对数据进行初始化
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
            school[i].Mscore[0][1] = school[i].Mscore[0][1] + school[i].score1[j][1];//进行男子项目总分的统计
        for (int k = data->num2; k < (data->num2 + data->num3); k++)
            school[i].Wscore[0][1] = school[i].Wscore[0][1] + school[i].score1[k][1];//进行女子项目总分的统计
        school[i].score[0][1] = school[i].Mscore[0][1] + school[i].Wscore[0][1];//进行总分的统计

    }
}

void Input(School school[], Num* data)
{
    char key1, key2;
    char str1[] = ".txt";
    printf("\n**************************************************************************************");
    printf("对数据信息进行录入");
    printf("*************************************************************************************");
    printf("输入你要录入信息的存储文件的名字:");
    scanf("%s", str);
    strcat(str, str1);//将文档以txt形式命名
    fp = fopen(str, "w");
    if (fp == NULL)
    {
        printf("存储的文件打开失败，请任意键退出");
        getchar();
        getchar();
        exit(1);
    }
    else
    {
    start1:printf("输入你要你要录入学校的个数:");
        scanf("%d", &(data->num1));
        if (data->num1 > n || data->num1 < 1)//对数据的输入进行判断，如果输入错误，则重新输入
        {
            printf("输入数据超出范围或有误,请重新输入\n");
            goto start1;

        }
    start2:printf("输入你要录入男子项目的个数:");
        scanf("%d", &(data->num2));
        if (data->num2 > m || data->num2 < 0)
        {
            printf("输入数据超出范围或有误,请重新输入\n");
            goto start2;

        }
    start3:printf("输入你要录入女子项目的个数:");
        scanf("%d", &(data->num3));
        if (data->num3 < 0 || data->num3>w)
        {
            printf("输入数据超出范围或有误,请重新输入\n");
            goto start3;

        }
        fflush(stdin);//刷新键盘

        fwrite(data, sizeof(Num), 1, fp);
        for (int i = 0; i < data->num1; i++)
        {
        start5:printf("输入第%d个学校的编号:", i + 1);
            scanf("%d", &(school[i].id));
            if (i >= 1)
            {
                for (int g = 0; g < i; g++)
                {
                    if (school[g].id == school[i].id)
                    {
                        printf("该学校的编号和其他学校的存在重复，请重新输入\n");
                        goto start5;

                    }
                }

            }
            for (int j = 0; j < (data->num2 + data->num3); j++)
            {
                if (j < data->num2)
                {
                start4:printf("输入该校项目编号为%d的男子项目的名次:", j + 1);
                }
                else
                {
                    printf("输入该校项目编号为%d的女子项目的名次:", j + 1);

                }
                scanf("%d", &num4);
                school[i].score1[j][0] = num4;//按项目编号顺序为项目名次赋值
                if ((j + 1) % 2 == 0)//无论男子项目还是女子项目，编号为偶数的可以输入前五名，奇数的只能输入前三名
                {
                    switch (num4)//对名次进行积分换算
                    {
                    case 0:school[i].score1[j][1] = 0; break;
                    case 1:school[i].score1[j][1] = 7; break;
                    case 2:school[i].score1[j][1] = 5; break;
                    case 3:school[i].score1[j][1] = 3; break;
                    case 4:school[i].score1[j][1] = 2; break;
                    case 5:school[i].score1[j][1] = 1; break;
                    default:printf("该名次输入超出范围，请再次输入\n"); goto start4;
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
                    default:printf("该名次输入超出范围，请再次输入\n"); goto start4;
                    }
                }
            }
            fflush(stdin);
        }
        Initial(school, data);
        AddUp(school, data);
        fwrite(school, sizeof(School), data->num1, fp);//在磁盘中写入数据块
    }
    fclose(fp);
    printf("继续执行请按1，退出程序请按任意键:");
    key1 = _getch();//获取命令符
    printf("%c", key1);//打印出命令符
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }

}
void IdSort(School  school[], Num* data)//按学校编号进行排序
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

void ScoreSort(School school[], Num* data)//进行总分的排序
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
    for (int k = 0; k < data->num1; k++)//排序完之后，将分数相同的赋值为一样的名次
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
void MscoreSort(School school[], Num* data)//进行男子团体总分的排序
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
    for (int k = 0; k < data->num1; k++)//排序完之后，将分数相同的赋值为一样的名次
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
void WscoreSort(School school[], Num* data)//进行女子团体总分的排序
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
            if (school[k].Wscore[0][1] == school[k - 1].Wscore[0][1])//排序完之后，将分数相同的赋值为一样的名次
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
void OutputId(School school[], Num* data, Str& name)//按学校编号进行排序输出
{
    char key1;
    char key2;
    printf("\n************************************************************************************");
    printf("学校编号排序输出如下:");
    printf("************************************************************************************\n");
    printf("%15s", name.str1);
    for (int i = 0; i < data->num2 + data->num3; i++)
    {
        if (i < data->num2)//判断是男子项目还是女子项目，采用字符对齐的方式进行输出
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
    printf("继续执行请按1，退出程序请按任意键:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void OutputScore(School school[], Num* data, Str& name)//按总分进行排序输出
{
    char key1;
    char key2;
    printf("\n**************************************************************************************");
    printf("总分排序输出如下:");
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
    printf("继续执行请按1，退出程序请按任意键:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void OutputMscore(School school[], Num* data, Str& name)//按男团体总分进行排序输出
{
    char key1;
    char key2;
    printf("\n***********************************************************************************");
    printf("男团体总分排序输出如下:");
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
    printf("继续执行请按1，退出程序请按任意键:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void OutputWscore(School school[], Num* data, Str& name)//按女团体总分进行排序输出
{
    char key1;
    char key2;
    printf("\n***********************************************************************************");
    printf("女团体总分排序输出如下:");
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
    printf("继续执行请按1，退出程序请按任意键:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void SearchItem(School school[], Num* data)//按学校编号查询学校某个项目的情况
{
    char key1;
    char key2;
    int num6;//学校编号
    int num7;//项目编号
    int flag = 0;
    printf("\n*****************************************************************************");
    printf("按学校编号查询学校某个项目的情况");
    printf("*******************************************************************************\n");
start1:printf("输入你要查询的学校的编号:");
    scanf("%d", &num6);
    if (num6 > data->num1 || num6 < 1)
    {
        printf("输入的数据有误，请重新输入学校编号\n");
        goto start1;
    }
    for (int k = 0; k < data->num1; k++)
    {
        if (school[k].id == num6)//进行判断是否存在该校的编号
        {
            flag = 1;
            break;
        }
    }
    if (flag != 1)
    {
        printf("没有该学校的编号,请重新输入");
        goto start1;

    }
start2:printf("输入你要查询的项目编号:");
    scanf("%d", &num7);
    if (num7 > (data->num2 + data->num3) || num7 < 1)
    {
        printf("输入的数据有误，请重新输入项目编号\n");
        goto start2;

    }
    for (int i = 0; i < data->num1; i++)
    {
        if (school[i].id == num6)
        {
            if (num7 > data->num2)
            {
                printf("\t\t\t\t\t\t\t\t\t女子项目");
                printf("  名次:%d  积分:%d\n", school[i].score1[num7 - 1][0], school[i].score1[num7 - 1][1]);

            }
            else
            {
                printf("\t\t\t\t\t\t\t\t\t男子项目");
                printf("  名次:%d  积分:%d\n", school[i].score1[num7 - 1][0], school[i].score1[num7 - 1][1]);


            }

        }
    }
    printf("继续执行请按1，退出程序请按任意键:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void SearchSchool(School school[], Num* data)//按项目编号查询取得前三或前五名的学校
{
    char key1;
    char key2;
    printf("\n***************************************************************************");
    printf("按项目编号查询取得前三或前五名的学校");
    printf("******************************************************************************");
    int num8;//记录运动的项目编号
    int i, j, t, k, z;
    School temp;
    int count = 1;
    char str1[] = "名次";
    char str2[] = "学校编号";
    int* p;
    p = (int*)malloc(sizeof(int) * data->num1);//动态申请内存
start:printf("输入你要查询的项目编号:");
    scanf("%d", &num8);
    if (num8 >= 1 && num8 <= data->num2 + data->num3)//选择排序
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
        printf("输入项目的编号存在错误,请重新输入\n");
        goto start;//返回重新输入
    }
    for (k = 0; k < data->num1; k++)//排序完之后,对各个项目的排名的名次进行赋值
    {
        if (k == 0)
        {
            p[k] = count;
            count++;
        }
        else
        {
            if (school[k].score1[num8 - 1][1] == school[k - 1].score1[num8 - 1][1])//如果得分相同，则名次赋值为相同
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
    if (num8 % 2 == 0)//判断是输出前五名成绩还是前三名成绩
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
    free(p);//释放内存
    printf("继续执行请按1，退出程序请按任意键:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void Revise(School school[], Num* data)//修改某个学校某个运动项目的名次
{
    printf("\n******************************************************************************");
    printf("修改某个学校某个运动项目的名次");
    printf("*********************************************************************************\n");
    int id1;//记录学校的编号
    int id2;//记录项目的编号
    int rank;//修改的名次
    int i;
    int flag = 0;
    School tmp;
    char key1;
    char key2;
start:printf("输入你要修改项目学校的编号:");
    scanf("%d", &id1);
    for (i = 0; i < data->num1; i++)
    {
        if (school[i].id == id1)//查询是否存在输入学校的编号
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
    start1:printf("输入你要修改项目的编号:");
        scanf("%d", &id2);
        if (id2 > (data->num2 + data->num3) || id2 < 1)//对编号进行判断
        {
            printf("输入的学校编号有误。请重新输入\n");
            goto start1;
        }
    start2:printf("输入该项目修改后的名次:");
        scanf("%d", &rank);
        fflush(stdin);
        if (id2 % 2 == 0)//无论男子项目还是女子项目，编号为偶数的可以输入前五名，奇数的只能输入前三名
        {
            switch (rank)//对名次进行积分换算
            {
            case 0:school[i].score1[id2 - 1][1] = 0; break;
            case 1:school[i].score1[id2 - 1][1] = 7; break;
            case 2:school[i].score1[id2 - 1][1] = 5; break;
            case 3:school[i].score1[id2 - 1][1] = 3; break;
            case 4:school[i].score1[id2 - 1][1] = 2; break;
            case 5:school[i].score1[id2 - 1][1] = 1; break;
            default:printf("该名次输入超出范围，请再次输入\n"); goto start2;
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
            default:printf("该名次输入超出范围，请再次输入\n"); goto start2;
            }
        }
    }
    else
    {
        printf("输入的学校编号没有，更改不了数据，请重新输入\n");
        goto start;//如果学校编号输入错误,返回重新开始输入

    }
    Initial(school, data);
    AddUp(school, data);//对修改后的数据进行重新统计
    fflush(stdin);
    school[i].score1[id2 - 1][0] = rank;
    char str1[] = "临时文档.txt";//建立一个临时文件用来存放数据
    FILE* p = fopen(str1, "w");
    FILE* fp = fopen(str, "r");
    if (p == NULL || fp == NULL)
    {
        printf("文件打开失败，按任意键退出");
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
            if (tmp.id != id1)//写入没有修改的学校的数据
            {
                fwrite(&tmp, sizeof(School), 1, p);
                fread(&tmp, sizeof(School), 1, fp);
            }
            else
            {
                fwrite(&school[i], sizeof(School), 1, p);//写入修改的学校的数据
                fread(&tmp, sizeof(School), 1, fp);
            }
        }
        fclose(fp);
        fclose(p);
        remove(str);//把原文件销掉
        rename(str1, str);//降临时文件命名为原文件名
    }
    printf("继续执行请按1，退出程序请按任意键:");
    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }
}
void Fread(School school[], Num* data)//在磁盘文件中读取数据块
{
    printf("\n**************************************************************************************");
    printf("对文件进行读取");
    printf("*****************************************************************************************");
    int k = 0;
    int key1, key2;
    School s;
    char str1[] = ".txt";
    printf("输入你要读取文件的名字:");
    scanf("%s", str);
    strcat(str, str1);
    fp = fopen(str, "r");
    if (fp == NULL)//文件打开失败
    {
        printf("文件打开失败，请按任意键退出程序:");
        getchar();
        getchar();
        exit(1);
    }
    else
    {
        fread(data, sizeof(Num), 1, fp);//读取文件中的数据
        fread(&s, sizeof(School), 1, fp);
        while (!feof(fp))
        {
            school[k] = s;
            k++;
            fread(&s, sizeof(School), 1, fp);
        }
    }
    fclose(fp);
    printf("确认读取请按1，退出程序请按任意键:");
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
    char str[] = "名次";
    char str1[] = "得分";
    printf("\n***************************************************************************");
    printf("按学校编号查询该校所有项目的名次和成绩");
    printf("****************************************************************************");
start1:printf("输入你要查看的学校的编号:");
    scanf("%d", &id1);
    fflush(stdin);
    for (i = 0; i < data->num1; i++)
    {
        if (school[i].id == id1)//查询是否存在输入学校的编号
        {
            flag = 1;
            break;
        }
    }

    if (flag != 1)
    {
        printf("输入的学校编号编号有误，请重新输入:\n");
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

    printf("\n确认请按1，退出程序请按任意键:");

    key1 = _getch();
    printf("%c", key1);
    key2 = _getch();
    switch (key1)
    {
    case '1':system("cls"); break;
    default:exit(1); break;
    }



}

void Tnterface()//打印菜单界面
{
    char ch;
    int j;
    ch = '*';
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t运动会分数统计系统\n");
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
    printf("\t\t\t\t\t\t     * 命令符0退出程序");
    printf("                                                             *\n");
    printf("\t\t\t\t\t\t     * 命令符1进行项目成绩的录入");
    printf("                                                   *\n");
    printf("\t\t\t\t\t\t     * 命令符2进行学校编号排序输出");
    printf("                                                 *\n");
    printf("\t\t\t\t\t\t     * 命令符3进行学校总分排序输出");
    printf("                                                 *\n");
    printf("\t\t\t\t\t\t     * 命令符4进行男子团体总分排序输出");
    printf("                                             *\n");
    printf("\t\t\t\t\t\t     * 命令符5进行女子团体总分排序输出");
    printf("                                             *\n");
    printf("\t\t\t\t\t\t     * 命令符6进行按学校编号查询学校某个项目的情况");
    printf("                                 *\n");
    printf("\t\t\t\t\t\t     * 命令符7进行按项目编号查询取得前三或前五的学校");
    printf("                               *\n");
    printf("\t\t\t\t\t\t     * 命令符8进行修改某个学校某个项目的名次");
    printf("                                       *\n");
    printf("\t\t\t\t\t\t     * 命令符9进行从磁盘中读取文件");
    printf("                                                 *\n");
    printf("\t\t\t\t\t\t     * 命令符a进行通过学校编号输出所有的项目成绩和名次");
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
    printf("!注意学校数目，男子项目个数，女子项目个数均不能超过20个，存储文件和读取文件须以.txt命名，\n");
    printf("\t\t\t\t\t\t");
    printf("如果项目没有名次输入0，必须先输入数据或读取文件后才能进行其他的操作,项目编号为单数只能输\n");
    printf("\t\t\t\t\t\t");
    printf("入前三名成绩，项目编号为偶数能输入前五名成绩.");


}
void main()
{
    School school[n];//最多只能保存个学校的数据
    Str name = { "学校编号", "学校名次", "男子项目","女子项目" ,"男团体总分","女团体总分", "学校总分" };
    Num data;
    char ch1;
    char ch2;

    for (;;)//操作进行循环
    {
        Tnterface();
    start1:    printf("\n请输入执行命令符:");
        ch1 = _getch();//读取命令符
        printf("%c", ch1);
        ch2 = _getch();
        switch (ch1)
        {
        case '0':exit(1); break;
        case '1':Input(school, &data); break;//数据的输入
        case '2':IdSort(school, &data); OutputId(school, &data, name); break;//按编号进行排序输出
        case '3':ScoreSort(school, &data); OutputScore(school, &data, name); break;//按总分进行排序输出
        case '4': MscoreSort(school, &data); OutputMscore(school, &data, name); break;//按男团体总分进行排序输出
        case '5':WscoreSort(school, &data); OutputWscore(school, &data, name); break;//按女团体进行排序输出
        case '6':SearchItem(school, &data); break;//按学校编号查询某项目的情况
        case '7':SearchSchool(school, &data); break;//按项目编号查询某取得前五名或前三名的学校
        case '8':Revise(school, &data); break;//修改某个项目的名次
        case '9':Fread(school, &data); break;//从磁盘中读取文件出来
        case 'a':PrintfItem(school, &data, name); break;//打印学校的全部项目情况;
        default: printf("输入有误，请重新输入\n"); goto start1;//如果输入错误则返回去重新输入
        }

    }
}