#include<cstdio>
#include<malloc.h>

//二叉排序树结构
typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

/***************函数声明***************/
//二叉排序树的查找
BSTree BSTSearch(BSTree T, int value, BSTree &p);
//二叉排序树的插入(递归)
bool BSTInsert(BSTree &T, int value);
//二叉排序树的插入(非递归)
bool BSTInsert_no(BSTree &T, int value);
//二叉排序树的构建
void BSTCreate(BSTree &T, int arr[], int len);
//二叉排序树的的删除
bool BSTDelete(BSTree &T, int value);
//删除结点
bool Delete(BSTree &T);
/**************************************/
int main()
{
    BSTree T=NULL;
    BSTInsert_no(T, 2);
    BSTInsert_no(T, 1);
    BSTInsert_no(T, 3);
    BSTInsert_no(T, 4);
    printf("%d\n", T->rchild->data);
    BSTDelete(T, 3);
    printf("%d\n", T->rchild->data);

}

/***************函数定义***************/
BSTree BSTSearch(BSTree T, int value, BSTree &p)
{
    p = NULL; //p指向被查找结点的双亲结点
    while(T != NULL)
    {
        p = T; //这个要放在前面 放在后面不能获取到双亲结点
        if(T->data > value)
            T = T->lchild;
        else if(T->data < value)
            T = T->rchild;
        else
            return T;
    }
    return T;
}

//二叉排序树的插入
bool BSTInsert(BSTree &T, int value)
{
    if(T == NULL)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->data = value;
        T->lchild = NULL;
        T->rchild = NULL;
        return true;
    }
    if(T->data > value)
        return BSTInsert(T->lchild, value);
    else if(T->data<value)
        return BSTInsert(T->rchild, value);
    else
        return false;

}

//二叉排序树的插入(非递归)
bool BSTInsert_no(BSTree &T, int value)
{
    BSTree pre=NULL, cur=NULL;
    cur = BSTSearch(T, value, pre);
    if(cur == NULL) //说明这个二叉排序树里面没有这个值
    {
        BSTree p = (BSTree)malloc(sizeof(BSTNode));
        p->data = value;
        p->lchild = p->rchild = NULL;

        if(pre == NULL) //说明这个二叉排序树为空
            T = p;
        else //说明树不为空 且找到合适的位置插入
        {
            if(pre->data > value)
                pre->lchild = p;
            else
                pre->rchild = p;
        }
        return true;
    }
    return false;

}

//二叉排序树的构建
void BSTCreate(BSTree &T, int arr[], int len)
{
    int i=0;
    while(i<len)
        BSTInsert(T, arr[i++]);
}

//二叉排序树的的删除
//参考博客https://www.jianshu.com/p/c6cb2c1460d0
bool BSTDelete(BSTree &T, int value)
{
    if(T == NULL) return false;
    if(T->data > value)
        BSTDelete(T->lchild, value);
    else if(T->data < value)
        BSTDelete(T->rchild, value);
    else
        Delete(T);
}

//删除结点
bool Delete(BSTree &T)
{
    BSTree p, pre=NULL;
    if(T->rchild == NULL) //右子树
    {
        p = T;
        T = T->lchild; //把当前的指针, 即双亲结点的孩子结点
                       //变成当前指针的下一个结点
        free(p);
    }
    else if(T->lchild == NULL)
    {
        p = T;
        T = T->rchild;
        free(p);
    }
    else //同时有左子树和右子树
    {
        p = T->lchild;
        while(p->rchild)
        {
            pre = p; //前驱结点的双亲结点
            p = p->rchild; //寻找待删除结点的前驱
        }
        T->data = p->data; //把前驱结点替换到待删除结点

        if(pre == NULL) //说明前驱结点就是待删除结点的左孩子结点
        {
            pre = T->lchild->lchild;
            T->lchild = pre;
        }
        else
            pre->rchild = p->lchild;

        free(p);

    }
    return true;
}
