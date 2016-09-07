#include <stdio.h>
#include <string.h>
int isAlpha(char);
int isDigit(char);
int main()
{
	int n;
	int i,j;
	int judge;
	int temp;
	int row,col;
	int len;
	int len1;
	int carry;
	int Res;
	char s[20];
	char res[20];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{                                       
		scanf("%s",&s);
		len=strlen(s);
		judge=0;
		for(j=0;j<len;j++)
		{
			if(s[j]<'z' && s[j]>'a')
				s[j]-=32;
		}
		for(j=2;j<len;j++)
			judge|=isAlpha(s[j]);
		if(isAlpha(s[0]) && isDigit(s[1]) && judge)
		{
				temp=0;
				while(s[temp]!='C')temp++;
				col=0;
				for(j=temp+1;j<len;j++)
					col=col*10+s[j]-'0';
				len1=0;
				while(col>0)
				{
					res[++len1]=col%26+'A';
					col/=26;
				}
				carry=0;
				for(j=1;j<=len1;j++)
				{
					Res=carry+res[j]-'A'-1;
					if(Res<0)
						carry=-1;
					else carry=0;
					Res=(Res+26)%26+'A';
					res[j]=Res;
				}
				if(res[len1]=='Z')len1--;
				for(j=len1;j>0;j--)
					printf("%c",res[j]);
				for(j=1;j<temp;j++)
					printf("%c",s[j]);
				printf("\n");
		}
		else {
			temp=0;
			row=col=0;
			while(isAlpha(s[temp]))temp++;
			for(j=0;j<temp;j++)
				col=col*26+s[j]-'A'+1;
			for(j=temp;j<len;j++)
				row=row*10+s[j]-'0';
			printf("R%dC%d\n",row,col);
		}
	}
	return 0;
}
int isAlpha(char ch)
{
	if(ch<='Z' && ch>='A')
		return 1;
	else return 0;
}
int isDigit(char ch)
{
	if(ch<='9' && ch>='0')
		return 1;
	else return 0;
}