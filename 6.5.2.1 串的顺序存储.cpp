#include<cstdio>
#include<malloc.h>
#define MAXSIZE 16

typedef struct
{
    char data[MAXSIZE];
    int length;
}SString;

//赋值操作
void StrAssign(SString &s, const char *ch)
{
    int len = 0;
    while(ch[len] != '\0')
        len++;
    s.length = len;
    //printf("length: %d\n", len);
    for(int i=0;i<len;i++) s.data[i] = ch[i];
}

//串拼接
void Concat(SString &s, SString s1, SString s2)
{
    int i=0, j=0;
    if(s1.length+s2.length >= MAXSIZE)
    {
        for(i=0;i<s1.length;i++)
            s.data[i] = s1.data[i];
        for(;i<MAXSIZE;i++)
            s.data[i] = s2.data[j++];
        s.length = MAXSIZE; //记得要改变拼接后的长度
    }
    else
    {
        for(i=0;i<s1.length;i++)
            s.data[i] = s1.data[i];
        for(j=0;j<s2.length;j++)
            s.data[i++] = s2.data[j];
        s.length = s1.length + s2.length;
    }
}

//获取子串
bool SubString(SString s, SString &sub, int pos, int l)
{
    if( pos<1 || pos>s.length || l < 0 || (pos+l)>s.length + 1)
        return false;
    int len = 0;
    for(int i=0;i<l;i++)
        sub.data[len++] = s.data[pos-1+i];
    sub.length = len;
    return true;
}

void PrintString(SString s)
{
    for(int i=0;i<s.length;i++)
        printf("%c", s.data[i]);
    printf("\n");
}

int main()
{
    SString s, s1;
    StrAssign(s, "What the fuck");
    if(!SubString(s, s1, 2, 3))
       printf("Error!\n");
    else
    PrintString(s1);
}
