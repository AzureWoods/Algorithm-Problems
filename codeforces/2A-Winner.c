#include <stdio.h>
#include <string.h>
typedef struct
{
	char Name[50];
	int Score;
}Player;
int main()
{
	int n;
	int i,j,k;
	int Len=0;
	int flag;
	int max;
	int res;
	char name[1000][50];
	int score[1000];
	int mark[1000]={0};
	Player List[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&name[i]);
		scanf("%d",&score[i]);
		List[i].Score=0;	
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<Len;j++)
		{
			if(strcmp(List[j].Name,name[i])==0)
			{
				flag=1;
				k=j;
				break;
			}
		}
		if(flag)
		{
			List[k].Score+=score[i];
		}
		else {
			strcpy(List[Len].Name,name[i]);
			List[Len].Score=score[i];
			Len++;
		}
	}
	max=List[0].Score;
	for(i=1;i<Len;i++)
	{
		if(List[i].Score>max)
			max=List[i].Score;
	}
	for(i=0;i<Len;i++)
	{
		if(List[i].Score==max)
			mark[i]=1;
		List[i].Score=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<Len;j++)
		{
			if(strcmp(List[j].Name,name[i])==0)
			{
				k=j;
				break;
			}
		}
		List[k].Score+=score[i];
		if(List[k].Score>=max && mark[k]==1)
		{
			res=i;
			break;
		}
	}
	printf("%s",name[res]);
	return 0;
}
