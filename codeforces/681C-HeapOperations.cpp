#include <bits/stdc++.h>
using namespace std;
int heap[1000000]={0};
int num=0;
char Op[500001][11];
int opV[500001];
void swap(int x,int y)
{
	int tmp;
	tmp=heap[x];
	heap[x]=heap[y];
	heap[y]=tmp;
}
void upAdjust(int k)
{
	int p;
	p=(k-1)/2;
	while(heap[k]<heap[p] && k>0)
	{
		swap(k,p);
		k=p;
		p=(k-1)/2;
	}
}
void downAdjust(int k,int n)
{
	int l,r;
	int min;
	l=k*2+1;
	r=l+1;
	min=(r>n)?l:(heap[l]<heap[r])?l:r;
	while(heap[min]<heap[k] && min<=n)
	{
		swap(min,k);
		k=min;
		l=k*2+1;
		r=l+1;
		min=(r>n)?l:(heap[l]<heap[r])?l:r;
	}
}
void insert(int element)
{
	heap[num++]=element;
	upAdjust(num-1);
}
void deleteMin()
{
	swap(0,num-1);
	num--;
	downAdjust(0,num-1);
}
int isEmpty()
{
	return (num==0)?1:0;
}
int main()
{
	int n;
	char op[20];
	int x;
	int min;
	int totOp=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>op;
		if(op[0]!='r')
			cin>>x;
		if(op[0]=='i')
		{
			insert(x);
			strcpy(Op[totOp],op);
			opV[totOp]=x;
			totOp++;
		}
		else if(op[0]=='g')
		{
			while(heap[0]<x && !isEmpty())
			{
				deleteMin();
				strcpy(Op[totOp],"removeMin");
				totOp++;
			}
			if(heap[0]!=x || isEmpty())
			{
				insert(x);
				strcpy(Op[totOp],"insert");
				opV[totOp]=x;
				totOp++;
			}
			strcpy(Op[totOp],"getMin");
			opV[totOp]=x;
			totOp++;
		}
		else {
			if(isEmpty())
			{
				insert(0);
				strcpy(Op[totOp],"insert");
				opV[totOp]=0;
				totOp++;	
			}
			deleteMin();
			strcpy(Op[totOp],op);
			totOp++;
		}
	}
	cout<<totOp<<endl;
	for(int i=0;i<totOp;i++)
	{
		if(Op[i][0]!='r')
		{
			cout<<Op[i]<<" "<<opV[i]<<endl;
		}
		else cout<<Op[i]<<endl;
	}
	return 0;
}