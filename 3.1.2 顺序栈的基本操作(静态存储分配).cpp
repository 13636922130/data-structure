#include<cstdio>
#define MAXSIZE 50

typedef struct
{
    int data[MAXSIZE];
    int top; //top == -1�����ջ
}SqStack;

//ջ�ĳ�ʼ��
void InitStack(SqStack &s)
{
    s.top = -1;
}

//�ж�ջ�Ƿ��
bool StackEmpty(SqStack s)
{
    if(s.top == -1)
        return true;
    else
        return false;
}

//��ջ
bool Push(SqStack &s, int num)
{
    if(top == MAXSIZE-1) return false; //�ж�ջ�ǲ�������
    s.top++;
    s[s.top] = num;
    return true;
}

//��ջ
bool Pop(SqStack &s)
{
    if(s.top == -1)
        return false;
    else
        s.top--;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack s, int &num)
{
    if(s.top == -1)
        return false;
    num = s.data[s.top];
    return false;
}

void main()
{

}

