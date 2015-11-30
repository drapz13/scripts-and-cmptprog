#include<bits/stdc++.h>

#define P pair<int,int>
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
long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
LL a[100009];
int main()
{
    int n,i,j;
    s(n);
    f(i,n)
    {
        cin>>a[i];

    }
    LL ans=a[0];
     for (i = 0; i < n; i++) {
    ans = __gcd(ans, a[i]);
  }
  //cout<<ans;
  int f=0;
  for(i=0;i<n;i++)
  {
      LL che= a[i]/ans;
      while(che%2==0)
      {
          che=che/2;
      }
      while(che%3==0)
      {
          che=che/3;
      }
      if(che!=1)
      {
          f=1;
      }
  }
  if(f==1)
  {
      cout<<"No\n";
  }
  else
    cout<<"Yes\n";
    return 0;
}