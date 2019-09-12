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

//十字链表的存储结构
typedef struct EdgeNode //弧结构
{
    int headindex, tailindex; //弧头尾顶点索引
    struct EdgeNode *hlink, *tlink; //同一个弧头结点和同一个弧尾结点的弧
}EdgeNode;

typedef struct //顶点结构
{
    VexType data; //顶点信息
    EdgeNode *firstin, *firstout; //已该顶点为弧头和弧尾的第一条弧
}VexNode, VexList[MAXVERTEXNUM];

typedef struct
{
    VexList Vex; //邻接表
    int vexnum, edgenum; //顶点数和弧数
}GLGraph;
