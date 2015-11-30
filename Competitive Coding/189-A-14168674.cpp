#include<bits/stdc++.h>


#define _fast ios_base::sync_with_stdio(false);cin.tie(0);
#define LL long long int
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define maxn 100000
#define mod 1000000007
bool comp(const int& a, const int& b)
       {
          return a<b?false:true;//min_heap
       }
using namespace std;
typedef pair<int,int> P;
int dp[4001];
int main()
{
    int n,a,b,c,i;
    cin>>n>>a>>b>>c;
    dp[0]=0;
    f(i,n+1)
    {
        if(i>=a)
        {   if((i!=a&&dp[i-a]!=0)||i==a)
            dp[i]=max(dp[i-a]+1,dp[i]);}
        if(i>=b)
        {if((i!=b&&dp[i-b]!=0)||i==b)dp[i]=max(dp[i-b]+1,dp[i]);}
        if(i>=c)
        {if((i!=c&&dp[i-c]!=0)||i==c)dp[i]=max(dp[i-c]+1,dp[i]);}
       // cout<<dp[i]<<" ";
    }
    cout<<dp[n];
    return 0;
}