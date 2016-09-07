#include <bits/stdc++.h>
using namespace std;
vector<int> M[100005];
int num[100005];
double Exp[100005];
void calNum(int node)
{
	num[node]=1;
	if(M[node].empty())
		return ;
	else {
		for(unsigned int it=0; it<M[node].size(); it++)
		{
			calNum(M[node][it]);
			num[node]+=num[M[node][it]];
		}
	}
}
void dfs(int node)
{
	if(M[node].empty())
		return ;
	else {
		double sum=0;
		// double ans=0;
		for(unsigned int it=0; it<M[node].size(); it++)
			sum+=num[M[node][it]];
		// for(unsigned int it=M[node].size()-1; it>=1; it--)
		// 	ans = ans + 1/((double)it);
		for(unsigned int it=0; it<M[node].size(); it++)
		{
			double tmp;
			double ans = (double)M[node].size();
			tmp = sum-num[M[node][it]];
			tmp = (ans==1)?0:tmp/2;
			Exp[M[node][it]]=Exp[node]+tmp+1;
			dfs(M[node][it]);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		M[x].push_back(i);
	}
	calNum(1);
	Exp[1]=1;
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%.6lf ",Exp[i]);
	return 0;
}
