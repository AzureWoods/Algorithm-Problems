#include <stdio.h>
int main()
{
	int n;
	int num[5]={0};
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[0]);
		num[num[0]]++;
	}
	num[1]-=(num[1]<num[3])?num[1]:num[3];
	num[0]=(num[1]<2*num[2])?num[1]:2*num[2];
	num[1]-=(num[1]<2*num[2])?num[1]:2*num[2];
	num[0]=(num[0]==0)?0:(num[0]-1)/2+1;
	num[1]=(num[1]==0)?0:(num[1]-1)/4+1;
	num[2]=(num[2]==0)?0:(num[2]+num[0]-1)/2+1;
	printf("%d",num[1]+num[2]+num[3]+num[4]);
	return 0;
}