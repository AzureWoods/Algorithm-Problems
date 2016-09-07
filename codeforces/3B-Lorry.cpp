#include <iostream>
using namespace std;
int capacity_1[100005],capacity_2[100005];
int index_1[100005],index_2[100005];
int len1,len2;
void swap(int x,int y,int* a,int* b)
{
	int tmp_i,tmp_i1;
	tmp_i1=a[x];
	a[x]=a[y];
	a[y]=tmp_i1;
	tmp_i=b[x];
	b[x]=b[y];
	b[y]=tmp_i;
}
void adjustDown(int cur,int n,int* a,int* b)
{
	int rc,lc;
	int min;
	lc=cur*2+1;
	rc=lc+1;
	min=(rc>n || a[lc]<=a[rc])?lc:rc;
	while(min<=n && a[min]<a[cur])
	{
		swap(min,cur,a,b);
		cur=min;
		lc=cur*2+1;
		rc=lc+1;
		min=(rc>n || a[lc]<=a[rc])?lc:rc;
	}
}
void HeapSort(int n,int* a,int* b)
{
	for(int i=(n-1)/2;i>=0;i--)
	{
		adjustDown(i,n,a,b);
	}
	for(int i=n;i>0;i--)
	{
		swap(i,0,a,b);
		adjustDown(0,i-1,a,b);
	}
}
int main()
{
	int n,vol;
	int sum=0;
	int type,capa;
	int v1,v2;
	int head1,head2;
	int end;
	int tmp;
	cin>>n>>vol;
	len1=len2=0;
	for(int i=0;i<n;i++)
	{
		cin>>type>>capa;
		if(type==1)
		{
			capacity_1[len1]=capa;
			index_1[len1++]=i+1;
			
		}
		else {
			capacity_2[len2]=capa;
			index_2[len2++]=i+1;
		}
	}
	HeapSort(len1-1,capacity_1,index_1);
	HeapSort(len2-1,capacity_2,index_2);
	head1=head2=0;
	capacity_1[len1]=0;
	capacity_2[len2]=0;
	while(head1<len1 || head2<len2)
	{
		if(vol==0)break;
		if(vol==1)
		{
			if(len1==0)break;
			tmp=(head1>=len1)?len1:head1;
			if(capacity_2[head2]>capacity_1[tmp]+capacity_1[tmp-1])
			{
				sum=sum-capacity_1[tmp-1]+capacity_2[head2++];
				head1=tmp-1;
			}
			else {
				sum+=capacity_1[head1];
				head1++;
			}
			vol--;
		}
		else {
			v1=(head1<len1)?capacity_1[head1]+capacity_1[head1+1]:0;
			v2=(head2<len2)?capacity_2[head2]:0;
			if(v2>v1)
			{
				sum+=capacity_2[head2++];
				vol-=2;
			}
			else {
				sum=sum+capacity_1[head1]+capacity_1[head1+1];
				if(head1==len1-1)
					vol--;
				else vol-=2;
				head1+=2;
			}
		}
	}
	cout<<sum<<endl;
	if(sum!=0)
	{
	end=(head1>len1)?len1-1:head1-1;
	for(int i=0;i<=end;i++)
		cout<<index_1[i]<<" ";
	end=head2-1;
	for(int i=0;i<=end;i++)
		cout<<index_2[i]<<" ";
}
	return 0;
}
