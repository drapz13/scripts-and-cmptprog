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
long long a[100009];
int dp[100009];
int main()
{
    int n,i;
    cin>>n;
    f(i,n)
    {
        cin>>a[i];
    }
    int c=1;
    dp[0]=1;
    for(i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            dp[i]=dp[i-1]+1;
        }
        else
            dp[i]=1;
    }
    for(i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
            dp[i]=max(dp[i+1],dp[i]);
        }
    }
    int maxx=0;
    for(i=0;i<n;i++)
        maxx=max(dp[i],maxx);
   // cout<<dp[i]<<" ";}
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            if(a[i]>=a[i+1])
            {
                maxx=max(dp[i+1]+1,maxx);
            }
        }
        else if(i==n-1)
        {
            if(a[i]<=a[i-1])
            {
                maxx=max(dp[i-1]+1,maxx);
            }
        }
        else
        {
            if(a[i-1]<a[i+1]-1)
            {
                if((a[i]<=a[i-1]&&a[i]>=a[i+1]))
                maxx=max(dp[i+1]+1+dp[i-1],maxx);
                else if(a[i]<=a[i-1])
                    maxx=max(dp[i+1]+dp[i-1],maxx);
                else if(a[i]>=a[i+1])
                    maxx=max(dp[i+1]+dp[i-1],maxx);
            }
            if(a[i]<=a[i-1])
            {
                maxx=max(dp[i-1]+1,maxx);
            }
            if(a[i]>=a[i+1])
            {
                maxx=max(dp[i+1]+1,maxx);
            }
        }
        //cout<<maxx<<" ";
    }
    cout<<maxx;
    return 0;
}