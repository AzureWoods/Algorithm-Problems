#include <iostream>
#include <string>
#include <cstring>
#define MOD 1000000007
using namespace std;
long long quickPow(long long k)
{
	if(k==0)
		return 1;
	if(k%2==0)
		return (quickPow(k/2)*quickPow(k/2))%MOD;
	else return 3*(quickPow(k/2)*quickPow(k/2))%MOD;
}
int main()
{
	int base64Table[200];
	long long sum;
	long long res;
	base64Table[48]=6;base64Table[49]=5;base64Table[50]=5;base64Table[51]=4;base64Table[52]=5;base64Table[53]=4;base64Table[54]=4;base64Table[55]=3;
	base64Table[56]=5;base64Table[57]=4;base64Table[65]=4;base64Table[66]=3;base64Table[67]=4;base64Table[68]=3;base64Table[69]=3;base64Table[70]=2;
	base64Table[71]=5;base64Table[72]=4;base64Table[73]=4;base64Table[74]=3;base64Table[75]=4;base64Table[76]=3;base64Table[77]=3;base64Table[78]=2;
	base64Table[79]=4;base64Table[80]=3;base64Table[81]=3;base64Table[82]=2;base64Table[83]=3;base64Table[84]=2;base64Table[85]=2;base64Table[86]=1;
	base64Table[87]=5;base64Table[88]=4;base64Table[89]=4;base64Table[90]=3;base64Table[97]=4;base64Table[98]=3;base64Table[99]=3;base64Table[100]=2;
	base64Table[101]=4;base64Table[102]=3;base64Table[103]=3;base64Table[104]=2;base64Table[105]=3;base64Table[106]=2;base64Table[107]=2;base64Table[108]=1;
	base64Table[109]=4;base64Table[110]=3;base64Table[111]=3;base64Table[112]=2;base64Table[113]=3;base64Table[114]=2;base64Table[115]=2;base64Table[116]=1;
	base64Table[117]=3;base64Table[118]=2;base64Table[119]=2;base64Table[120]=1;base64Table[121]=2;base64Table[122]=1;base64Table[45]=1;base64Table[95]=0;

//	string s;
	char s[100005];
	cin>>s;
	sum=0;
	for(int i=0;i<strlen(s);i++)
	{
		sum+=base64Table[s[i]];
	}
	res=quickPow(sum);
	cout<<res;
	return 0;
}
