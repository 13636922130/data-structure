#include<cstdio>
#include<malloc.h>

//链式队列节点
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}LinkNode;

//链式队列
typedef struct
{
    LinkNode *front, *rear;
}Queue;

/*
    链式队列大概的结构如下：

    头->1->2->3->4->NULL
    ︿           ︿
    |            |
    front       rear

    front始终在头节点,通过获取下个节点的值来出队

    这是一直往队列push 1, 2, 3 ,4的情况
*/


//初始化
void InitQueue(Queue &q)
{
    q.front = (LinkNode *)malloc(sizeof(LinkNode));
    q.rear = q.front;
    q.front->next = NULL; //
}

//判断队列是否为空
bool QueueEmpty(Queue q)
{
    if(q.front == q.rear) return true;
    return false;
}

//入队
//采用尾插法
void EnQueue(Queue &q, int num)
{
    LinkNode *ptr = (LinkNode *)malloc(sizeof(LinkNode));
    ptr->data = num;
    ptr->next = q.rear->next; //等价于ptr->next = NULL
    q.rear->next = ptr;
    q.rear = ptr;
}

//出队
bool DeQueue(Queue &q, int &num)
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

int main()
{
    int num;
    Queue q;
    InitQueue(q);
    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
}
