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
int a[1005];
int vis[1005];
int main()
{
    int n,i,j,k,l,cnt=0,c=0;
    cin>>n;
    f(i,n)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        for(j=0;j<n;j++)
        {
            if(vis[j]==0&&a[j]<=c)
            {
                vis[j]=1;
                c++;
            }
        }
        if(i%2!=0)
        for(k=n-1;k>=0;k--)
        {
            if(vis[k]==0&&a[k]<=c)
            {
                vis[k]=1;
                c++;
            }
        }
        int f=0;
        for(l=0;l<n;l++)
        {
            if(vis[l]==0)
            {
                f=1;
                break;
            }
        }
        if(f==0)
            break;
        cnt++;
    }
    cout<<cnt;
    return 0;
}