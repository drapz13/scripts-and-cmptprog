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
LL a[100009];
int main()
{
    int n,i;
    int c=1;
    int maxx=1;
    cin>>n;
    f(i,n)
    cin>>a[i];
    for(i=1;i<n;i++)
    {
        if(a[i]>=a[i-1])
        {
            c++;
        }
        else
        {
            maxx=max(maxx,c);
            c=1;
        }
    }
    maxx=max(maxx,c);
    cout<<maxx<<endl;
    return 0;
}