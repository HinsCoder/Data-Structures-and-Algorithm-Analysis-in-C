#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>     //使用Sleep函数  
#include<stdlib.h>      //使用system函数
#include<time.h>        //使用获取当前日期时间函数
#include<string.h>      //使用字符串比较函数strcmp
#define judge 5	//评委人数
#define maxstu 10	//学生人数 
struct student	//定义学生结构体 
{
    char class[10];	//班级 
    char name[20];	//名字 
    int score[judge];	//评委评分 
    float max;	//最大值 
    float min;	//最小值 
    float sum;	//总分
    float average;	//平均值 
};
int count = 0;	//学生人数 
struct student stu[judge];	//定义全局变量 

void score_handle(int i, int j, float max1, float min1)    //嵌套分数处理函数
{
    for (i = 0; i < count; i++)
    {
        max1 = stu[i].score[0];          //假定第一个为最大值，进行顺序比较
        for (j = 0; j < judge; j++)
        {
            if (max1 < stu[i].score[j])
                max1 = stu[i].score[j];
        }                                //循环遍历评分找最大值
        stu[i].max = max1;               //将找到的最大值存入结构体max中
    }
    for (i = 0; i < count; i++)
    {
        min1 = stu[i].score[0];          //假定第一个为最小值，进行顺序比较
        for (j = 0; j < judge; j++)
        {
            if (min1 > stu[i].score[j])
                min1 = stu[i].score[j];
        }                                //循环遍历评分找最小值
        stu[i].min = min1;               //将找到的最小值存入结构体min中
    }
    for (i = 0; i < count; i++)
    {
        stu[i].sum = stu[i].score[0];    //定义第i位学生的总分
        for (j = 1; j < judge; j++)
        {
            stu[i].sum = stu[i].sum + stu[i].score[j];
        }                                //总分为各评委评分加起来
        stu[i].average = (stu[i].sum - stu[i].max - stu[i].min) / 3;
    }                                    //去掉一个最低分和一个最高分
}

fun1()	//选手信息录入 
{
    int i, j;	//i代表学生，j代表评委 
    int sm;		//定义需要录入几位学生 
    float max1=0, min1=0;	//最大值，最小值 
    printf("请输入10位以内学生人数:");
    scanf("%d", &sm);
    for (i = 0; i < sm; i++)
    {
        printf("请输入%d号选手信息\n", i + 1);
        printf("请输入班级:");
        scanf("%s", &stu[i].class);
        getchar();
        printf("请输入姓名:");
        gets(stu[i].name);
        for (j = 0; j < judge; j++)
        {
            printf("请输入%d号评委打分（100分制）:", j + 1);
            scanf("%d", &stu[i].score[j]);
        }
        count++;
    }
    score_handle(i,j, max1, min1);    //最高分，最低分，总分, 平均值
    
}
fun2()//按姓名查找
{
    int i;		//定义循环 
    char x[20];	//定义查找姓名 
    printf("请输入要查找学生的名字：");
    leap:scanf("%s", x);
    getchar();
    for (i = 0; i < count; i++)
    {
        
        
        if (strcmp(stu[i].name, x) != 0)     //判断是否相等 
        {
            continue;
        }
        else
        {
            printf("要查找的学生的信息为：\n班级：%s 姓名：%s 分数：%d %d %d %d %d 最高分:%g 最低分:%g 总分:%g 平均值:%.2f\n",           //%g用于避免输出无意义的0值
                stu[i].class, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].max, stu[i].min, stu[i].sum, stu[i].average);
            break;
        }
    }
    while (i == count)
    {
        printf("没有找到姓名为%s的学生信息,请再输入一次\n", x);
        goto leap;
    }
    getchar();
}
fun3()	//插入歌手信息
{
    int location, i, j;
    float max2, min2;
    struct student x;	//定义局部变量 
    if (count == maxstu)
    {
        printf("位置已满，无法插入\n");
        Sleep(2000);
    }
    else
    {
        printf("请输入要插入的位置:");
        scanf("%d", &location);
        if (location > count + 1 || location < 1)
        {
            printf("位置错误\n");
            Sleep(2000);
        }
        else
        {
            getchar();
            printf("请输入班级:");
            scanf("%s", &x.class);
            getchar();
            printf("请输入姓名:");
            gets(x.name);
            for (j = 0; j < judge; j++)
            {
                printf("请输入评委打分:");
                scanf("%d", &x.score[j]);
            }
            getchar();
            for (i = 0; i < count; i++)
            {
                max2 = x.score[0];
                for (j = 0; j < judge; j++)
                {
                    if (max2 < x.score[j])
                        max2 = x.score[j];
                }
                x.max = max2;
            }
            for (i = 0; i < count; i++)
            {
                min2 = x.score[0];
                for (j = 0; j < judge; j++)
                {
                    if (min2 > x.score[j])
                        min2 = x.score[j];
                }
                x.min = min2;
            }
            for (i = 0; i < count; i++)
            {
                x.sum = x.score[0];
                for (j = 1; j < judge; j++)
                {
                    x.sum = x.sum + x.score[j];
                }
                x.average = (x.sum - x.max - x.min) / 3;
            }
            for (i = count - 1; i >= location - 1; i--)
            {
                stu[i + 1] = stu[i];
            }
            stu[location - 1] = x;
            count++;
        }
    }
}
fun4()	//删除歌手信息
{
    int i, j;
    char a[20];
    printf("请输入要删除学生的名字：");
    leep:scanf("%s", a);
    getchar();
    for (i = 0; i < count; i++)
    {
        
        if (strcmp(stu[i].name, a) != 0)
        {
            continue;
        }
        else
        {
            printf("要删除的学生的信息为：\n班级：%s 姓名：%s 分数：%d %d %d %d %d 最高分:%g 最低分:%g 总分:%g 平均值:%.2f\n",
                stu[i].class, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].max, stu[i].min, stu[i].sum, stu[i].average);  
        }
        getchar();
        for (j = i + 1; j <= count; j++)
        {
            stu[j - 1] = stu[j];
        }
        count--;
        break;
    }
    while (i == count)
    {
        printf("没有找到姓名为%s的学生信息,请再输入一次\n", a);
        goto leep;
    }
}
fun5()	//修改歌手信息
{
    int i, j;
    float max2, min2;
    char m[20];
    printf("请输入要修改学生的名字：");
    laap:scanf("%s", m);
    getchar();
    for (i = 0; i < count; i++)
    {
        if (strcmp(stu[i].name, m) != 0)
        {
            continue;
        }
        else
        {
            printf("当前学生的信息为：\n班级：%s 姓名：%s 分数：%d %d %d %d %d 最高分:%g 最低分:%g 总分:%g 平均值:%.2f\n",
                stu[i].class, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].max, stu[i].min, stu[i].sum, stu[i].average);
            printf("请输入要修改的班级:");
            scanf("%s", &stu[i].class);
            getchar();
            printf("请输入要修改的姓名:");
            gets(stu[i].name);
            for (j = 0; j < judge; j++)
            {
                printf("请输入%d评委打分:", j + 1);
                scanf("%d", &stu[i].score[j]);
            }
        }break;
        
    }
    while (i == count)
    {
        printf("没有找到姓名为%s的学生信息,请再输入一次\n", m);
        goto laap;
    }
    getchar();
    //最高分，最低分，总分
    for (i = 0; i < count; i++)
    {
        max2 = stu[i].score[0];
        for (j = 0; j < judge; j++)
        {
            if (max2 < stu[i].score[j])
                max2 = stu[i].score[j];
        }
        stu[i].max = max2;
    }
    for (i = 0; i < count; i++)
    {
        min2 = stu[i].score[0];
        for (j = 0; j < judge; j++)
        {
            if (min2 > stu[i].score[j])
                min2 = stu[i].score[j];
        }
        stu[i].min = min2;
    }
    for (i = 0; i < count; i++)
    {
        stu[i].sum = stu[i].score[0];
        for (j = 1; j < judge; j++)
        {
            stu[i].sum = stu[i].sum + stu[i].score[j];
        }
        stu[i].average = (stu[i].sum - stu[i].max - stu[i].min) / 3;
    }
}
fun6()	//显示学生信息 
{
    int i;
    getchar();
    for (i = 0; i < count; i++)
    {
        printf("\n%d号选手的信息为：\n班级：%s 姓名：%s 分数：%d %d %d %d %d 最高分:%g 最低分:%g 总分:%g 平均值:%.2f\n", i + 1,
            stu[i].class, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].max, stu[i].min, stu[i].sum, stu[i].average);
    }
    getchar();
}
fun7()	//按平均分排序 
{
    int i, j, k;
    struct student temp;
    for (i = 0; i < count; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (stu[i].average > stu[j].average)
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    getchar();
    printf("平均分按高到低排序为：\n");
    for (i = count - 1, k = 1; i >= 0; i--,k++)
    {
        printf("\n第%d名：\n班级：%s 姓名：%s 分数：%d %d %d %d %d 最高分:%g 最低分:%g 总分:%g 平均值:%.2f \n", k,
            stu[i].class, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].max, stu[i].min, stu[i].sum, stu[i].average);
    }
    getchar();
}
void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)      //界面颜色处理
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, (ForeColor % 16) | (BackGroundColor % 16 * 16));
}
int main()
{
    int n, i;
    for (i = 1; i <= 50; i++)
    {
        SetColor(0, 7);               //设置字体为0（黑色），背景色为7（灰色）
        printf(" ");
        printf("%d%%", 2 * i);         //打印进度条的百分数，并递增
        Sleep(101 - 2 * i);            //进度条加载
        printf("\b\b\b");              //退格
    }
    SetColor(0, 15);                   //设置字体为0（黑色），背景色为15（白色）
    printf("\b\n\n\t加载完成！即将进入：");
    Sleep(1000);                       //等待1秒
    system("cls");                     //清屏
    do
    {
        system("cls");                 //每次回到主菜单都清屏
        printf("\n\t******2022仲园新歌声大赛评分系统******\n\n");
        time_t timep;
        struct tm* p;
        time(&timep);
        p = gmtime(&timep);
        printf("\t 当前日期时间为%d.%d.%d %d:%d\n\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);   //获取当前日期时间
        printf("\n\t\t1：输入选手数据\n");
        printf("\n\t\t2：按姓名查找\n");
        printf("\n\t\t3：追加歌手信息\n");
        printf("\n\t\t4：删除歌手信息\n");
        printf("\n\t\t5：修改歌手信息\n");
        printf("\n\t\t6：显示歌手信息\n");
        printf("\n\t\t7：按平均分排序\n");
        printf("\n\t\t0：退出\n");
        printf("\n\t\t请选择（0-7）:\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:fun1(); break;
        case 2:fun2(); break;
        case 3:fun3(); break;
        case 4:fun4(); break;
        case 5:fun5(); break;
        case 6:fun6(); break;
        case 7:fun7(); break;
        }
    } while (n != 0);
    return 0;
}

