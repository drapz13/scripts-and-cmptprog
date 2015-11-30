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
int a[109][1000];
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    f(i,n)
    {
        f(j,2*m)
        {
          cin>>a[i][j];
        }
    }
    int c=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*m;j=j+2)
        {
            if(a[i][j]==1||a[i][j+1]==1)
                c++;
        }
    }
    cout<<c;
    return 0;
}