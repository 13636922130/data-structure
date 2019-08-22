#include<cstdio>
#include<malloc.h>

//二叉树结构体
typedef struct BiNode
{
    char data; //数据域
    struct BiNode *lchild, *rchild; //指针域
}BiNode, *BiTree;

//链栈结构体
typedef struct Stack
{
    BiTree data;
    struct Stack *next;
}Stack;


/***************函数声明***************/

//按先序序列建立二叉链表
void CreateBiTree(BiTree &T);
//链栈的初始化
void InitStack(Stack *&L);
//判断栈是否空
bool IsEmpty(Stack *L);
//进栈
bool Push(Stack *&L, BiTree t);
//出栈
bool Pop(Stack *&L, BiTree &t);
//中序遍历(非递归)
void InOrder(BiTree T);
//先序遍历(非递归)
void PreOrder(BiTree T);
//第一种后序遍历方法(非递归)
void PostOrder(BiTree T);

/**************************************/

int main()
{
    BiTree T;
    CreateBiTree(T);
    printf("PreOrder:  ");
    PreOrder(T);
    printf("\n");
    printf("InOrder:   ");
    InOrder(T);
    printf("\n");
    printf("PostOrder1:");
    PostOrder(T);
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
bool Push(Stack *&L, BiTree t)
{
    Stack *node = (Stack *)malloc(sizeof(Stack));
    node->data = t;
    node->next = L;
    L = node;
    return true;
}

//出栈
bool Pop(Stack *&L, BiTree &t)
{
    if(IsEmpty(L)) return false; //栈空
     Stack *ptr = L;
    t = ptr->data;
    L = ptr->next;
    free(ptr);
    return true;
}

//中序遍历(非递归)
void InOrder(BiTree T)
{
    Stack *s;
    InitStack(s);
    BiTree ptr = T;

    while(ptr || !IsEmpty(s)) //当指针和栈都不为空时
    {
        if(ptr) //如果指针不为空 说明指向某个结点
        {
            Push(s, ptr); //把该结点推入栈中
            ptr = ptr->lchild; //寻找该节点的左孩子结点
        }
        else //如果该结点为空
        {
            Pop(s, ptr); //把栈中的结点推出
            printf("%c", ptr->data); //
            ptr = ptr->rchild; //因为左孩子结点已经为空 去寻找右孩子结点
        }
    }
}

//先序遍历(非递归)
void PreOrder(BiTree T)
{
    Stack *s;
    InitStack(s);
    BiTree ptr = T;
    while(ptr || !IsEmpty(s))
    {
        if(ptr)
        {
            printf("%c", ptr->data); //因为是先序 需要先把中间结点输出
            Push(s, ptr); //再把该结点推进栈
            ptr = ptr->lchild; //寻找左孩子结点
        }
        else
        {
            Pop(s, ptr); //从栈取出
            ptr = ptr->rchild; //左孩子结点已经找过了 寻找右孩子结点
        }
    }
}

/*
后序遍历
    依照左孩子结点->右孩子结点->双亲结点的思路,
    可以逆序、按双亲结点->右孩子结点->左孩子结点压入栈

    栈s2用于存储后序遍历的结果
    栈s1负责结点的回溯

    该算法用了两个栈 比较浪费空间
*/

void PostOrder(BiTree T)
{
    Stack *s1, *s2;
    InitStack(s1);
    InitStack(s2);
    BiTree ptr = T;

    while(ptr || !IsEmpty(s1))
    {
        while(ptr) //如果结点存在
        {
            Push(s1, ptr); //把结点同时压入栈s1、s2中
            Push(s2, ptr);
            ptr = ptr->rchild; //再取右孩子结点
        }
        //此时的结点没有右孩子结点
        Pop(s1, ptr); //回溯最后一个压入栈的结点
        ptr = ptr->lchild; //取它的左孩子结点
    }

    while(!IsEmpty(s2)) //栈s2存储后序遍历的结果
    {
        Pop(s2, ptr);
        printf("%c", ptr->data);
    }

}






