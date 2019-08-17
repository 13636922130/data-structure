#include<cstdio>
#include<malloc.h>

typedef struct
{
    char *data;
    int length;
}HString;

//赋值操作
void StrAssign(HString &s, const char *ch)
{
    int len=0;
    while(ch[len] != NULL)
        len++;
    s.data = (char *)malloc(len*sizeof(char));
    s.length = len;
    for(int i=0;i<len;i++)
        s.data[i] = ch[i];
}

//在串s的第pos个字符之前插入串s1
bool StrInsert(HString &s, int pos, HString s1)
{
    int len = s.length + s1.length;
    if(pos<1 || pos>s.length+1) return false;
    s.data = (char *)realloc(s.data, len*sizeof(char)); //重新为s.data分配空间
    s.length = len;

    for(int i=s.length-1;i>=pos-1;i--)
        s.data[s1.length+i] = s.data[i]; //为要插入的值腾出空间
    for(int i=0;i<s1.length;i++)
        s.data[pos-1+i] = s1.data[i];

    return true;
}

void PrintString(HString s)
{
    for(int i=0;i<s.length;i++)
        printf("%c", s.data[i]);
    printf("\n");
}

int main()
{
    HString s, s1;
    StrAssign(s, "Hello, world");
    StrAssign(s1, "the");
    StrInsert(s, 13, s1);
    PrintString(s);
}
