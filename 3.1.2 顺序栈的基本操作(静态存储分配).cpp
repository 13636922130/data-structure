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
    if(s.top == MAXSIZE-1) return false; //�ж�ջ�ǲ�������
    s.top++;
    s.data[s.top] = num;
    return true;
}

//��ջ
bool Pop(SqStack &s, int &num)
{
    if(StackEmpty(s))
        return false;
    num = s.data[s.top--];
}

//��ȡջ��Ԫ��
bool GetTop(SqStack s, int &num)
{
    if(StackEmpty(s))  return false;
    num = s.data[s.top];
	return true;
}

int main()
{
    SqStack s;
    InitStack(s);
    Push(s, 3);
    Push(s, 2);
    Push(s, 1);
    int num;
    Pop(s, num);
    printf("%d\n", num);
    GetTop(s, num);
    printf("%d\n", num);
    GetTop(s, num);
    printf("%d\n", num);
    Pop(s, num);
    printf("%d\n", num);
    Pop(s, num);
    printf("%d\n", num);
}

