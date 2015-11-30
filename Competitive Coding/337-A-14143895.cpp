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

int main()
{
    int i,n,m,a[100];
    cin>>n>>m;
    f(i,m)
    {
        cin>>a[i];
    }
    sort(a,a+m);
    int ans=INT_MAX;
    f(i,m-n+1)
    {
        ans=min(a[i+n-1]-a[i],ans);
    }
    cout<<ans;
    return 0;
}