#include<cstdio>
#include<malloc.h>
#include<algorithm>
#include<stack>
using namespace std;
#define MAXVEX 100

int indegree[MAXVEX];

//弧结构
typedef struct EdgeNode
{
    int vexindex;
    struct EdgeNode *next;
}EdgeNode;

//顶点结构
typedef struct
{
    char data;
    EdgeNode *first;
}VexNode;

//邻接表结构
typedef struct
{
    VexNode vex[MAXVEX];
    int vexnum, edgenum;
}Graph;

//链栈结构体
typedef struct Stack
{
    int  data;
    struct Stack *next;
}Stack;

/***************函数声明***************/
//创建邻接矩阵
void CreateGraph(Graph &G);
//获取所有顶点的入度
void GetInDegree(Graph G);
//链栈的初始化
void InitStack(Stack *&L);
//判断栈是否空
bool IsEmpty(Stack *L);
//进栈
bool Push(Stack *&L, int t);
//出栈
bool Pop(Stack *&L, int &t);
//拓扑排序
void TopologicalSort(Graph G);
/**************************************/

int main()
{
    Graph G;
    CreateGraph(G);
    TopologicalSort(G);
}

/***************函数定义***************/
void CreateGraph(Graph &G)
{

    printf("Enter the amount of vertex and edge:");
    scanf("%d %d", &G.vexnum, &G.edgenum);
    getchar();

    printf("Enter the data of the vertex\n");
    for(int i=1;i<=G.vexnum;i++)
    {
        scanf("%c", &G.vex[i].data);
        getchar();
        G.vex[i].first = NULL;
    }

    int s, t;
    printf("Enter the start and end of every edge\n");
    for(int i=0;i<G.edgenum;i++)
    {
        scanf("%d %d", &s, &t);
        EdgeNode *ptr = (EdgeNode *)malloc(sizeof(EdgeNode));
        ptr->vexindex = t;
        EdgeNode *p = G.vex[s].first;
        G.vex[s].first = ptr;
        ptr->next = p;
    }
}

void GetInDegree(Graph G)
{
    fill(indegree, indegree+MAXVEX, 0);
    for(int i=1;i<=G.vexnum;i++)
    {
        EdgeNode *p = G.vex[i].first;
        while(p)
        {
            indegree[p->vexindex]++;
            p = p->next;
        }
    }
}

//链栈的初始化
void InitStack(Stack *&L)
{
    L = (Stack *)malloc(sizeof(Stack));
    L->next = NULL;
}

//判断栈是否空
bool IsEmpty(Stack *L)
{
    if(L->next == NULL) return true;
    return false;
}

//进栈
bool Push(Stack *&L, int t)
{
    Stack *node = (Stack *)malloc(sizeof(Stack));
    node->data = t;
    node->next = L;
    L = node;
    return true;
}

//出栈
bool Pop(Stack *&L, int &t)
{
    if(IsEmpty(L)) return false; //栈空
     Stack *ptr = L;
    t = ptr->data;
    L = ptr->next;
    free(ptr);
    return true;
}

//拓扑排序
void TopologicalSort(Graph G)
{
    GetInDegree(G);
    Stack *s;
    InitStack(s);
    for(int i=1;i<=G.vexnum;i++)
    {
        if(!indegree[i])
            Push(s, i);
    }
    while(!IsEmpty(s))
    {
        int i;
        Pop(s, i);
        printf("%d ", i);
        EdgeNode *p = G.vex[i].first;
        while(p)
        {
            int j = p->vexindex;
            indegree[j]--;
            if(!indegree[j])
                Push(s, j);
            p = p->next;
        }
    }
}
