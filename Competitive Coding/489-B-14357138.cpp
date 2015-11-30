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
int a[101],b[101];
int main()
{
    int n,m,i,j,k,cnt=0;
    cin>>n;
    f(i,n)
    {
        cin>>a[i];
    }
    cin>>m;
    f(i,m)
    cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    j=0;
    k=0;
    while(j!=n&&k!=m)
    {
        if(abs(a[j]-b[k])<=1)
        {
            j++;
            k++;
            cnt++;
        }
        else if(a[j]<b[k])
            j++;
        else
            k++;
    }
    cout<<cnt;
    return 0;
}