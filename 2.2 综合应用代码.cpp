/*********************** 1 ***********************/
int DeleteMin(SqList &L)
{
    if(L.length == 0)
    {
        printf("List empty!\n");
        exit(1);
    }

    int min_index = 0;
    for(int i=1;i<L.length;i++)
    {
        if(L.data[i] < L.data[min_index])
            min_index = i;
    }
    L.data[min_index] = L.data[L.length-1];
    L.length--;
    return L.data[min_index];
}

/*********************** 2 ***********************/
void Reverse(SqList &L)
{
    int len = L.length;
    int temp;
    for(int i=0;i<=len/2-1;i++)
    {
        temp = L.data[len-1-i];
        L.data[len-1-i] = L.data[i];
        L.data[i] = temp;
    }
}

/*********************** 3 ***********************/
void DeleteVal(SqList &L, int value)
{
    int index = 0;
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i] != value)
            L.data[index++] = L.data[i];
    }
    L.length = index;
}

/*********************** 4 ***********************/
//降序也能删除
void DeleteRegion(SqList &L, int s, int t)
{
    int index=-1, len=0;
    if(L.length==0 || s>=t)
    {
        printf("Error!");
        exit(1);
    }

    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]>=s && index==-1 && L.data[i]<=t)
            index=i;
        if(index!=-1 && L.data[i]>=s && L.data[i]<=t)
            len++;
    }
    for(int i=index;i<index+len;i++)
    {
        if (i+len>L.length-1) break;
        L.data[i] = L.data[i+len];
    }
    L.length -= len;
}

/*********************** 5 ***********************/
void DeleteRegion(SqList &L, int s, int t)
{
    int len=0;
    if(L.length==0 || s>=t)
    {
        printf("Error!");
        exit(1);
    }

    for(int i=0;i<L.length;i++) //从前往后
    {
        if(L.data[i]>=s && L.data[i]<=t)
            len++; //len值会一直保留
        else
        {
            if(len!=0)
                L.data[i-len] = L.data[i];
        }
    }
    L.length -= len;
}

/*********************** 6 ***********************/
void DeleteRepeat(SqList &L)
{
    int last=L.data[0];
    int len = 0;
    for(int i=1;i<L.length;i++)
    {
        if(L.data[i] == last)
            len++;
        else
        {
            last = L.data[i];
            L.data[i-len] = L.data[i];
        }
    }
    L.length -= len;
}

/*********************** 7 ***********************/
void MergeOrder(SqList L1, SqList L2, SqList &L3)
{
    int i=0, j=0, k=0;
    while(i<L1.length && j<L2.length)
    {
        if(L1.data[i] < L2.data[j])
            L3.data[k++] = L1.data[i++];
        else
            L3.data[k++] = L2.data[j++];
    }

    for(;i<L1.length;i++)
        L3.data[k++] = L1.data[i];
    for(;j<L2.length;j++)
        L3.data[k++] = L2.data[j];
    L3.length = k; //记得添加长度
}

/*********************** 9 ***********************/
void Test9(SqList &L, int value)
{
    int left = 0, right = L.length-1;
    while(left<=right) //需要等于
    {
        int middle = (left+right)/2;
        if(L.data[middle]>value)
            right = middle - 1; //减一
        else if(L.data[middle]<value)
            left = middle + 1; //减一
        else if(L.data[middle] == value)
        {
            int temp = L.data[middle];
            L.data[middle] = L.data[middle+1];
            L.data[middle+1] = temp;
            break;
        }
    }

    //这部分可以利用前面的left来插入
    //不用再写循环增加复杂度
    if(left > right)
    {
        for(int i=L.length;i>left;i--)
            L.data[i] = L.data[i-1];
        L.data[left] = value;
        L.length++;
    }
}

/*********************** 10 ***********************/
//函数反转
void Reverse(int *a, int s, int t) //s t是逻辑上的索引
{
    int temp;
    for(int i=0;i<=(t-s)/2;i++) 
    {
        temp = a[s+i-1];
        a[s+i-1] = a[t-1-i];
        a[t-1-i] = temp;
    }
}

//循环左移
//O(n)
void LeftShift(int *a, int n, int p)
{
    Reverse(a, 1, n); //O((n-1)/2)
    Reverse(a, 1, n-p); //O((n-p-1)/2)
    Reverse(a, n-p+1, n); //O((p-1)/2)
}

/*********************** 11 ***********************/
int FindMid(int *a, int *b, int n)
{
    //分别表示s1 s2的开头和结尾
    int s1 = 0, t1 = n-1;
    int s2 = 0, t2 = n-1;
    while(s1 != t1 || s2 != t2) //一直循环 直到两边都只剩长度1
    {
        int m1 = (s1+t1)/2;
        int m2 = (s2+t2)/2;
        if(a[m1] < b[m2]) 
        {
            /*
            如果a的中位数小于b的中位数,说明a+b的中位数在a~b之间
            那需要去掉a中位数左边的部分 取掉b中位数右边的部分
            */
            if((t1-s1)%2 == 1) //数组的长度为偶数
            {
                s1 = m1 + 1; // 加一可以防止当只有两个元素是陷入死循环
                t2 = m2;
            }
            else //奇数个长度
            {
                s1 = m1;
                t2 = m2;
            }
        }
        else if(a[m1] > b[m2])
        {
            /*
            如果a的中位数大于b的中位数,说明a+b的中位数在b~a之间
            那需要去掉a中位数右边的部分 取掉b中位数左边的部分
            */
            if((t1-s1)%2 == 1) //偶数个长度
            {
                t1 = m1;
                s2 = m2 + 1;
            }
            else //奇数个长度
            {
                t1 = m1;
                s2 = m2;
            }
        }
        else //如果a, b的中位数相等 a+b的中位数也是这个
            return a[m1]; 
    }
    return (a[s1]<b[s2]?a[s1]:b[s2]); //去a, b中小的那个中位数就是a+b的中位数
}

/*********************** 13 ***********************/
int FindMin(int *a, int n)
{
    int *b = (int *)malloc(n*sizeof(n));
    memset(b, 0, sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        if(a[i] > 0)
            b[a[i]] = 1;
    }
    for(int i=1;i<n;i++)
    {
        if(!b[i]) return i;
    }
}