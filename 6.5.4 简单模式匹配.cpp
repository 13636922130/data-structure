#include<cstdio>
#define MAXSIZE 50

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

//简单的模式匹配
//最坏的情况下时间复杂度为O(s.length*sub.length)
int Index(SString s, SString sub, int pos)
{
    if(sub.length > s.length || pos < 1 || pos > (s.length - sub.length + 1))
        return 0;
    for(int i=pos-1;i<=s.length-sub.length;i++)
    {
        int cur = i;
        for(int j=0;j<sub.length;j++)
        {
            if(sub.data[j] == s.data[cur])
                cur++;
            else
                break;
        }
        if(cur == (i + sub.length)) return i+1;
        else continue;
    }
    return 0;
}

int main()
{
    SString s1, s2;
    StrAssign(s1, "ababcabcacbab");
    StrAssign(s2, "abcac");
    printf("%d\n", Index(s1, s2, 1));
}
