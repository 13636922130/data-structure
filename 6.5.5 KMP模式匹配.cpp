#include<cstdio>
#include<malloc.h>
#define MAXSIZE 50

/*
    关于KMP粗略的了解可以参考:
    https://blog.csdn.net/f1033774377/article/details/82556438
    关于KMP部分匹配值, next数组的计算等细节可以参考:
    https://blog.csdn.net/gao506440410/article/details/81812163

    在这里模式串和文本串统一使用的索引从0开始
*/

typedef struct
{
    char data[MAXSIZE];
    int length;
}SString;

/***************函数声明***************/
//赋值操作
void StrAssign(SString &s, const char *ch);
//输出串
void PrintStr(SString s);
//获得匹配串的next数组
void GetNext(SString s, int next[]);
//kmp模式匹配算法
//时间复杂度O(s.length+t.length)
int KMPSearch(SString s, SString t, int pos);
/**************************************/

int main()
{
    SString s, t;
    StrAssign(s, "bbc abcdab abcdabcdabde");
    StrAssign(t, "abcdabd");
    int index = KMPSearch(s, t, 17);
    if(index == -1)
        printf("Not Found!\n");
    else
    {
        PrintStr(s);
        for(int i=0;i<index-1;i++) printf(" ");
        PrintStr(t);
        printf("%d\n", index);
    }
}


/***************函数定义***************/
//输出串
void PrintStr(SString s)
{
    for(int i=0;i<s.length;i++)
        printf("%c", s.data[i]);
    printf("\n");
}

//赋值操作
void StrAssign(SString &s, const char *ch)
{
    int i = 0;
    while(ch[i])
    {
        s.data[i] = ch[i];
        i++;
    }
    s.length = i;
}

//获得next数组
void GetNext(SString s, int *next)
{
    int i=0, k=-1;
    int len = s.length;

    /*
    这里的next数组已经是右移一位
    next[i]表示0~(i-1)位串的部分匹配值
    故第一位的next需要赋值为-1
    */
    next[i] = -1;

    while(i<len) //遍历串的每一个字符，来求得下一位的next值
    {
        /*
        有四种情况会进入该if块中:
        1、程序初始化, 此时next[0] = -1. 则next[1] = 0
        2、s[i] == s[k]情况下, 说明有相同长度的前缀后缀, 则next[i+1] = k+1
        3、程序在递归前缀索引时找到了相同的前缀后缀, 令next[i+1] = k+1
        4、递归到k == -1的情况, 说明实在找不到相同的前缀索引, 令next[i+1] = 0, 即next[i+1] = k+1
        */
        if(k == -1 || s.data[i] == s.data[k])
        {
            k++;
            i++;
            next[i] = k;
        }
        /*
        如果s[i] != s[k], 说明没有找到相同的前缀后缀,
        则递归前缀索引去寻找相同的前缀后缀
        */
        else
            k = next[k];
    }
}

//kmp模式匹配算法
int KMPSearch(SString s, SString t, int pos)
{
    int tLen = t.length;
    int sLen = s.length;
    if(tLen > sLen || pos < 1 || pos > (sLen - tLen + 1))
        return -1;

    int i = pos-1, j = 0; //文本串和模式串的索引
    int *next = (int *)malloc(tLen*sizeof(int)); //next数组

    //获取匹配串的next数组
    GetNext(t, next);

    while(i<sLen && j<tLen) //如果匹配成功时j == tLen会跳出循环
    {
         /*
         如果字符匹配成功, 继续匹配下一个字符
         如果j==-1 说明模式串没有找到位置去跳跃,
         那么j回到模式串的开头, 从文本串的下一个字符重新开始匹配
         */
         if(j == -1 || s.data[i] == t.data[j])
         {
             i++;
             j++;
         }
         else
             j = next[j];
    }

    if(j == tLen)
        return (i-j)+1;
    else
        return -1;

}
