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

/**************************************/

int main()
{
    ThreadTree T;
    CreateThreadTree(T);
    CreateInThread(T);
    printf("%c", T->lchild->rchild->rchild->rchild->lchild->data);

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
    if(p != NULL)
    {
        InThread(p->lchild, pre); //线索化左子树
        //建立前驱线索
        if(p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        //建立后继线索
        if(pre != NULL && pre->rchild == NULL)
        {
            //此时的pre是传递给InThread后，已经被修改
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre); //线索化右子树
    }
}
//主过程算法
void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if(T != NULL)
    {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}




