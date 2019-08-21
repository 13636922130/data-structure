#include<cstdio>
#include<malloc.h>

typedef struct BiNode
{
    char data; //数据域
    struct BiNode *lchild, *rchild; //指针域
}BiNode, *BiTree;


/***************函数声明***************/
//按先序序列建立二叉链表
void CreateBiTree(BiTree &T);
//先序遍历
//时间复杂度O(n)
void PreOrder(BiTree T);
//中序遍历
//时间复杂度O(n)
void InOrder(BiTree T);
//后序遍历
//时间复杂度O(n)
void PostOrder(BiTree T);
/**************************************/

int main()
{
    BiTree T;
    CreateBiTree(T);
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");

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

//先序遍历
//时间复杂度O(n)
void PreOrder(BiTree T)
{
     if(T != NULL)
     {
         printf("%c", T->data);
         PreOrder(T->lchild);
         PreOrder(T->rchild);
     }
}

//中序遍历
//时间复杂度O(n)
void InOrder(BiTree T)
{
    if(T != NULL)
    {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}

//后序遍历
//时间复杂度O(n)
void PostOrder(BiTree T)
{
    if(T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}
