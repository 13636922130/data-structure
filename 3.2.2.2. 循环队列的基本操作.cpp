#include<cstdio>
#include<malloc.h>
#define MAXSIZE 4

typedef struct
{
    int data[MAXSIZE];
    int front, rear;
    //front指向队头元素
    //rear指向队尾元素的下一个位置
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
//牺牲一个单位来区分队空还是队满的情况
bool QueueFull(Queue q)
{
    //对MAXSIZE取余可以防止front和rear分别在0两侧的情况
    if((q.rear+1)%MAXSIZE == q.front)
        return true;
    return false;
}

//队列内数据元素的长度
int QueueLength(Queue q)
{
    //可以防止循环后rear的值小于front的情况
    int num = (q.rear-q.front+MAXSIZE)%MAXSIZE;
    return num;
}

//进队列
bool EnQueue(Queue &q, int num)
{
    if(QueueFull(q)) return false;
    q.data[q.rear] = num;
    q.rear = (q.rear+1) % MAXSIZE; //队尾指针前进的时候一定要取余
    return true;                   //才能达到循环的效果
}

//出队列
bool DeQueue(Queue &q, int &num)
{
    if(QueueEmpty(q)) return false;
    num = q.data[q.front];
    q.front = (q.front+1)%MAXSIZE;
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
    if(!EnQueue(q, 1)) printf("Insert error!\n");
    if(!EnQueue(q, 2)) printf("Insert error!\n");
    if(!EnQueue(q, 3)) printf("Insert error!\n");
    if(QueueFull(q)) printf("Queue Full!\n");
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
    if(!GetHead(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
    if(!EnQueue(q, 4)) printf("Insert error!\n");
    if(!EnQueue(q, 5)) printf("Insert error!\n");
    if(QueueFull(q)) printf("Queue Full!\n");
    if(!EnQueue(q, 6)) printf("Insert error!\n");

}
