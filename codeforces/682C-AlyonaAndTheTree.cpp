#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct _Node
{
	ll edgeValue;
	int c;
	struct _Node* next;
}Node;
Node* child[100005];
ll nodeValue[100005];
int n;
int bfs(int node, ll max)
{
	int queue[100005];
	ll Max[100005];
	int curNode;
	int curMax;
	Node* p;
	int sum=0;
	int head=0;
	int tail=0;
	queue[head]=node;
	Max[head]=max;
	tail++;
	while(head!=tail)
	{
		curNode=queue[head];
		curMax=Max[head++];
		p=child[curNode];
		if(curMax<nodeValue[curNode] || curNode==1)
		{
			sum++;
			for(;p!=NULL;p=p->next)
			{
				queue[tail]=p->c;
				Max[tail]=(curMax<0)?p->edgeValue:p->edgeValue+curMax;
				tail++;
			}
		}
	}
	return sum;
}
int main()
{
	Node* p;
	Node* q;
	int father;
	ll edgeV;
	int maxNum;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>nodeValue[i];
	for(int i=2;i<=n;i++)
	{
		cin>>father>>edgeV;
		p=child[father];
		q=(Node*)malloc(sizeof(Node));
		q->c=i;
		q->next=NULL;
		q->edgeValue=edgeV;
		if(p==NULL)
		{
			child[father]=q;
		}
		else {
			while(p->next!=NULL)
				p=p->next;
			p->next=q;
		}
	}
	maxNum=bfs(1,0);
	cout<<(n-maxNum);
	return 0;
}
