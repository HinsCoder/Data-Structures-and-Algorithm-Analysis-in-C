#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>     //ʹ��Sleep����  
#include<stdlib.h>      //ʹ��system����
#include<time.h>        //ʹ�û�ȡ��ǰ����ʱ�亯��
#include<string.h>      //ʹ���ַ����ȽϺ���strcmp
#define judge 5	//��ί����
#define maxstu 10	//ѧ������ 
struct student	//����ѧ���ṹ�� 
{
    char class[10];	//�༶ 
    char name[20];	//���� 
    int score[judge];	//��ί���� 
    float max;	//���ֵ 
    float min;	//��Сֵ 
    float sum;	//�ܷ�
    float average;	//ƽ��ֵ 
};
int count = 0;	//ѧ������ 
struct student stu[judge];	//����ȫ�ֱ��� 

void score_handle(int i, int j, float max1, float min1)    //Ƕ�׷���������
{
    for (i = 0; i < count; i++)
    {
        max1 = stu[i].score[0];          //�ٶ���һ��Ϊ���ֵ������˳��Ƚ�
        for (j = 0; j < judge; j++)
        {
            if (max1 < stu[i].score[j])
                max1 = stu[i].score[j];
        }                                //ѭ���������������ֵ
        stu[i].max = max1;               //���ҵ������ֵ����ṹ��max��
    }
    for (i = 0; i < count; i++)
    {
        min1 = stu[i].score[0];          //�ٶ���һ��Ϊ��Сֵ������˳��Ƚ�
        for (j = 0; j < judge; j++)
        {
            if (min1 > stu[i].score[j])
                min1 = stu[i].score[j];
        }                                //ѭ��������������Сֵ
        stu[i].min = min1;               //���ҵ�����Сֵ����ṹ��min��
    }
    for (i = 0; i < count; i++)
    {
        stu[i].sum = stu[i].score[0];    //�����iλѧ�����ܷ�
        for (j = 1; j < judge; j++)
        {
            stu[i].sum = stu[i].sum + stu[i].score[j];
        }                                //�ܷ�Ϊ����ί���ּ�����
        stu[i].average = (stu[i].sum - stu[i].max - stu[i].min) / 3;
    }                                    //ȥ��һ����ͷֺ�һ����߷�
}

fun1()	//ѡ����Ϣ¼�� 
{
    int i, j;	//i����ѧ����j������ί 
    int sm;		//������Ҫ¼�뼸λѧ�� 
    float max1=0, min1=0;	//���ֵ����Сֵ 
    printf("������10λ����ѧ������:");
    scanf("%d", &sm);
    for (i = 0; i < sm; i++)
    {
        printf("������%d��ѡ����Ϣ\n", i + 1);
        printf("������༶:");
        scanf("%s", &stu[i].class);
        getchar();
        printf("����������:");
        gets(stu[i].name);
        for (j = 0; j < judge; j++)
        {
            printf("������%d����ί��֣�100���ƣ�:", j + 1);
            scanf("%d", &stu[i].score[j]);
        }
        count++;
    }
    score_handle(i,j, max1, min1);    //��߷֣���ͷ֣��ܷ�, ƽ��ֵ
    
}
fun2()//����������
{
    int i;		//����ѭ�� 
    char x[20];	//����������� 
    printf("������Ҫ����ѧ�������֣�");
    leap:scanf("%s", x);
    getchar();
    for (i = 0; i < count; i++)
    {
        
        
        if (strcmp(stu[i].name, x) != 0)     //�ж��Ƿ���� 
        {
            continue;
        }
        else
        {
            printf("Ҫ���ҵ�ѧ������ϢΪ��\n�༶��%s ������%s ������%d %d %d %d %d ��߷�:%g ��ͷ�:%g �ܷ�:%g ƽ��ֵ:%.2f\n",           //%g���ڱ�������������0ֵ
                stu[i].class, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].max, stu[i].min, stu[i].sum, stu[i].average);
            break;
        }
    }
    while (i == count)
    {
        printf("û���ҵ�����Ϊ%s��ѧ����Ϣ,��������һ��\n", x);
        goto leap;
    }
    getchar();
}
fun3()	//���������Ϣ
{
    int location, i, j;
    float max2, min2;
    struct student x;	//����ֲ����� 
    if (count == maxstu)
    {
        printf("λ���������޷�����\n");
        Sleep(2000);
    }
    else
    {
        printf("������Ҫ�����λ��:");
        scanf("%d", &location);
        if (location > count + 1 || location < 1)
        {
            printf("λ�ô���\n");
            Sleep(2000);
        }
        else
        {
            getchar();
            printf("������༶:");
            scanf("%s", &x.class);
            getchar();
            printf("����������:");
            gets(x.name);
            for (j = 0; j < judge; j++)
            {
                printf("��������ί���:");
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
fun4()	//ɾ��������Ϣ
{
    int i, j;
    char a[20];
    printf("������Ҫɾ��ѧ�������֣�");
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
            printf("Ҫɾ����ѧ������ϢΪ��\n�༶��%s ������%s ������%d %d %d %d %d ��߷�:%g ��ͷ�:%g �ܷ�:%g ƽ��ֵ:%.2f\n",
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
        printf("û���ҵ�����Ϊ%s��ѧ����Ϣ,��������һ��\n", a);
        goto leep;
    }
}
fun5()	//�޸ĸ�����Ϣ
{
    int i, j;
    float max2, min2;
    char m[20];
    printf("������Ҫ�޸�ѧ�������֣�");
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
            printf("��ǰѧ������ϢΪ��\n�༶��%s ������%s ������%d %d %d %d %d ��߷�:%g ��ͷ�:%g �ܷ�:%g ƽ��ֵ:%.2f\n",
                stu[i].class, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].max, stu[i].min, stu[i].sum, stu[i].average);
            printf("������Ҫ�޸ĵİ༶:");
            scanf("%s", &stu[i].class);
            getchar();
            printf("������Ҫ�޸ĵ�����:");
            gets(stu[i].name);
            for (j = 0; j < judge; j++)
            {
                printf("������%d��ί���:", j + 1);
                scanf("%d", &stu[i].score[j]);
            }
        }break;
        
    }
    while (i == count)
    {
        printf("û���ҵ�����Ϊ%s��ѧ����Ϣ,��������һ��\n", m);
        goto laap;
    }
    getchar();
    //��߷֣���ͷ֣��ܷ�
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
fun6()	//��ʾѧ����Ϣ 
{
    int i;
    getchar();
    for (i = 0; i < count; i++)
    {
        printf("\n%d��ѡ�ֵ���ϢΪ��\n�༶��%s ������%s ������%d %d %d %d %d ��߷�:%g ��ͷ�:%g �ܷ�:%g ƽ��ֵ:%.2f\n", i + 1,
            stu[i].class, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].max, stu[i].min, stu[i].sum, stu[i].average);
    }
    getchar();
}
fun7()	//��ƽ�������� 
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
    printf("ƽ���ְ��ߵ�������Ϊ��\n");
    for (i = count - 1, k = 1; i >= 0; i--,k++)
    {
        printf("\n��%d����\n�༶��%s ������%s ������%d %d %d %d %d ��߷�:%g ��ͷ�:%g �ܷ�:%g ƽ��ֵ:%.2f \n", k,
            stu[i].class, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].score[4], stu[i].max, stu[i].min, stu[i].sum, stu[i].average);
    }
    getchar();
}
void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)      //������ɫ����
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, (ForeColor % 16) | (BackGroundColor % 16 * 16));
}
int main()
{
    int n, i;
    for (i = 1; i <= 50; i++)
    {
        SetColor(0, 7);               //��������Ϊ0����ɫ��������ɫΪ7����ɫ��
        printf(" ");
        printf("%d%%", 2 * i);         //��ӡ�������İٷ�����������
        Sleep(101 - 2 * i);            //����������
        printf("\b\b\b");              //�˸�
    }
    SetColor(0, 15);                   //��������Ϊ0����ɫ��������ɫΪ15����ɫ��
    printf("\b\n\n\t������ɣ��������룺");
    Sleep(1000);                       //�ȴ�1��
    system("cls");                     //����
    do
    {
        system("cls");                 //ÿ�λص����˵�������
        printf("\n\t******2022��԰�¸�����������ϵͳ******\n\n");
        time_t timep;
        struct tm* p;
        time(&timep);
        p = gmtime(&timep);
        printf("\t ��ǰ����ʱ��Ϊ%d.%d.%d %d:%d\n\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);   //��ȡ��ǰ����ʱ��
        printf("\n\t\t1������ѡ������\n");
        printf("\n\t\t2������������\n");
        printf("\n\t\t3��׷�Ӹ�����Ϣ\n");
        printf("\n\t\t4��ɾ��������Ϣ\n");
        printf("\n\t\t5���޸ĸ�����Ϣ\n");
        printf("\n\t\t6����ʾ������Ϣ\n");
        printf("\n\t\t7����ƽ��������\n");
        printf("\n\t\t0���˳�\n");
        printf("\n\t\t��ѡ��0-7��:\n");
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

