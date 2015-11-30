#include <bits/stdc++.h>
using namespace std;
int dp[100005],a[100005];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    long long ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        dp[a[i]]=i;
    }
    for(int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        if(dp[b]==0)
            ans=ans+1;
        else
        {
            int t=dp[b];
            int u=a[t-1];
            a[t-1]=b;
            a[t]=u;
            dp[u]++;
            dp[b]--;
            ans=ans+t/k+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}