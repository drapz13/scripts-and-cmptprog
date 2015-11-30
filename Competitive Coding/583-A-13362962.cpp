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
int h[55],v[55];
int main()
{
    int n,i,j,h1,v1;
    cin>>n;
    f(i,n*n)
    {
        cin>>h1>>v1;
        if(h[h1]==0&&v[v1]==0)
        {
            h[h1]=1;
            v[v1]=1;
            cout<<i+1<<" ";
        }
    }
    return 0;
}