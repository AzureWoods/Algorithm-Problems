#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node
{
public:
	int left;
	int right;
	ll sum;
	ll add;
};
int num[200005];
int pos[200005];
Node seg_Tree[800005];
void init(int index,int l, int r)
{
	seg_Tree[index].left=l;
	seg_Tree[index].right=r;
	if(l==r)
	{
		seg_Tree[index].sum=num[l];
		seg_Tree[index].add=0;
		pos[l]=index;
		return ;
	}
	init(index << 1, l, (l+r) >> 1);
	init((index << 1)+1, ((l+r) >> 1)+1, r);
	seg_Tree[index].sum=seg_Tree[index << 1].sum+seg_Tree[(index << 1)+1].sum;
	seg_Tree[index].add=0;
}
ll Output(int index, int a, int b, int l, int r)
{
	if(a==l && b==r)
		return seg_Tree[index].sum+seg_Tree[index].add*(b-a+1);
	int mid=(l+r) >> 1;
	if(b<=mid)
		return Output(index << 1, a, b, l, mid)+seg_Tree[index].add*(b-a+1);
	else if(a>mid)
		return Output((index << 1)+1, a, b, mid+1, r)+seg_Tree[index].add*(b-a+1);
	else return Output(index << 1, a, mid, l, mid)+Output((index << 1)+1, mid+1, b, mid+1, r)+seg_Tree[index].add*(b-a+1);
}
void Add(int index, int a, int b, int l, int r,int value)
{
	if(a==l && b==r)
	{
		seg_Tree[index].add+=value;
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
		cin>>op;
		switch(op)
		{
			case 1:
				cin>>a>>b>>x;
				Add(1,a,b,1,n,x);
				break;
			default:
				cin>>a>>b;
				cout<<Output(1,a,b,1,n)<<endl;
		}
	}
	return 0;
}
