#include <bits/stdc++.h>
using namespace std;
bool vis[15];
int order[15];
void dfs(int tot, int step)
{
    if(step>tot)
    {
        for(int i=1;i<=tot;i++)
            printf("%d ",order[i]);
        printf("\n");
        return ;
    }
    for(int i=1;i<=tot;i++)
    {
        if(vis[i])
            continue;
        order[step]=i;
        vis[i]=true;
        dfs(tot,step+1);
        vis[i]=false;
    }
}
int main()
{
    int n;
    cin>>n;
    memset(vis,false,sizeof(vis));
    dfs(n,1);
    return 0;
}