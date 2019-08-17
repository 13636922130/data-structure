#include<cstdio>
#include<malloc.h>

typedef struct
{
    char *data;
    int length;
}HString;

//��ֵ����
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

//�ڴ�s�ĵ�pos���ַ�֮ǰ���봮s1
bool StrInsert(HString &s, int pos, HString s1)
{
    int len = s.length + s1.length;
    if(pos<1 || pos>s.length+1) return false;
    s.data = (char *)realloc(s.data, len*sizeof(char)); //����Ϊs.data����ռ�
    s.length = len;

    for(int i=s.length-1;i>=pos-1;i--)
        s.data[s1.length+i] = s.data[i]; //ΪҪ�����ֵ�ڳ��ռ�
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
