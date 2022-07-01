#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

#define INF     32767               //�����
#define MAXV    100                 //��󶥵����

typedef char InfoType;
/*-------------------------���¶����ڽӾ�������---------------------------*/
typedef struct
{
    int no;                         //������
    InfoType info;                  //������Ϣ
}VertexType;                        //��������

typedef struct
{
    int edges[MAXV][MAXV];          //�ڽӾ�������(��һ����ά�����Ŷ�����ϵ(�߻�)������)
    int n;                          //������
    int e;                          //����
    VertexType vexs[MAXV];          //��Ŷ�����Ϣ(��һ��һά������ͼ�����ж�������)
}MatGraph;                          //������ͼ�ڽӾ�������

//�ڽӱ��ʾ��-��ÿ��������ڽӵ㴮��һ��������
/*-----------���¶����ڽӱ�����--------------*/
typedef struct ArcNode
{
    int adjvex;                     //�ñߵ��ڽӵ���
    struct ArcNode* nextarc;        //ָ����һ���ߵ�ָ��
    int weight;                     //�ñߵ������Ϣ,��Ȩֵ(�����ͱ�ʾ)
}ArcNode;                           //�߽������

typedef struct VNode
{
    InfoType info;                  //����������Ϣ
    int cnt;                        //��Ŷ������,��������������
    ArcNode* firstarc;              //ָ���һ����
}VNode;                             //�ڽӱ�������

typedef struct
{
    VNode adjlist[MAXV];            //�ڽӱ�ͷ�������
    int n;                          //ͼ�ж�����
    int e;                          //ͼ�б���
}AdjGraph;                          //������ͼ�ڽӱ�����

/*-------------------------�ڽӾ���Ļ��������㷨---------------------------*/
/*------------�ɱ�����A��������n�ͱ���e����ͼ���ڽӾ���g--------------------*/
void CreateMat(MatGraph& g, int A[MAXV][MAXV], int n, int e)
{
    int i, j;

    g.n = n;
    g.e = e;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            g.edges[i][j] = A[i][j];
}

/*------------����ڽӾ���g--------------------*/
void DispMat(MatGraph g)
{
    int i, j;

    for (i = 0; i < g.n; i++)
    {
        for (j = 0; j < g.n; j++)
        {
            if (g.edges[i][j] != INF)
                printf("%4d", g.edges[i][j]);
            else
                printf("%4s", "��");
        }
        printf("\n");
    }
}

/*-------------------------�ڽӱ�Ļ��������㷨---------------------------*/
/*-------------------�ɱ�����A��������n�ͱ���e����ͼ���ڽӱ�G--------------------*/
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode* p;

    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++)                              //���ڽӱ�������ͷ����ָ�����ó�ֵNULL
    {
        G->adjlist[i].firstarc = NULL;
    }

    for (i = 0; i < n; i++)                              //����ڽӾ����е�ÿ��Ԫ��
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (A[i][j] != 0 && A[i][j] != INF)          //����һ����
            {
                p = (ArcNode*)malloc(sizeof(ArcNode)); //����һ�����p
                p->adjvex = j;                          //�ڽӵ���
                p->weight = A[i][j];                    //�ߵ�Ȩ��
                p->nextarc = G->adjlist[i].firstarc;    //����ͷ�巨������p
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

/*-------------------����ڽӱ�G--------------------*/
void DispAdj(AdjGraph* G)
{
    ArcNode* p;

    for (int i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("����%d: ", i);
        while (p != NULL)
        {
            printf("%3d[%d]->", p->adjvex, p->weight);  //�ڽӵ���[Ȩ��]
            p = p->nextarc;
        }
        printf("��\n");
    }
}

/*-------------------����ͼ���ڽӱ�G--------------------*/
void DestroyAdj(AdjGraph*& G)
{
    ArcNode* pre, * p;

    for (int i = 0; i < G->n; i++)
    {
        pre = G->adjlist[i].firstarc;                   //preָ���i����������׽��
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL)                            //�ͷŵ�i������������б߽��
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);                                            //�ͷ�ͷ�������
}

int main(void)
{
    MatGraph g;
    AdjGraph* G;
    int n = 6;                                  //ͼ�еĶ�����
    int e = 10;                                 //ͼ�еı���
    int A[MAXV][MAXV] = {
        {0, 5, INF, 7, INF, INF}, {INF, 0, 4, INF, INF, INF},
        {8, INF, 0, INF, INF, 9}, {INF, INF, 5, 0, INF, 6},
        {INF, INF, INF, 5, 0, INF}, {3, INF, INF, INF, 1, 0}
    };

    CreateMat(g, A, n, e);
    printf("(1)ͼ���ڽӾ���:\n");
    DispMat(g);

    CreateAdj(G, A, n, e);
    printf("(2)ͼ���ڽӱ�:\n");
    DispAdj(G);
    printf("(3)����ͼ���ڽӱ�\n");
    DestroyAdj(G);

    return 0;
}
