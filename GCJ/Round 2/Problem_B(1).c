#include <stdio.h>
int T;
double P[20];
double queue[20];
int n,k;
int choose[20];
double p;
void calPosibility(int step,int st)
{
	double temp;
	int i;
	if(step==k/2)
	{
		temp=1;
		for(i=0;i<k;i++)
		{
			if(choose[i])
				temp*=queue[i];
			else temp=temp*(1.0-queue[i]);
		}
		p+=temp;
	}
	else {
		for(i=st;i<k;i++)
		{
			if(choose[i])
				continue;
			choose[i]=1;
			calPosibility(step+1,i+1);
			choose[i]=0;
		}
	}
}
int main()
{
	int i,j,l;
	int max;
	double temp;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d",&n,&k);
		for(j=0;j<n;j++)
			scanf("%lf",&P[j]);
		for(j=0;j<n;j++)
			choose[j]=0;
		for(j=0;j<n-1;j++)
		{
			max=j;
			for(l=j+1;l<n;l++)
			{
				if(P[l]>P[max])
					max=l;
			}
			temp=P[max];
			P[max]=P[j];
			P[j]=temp;
		}
		for(j=0;j<k/2;j++)
			queue[j]=P[j];
		for(j=n-1;j>=n-k/2;j--)
			queue[k/2+n-j-1]=P[j];
		p=0;
		calPosibility(0,0);
		printf("Case #%d: %.6lf\n",i+1,p);
	}
	return 0;
}
