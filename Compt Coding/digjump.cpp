#include <bits/stdc++.h>
#define sflld(n) scanf("%lld",&n)
#define sfulld(n) scanf("%llu",&n)
#define sfd(n) scanf("%d",&n)
#define sfld(n) scanf("%ld",&n)
#define sfs(n) scanf("%s",&n)
#define ll long long
#define ull unsigned long long int
#define pflld(n) printf("%lld\n",n)
#define pfd(n) printf("%d\n",n)
#define pfld(n) printf("%ld\n",n)
#define md 1000000007

using namespace std;
ll dp[1005][1005];
int n,k;
vector<int>adj[1005];
ll solve(int i,int s)
{
    if(s==k)
    {
        if(i==n-1)
            return 1;
        return 0;
    }
    if(dp[i][s]!=-1)
        return dp[i][s];
    ll res=0;
    for(int j=0;j<adj[i].size();j++)
    {
        //cout<<j<<" "<<i<<" "<<s<<" "<<res<<endl;
        res=(res+solve(adj[i][j],s+1))%md;
    }

    return dp[i][s]=res%md;

}
int main()
{
   int t,v,e,u,i;
   sfd(t);
   while(t--)
   {
       sfd(n);
       sfd(e);
       sfd(k);
       for(i=0;i<=n;i++)
       {
           adj[i].clear();
       }
       memset(dp,-1,sizeof(dp));
       while(e--)
       {
           sfd(u);
           sfd(v);
           u--;
           v--;
           if(u!=v)
           {
                adj[u].push_back(v);
                adj[v].push_back(u);
           }
           else
           {
                adj[u].push_back(v);
           }
       }
       ll a=solve(0,0);
       pflld(a);
       /*for(i=0;i<=n;i++)
       {
           for(int j=0;j<=k;j++)
            cout<<dp[i][j]<<" ";
           cout<<endl;
       }*/
   }
    return 0;
}
