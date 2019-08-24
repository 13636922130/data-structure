#include<cstdio>
#include<malloc.h>

/*
线索树结构
    ltag == 0: lchild指向左孩子结点
    ltag == 1: lchild指向前驱结点
    rtag == 0: rchild指向右孩子结点
    rtag == 1: rchild指向后继结点
*/
typedef struct ThreadNode
{
    char data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

/***************函数声明***************/

//按先序序列创建二叉树
void CreateThreadTree(ThreadTree &T);
//中序线索化二叉树
void InThread(ThreadTree &p, ThreadTree &pre);
//主过程算法
void CreateInThread(ThreadTree);
//中序序列下的第一个结点
ThreadTree FirstNode(ThreadTree T);
//中序序列下的后继节结点
ThreadTree NextNode(ThreadTree T);
//中序遍历
void InOrder(ThreadTree T);

/**************************************/

int main()
{
    ThreadTree T;
    CreateThreadTree(T);
    CreateInThread(T);
    InOrder(T);

}
/***************函数定义***************/
//按先序序列创建二叉树
void CreateThreadTree(ThreadTree &T)
{
    char ch;
    scanf("%c", &ch);
    if(ch == ' ') T = NULL;
    else
    {
        T = (ThreadTree)malloc(sizeof(ThreadNode));
        T->data = ch;
        CreateThreadTree(T->lchild);
        CreateThreadTree(T->rchild);
    }
}

//中序线索化二叉树
void InThread(ThreadTree &p, ThreadTree &pre)
{
    if(p == NULL) return;
    InThread(p->lchild, pre);
    if(p->lchild == NULL)
    {
        p->lchild = pre;
        p->ltag = 1;
    }
    if(pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = p;
        pre->rtag = 1;
    }
    pre = p;
    InThread(p->rchild, pre);
}

//线索化主程序
void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    InThread(T, pre);
    pre->rchild = NULL;
    pre->rtag = 1;
}

//中序序列下的第一个结点
ThreadTree FirstNode(ThreadTree T)
{
    while(T->ltag == 0) //循环查找最左下结点
        T = T->lchild;
    return T;
}

//中序序列下的后继节结点
ThreadTree NextNode(ThreadTree T)
{
    //此时该结点的右孩子结点不为空
    //有孩子结点不是指向中序序列的下一个结点
    //而是二叉树结构的右孩子结点
    //但是可以寻找右孩子树的开头结点来得到该结点在中序序列的下一个结点
    if(T->rtag == 0) return FirstNode(T->rchild);
    else return T->rchild;
}

//中序遍历
void InOrder(ThreadTree T)
{
    T = FirstNode(T);
    while(T != NULL)
    {
        printf("%c", T->data);
        T = NextNode(T);
    }

}


