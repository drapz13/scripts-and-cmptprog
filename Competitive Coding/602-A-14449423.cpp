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
long long powm(LL a,int b)
{
    int i;
    LL res=1;
    f(i,b)
    {
        res=res*a;
    }
    return res;
}
int main()
{
    LL ans1=0,ans2=0;
    int n,m,i;
    LL x,y,z;
    cin>>n>>x;
    f(i,n)
    {
        cin>>z;
        ans1+=powm(x,n-i-1)*(z);
    }
    cin>>m>>y;
    f(i,m)
    {
        cin>>z;
        ans2+=powm(y,m-i-1)*(z);
    }
    if(ans1>ans2)
    {
        cout<<">";
    }
    else if(ans1==ans2)
    {
        cout<<"=";
    }
    else
        cout<<"<";
    return 0;
}