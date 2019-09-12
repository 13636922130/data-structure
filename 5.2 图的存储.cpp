#include<cstdio>

//邻接矩阵的存储结构定义
#define MAXVERTEXNUM 100
typedef char VexType; //顶点数据类型
typedef int EdgeType; //边数据类型
typedef struct
{
    VexType Vex[MAXVERTEXNUM]; //顶点表
    EdgeType Edge[MAXVERTEXNUM][MAXVERTEXNUM]; //邻接矩阵
    int vexnum, edgenum; //顶点数和边数
}MGraph;

//简单的邻接表结构定义
EdgeType MGraph[MAXVERTEXNUM][MAXVERTEXNUM];

//邻接表的结构定义
//顶点表结点->边表结点->边表结点->...
typedef struct EdgeNode //边表结点
{
    int index; //顶点表索引
    struct EdgeNode *next; //下一个边表
}EdgeNode;

typedef struct //顶点表结点
{
    VexType data; //顶点数据
    EdgeNode *head; //指向第一个边表
}VexNode, VexList[MAXVERTEXNUM];

typedef struct
{
    VexList Vex; //定义邻接表
    int vexnum, edgenum; //顶点数和边数
}ALGraph;
