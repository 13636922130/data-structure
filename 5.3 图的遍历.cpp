bool vis[MAXVERTEXNUM];
Queue Q;
//BFS
//空间复杂度O(|v|)
//邻接矩阵时间复杂度O(v^2)
//邻接表时间复杂度O(|v|+|E|)
void BFSTraverse(Graph G)
{
    for(int i=0;i<G.vexnum;i++)
        vis[i] = false; //标记数组初始化
    InitQueue(Q); //初始化队列
    for(int i=0;i<G.vexnum;i++) //遍历所有顶点
    {
        if(!vis[i]) //如果还未被标记，从该点开始BFS搜索
            BFS(G, i);
    }
}
void BFS(Graph G, int v)
{
    visit(v); //对该顶点的操作
    vis[v] = true; //标志位置为true
    EnQueue(Q, v); //把该顶点入队
    while(!isEmpty(Q))
    {
        DeQueue(Q, v); //出队顶点到v
        for(int w=FirstNeighbor(G, v);w>=0;w=NextNeighbor(G, v, w)) //找出顶点v的所有邻近顶点
        {
            if(!vis[w]) //如果未被访问过
            {
                visit(w);
                vis[w] = true; //标志位置为true
                EnQueue(Q, w); //把该顶点入队
            }
        }
    }
}

//DFS
//空间复杂度O(|V|);
//邻接矩阵时间复杂度O(v^2)
//邻接表时间复杂度O(|v|+|E|)
void DFSTraverse(Graph G)
{
    for(int i=0;i<G.vexnum;i++)
        vis[i] = false; //标志位初始化
    for(int i=0;i<G.vexnum;i++) //遍历所有顶点
    {
        if(!vis[i]) //如果还未被标记，从该点开始DFS搜索
            DFS(G, i);
    }
}
void DFS(Graph G, int v)
{
    visit(v);
    vis[v] = true; //标志位置为true
    for(int w=FirstNeighbor(G, v);w>=0;w=NextNeighbor(G, v, w)) //遍历顶点v所有的邻接顶点
    {
        if(!vis[w]) //如果该顶点未被标志 以该点进入DFS
            DFS(G, w);
    }
}
