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
int ans=0,maxx=0;
int a[100009];
int main()
{
    int n,i,j,k,p=0,s=0;
    cin>>n;
    int b[100009];
    int f=1;
    f(i,n)
    {
        cin>>a[i];
        b[i]=a[i];
        if(a[i]==0)
            f=0;
        if(a[i]==1)
            maxx++;
    }
    int pkka=maxx;
        for(j=0;j<n;j++)
        {
            ans=maxx;
            for(k=j;k<n;k++)
            {
                if(a[k]==1)
                {
                    ans--;
                }
                else
                    ans++;
                pkka=max(pkka,ans);
            }
        }
        if(f==0)
        cout<<pkka;
        else
            cout<<pkka-1;
    return 0;
}