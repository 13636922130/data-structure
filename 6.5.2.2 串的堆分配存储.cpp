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
    while(ch[len])
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

//串比较操作
int StrCompare(HString s1, HString s2)
{
    for(int i=0;i<s1.length&&i<s2.length;i++) //取s1 s2中长度的最小值
    {
        if(s1.data[i] < s2.data[i])
            return -1;
        else if(s1.data[i] > s2.data[i])
            return 1;
    }
    if(s1.length == s2.length) return 0;
    return (s1.length>s2.length?1:-1);
}

//求串长
int StrLength(HString s)
{
    return s.length;
}

//清空串操作
void ClearStr(HString &s)
{
    free(s.data);
    s.length = 0;
    s.data = NULL;
}

//串拼接操作
void StrCat(HString &s, HString s1, HString s2)
{
    int len = s1.length + s2.length;
    int i;
    s.data = (char *)malloc(len*sizeof(char));
    s.length = len;
    for(i=0;i<s1.length;i++)
        s.data[i] = s1.data[i];
    for(int j=0;j<s2.length;j++)
        s.data[i++] = s2.data[j];
}

//获取子串
bool SubString(HString s, HString &sub, int pos, int l)
{
    //pos为逻辑上的索引
    if( pos<1 || pos>s.length || l < 0 || (pos+l)>s.length + 1)
        return false;
    if(sub.data) free(sub.data);
    sub.data = (char *)malloc(l*sizeof(char));
    int len = 0;
    for(int i=0;i<l;i++)
        sub.data[len++] = s.data[pos-1+i];
    sub.length = len;
    return true;
}

//输出串操作
void PrintString(HString s)
{
    for(int i=0;i<s.length;i++)
        printf("%c", s.data[i]);
    printf("\n");
}

//获取s从第pos个位置开始后与sub相等的子串的逻辑索引
int Index(HString s, HString sub, int pos)
{
    if(sub.length > s.length || pos > (s.length-sub.length+1) || pos < 1)
        return 0;
    while(pos<=s.length-sub.length+1)
    {
        HString temp;
        SubString(s, temp, pos, sub.length);
        if(StrCompare(temp, sub) == 0)
            return pos;
        else pos++;
    }
    return 0;

}


int main()
{
    HString s1, s2;
    StrAssign(s1, "Hello, world");
    StrAssign(s2, "world");
    printf("%d\n", Index(s1, s2, 9));

}
