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
void PostOrder1(BiTree T);
//第二种后序遍历方法(非递归)
void PostOrder2(BiTree T);

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
    PostOrder1(T);
    printf("\n");
    printf("PostOrder2:");
    PostOrder2(T);
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

//获取栈顶元素
bool GetTop(Stack *s, BiTree &num)
{
    if(IsEmpty(s)) return false;
    num = s->data;
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
void PostOrder1(BiTree T)
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

/*
第二种后序遍历
    在遍历结点的时候会保存上一个遍历过的结点,
    通过两个结点的关系来执行相应的操作

    因为这个算法不是最后一次性从栈取出来得到正确的后序遍历
    而是在遍历的过程中把先序遍历输出
    所以在遍历的时候还是会按左孩子结点->右孩子结点->双亲结点的顺序来
*/
void PostOrder2(BiTree T)
{
    Stack *s;
    InitStack(s);
    BiTree curr = NULL, pre = NULL, ptr;
    Push(s, T); //先把根节点推入栈中

    while(!IsEmpty(s))
    {
        GetTop(s, curr); //获取栈顶元素 但不弹出栈
        //如果是根结点 或者上一个结点是当前结点的双亲结点
        if(pre == NULL || pre->lchild == curr || pre->rchild == curr)
        {
            //优先把左孩子结点推入栈中 按照后序遍历的次序来
            if(curr->lchild != NULL)
                Push(s, curr->lchild);
            else if(curr->rchild != NULL)
                Push(s, curr->rchild);
        }
        //如果当前结点和上一个结点是一样的
        //说明当前结点已经可以被输出
        else if(curr == pre)
        {
            Pop(s, ptr); //把当前结点从栈弹出
            printf("%c", ptr->data);
        }
        //如果上一个结点是当前结点的左孩子结点
        //说明已经开始回溯了
        //这时候就可以去取他的右孩子结点
        else if(curr->lchild == pre)
        {
            if(curr->rchild != NULL)
                Push(s, curr->rchild); //如果有右孩子结点 推入栈中
        }
        pre = curr;
    }

}






