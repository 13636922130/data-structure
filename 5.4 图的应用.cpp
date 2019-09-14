/*
考研图的应用很少以算法设计题出现
而是考察算法具体执行过程
具体源代码后期贴上
*/

#include<cstdio>
#define VEXMAX 1000
//无穷大的定义参考 https://blog.csdn.net/mylovestart/article/details/8238088
#define INF 0x3F3F3F3F
int G[VEXMAX][VEXMAX];
int dist[VEXMAX][VEXMAX];
int n;

void show()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j] == INF)
                printf("  -1");
            else
                printf("%4d", dist[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter the number of vertex:");
    scanf("%d", &n);
    printf("Enter the graph(-1 stands for infinite)\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &G[i][j]);
            if(G[i][j] == -1)
                G[i][j] = INF;
            else if(i == j)
                G[i][j] = 0;

            dist[i][j] = G[i][j];
        }
    }

    printf("******dist(-1)******\n");
    show();
    printf("********************\n");
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }

        printf("******dist(%d)******\n", k);
        show();
        printf("********************\n");
    }

}
