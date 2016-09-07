#include <bits/stdc++.h>
using namespace std;
map <int, int> M;
int main()
{
	int n;
	int x;
	char op;
	cin>>n;
	M[0]=1;
	for(int i=0;i<n;i++)
	{
		cin>>op;
		cin>>x;
		if(op=='+')
			M[x]++;
		else if(op=='-'){
			M[x]--;
			if(M[x]==0)
				M.erase(M.find(x));
		}
		else {
			int l=0;
			int r=(1 << 30) - 1;
			int best=r^x;
			for(int it=29;it>=0;it--)
			{
				int curBit=(1 << it) & best;
				if(curBit)
				{
					l = l | (1 << it);
					r = r | (1 << it);
					if(M.lower_bound(l)==M.upper_bound(r))
					{
						l = l & (~(1 << it));
						r = r & (~(1 << it));
					}
				}
				else {
						l = l & (~(1 << it));
						r = r & (~(1 << it));
					if(M.lower_bound(l)==M.upper_bound(r))
					{
						l = l | (1 << it);
						r = r | (1 << it);
					}
				}
			}
			cout<<(l^x)<<endl;
		}
	}
	return 0;
}
