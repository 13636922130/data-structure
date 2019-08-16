#include<cstdio>
#include<malloc.h>
#define MAXSIZE 4

typedef struct
{
    int data[MAXSIZE];
    int front, rear;
    //frontָ���ͷԪ��
    //rearָ���βԪ�ص���һ��λ��
}Queue;

//���еĳ�ʼ��
void InitQueue(Queue &q)
{
    q.front = q.rear = 0;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue q)
{
    if(q.front == q.rear) return true;
    return false;
}

//�ж϶����Ƿ�Ϊ��
//����һ����λ�����ֶӿջ��Ƕ��������
bool QueueFull(Queue q)
{
    //��MAXSIZEȡ����Է�ֹfront��rear�ֱ���0��������
    if((q.rear+1)%MAXSIZE == q.front)
        return true;
    return false;
}

//����������Ԫ�صĳ���
int QueueLength(Queue q)
{
    //���Է�ֹѭ����rear��ֵС��front�����
    int num = (q.rear-q.front+MAXSIZE)%MAXSIZE;
    return num;
}

//������
bool EnQueue(Queue &q, int num)
{
    if(QueueFull(q)) return false;
    q.data[q.rear] = num;
    q.rear = (q.rear+1) % MAXSIZE; //��βָ��ǰ����ʱ��һ��Ҫȡ��
    return true;                   //���ܴﵽѭ����Ч��
}

//������
bool DeQueue(Queue &q, int &num)
{
    if(QueueEmpty(q)) return false;
    num = q.data[q.front];
    q.front = (q.front+1)%MAXSIZE;
    return true;
}

//��ȡ��ͷԪ��
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
