#include<cstdio>
#include<malloc.h>
#define MAXSIZE 50

typedef struct
{
    int data[MAXSIZE];
    int front, rear;
}Queue;

//队列的初始化
void InitQueue(Queue &q)
{
    q.front = q.rear = 0;
}

//判断队列是否为空
bool QueueEmpty(Queue q)
{
    if(q.front == q.rear) return true;
    return false;
}

//判断队列是否为满
bool QueueFull(Queue q)
{
    if(q.rear == MAXSIZE) return true;
    return false;
}

//进队列
bool EnQueue(Queue &q, int num)
{
    if(QueueFull(q)) return false;
    q.data[q.rear++] = num;
    return true;
}

//出队列
bool DeQueue(Queue &q, int &num)
{
    if(QueueEmpty(q)) return false;
    num = q.data[q.front++];
    return true;
}

//获取队头元素
bool GetHead(Queue q, int &num)
{
    if(QueueEmpty(q)) return false;
    num = q.data[q.front];
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
    DeQueue(q, num);
    printf("%d\n", num);
    GetHead(q, num);
    printf("%d\n", num);
    DeQueue(q, num);
    printf("%d\n", num);
    DeQueue(q, num);
    printf("%d\n", num);

}
