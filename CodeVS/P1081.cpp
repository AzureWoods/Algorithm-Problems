#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node
{
public:
	int left;
	int right;
	ll sum;
};
int num[100005];
int pos[100005];
Node seg_Tree[400005];
void init(int index,int l, int r)
{
	seg_Tree[index].left=l;
	seg_Tree[index].right=r;
	if(l==r)
	{
		seg_Tree[index].sum=num[l];
		pos[l]=index;
		return ;
	}
	init(index << 1, l, (l+r) >> 1);
	init((index << 1)+1, ((l+r) >> 1)+1, r);
	seg_Tree[index].sum=0;
}
ll Output(int x)
{
	if(x==0)
		return 0;
	return Output(x >> 1)+seg_Tree[x].sum;
}
void Add(int index, int a, int b, int l, int r,int value)
{
	if(a==l && b==r)
	{
		seg_Tree[index].sum+=value;
		return ;
	}
	int mid=(l+r) >> 1;
	if(b<=mid)
		Add(index << 1, a, b, l, mid, value);
	else if(a>mid)
		Add((index << 1)+1, a, b, mid+1, r, value);
	else 
		{
			Add(index << 1, a, mid, l, mid, value);
			Add((index << 1)+1, mid+1, b, mid+1, r, value);
		}
}
int main()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	init(1,1,n);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int op;
		int x,a,b;
		int index;
		cin>>op;
		switch(op)
		{
			case 1:
				cin>>a>>b>>x;
				Add(1,a,b,1,n,x);
				break;
			default:
				cin>>index;
				cout<<Output(pos[index])<<endl;
		}
	}
	return 0;
}
