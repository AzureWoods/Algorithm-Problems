#include <bits/stdc++.h>
using namespace std;
int main()
{
    int len=0;
    int ans1=1,ans2=1;
    int missile[30];
    int dp1[30],dp2[30];
    while((scanf("%d",&missile[len++]))!=EOF);
    len--;
    dp1[0]=1;
    dp2[0]=1;
    for(int i=1;i<len;i++)
    {
        int max1=0;
        int max2=0;
        for(int j=i-1;j>=0;j--)
        {
            if(missile[j]>=missile[i])
            {
                if(dp1[j]>max1)
                    max1=dp1[j];
            }
            if(missile[j]<=missile[i])
            {
                if(dp2[j]>max2)
                    max2=dp2[j];
            }
        }
        dp1[i]=max1+1;
        dp2[i]=max2+1;
        if(dp1[i]>ans1)
            ans1=dp1[i];
        if(dp2[i]>ans2)
            ans2=dp2[i];
    }
    cout<<ans1<<endl<<ans2;
    return 0;
}
