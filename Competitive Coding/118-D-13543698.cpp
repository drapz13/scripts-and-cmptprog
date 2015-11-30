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
#define mod 100000000
bool comp(const int& a, const int& b)
       {
          return a<b?false:true;//min_heap
       }
using namespace std;
typedef pair<int,int> P;
int n1,n2,k1,k2;
long long dp[105][105][15][15];
/**
long long int solve(int i,int j,int c1,int c2)
{
    if(dp[i][j][c1][c2]!=-1)
        return dp[i][j][c1][c2];
    if(i==0&&j==0)
    {
        if(c1<=k1&&c2<=k2)
            return 1;
        return 0;
    }
    if(c1>k1||c2>k2)
        return 0;
    if(i==0)
    {
        dp[i][j][c1][c2]=solve(i,j-1,c1,c2+1);
        dp[i][j][c1][c2]%=mod;
        return dp[i][j][c1][c2];
    }
    if(j==0)
    {
        dp[i][j][c1][c2]=solve(i-1,j,c1+1,c2);
        dp[i][j][c1][c2]%=mod;
        return dp[i][j][c1][c2];
    }
    LL cnt=0;
    cnt+=solve(i-1,j,c1+1,0);
    cnt+=solve(i,j-1,0,c2+1);
    dp[i][j][c1][c2]=cnt%mod;
    return dp[i][j][c1][c2];
}
**/
int main()
{
    memset(dp,0,sizeof(dp));
    cin>>n1>>n2>>k1>>k2;
   // solve(n1,n2,0,0);
    int i,j,k,l;
    //cout<<dp[n1][n2][0][0];
    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
        {
            for(k=0;k<=k1;k++)
            {
                for(l=0;l<=k2;l++)
                {

                    if(i==0&&j==0)
                        dp[i][j][k][l]=1;

                    else if(i==0)
                    dp[i][j][k][l]=dp[i][j-1][k][l+1];

                    else if(j==0)
                        dp[i][j][k][l]=dp[i-1][j][k+1][l];
                    else
                    dp[i][j][k][l]=dp[i-1][j][k+1][0]+dp[i][j-1][0][l+1];

                    dp[i][j][k][l]%=mod;
                }
            }
        }
    }
    cout<<dp[n1][n2][0][0];
    return 0;
}