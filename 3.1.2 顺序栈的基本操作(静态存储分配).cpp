#include<cstdio>
#define MAXSIZE 50

typedef struct
{
    int data[MAXSIZE];
    int top; //top == -1代表空栈
}SqStack;

//栈的初始化
void InitStack(SqStack &s)
{
    s.top = -1;
}

//判断栈是否空
bool StackEmpty(SqStack s)
{
    if(s.top == -1)
        return true;
    else
        return false;
}

//进栈
bool Push(SqStack &s, int num)
{
    if(top == MAXSIZE-1) return false; //判断栈是不是满了
    s.top++;
    s[s.top] = num;
    return true;
}

//出栈
bool Pop(SqStack &s)
{
    if(s.top == -1)
        return false;
    else
        s.top--;
}

//获取栈顶元素
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

