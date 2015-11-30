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
long long int a[100009],b[100009];
int main()
{
    int n,k,i,j;
    long long int m=1;
    cin>>n>>k;
    f(i,k)
    {
        m=m*10;
    }
    LL best=1,cnt=0;
    f(i,n/k)
    {
        cin>>a[i];
    }
    f(i,n/k)
    {
        cin>>b[i];
    }
    f(i,n/k)
    {
        cnt=0;
        cnt=(m-1)/a[i];
        //cnt%=mod;
        cnt-=((m/10)*(b[i]+1)-1)/a[i];
        if(b[i]!=0)
        cnt+=((m/10)*b[i]-1)/a[i];
        else
            cnt+=0;
        //cnt%=mod;
        if(b[i]!=0)
        best*=(cnt+1);
        else
            best*=(cnt);
        best%=mod;
    }
    cout<<best;
    return 0;
}