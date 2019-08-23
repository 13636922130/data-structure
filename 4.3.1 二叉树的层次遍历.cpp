#include<cstdio>
#include<malloc.h>

//二叉树结构体
typedef struct BiNode
{
    char data; //数据域
    struct BiNode *lchild, *rchild; //指针域
}BiNode, *BiTree;

//链式队列节点
typedef struct LinkNode
{
    BiTree data;
    struct LinkNode *next;
}LinkNode;

//链式队列
typedef struct
{
    LinkNode *front, *rear;
}Queue;

/***************函数声明***************/

//按先序序列建立二叉链表
void CreateBiTree(BiTree &T);
//初始化
void InitQueue(Queue &q);
//判断队列是否为空
bool QueueEmpty(Queue q);
//入队
//采用尾插法
void EnQueue(Queue &q, BiTree num);
//出队
bool DeQueue(Queue &q, BiTree &num);
//层次遍历
void LevelOrder(BiTree T);

/**************************************/

int main()
{
    BiTree T;
    CreateBiTree(T);
    LevelOrder(T);
}

/***************函数定义***************/

//按先序序列建立二叉链表
void CreateBiTree(BiTree &T)
{
    char ch;
    scanf("%c", &ch);
    if(ch == ' ')
        T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiNode));
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

//初始化
void InitQueue(Queue &q)
{
    q.front = (LinkNode *)malloc(sizeof(LinkNode));
    q.rear = q.front;
    q.front->next = NULL;
}

//判断队列是否为空
bool QueueEmpty(Queue q)
{
    if(q.front == q.rear) return true;
    return false;
}

//入队
//采用尾插法
void EnQueue(Queue &q, BiTree num)
{
    LinkNode *ptr = (LinkNode *)malloc(sizeof(LinkNode));
    ptr->data = num;
    ptr->next = q.rear->next; //等价于ptr->next = NULL
    q.rear->next = ptr;
    q.rear = ptr;
}

//出队
bool DeQueue(Queue &q, BiTree &num)
{
    if(QueueEmpty(q)) return false;
    LinkNode *ptr = q.front->next;
    num = ptr->data;
    q.front->next = ptr->next;

    if(q.rear == ptr)      //当队列除了头节点以外的唯一节点时
        q.rear = q.front;  //防止把这个节点释放后rear指向空、无法
                           //判断队列为空的情况

    free(ptr); //需要把队头释放
    return true;
}

//层次遍历
void LevelOrder(BiTree T)
{
    BiTree ptr = T;
    Queue q;
    InitQueue(q);
    EnQueue(q, ptr);

    while(!QueueEmpty(q))
    {
        DeQueue(q, ptr);
        printf("%c", ptr->data);
        if(ptr->lchild != NULL)
            EnQueue(q, ptr->lchild);
        if(ptr->rchild != NULL)
            EnQueue(q, ptr->rchild);
    }

}


