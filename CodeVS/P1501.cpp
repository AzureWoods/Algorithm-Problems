#include <bits/stdc++.h>
using namespace std;
int L[20],R[20];
int C[100]={0};
void dfs(int node, int step)
{
    if(!node)
        return;
    C[step]++;
    dfs(L[node],step+1);
    dfs(R[node],step+1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>L[i]>>R[i];
    dfs(1,1);
    int sum=0;
    int Max=-1;
    for(int i=1;;i++)
    {
        if(!C[i])
            break;
        sum++;
        if(C[i]>Max)
            Max=C[i];
    }
    cout<<Max<<' '<<sum;
    return 0;
}