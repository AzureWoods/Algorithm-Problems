#include <bits/stdc++.h>
using namespace std;
int Re[10][10];
int color[10][5];
int n;
int sum=0;
void dfs(int step)
{
    if(step>n)
    {
        sum++;
        return ;
    }
    for(int i=0;i<4;i++)
    {
        if(color[step][i])
            continue;
        for(int j=1;j<=n;j++)
        {
            if(Re[step][j])
                color[j][i]++;
        }
        dfs(step+1);
        for(int j=1;j<=n;j++)
        {
            if(Re[step][j])
                color[j][i]--;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>Re[i][j];
    memset(color,0,sizeof(color));
    dfs(1);
    cout<<sum<<endl;
    return 0;
}
