#include <stdio.h>
int n,k;
double P[20];
int mark[20]={0};
double queue[20];
double max;
double p;
int choose[20]={0};
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
void SearchK(int step)
{
	int i;
	if(step==k)
	{
		p=0;
		calPosibility(0,0);
		if(p>max)
			max=p;
	}
	else {
		for(i=0;i<n;i++)
		{
			if(mark[i])
				continue;
			queue[step]=P[i];
			mark[i]=1;
			SearchK(step+1);
			mark[i]=0;
		}
	}
}
int main()
{
	int T;
	int i,j;
	freopen("b.in","r",stdin);
	freopen("b1.out","w",stdout);
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d",&n,&k);
		for(j=0;j<n;j++)
			scanf("%lf",&P[j]);
		max=-1;
		for(j=0;j<n;j++)
			mark[j]=choose[j]=0;
		SearchK(0);
		printf("Case #%d: %.6lf\n",i+1,max);
	}
	return 0;
}
