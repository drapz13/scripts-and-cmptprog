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
pair<LL,LL> a[100009];
pair<LL,LL> b[100009];
int main()
{
    int n,i;
    s(n);
    f(i,n)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
            if((i+1)<n&&i-1>=0)
            b[a[i].second].first=min(a[i+1].first-a[i].first,a[i].first-a[i-1].first);
            else if((i+1)==n)
                b[a[i].second].first=a[i].first-a[i-1].first;
            else
                b[a[i].second].first=a[i+1].first-a[i].first;
            b[a[i].second].second=max(a[n-1].first-a[i].first,a[i].first-a[0].first);
    }
    for(i=0;i<n;i++)
    {
        cout<<b[i].first<<" "<<b[i].second<<endl;
    }
    return 0;
}