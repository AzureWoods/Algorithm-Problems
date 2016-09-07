#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<char, char> M;
	M['A']='A';M['H']='H';M['I']='I';M['M']='M';M['O']='O';M['T']='T';
	M['U']='U';M['V']='V';M['W']='W';M['X']='X';M['Y']='Y';
	M['b']='d';M['d']='b';M['i']='i';M['o']='o';M['p']='q';M['q']='p';M['v']='v';M['w']='w';M['x']='x';
	string ss;
	cin>>ss;
	int i=0;
	int j=ss.size()-1;
	int flag=1;
	while(i<=j)
	{

		if(M[ss[i]] != ss[j])
		{
			flag=0;
			break;
		}
		i++;
		j--;
	}
	if(flag)
		cout<<"TAK";
	else cout<<"NIE";
	return 0;
}