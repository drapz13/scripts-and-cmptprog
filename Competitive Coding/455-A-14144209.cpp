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
long long int a[100009],dp[100009],cnt[100009],c[100009];
int main()
{
    int n,i;
    while(s(n)!=EOF)
    {
        int as;
        int k=0;
        memset(cnt,0,sizeof(cnt));
        f(i,n)
        {
            cin>>as;
            if(cnt[as]==0)
            {a[k]=as;k++;}
            cnt[as]++;

        }
        sort(a,a+k);
        f(i,a[k-1]+1)
        {
            c[i]=cnt[i]*i;
        }
        dp[0]=c[a[0]];
        if(a[0]+1==a[1])
            dp[1]=max(c[a[1]],c[a[0]]);
        else
            dp[1]=c[a[1]]+c[a[0]];
        for(i=2;i<k;i++)
        {
            if(a[i-1]+1==a[i])
            {
                dp[i]=max(dp[i-1],c[a[i]]+dp[i-2]);
            }
            else
                dp[i]=dp[i-1]+c[a[i]];
        }
        cout<<dp[k-1]<<endl;
    }
    return 0;
}