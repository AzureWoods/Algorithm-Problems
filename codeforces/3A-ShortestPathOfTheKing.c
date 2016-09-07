#include <stdio.h>
#include <math.h>
int main()
{
	char stPos[3];
	char endPos[3];
	char First[3];
	char Next[2];
	int x,y;
	int min,max;
	scanf("%s",&stPos);
	scanf("%s",&endPos);
	x=endPos[0]-stPos[0];
	y=endPos[1]-stPos[1];
	min=(abs(x)>abs(y))?abs(y):abs(x);
	max=(abs(x)>abs(y))?abs(x):abs(y);
	printf("%d\n",max);
	if(x<0)
	{
		First[0]='L';
		if(abs(x)>abs(y))
			Next[0]='L';
	}
	else {
		First[0]='R';
		if(abs(x)>abs(y))
			Next[0]='R';
	}
	if(y<0)
	{
		First[1]='D';
		if(abs(y)>abs(x))
			Next[0]='D';
	}
	else {
		First[1]='U';
		if(abs(y)>abs(x))
			Next[0]='U';
	}
	First[2]=Next[1]='\0';
	int i;
	for(i=0;i<min;i++)
		printf("%s\n",First);
	for(i=0;i<max-min;i++)
		printf("%s\n",Next);
	return 0;
}
