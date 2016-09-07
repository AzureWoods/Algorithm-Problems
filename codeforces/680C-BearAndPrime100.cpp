#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int Try[20]={2,3,4,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49};
	char Ans[5];
	int sum=0;
	for(int i=0;i<19;i++)
	{
		printf("%d\n",Try[i]);
		fflush(stdout);
		scanf("%s",Ans);
		if(strcmp(Ans,"yes")==0)
			sum++;
	}
	if(sum>=2)
	{
		printf("composite\n");
		fflush(stdout);
	}
	else 
	{
		printf("prime\n");
		fflush(stdout);
	}
	return 0;
}