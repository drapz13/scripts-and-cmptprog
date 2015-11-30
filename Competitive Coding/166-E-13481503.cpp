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
LL cnt=0;
int n;
//long dp[10000001][4];
/*int solve(int i,int past)
{
    if(dp[i][past]!=-1)
        return dp[i][past];
    if(dp[n-i][past]!=-1)
            return dp[n-i][past];
    if(i==n)
    {
        if(past==0)
        {
            dp[i][past]=1;
            return 1;
        }
        dp[i][past]=0;
        return 0;
    }
    LL sum=0;
    if(past==0)
    {sum+=solve(i+1,1);
    sum+=solve(i+1,2);
    sum+=solve(i+1,3);}
    if(past==1)
    {
    sum+=solve(i+1,0);
    sum+=solve(i+1,2);
    sum+=solve(i+1,3);
    }
    if(past==2)
    {
    sum+=solve(i+1,0);
    sum+=solve(i+1,1);
    sum+=solve(i+1,3);
    }
    if(past==3)
    {
    sum+=solve(i+1,0);
    sum+=solve(i+1,2);
    sum+=solve(i+1,1);
    }
    dp[i][past]=sum%mod;
    return dp[i][past];
}*/
long long dp[2][4];
int main()
{
    cin>>n;
    int i,j;
    memset(dp,0,sizeof(dp));
//    solve(0,0);
    dp[0][0]=0;
    dp[0][1]=0;
    dp[0][2]=0;
    dp[0][3]=0;
    dp[1][0]=0;
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=1;
    for(i=2;i<=n;i++)
    {
        int k=i%2;
        for(j=0;j<4;j++)
        {
            dp[k][j]=dp[1-k][(j+1)%4]+dp[1-k][(j+2)%4]+dp[1-k][(j+3)%4];
            dp[k][j]%=mod;
        }
        //cout<<dp[i][0]<<endl;
    }
    cout<<dp[n%2][0]%mod;
    return 0;
}