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
LL dp[1009][1009];
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    if(n>=m)
    {
        cout<<"YES";
        return 0;
    }
    int x;
    for(i=0;i<n;i++)
    {
        cin>>x;
        x=x%m;

        for(j=0;j<m;j++)
        {
            if(i)
                {dp[i][j]=dp[i-1][j];
                if(x<=j)
                dp[i][j]=dp[i][j]||dp[i-1][(j-x)];
                if(x>=j)
                {
                    dp[i][j]=dp[i][j]||dp[i-1][(j-x)+m];
                }
                }
        }
        dp[i][x]=1;
        if(dp[i][0]==1)
        {
            cout<<"YES";
            return 0;
        }
    }
    /**for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }**/
    cout<<"NO";
    return 0;
}