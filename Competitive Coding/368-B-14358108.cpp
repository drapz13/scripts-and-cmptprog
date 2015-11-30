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
int a[1000009],b[1000009],sum[1000009];
map<int,int>m;
int main()
{
    int q,x;
    cin>>x>>q;
    int i;
    f(i,x)
    cin>>a[i];
    for(i=x-1;i>=0;i--)
    {
        if(m[a[i]]==0)
        {
            b[i]=1;
            m[a[i]]=1;
        }
    }
    for(i=x-1;i>=0;i--)
    {
        sum[i]=b[i]+sum[i+1];
    }
    //f(i,x)
    //cout<<sum[i]<<" ";

    w(q)
    {
        int num1;
        cin>>num1;
        cout<<sum[num1-1]<<endl;
    }
    return 0;
}