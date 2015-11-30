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
pair<long long int,long long int>a[100009];
int main()
{
    int n,i,j;
    LL d,maxx,curr,sum1;
    cin>>n;
    cin>>d;
    f(i,n)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    maxx=a[0].second;
    sum1=a[0].second;
    j=1;
    for(i=0;i<n;)
    {
        if(a[j].first-a[i].first<d)
        {
            while(j<n&&a[j].first-a[i].first<d)
            {

                sum1+=a[j].second;
                maxx=max(sum1,maxx);
                j++;
            }
        }
        else
        {
            while(i!=j&&a[j].first-a[i].first>=d)
            {
                sum1-=a[i].second;
                i++;
            }
        }
        if(i>=n||j>=n)
            break;
    }
    maxx=max(sum1,maxx);
    cout<<maxx;
    return 0;
}